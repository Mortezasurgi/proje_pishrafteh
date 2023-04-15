#include "faze2.h"
#include "ui_faze2.h"

faze2::faze2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::faze2)
{
    ui->setupUi(this);
}

faze2::~faze2()
{
    delete ui;
}
