#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlite3.h"

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
//    sqlite3 *db;
//    const char* dir = "sqluser.db";
//    int rc=0;
//    rc = sqlite3_open_v2(dir, &db,SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
//    if(rc)
//        fprintf(stderr, "Error Open Database %s\n", sqlite3_errmsg(db));
//    else
//        fprintf(stdout, "Database opended\n");
    QString login = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
//    rc = sqlite3_user_add(db, login, pass, 4, 1);
    if (login == "ADMIN") {
        twind = new TWindow(this);
        twind->show();
    } else {
        swindow = new SWindow(this);
        swindow->show();
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    window = new Dovid(this);
    window->show();
}
