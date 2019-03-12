#include "mandalaman.h"
#include "ui_mandalaman.h"

Mandalaman::Mandalaman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mandalaman)
{
    ui->setupUi(this);
}

Mandalaman::~Mandalaman()
{
    delete ui;
}
