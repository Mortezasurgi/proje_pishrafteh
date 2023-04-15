#include "pishvas.h"
#include "ui_pishvas.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "sabtenamvavorood.h"

pishvas::pishvas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pishvas)
{
    ui->setupUi(this);
    QSqlDatabase database ;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\projectpishrafteh.db");
    database.open();
}

pishvas::~pishvas()
{
    delete ui;
}

void pishvas::on_pushButton_2_clicked()
{
    sabtenamvavorood *page2 = new sabtenamvavorood;
    page2->setWindowTitle("Log in   or   sign up!");
    page2->show();
}
