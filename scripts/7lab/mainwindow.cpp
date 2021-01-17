#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <QStandardItemModel>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

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



void MainWindow::on_pushButton_clicked()
{
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(4);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Назва" << "Продукція" << "Кількіть" << "Рентабельність");
        ui->tableView->setModel(csvModel);
        QFile file("/Users/asydoruk/scripts/7lab/Surname.dat");
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
//        csvModel->removeRow(1);
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->resizeColumnsToContents();

}

void MainWindow::on_pushButton_2_clicked()
{
    int max = 1;
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(4);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Назва" << "Продукція" << "Кількіть" << "Рентабельність");
        ui->tableView_2->setModel(csvModel);
        QFile file("/Users/asydoruk/scripts/7lab/Surname.dat");
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
        for (int i = 0; i < csvModel->rowCount();i++){
            if (csvModel->index(i,2).data().toInt() > max) {
                max = csvModel->index(i,2).data().toInt();
            }
        }
        for (int i = 0; i < csvModel->rowCount();i++){
            if (csvModel->index(i,2).data().toInt() != max) {
                csvModel->removeRow(i);
            }
        }
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView_2->resizeColumnsToContents();
}

void MainWindow::on_pushButton_3_clicked()
{
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(4);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Назва" << "Продукція" << "Кількіть" << "Рентабельність");
        ui->tableView_2->setModel(csvModel);
        QFile file("/Users/asydoruk/scripts/7lab/Surname.dat");
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

                if (standardItemsList.at(3)->text().toInt() < 0) {
                    csvModel->insertRow(csvModel->rowCount(), standardItemsList);
                }
            }
            file.close();
        }
//        csvModel->removeRow(1);
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView_2->resizeColumnsToContents();
}
