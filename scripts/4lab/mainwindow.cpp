#include "mainwindow.h"
#include "ui_mainwindow.h"

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

std::vector<std::string> splity(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void MainWindow::on_pushButton_clicked()
{
    QString stri = ui->lineEdit->text();
    std::string str = stri.toStdString();
    char cstr[str.size() + 1];
    strcpy(cstr, str.c_str());
    for(int i = 0;i < str.length();i++) {
        if(isdigit(cstr[i]))
            cstr[i] = '+';

    }
    ui->label_3->setText(QString::fromStdString(cstr));
}

void MainWindow::on_pushButton_2_clicked()
{
    int num = 0;
    QString stri = ui->lineEdit_2->text();
    std::string str = stri.toStdString();
    std::vector<std::string> arrwd = splity(str," ");
    for(auto wd : arrwd) {
        if(wd.length() % 2 == 0) {
            num++;
        }
    }
    str = "Num = " + std::to_string(num);
    ui->label_5->setText(QString::fromStdString(str));
}
