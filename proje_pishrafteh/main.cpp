#include "pishvas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pishvas w;
    w.show();

    return a.exec();
}
