#ifndef SABTENAMVAVOROOD_H
#define SABTENAMVAVOROOD_H

#include <QWidget>

namespace Ui {
class sabtenamvavorood;
}

class sabtenamvavorood : public QWidget
{
    Q_OBJECT

public:
    explicit sabtenamvavorood(QWidget *parent = nullptr);
    ~sabtenamvavorood();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();




    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::sabtenamvavorood *ui;
};

#endif // SABTENAMVAVOROOD_H
