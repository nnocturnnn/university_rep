#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
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


void MainWindow::on_pushButton_clicked()
{
    double res;
    double y = QString(ui->textEdit_2->toPlainText()).toDouble();
    double i = QString(ui->textEdit->toPlainText()).toDouble();
    res = 0.81*cos(i)/log(y)+2*pow(i,3);
    QString qstr = QString::fromStdString("L=" + std::to_string(res));
    ui->label_4->setText(qstr);

}

void MainWindow::on_pushButton_2_clicked()
{
    double res;
    double x = QString(ui->textEdit_3->toPlainText()).toDouble();
    double y = QString(ui->textEdit_4->toPlainText()).toDouble();
    double z = QString(ui->textEdit_5->toPlainText()).toDouble();
    double c = QString(ui->textEdit_6->toPlainText()).toDouble();
    res = tan(pow(x,4)-6)-pow(cos(z+pow(x,3)*y),3*x)/pow(cos(pow(x,3)),2) + pow(c,2);
    QString qstr = QString::fromStdString("G=" + std::to_string(res));
    ui->label_9->setText(qstr);
}


void MainWindow::on_pushButton_6_clicked()
{
    double x = QString(ui->textEdit_11->toPlainText()).toDouble();
    QString qstr = QString::fromStdString("W=" + std::to_string((exp(x) - exp(-x))*tan(x+1)-pow(tan(2),2+(exp(x-1) - exp(-x+1)))));
     ui->label_26->setText(qstr);
}

void MainWindow::on_pushButton_3_clicked()
{
    double res;
    double x = QString(ui->textEdit_7->toPlainText()).toDouble();
    res = (pow(x,2)+sqrt(pow(sin(x),2)-log(pow(x,2)-3)))/pow(x+sqrt(5.5*x+log(x)),2);
    QString qstr = QString::fromStdString("V16=" + std::to_string(res));
    ui->label_14->setText(qstr);
}


void MainWindow::on_pushButton_4_clicked()
{
    double res;
    double x = QString(ui->textEdit_8->toPlainText()).toDouble();
    res = (4*pow(x,2) - pow(3,x))/(2*pow(x,2) + 1) + log(x)/(2*x+3);
    QString qstr = QString::fromStdString("y=" + std::to_string(res));
    ui->label_15->setText(qstr);
}

void MainWindow::on_pushButton_5_clicked()
{
    double m = QString(ui->textEdit_9->toPlainText()).toDouble();
    double p = QString(ui->textEdit_10->toPlainText()).toDouble();
    ui->label_20->setText(QString::fromStdString("x=" + std::to_string(log(pow(sqrt(m),2)+p)+sqrt(m))));
    ui->label_22->setText(QString::fromStdString("y=" + std::to_string(pow(sqrt(m),2)+p)));
    ui->label_23->setText(QString::fromStdString("t=" + std::to_string(sqrt(m))));
}
