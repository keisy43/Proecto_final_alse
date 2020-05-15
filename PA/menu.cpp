#include "menu.h"
#include "ui_menu.h"
#include "regpc.h"
#include "prueba.h"
#include <QMenuBar>
#include "tiempod.h"
#include "paciente.h"


menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{

    regpc a(this);
    a.setModal(true);

     a.show();
     a.exec();

}




void menu::on_prueba_clicked()
{
    paciente a(this);
    a.setModal(true);

     a.show();
     a.exec();
}
