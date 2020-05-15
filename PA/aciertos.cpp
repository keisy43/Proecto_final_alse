#include "aciertos.h"
#include "ui_aciertos.h"
#include "prueba.h"


aciertos::aciertos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aciertos)
{
    ui->setupUi(this);
    ui->ac->setText(QString::number(conteo));
    ui->valor->setText(QString::number(_nota));
}

aciertos::~aciertos()
{
    delete ui;
}






