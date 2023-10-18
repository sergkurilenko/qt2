#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QIODevice"
#include <QFileDialog>
#include <QBitArray>
#include <QDebug>
#include <QDataStream>

#include "bytearraymodel.h"
#include "checkboxdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QByteArray data0 = QString("011111111").toLocal8Bit();
    QBitArray data(data0.count()*8);
    for(int i=0; i<data0.count(); ++i) {
        for(int b=0; b<8;b++) {
            data.setBit( i*8+b, data0.at(i)&(1<<(7-b)) );
        }
    }
    qDebug() << data;
    ByteArrayModel* model = new ByteArrayModel(data, this);
    QItemSelectionModel* selModel = new QItemSelectionModel(model, model);

    CheckBoxDelegate *delegate = new CheckBoxDelegate();

    model->setObjectName("model");
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(selModel);
    ui->tableView_2->setModel(model);
    ui->tableView_2->setSelectionModel(selModel);
    for(int i=0;i<8;i++){
    ui->tableView->setItemDelegateForColumn(i, delegate);
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

