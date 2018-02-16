#ifndef BIGUINTCALCULATOR_H
#define BIGUINTCALCULATOR_H

#include <QMainWindow>

namespace Ui {
class biguintcalculator;
}

class biguintcalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit biguintcalculator(QWidget *parent = 0);
    ~biguintcalculator();

private slots:
    void on_addButton_clicked();

    void on_subtractButton_clicked();

    void on_memButton_clicked();

    void on_callMemButton_clicked();

    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_multButton_clicked();

private:
    Ui::biguintcalculator *ui;
};

#endif // BIGUINTCALCULATOR_H
