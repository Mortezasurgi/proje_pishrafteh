#ifndef PISHVAS_H
#define PISHVAS_H

#include <QMainWindow>

namespace Ui {
class pishvas;
}

class pishvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit pishvas(QWidget *parent = nullptr);
    ~pishvas();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::pishvas *ui;
};

#endif // PISHVAS_H
