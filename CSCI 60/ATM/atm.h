#ifndef ATM_H
#define ATM_H

#include <QMainWindow>
#include "bankaccount.h"
namespace Ui {
class ATM;
}

class ATM : public QMainWindow
{
    Q_OBJECT

public:
    explicit ATM(QWidget *parent = 0);
    ~ATM();

private slots:
    void on_initialButton_clicked();

    void on_withdrawButton_clicked();

    void on_depositButton_clicked();

private:
    Ui::ATM *ui;
};

#endif // ATM_H
