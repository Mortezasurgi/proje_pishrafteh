#ifndef FAZE2_H
#define FAZE2_H

#include <QWidget>

namespace Ui {
class faze2;
}

class faze2 : public QWidget
{
    Q_OBJECT

public:
    explicit faze2(QWidget *parent = nullptr);
    ~faze2();

private:
    Ui::faze2 *ui;
};

#endif // FAZE2_H
