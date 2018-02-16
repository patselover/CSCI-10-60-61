#include "biguintcalculator.h"
#include "ui_biguintcalculator.h"
#include "biguint.h"
#include <QString>
#include <QlineEdit>
#include <QMessageBox>
#include <cstdlib>
biguintCalculator::biguintCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::biguintCalculator)
{
    ui->setupUi(this);
}

biguintCalculator::~biguintCalculator()
{
    delete ui;
}

void biguintCalculator::on_addButton_clicked()
{
    QString qstr = ui->rhsEdit->text();
    std::string str = qstr.toStdString();
    biguint a(str);

    QString qstl = ui->lhsEdit->text();
    std::string stl = qstl.toStdString();
    biguint b(stl);

    biguint res(a+b);

    std::string rstr = res.toStdString();
    QString rqstr = QString::fromStdString(rstr);
    ui->resultEdit->setText(rqstr);
}

void biguintCalculator::on_subtractButton_clicked()
{
    QString qstr = ui->rhsEdit->text();
    std::string str = qstr.toStdString();
    biguint a(str);

    QString qstl = ui->lhsEdit->text();
    std::string stl = qstl.toStdString();
    biguint b(stl);

    biguint res(a-b);

    std::string rstr = res.toStdString();
    QString rqstr = QString::fromStdString(rstr);
    ui->resultEdit->setText(rqstr);
}

void biguintCalculator::on_memButton_clicked()
{
    QString qstr = ui->resultEdit->text();
    ui->memEdit->setText(qstr);
}

void biguintCalculator::on_callMemButton_clicked()
{
    ui->lhsEdit->setText(ui->memEdit->text());
}

void biguintCalculator::on_actionAbout_triggered()
{
    QMessageBox::information(
        this,
        tr("Application Name"),
        tr("Pat Selover Copyright 2016"));
}

void biguintCalculator::on_actionQuit_triggered()
{
    exit(1);
}

void biguintCalculator::on_div9Button_clicked()
{
    QString qstr = ui->resultEdit->text();
    std::string str = qstr.toStdString();
    biguint a(str);
    if(a.divisible_by_9()){
        ui->div9Edit->setText("Yes");
    }
    else
        ui->div9Edit->setText("No");
}
