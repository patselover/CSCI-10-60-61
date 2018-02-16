#include "biguintcalculator.h"
#include "ui_biguintcalculator.h"
#include "biguint.h"
#include <QString>
#include <QlineEdit>
#include <QMessageBox>
#include <cstdlib>
biguintcalculator::biguintcalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::biguintcalculator)
{
    ui->setupUi(this);
}

biguintcalculator::~biguintcalculator()
{
    delete ui;
}

void biguintcalculator::on_addButton_clicked()
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

void biguintcalculator::on_subtractButton_clicked()
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

void biguintcalculator::on_memButton_clicked()
{
    QString qstr = ui->resultEdit->text();
    ui->memEdit->setText(qstr);
}

void biguintcalculator::on_callMemButton_clicked()
{
    ui->lhsEdit->setText(ui->memEdit->text());
}

void biguintcalculator::on_actionAbout_triggered()
{
    QMessageBox::information(
        this,
        tr("Application Name"),
        tr("Pat Selover Copyright 2016"));
}

void biguintcalculator::on_actionQuit_triggered()
{
    exit(1);
}

void biguintcalculator::on_multButton_clicked()
{
    QString qstr = ui->rhsEdit->text();
    std::string str = qstr.toStdString();
    biguint a(str);

    QString qstl = ui->lhsEdit->text();
    std::string stl = qstl.toStdString();
    biguint b(stl);

    biguint res(a*b);

    std::string rstr = res.toStdString();
    QString rqstr = QString::fromStdString(rstr);
    ui->resultEdit->setText(rqstr);
}

