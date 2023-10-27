/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTextEdit *descriptionEd;
    QLineEdit *nameEd;
    QPushButton *nextBtn;
    QLineEdit *priceEd;
    QPushButton *prevBtn;
    QLabel *imageEd;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(691, 463);
        Form->setWindowOpacity(1.000000000000000);
        descriptionEd = new QTextEdit(Form);
        descriptionEd->setObjectName(QString::fromUtf8("descriptionEd"));
        descriptionEd->setGeometry(QRect(450, 190, 221, 211));
        descriptionEd->setReadOnly(true);
        nameEd = new QLineEdit(Form);
        nameEd->setObjectName(QString::fromUtf8("nameEd"));
        nameEd->setGeometry(QRect(510, 60, 161, 24));
        nameEd->setReadOnly(true);
        nextBtn = new QPushButton(Form);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));
        nextBtn->setGeometry(QRect(580, 420, 80, 25));
        priceEd = new QLineEdit(Form);
        priceEd->setObjectName(QString::fromUtf8("priceEd"));
        priceEd->setGeometry(QRect(510, 100, 161, 24));
        priceEd->setReadOnly(true);
        prevBtn = new QPushButton(Form);
        prevBtn->setObjectName(QString::fromUtf8("prevBtn"));
        prevBtn->setGeometry(QRect(470, 420, 80, 25));
        imageEd = new QLabel(Form);
        imageEd->setObjectName(QString::fromUtf8("imageEd"));
        imageEd->setGeometry(QRect(50, 40, 361, 381));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 160, 71, 16));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(460, 100, 41, 16));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(460, 60, 55, 16));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "MebelShop", nullptr));
        nextBtn->setText(QApplication::translate("Form", "Next->", nullptr));
        prevBtn->setText(QApplication::translate("Form", "<-Pevios", nullptr));
        imageEd->setText(QApplication::translate("Form", "TextLabel", nullptr));
        label->setText(QApplication::translate("Form", "Description", nullptr));
        label_2->setText(QApplication::translate("Form", "Price", nullptr));
        label_3->setText(QApplication::translate("Form", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
