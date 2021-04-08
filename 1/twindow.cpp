#include "twindow.h"
#include "ui_twindow.h"

TWindow::TWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TWindow)
{
    ui->setupUi(this);
}

TWindow::~TWindow()
{
    delete ui;
}



void TWindow::on_pushButton_5_clicked()
{

}

void TWindow::on_pushButton_4_clicked()
{

}

void TWindow::on_pushButton_3_clicked()
{

}

void TWindow::on_pushButton_2_clicked()
{

}

void TWindow::on_pushButton_clicked()
{

}
