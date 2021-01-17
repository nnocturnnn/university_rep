#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <QStandardItemModel>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include "QStandardItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(6);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Фірма" << "Модель" << "Діагональ" << "Ціна" << "Дата Поставки" << "2SIM");
        ui->tableView_2->setModel(csvModel);
        QFile file("/Users/asydoruk/scripts/surname.bin");
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QList<QStandardItem *> standardItemsList;
                for (QString item : line.split(" ")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                if (standardItemsList.at(0)->text() == "Samsung" && standardItemsList.at(5)->text() == "так") {
                    csvModel->insertRow(csvModel->rowCount(), standardItemsList);
                }
            }
            file.close();
        }
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView_2->resizeColumnsToContents();
}

void MainWindow::on_pushButton_clicked()
{
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(6);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Фірма" << "Модель" << "Діагональ" << "Ціна" << "Дата Поставки" << "2SIM");
        ui->tableView_2->setModel(csvModel);
        QFile file("/Users/asydoruk/scripts/surname.bin");
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QList<QStandardItem *> standardItemsList;
                for (QString item : line.split(" ")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                    csvModel->insertRow(csvModel->rowCount(), standardItemsList);
            }
            file.close();
        }
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView_2->resizeColumnsToContents();
}

void MainWindow::on_pushButton_2_clicked()
{
    QStandardItem *item;
    QStandardItem *item2;
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(6);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Фірма" << "Модель" << "Діагональ" << "Ціна" << "Дата Поставки" << "2SIM");
        ui->tableView_2->setModel(csvModel);
        QFile file("/Users/asydoruk/scripts/surname.bin");
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QList<QStandardItem *> standardItemsList;
                for (QString item : line.split(" ")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                    csvModel->insertRow(csvModel->rowCount(), standardItemsList);
            }
            file.close();
        }
        for (int i = 0; i < csvModel->rowCount() - 1; i++) {
            for (int j = 0; j < csvModel->rowCount() - i - 1; j++) {
                if(csvModel->index(j,3).data().toInt() > csvModel->index(j + 1,3).data().toInt()) {
                    for(int k = 0; k < 6; k++) {
                        QString buf = csvModel->index(j,k).data().toString();
                        item = new QStandardItem(buf);
                        item2 = new QStandardItem(csvModel->index(j+1,k).data().toString());
                        csvModel->setItem(j,k,item2);
                        csvModel->setItem(j+1,k,item);
                    }
                }
            }
        }
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView_2->resizeColumnsToContents();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString full = ui->lineEdit->text() + " " + ui->lineEdit_2->text() + " " + ui->lineEdit_3->text() + " " + ui->lineEdit_4->text() + " " + ui->lineEdit_5->text() + " " + ui->lineEdit_6->text();
    std::ofstream fileOUT("/Users/asydoruk/scripts/surname.bin", std::ios::app);
    fileOUT << full.toStdString() << std::endl;
    fileOUT.close();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_pushButton_8_clicked()
{
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(6);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Фірма" << "Модель" << "Діагональ" << "Ціна" << "Дата Поставки" << "2SIM");
        ui->tableView_3->setModel(csvModel);
        QFile file("/Users/asydoruk/scripts/surname.bin");
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QList<QStandardItem *> standardItemsList;
                for (QString item : line.split(" ")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                QDateTime departTime = QDateTime::fromString(standardItemsList.at(4)->text(),"dd.MM.yyyy");
                if (departTime > QDateTime::fromString("17.12.2020","dd.MM.yyyy")) {
                    csvModel->insertRow(csvModel->rowCount(), standardItemsList);
                }
            }
            file.close();
        }
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView_3->resizeColumnsToContents();
    std::ofstream fileOUT("/Users/asydoruk/scripts/new.txt");
    for (int i = 0; i < csvModel->rowCount() - 1; i++) {
        QString buf = "";
        for(int k = 0; k < 6; k++) {
            buf += csvModel->index(i,k).data().toString();
        }
        fileOUT << buf.toStdString() << std::endl;
    }
    fileOUT.close();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
