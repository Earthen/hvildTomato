#include "hvildtomato.h"
#include "ui_hvildtomato.h"

HvildTomato::HvildTomato(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HvildTomato)
{
    ui->setupUi(this);
}

HvildTomato::~HvildTomato()
{
    delete ui;
}
