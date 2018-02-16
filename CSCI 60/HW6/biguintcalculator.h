#ifndef BIGUINTCALCULATOR_H
#define BIGUINTCALCULATOR_H

#include <QMainWindow>
#include "biguint.h"
namespace Ui {
class biguintCalculator;
}

class biguintCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit biguintCalculator(QWidget *parent = 0);
    ~biguintCalculator();

private slots:
    void on_addButton_clicked();

    void on_subtractButton_clicked();

    void on_memButton_clicked();

    void on_callMemButton_clicked();

    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_div9Button_clicked();

private:
    Ui::biguintCalculator *ui;
};

#endif // BIGUINTCALCULATOR_H
