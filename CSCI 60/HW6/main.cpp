#include "biguintcalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    biguintCalculator w;
    w.show();

    return a.exec();
}
