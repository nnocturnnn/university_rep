#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    this->setStyleSheet("{background-image: url(:/Users/asydoruk/scripts/8.1;}");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_label_linkActivated(const QString &link)
{

}
