/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *page_3;
    QPushButton *pushButton_8;
    QTableView *tableView_3;
    QWidget *page_2;
    QPushButton *pushButton_3;
    QTableView *tableView_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 150, 741, 321));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 120, 261, 51));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 40, 261, 51));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(540, 270, 181, 51));
        QFont font;
        font.setPointSize(17);
        pushButton_5->setFont(font);
        lineEdit_3 = new QLineEdit(page);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 200, 261, 51));
        lineEdit_4 = new QLineEdit(page);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(380, 40, 261, 51));
        lineEdit_5 = new QLineEdit(page);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(380, 120, 261, 51));
        lineEdit_6 = new QLineEdit(page);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(380, 200, 261, 51));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 0, 81, 31));
        QFont font1;
        font1.setPointSize(15);
        label_3->setFont(font1);
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 90, 81, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 170, 91, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(480, 0, 61, 31));
        label_6->setFont(font1);
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(480, 90, 91, 31));
        label_7->setFont(font1);
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(490, 170, 91, 31));
        label_8->setFont(font1);
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(490, 260, 211, 51));
        tableView_3 = new QTableView(page_3);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(10, 30, 731, 192));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 30, 311, 61));
        tableView_2 = new QTableView(page_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 120, 731, 192));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 30, 241, 61));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 30, 211, 61));
        stackedWidget->addWidget(page_2);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 391, 61));
        QFont font2;
        font2.setPointSize(20);
        label->setFont(font2);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 90, 151, 41));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(220, 90, 241, 41));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(450, 90, 161, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\260\320\275\321\226\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\224\321\226\320\260\320\263\320\276\320\275\320\260\320\273\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\246\321\226\320\275\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "2SIM", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275\320\270 \320\267\320\260 \320\276\321\201\321\202\320\260\320\275\320\275\321\226\320\271 \320\274\321\226\321\201\321\217\321\206\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275\320\270 Samsung \320\267 \320\264\320\262\320\276\320\274\320\260 SIM-\320\272\320\260\321\200\321\202\320\260\320\274\320\270", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \320\267\320\260 \321\206\321\226\320\275\320\276\321\216", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\237 9 \320\245\320\260\320\266\320\270\320\273\320\265\320\275\320\272\320\276 \320\220\321\200\321\202\320\265\320\274 \320\237\320\221-71 \320\222\320\260\321\200i\320\260\320\275\321\202 16", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\262\320\275\320\265\320\275\320\275\321\217 \321\204\320\260\320\271\320\273\321\203", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\261\321\226\321\200 \320\264\320\260\320\275\320\275\320\270\321\205 \321\202\320\260 \320\262\320\270\320\262\320\265\320\264\320\265\320\275\320\275\321\217 \321\204\320\260\320\271\320\273\321\203", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\262\320\265\320\264\320\265\320\275\320\275\321\217 \320\262 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
