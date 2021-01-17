#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <QStandardItemModel>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

QString f_name;

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
    QString filename = QFileDialog::getOpenFileName(this,
           tr("Choise file"), "/Users/asydoruk/scripts",
           tr("All Files (*)"));
    extern QString f_name;
    f_name = filename;
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(4);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Назва" << "Жанр" << "Дата" << "Початок");
        ui->tableView->setModel(csvModel);
        QFile file(filename);
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            // Создаём поток для извлечения данных из файла
            QTextStream in(&file);
            // Считываем данные до конца файла
            while (!in.atEnd())
            {
                // ... построчно
                QString line = in.readLine();
                // Добавляем в модель по строке с элементами
                QList<QStandardItem *> standardItemsList;
                // учитываем, что строка разделяется точкой с запятой на колонки
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
    extern QString f_name;
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(4);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Назва" << "Жанр" << "Дата" << "Початок");
        ui->tableView_2->setModel(csvModel);
        QFile file(f_name);
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            // Создаём поток для извлечения данных из файла
            QTextStream in(&file);
            // Считываем данные до конца файла
            while (!in.atEnd())
            {
                // ... построчно
                QString line = in.readLine();
                // Добавляем в модель по строке с элементами
                QList<QStandardItem *> standardItemsList;
                // учитываем, что строка разделяется точкой с запятой на колонки
                for (QString item : line.split(" ")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                QDateTime departTime = QDateTime::fromString(standardItemsList.at(3)->text(),"hh:mm:ss");
                if (departTime < QDateTime::currentDateTime() && standardItemsList.at(1)->text() == "балет") {
                    csvModel->insertRow(csvModel->rowCount(), standardItemsList);
                }
            }
            file.close();
        }
//        ui->tableView->hideRow(1);
//        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView_2->resizeColumnsToContents();
}

void MainWindow::on_pushButton_3_clicked()
{
    extern QString f_name;
    QStandardItemModel *csvModel;
    csvModel = new QStandardItemModel(this);
        csvModel->setColumnCount(4);
        csvModel->setHorizontalHeaderLabels(QStringList() << "Назва" << "Жанр" << "Дата" << "Початок");
        ui->tableView_2->setModel(csvModel);
        QFile file(f_name);
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            // Создаём поток для извлечения данных из файла
            QTextStream in(&file);
            // Считываем данные до конца файла
            while (!in.atEnd())
            {
                // ... построчно
                QString line = in.readLine();
                // Добавляем в модель по строке с элементами
                QList<QStandardItem *> standardItemsList;
                // учитываем, что строка разделяется точкой с запятой на колонки
                for (QString item : line.split(" ")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                QDateTime departTime = QDateTime::fromString(standardItemsList.at(3)->text(),"hh:mm:ss");
                if (departTime > QDateTime::fromString("13:00:00","hh:mm:ss")) {
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

void MainWindow::on_pushButton_4_clicked()
{
    extern QString f_name;
    QString full = ui->lineEdit->text() + " " + ui->lineEdit_2->text() + " " + ui->lineEdit_3->text() + " " + ui->lineEdit_4->text();
    std::ofstream fileOUT(f_name.toStdString(), std::ios::app);
    fileOUT << full.toStdString() << std::endl;
    fileOUT.close();
}
