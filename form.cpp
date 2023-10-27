#include "form.h"
#include "ui_form.h"
#include <QtSql>
#include <QDebug>
#include <QtWidgets>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setupModel();
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->nameEd, model->fieldIndex("name"));
    mapper->addMapping(ui->descriptionEd, model->fieldIndex("description"));
    mapper->addMapping(ui->priceEd, model->fieldIndex("price"));
    connect(ui->prevBtn, &QPushButton::clicked,
            mapper, &QDataWidgetMapper::toPrevious);
    connect(ui->nextBtn, &QPushButton::clicked,
            mapper, &QDataWidgetMapper::toNext);
    connect(mapper, &QDataWidgetMapper::currentIndexChanged, this, &Form::updateImg);
    mapper->toFirst();
}

void Form::setupModel()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sql");
    if (!db.open()) {
        QMessageBox::critical(0, tr("Cannot open database"),
            tr("Unable to establish a database connection."), QMessageBox::Cancel);
        return;
    }

    model = new QSqlRelationalTableModel(this);
    model->setTable("goods");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
}

void Form::updateImg(int row)
{
    QPixmap pixmap(model->record(row).value("image").toString());
    ui->imageEd->setPixmap(pixmap);
    ui->imageEd->setMask(pixmap.mask());
    ui->imageEd->setScaledContents(true);
    ui->imageEd->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->imageEd->show();
}

Form::~Form()
{
    delete ui;
}
