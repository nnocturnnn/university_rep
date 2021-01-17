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


std::string get_last_word(const std::string& str)
{
    if (str.length() == 0)
    {
        return 0;
    }

    int len = str.length();
    int i = len - 1;
    while (i >= 0 && str[i] != ' ')
    {
        i--;
    }
    std::string last_word;
    for (int j = i + 1; j < len; j++)
    {
        last_word += str[j];
    }
    return last_word;
}



void MainWindow::on_pushButton_clicked()
{
    QString stri = ui->lineEdit->text();
    std::string str = stri.toStdString();
    std::string last_world = get_last_word(str);
    std::string reverse_worl(last_world);
    std::reverse(reverse_worl.begin(), reverse_worl.end());
    str.replace(str.find(last_world),last_world.length(),reverse_worl);
    ui->label_3->setText(QString::fromStdString(str));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString stri = ui->lineEdit_2->text();
    std::string str = stri.toStdString();
    std::string p = ".,:-";
        for(auto it = str.begin(); it < str.end(); it++){
            for(auto pt = p.begin(); pt != p.end(); pt++){
                if(*it == *pt){
                    str.erase(it);
                }
            }
       }
    ui->label_5->setText(QString::fromStdString(str));
}
