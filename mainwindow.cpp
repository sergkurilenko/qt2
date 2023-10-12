#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imgarraymodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage data;
    data.load("seccode.png");
    ImgArrayModel* model = new ImgArrayModel(data, this);
    model->setObjectName("model");
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

