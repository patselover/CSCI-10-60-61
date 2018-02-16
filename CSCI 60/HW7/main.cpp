#include "biguintcalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    biguintcalculator w;
    w.show();

    return a.exec();
}
