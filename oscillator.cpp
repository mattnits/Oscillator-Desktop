#include "oscillator.h"
#include "ui_oscillator.h"

Oscillator::Oscillator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Oscillator)
{
    ui->setupUi(this);
}

Oscillator::~Oscillator()
{
    delete ui;
}

void Oscillator::on_dbFileButton_clicked()
{

}
