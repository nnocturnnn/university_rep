#include "dovid.h"
#include "ui_dovid.h"

Dovid::Dovid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dovid)
{
    ui->setupUi(this);
}

Dovid::~Dovid()
{
    delete ui;
}



