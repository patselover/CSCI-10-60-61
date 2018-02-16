#include "reciprocal.h"
#include <QApplication>
#include "rational.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Reciprocal w;
    w.show();

    return a.exec();
}
