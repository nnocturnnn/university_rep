/********************************************************************************
** Form generated from reading UI file 'autor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOR_H
#define UI_AUTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Autor
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Autor)
    {
        if (Autor->objectName().isEmpty())
            Autor->setObjectName(QString::fromUtf8("Autor"));
        Autor->resize(400, 300);
        label = new QLabel(Autor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 10, 171, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(Autor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 0, 181, 201));
        label_2->setFont(font);

        retranslateUi(Autor);

        QMetaObject::connectSlotsByName(Autor);
    } // setupUi

    void retranslateUi(QDialog *Autor)
    {
        Autor->setWindowTitle(QCoreApplication::translate("Autor", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Autor", "\320\240\320\276\320\261\320\276\321\202\321\203 \320\262\320\270\320\272\320\276\320\275\320\260\320\262", nullptr));
        label_2->setText(QCoreApplication::translate("Autor", "<html><head/><body><p>\320\244\320\260\320\274\320\270\320\273\320\270\321\217 \320\230 \320\236</p><p>\320\237\320\221-71 \320\222\320\260\321\200i\320\260\320\275\321\202 16</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Autor: public Ui_Autor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOR_H
