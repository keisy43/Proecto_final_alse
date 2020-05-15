#include "paciente.h"
#include "ui_paciente.h"
#include <regpc.h>

paciente::paciente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paciente)
{
    ui->setupUi(this);
}

paciente::~paciente()
{
    delete ui;
}

void paciente::on_pushButton_clicked()
{
    _nombre=ui->nombrep->text().toStdString();
    _id=ui->idp->text().toInt();

}
