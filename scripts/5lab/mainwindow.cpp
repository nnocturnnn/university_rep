#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <iostream>

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

bool isInside(const std::string & str, char c)
{
    return str.find(c) != std::string::npos;
}

void MainWindow::on_pushButton_clicked()
{
    int num = 0;
    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Choise file"), "/",
           tr("file (*.abk);;All Files (*)"));
    std::ifstream file(fileName.toStdString());
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if(isupper(line.c_str()[0]));
                num++;
        }
        file.close();
    }
    ui->label_3->setText(QString::fromStdString("Num = " + std::to_string(num)));
}

void MainWindow::on_pushButton_2_clicked()
{
    int num = 0;
    std::string lab;
    std::fstream file;
    std::string word;
    QString filename = QFileDialog::getOpenFileName(this,
           tr("Choise file"), "/",
           tr("file (*.abk);;All Files (*)"));
    file.open(filename.toStdString());
    while (file >> word)
    {
       if(!isInside(word,'o')) {
           num++;
           lab += word + " ";

        }
    }
    std::cout << lab;
    ui->label_5->setText(QString::fromStdString("Num = " + std::to_string(num) + lab));
}
