#include "reciprocal.h"
#include "ui_reciprocal.h"
#include "rational.h"
Reciprocal::Reciprocal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reciprocal)
{
    ui->setupUi(this);
    Rational mem();
}

Reciprocal::~Reciprocal()
{
    delete ui;
}


void Reciprocal::on_addButton_clicked()
{
    Rational r1 (ui->numBox->value(), ui->denBox->value());
    Rational r2 (ui->numBox_2->value(), ui->denBox_2->value());
    Rational res = r1+r2;
    res.Reduce();
    ui->rdenBox->setValue(res.get_den());
    ui->rnumBox->setValue(res.get_num());
}

void Reciprocal::on_subtractButton_clicked()
{
    Rational r1 (ui->numBox->value(), ui->denBox->value());
    Rational r2 (ui->numBox_2->value(), ui->denBox_2->value());
    r2.set_num(-r2.get_num());
    Rational res = r1+r2;
    res.Reduce();
    ui->rdenBox->setValue(res.get_den());
    ui->rnumBox->setValue(res.get_num());
}

void Reciprocal::on_multiplyButton_clicked()
{
    Rational r1 (ui->numBox->value(), ui->denBox->value());
    Rational r2 (ui->numBox_2->value(), ui->denBox_2->value());
    Rational res = r1*r2;
    res.Reduce();
    ui->rdenBox->setValue(res.get_den());
    ui->rnumBox->setValue(res.get_num());
}

void Reciprocal::on_divideButton_clicked()
{
    Rational r1 (ui->numBox->value(), ui->denBox->value());
    Rational r2 (ui->numBox_2->value(), ui->denBox_2->value());
    Rational res = r1*r2.Reciprocal();
    res.Reduce();
    ui->rdenBox->setValue(res.get_den());
    ui->rnumBox->setValue(res.get_num());
}

void Reciprocal::on_memButton_clicked()
{
    mem.set_den(ui->rdenBox->value());
    mem.set_num(ui->rnumBox->value());
}

void Reciprocal::on_callMemButton_clicked()
{
    ui->numBox_2->setValue(mem.get_num());
    ui->denBox_2->setValue(mem.get_den());
}
