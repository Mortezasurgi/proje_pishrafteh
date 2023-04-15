#include "safhe_taeid.h"
#include "ui_safhe_taeid.h"
#include "codetaeid.h"
#include "QMessageBox"
#include "faze2.h"
safhe_taeid::safhe_taeid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::safhe_taeid)
{
    ui->setupUi(this);
}

safhe_taeid::~safhe_taeid()
{
    delete ui;
}

void safhe_taeid::on_pushButton_clicked()
{
    int mohtava;
    mohtava=ui->lineEdit->text().toInt();
    int cc = code;

    if(cc==mohtava){
        QMessageBox::information(this,"","confirmation done!");
        faze2 *page4 = new faze2;
        this->hide();
        page4->show();
    }
    else {
        QMessageBox::information(this,"","the entered code is wrong !");
    }
}
