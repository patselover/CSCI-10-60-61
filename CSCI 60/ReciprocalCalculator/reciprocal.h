#ifndef RECIPROCAL_H
#define RECIPROCAL_H

#include <QMainWindow>
#include "rational.h"
namespace Ui {
class Reciprocal;
}

class Reciprocal : public QMainWindow, public Rational
{
    Q_OBJECT

public:
    explicit Reciprocal(QWidget *parent = 0);
    ~Reciprocal();
private slots:

    void on_addButton_clicked();

    void on_subtractButton_clicked();

    void on_multiplyButton_clicked();

    void on_divideButton_clicked();

    void on_memButton_clicked();

    void on_callMemButton_clicked();

private:
    Ui::Reciprocal *ui;
    Rational mem;
};

#endif // RECIPROCAL_H
