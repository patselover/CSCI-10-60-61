#include "atm.h"
#include "ui_atm.h"
#include "bankaccount.h"
ATM::ATM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ATM)
{
    ui->setupUi(this);
    ba = BankAccount();
    ui->initialSpinBox->setRange(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());

}

ATM::~ATM()
{
    delete ui;
}

void ATM::on_initialButton_clicked()
{
    double amount =ui->initialSpinBox->value();
    ba = BankAccount(amount);
    ui->balanceSpinBox->setValue(ba.get_balance());

}

void ATM::on_withdrawButton_clicked()
{
    double amount = ui->transactionSpinBox->value();
    ba.withdraw(amount);
    ui->balanceSpinBox->setValue(ba.get_balance());
}

void ATM::on_depositButton_clicked()
{
    double amount = ui->transactionSpinBox->value();
    ba.deposit(amount);
    ui->balanceSpinBox->setValue(ba.get_balance());
}
