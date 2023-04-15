#ifndef SAFHE_TAEID_H
#define SAFHE_TAEID_H

#include <QWidget>

namespace Ui {
class safhe_taeid;
}

class safhe_taeid : public QWidget
{
    Q_OBJECT

public:
    explicit safhe_taeid(QWidget *parent = nullptr);
    ~safhe_taeid();

private slots:
    void on_pushButton_clicked();

private:
    Ui::safhe_taeid *ui;
};

#endif // SAFHE_TAEID_H
