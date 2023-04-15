#include "sabtenamvavorood.h"
#include "ui_sabtenamvavorood.h"
#include "QString"
#include "string"
#include "iostream"
#include "QMessageBox"
#include "safhe_taeid.h"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "codetaeid.h"
#include "faze2.h"
int code=0;

int random;
QString check_captcha;
sabtenamvavorood::sabtenamvavorood(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sabtenamvavorood)
{

    ui->setupUi(this);
    QSqlDatabase database ;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\projectpishrafteh.db");
    database.open();
    ui->groupBox_2->hide();
    random = rand()%10;
    QString s = "border-image: url(:/new/prefix1/image"+QString::number(random)+".png);";
    ui->label_9->setStyleSheet(s);
}

sabtenamvavorood::~sabtenamvavorood()
{
    delete ui;
}

int checker=0,checker_login=0 ;//for eye slot
void sabtenamvavorood::on_pushButton_4_clicked()
{
    QString user, pass, cap;
    user = ui->username_lineEdit_2->text();
    pass = ui->password_lineEdit_2->text();
    cap  = ui->lineEdit->text();
    bool toolemojazepass = (pass.length() >= 7);
    bool aya_pass_chardelkhahdre = false;
    QChar c,g;
    for (int i=0; i<pass.length();i++)
    {
        c = pass[i];
        if (c == '*'||c == '&'||c == '^'||c == '%'||c == '#' || c == '$')
        {
            aya_pass_chardelkhahdre = true;
            break;
        }
    }
    bool aya_user_passgheirmojaznadarad = true;//dar ebteda bale nadarad
    for (int j=0; j<user.length();j++)
    {
        g = user[j];
        if (g == '*'||g == '&'||g == '^'||g == '%'||g == '#' || g == '$')
        {
            aya_user_passgheirmojaznadarad = false;//inja yani gheire mojAZ dre
            break; }
    }
    if (toolemojazepass && aya_pass_chardelkhahdre && aya_user_passgheirmojaznadarad) //age hamechi ok bud dar soorati k user tekrari nbud b data base add she
    {
        QSqlQuery q;
         q.exec("SELECT username FROM details WHERE username= '"+user+"'");
         if(q.first())
         {
             QMessageBox::warning(this,"","this username is now exist, please enter another username!");
         }
         else {
             if(cap==check_captcha) //capcha
             {
                 QSqlQuery p;
                 p.exec("INSERT INTO details(username,password)VALUES('"+user+"', '"+pass+"')");
                 codeetaeid ob;
                 ob.c=rand()%10000;
                 code = ob.c;



                 safhe_taeid *pagetaeid = new safhe_taeid;
                 this->hide();
                 pagetaeid->show();

                 QMessageBox::warning(this,"","your confirmation code is"+QString::number(ob.c)+"  please enter the confirmation code in lineedit!");
             }
             else {
                 QMessageBox::warning(this,"","please enter the true capcha!");
             }


         }
    }
    else if(toolemojazepass==false && aya_pass_chardelkhahdre && aya_user_passgheirmojaznadarad){
         QMessageBox::information(this,"","the password should has at least 7 chars!");
    }
    else if(toolemojazepass && aya_pass_chardelkhahdre==false && aya_user_passgheirmojaznadarad)
    {
        QMessageBox::information(this,"","the password should has at least one of these chars : *&^%#$ !");
    }
    else if(toolemojazepass && aya_pass_chardelkhahdre && aya_user_passgheirmojaznadarad==false)
    {
        QMessageBox::information(this,"","the username should *not* has  one of these chars : *&^%#$ !");
    }
    else if(toolemojazepass==false && aya_pass_chardelkhahdre==false && aya_user_passgheirmojaznadarad){
         QMessageBox::information(this,"","the password should has at least 7 chars and the password should has at least one of these chars : *&^%#$ !!");
    }
    else if(toolemojazepass==false && aya_pass_chardelkhahdre && aya_user_passgheirmojaznadarad==false)
    {
        QMessageBox::information(this,"","the password should has at least 7 chars and !the username should *not* has  one of these chars : *&^%#$ !");
    }
    else if(toolemojazepass && aya_pass_chardelkhahdre==false && aya_user_passgheirmojaznadarad==false)
    {
        QMessageBox::information(this,"","the password should has at least one of these chars : *&^%#$ ! and the username should *not* has  one of these chars : *&^%#$ !");
    }
    else if(toolemojazepass && aya_pass_chardelkhahdre==false && aya_user_passgheirmojaznadarad==false)
    {
        QMessageBox::information(this,"","the password should has at least 7 chars! and the password should has at least one of these chars : *&^%#$ ! and the username should *not* has  one of these chars : *&^%#$ !");
    }
}

void sabtenamvavorood::on_pushButton_3_clicked()
{
    ui->groupBox->hide();
    ui->groupBox_2->show();
}
//ui->pushButton->setStyleSheet("");




void sabtenamvavorood::on_pushButton_clicked()
{
        if(checker==0){
            ui->password_lineEdit_2->setEchoMode(QLineEdit::Normal);
            ui->pushButton->setStyleSheet("border-image: url(:/new/prefix1/hide_eye.png);");
            checker=1;
            return;
            }
        ui->pushButton->setStyleSheet("border-image: url(:/new/prefix1/show_eye.png);");
              ui->password_lineEdit_2->setEchoMode(QLineEdit::Password);
        checker=0;
}

void sabtenamvavorood::on_pushButton_2_clicked()  //login
{
    QString user, pass, checkpass="-";
    user = ui->username_lineEdit->text();
    pass = ui->password_lineEdit->text();
    QSqlQuery q, p;
     q.exec("SELECT username FROM details WHERE username= '"+user+"'");
     if(q.first()) //age hamchin useri vojood dasht
     {
         p.exec("SELECT password FROM details WHERE username= '"+user+"'");
         if(p.first())
         {
             checkpass = p.value(0).toString();
         }
     }
     else {
         QMessageBox::warning(this,"","such a username dos not exist? sign up?");
     }
     if(pass==checkpass)
     {
         faze2 *page4 = new faze2;
         this->hide();
         page4->show();
     }

}


void sabtenamvavorood::on_pushButton_5_clicked()
{
    if(checker_login==0){
        ui->password_lineEdit->setEchoMode(QLineEdit::Normal);
        ui->pushButton_5->setStyleSheet("border-image: url(:/new/prefix1/hide_eye.png);");
        checker_login=1;
        return;
        }
    ui->pushButton_5->setStyleSheet("border-image: url(:/new/prefix1/show_eye.png);");
          ui->password_lineEdit->setEchoMode(QLineEdit::Password);
    checker_login=0;
}

void sabtenamvavorood::on_pushButton_6_clicked()
{
    random = rand()%10;
    QString s = "border-image: url(:/new/prefix1/image"+QString::number(random)+".png);";
    ui->label_9->setStyleSheet(s);
    switch (random) {
    case 0:
        check_captcha = "33179";
        break;
    case 1:
        check_captcha ="qVpXayK";
        break;
    case 2:
        check_captcha ="captcha246";
        break;
    case 3:
        check_captcha ="59qbt";
        break;
    case 4:
        check_captcha ="PJDJH";
        break;
    case 5:
        check_captcha ="22776";
        break;
    case 6:
        check_captcha ="8Z8ME";
        break;
    case 7:
        check_captcha ="72351";
        break;
    case 8:
        check_captcha ="31183";
        break;
    case 9:
        check_captcha ="15414";
        break;
    }
}
