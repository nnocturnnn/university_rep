#include "swindow.h"
#include "ui_swindow.h"
#include "sqlite3.h"

SWindow::SWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SWindow)
{
    ui->setupUi(this);
}

SWindow::~SWindow()
{
    delete ui;
}

void SWindow::on_pushButton_clicked()
{
   QString pass = ui->label->text();
   QString pass_n = ui->label_2->text();
   sqlite3_stmt * stmt;
   sqlite3 *db;
   const char* dir = "sqluser.db";
   int rc=0;
   rc = sqlite3_open_v2(dir, &db,SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
   QString sqlstatement = "INSERT INTO abe_account (" + username + "," + name + "," + department + "," + password + ");";

   if (sqlite3_open("abeserver.db", &db) == SQLITE_OK)
   {
   sqlite3_prepare( db, sqlstatement.c_str(), -1, &stmt, NULL );//preparing the statement
   sqlite3_step( stmt );//executing the statement
     }

   sqlite3_finalize(stmt);

}
