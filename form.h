#ifndef FORM_H
#define FORM_H

#include <QWidget>
QT_BEGIN_NAMESPACE
class QDataWidgetMapper;
class QSqlRelationalTableModel;
QT_END_NAMESPACE

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    void setupModel();
    QSqlRelationalTableModel *model;
    QDataWidgetMapper *mapper;
private slots:
    void updateImg(int row);
};

#endif // FORM_H
