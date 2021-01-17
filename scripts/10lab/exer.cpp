#include "exer.h"
#include "ui_exer.h"

Exer::Exer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exer)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("background-image: url(\"https://www.imgonline.com.ua/examples/jpeg-artifacts_3x.png\")");
}

Exer::~Exer()
{
    delete ui;
}
