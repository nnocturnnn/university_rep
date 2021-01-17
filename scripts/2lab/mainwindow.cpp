#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

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
    int index;
    QString str = ui->lineEdit->text();
    char cstr[str.size() + 1];
    std::string stri = str.toStdString();
    strcpy(cstr, stri.c_str());
    for(int i = 0;i < str.length();i++) {
        if(cstr[i] == ' ') {
            index = i;
        }
    }
    ui->label_3->setText(QString::fromStdString("Index = " +  std::to_string(index)));
}

std::string removeSpaces(std::string input)
{
  input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit_2->text();
    std::string st = removeSpaces(str.toStdString());
    ui->label_5->setText(QString::fromStdString(st));
}
