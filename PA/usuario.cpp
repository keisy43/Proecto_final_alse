#include "usuario.h"
#include "ui_usuario.h"
#include "regu.h"
#include "db_local.h"
#include "menu.h"
#include "QDebug"
#include <string>
#include <iostream>
#include <sstream>
#include <sqlite3.h>

usuario::usuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usuario)
{
    ui->setupUi(this);


}

usuario::~usuario()
{
    delete ui;

}


void usuario::on_Ru_clicked()
{
  // sirve para mostrar la ventana emergente
   regu a(this);
    a.setModal( true );
    a.show();
    a.exec();
}
void usuario::on_ingresar_clicked()
{
     usuario  _dato;
db_local ac;
  ac.abrirDB("/home/alseuser/superproyecto_alse/PA/_Datos");

  _dato.setUser(ui->usuario_2->text().toStdString());
  _dato.setContra(ui->contrase->text().toStdString());
  if(ac.verificarusuario( _dato)==false){
  menu a(this);
  a.setModal(true);
  a.show();
  a.exec();
  ac.cerrarDB();
  }
  }






string usuario::getContra() const
{
    return contra;
}

void usuario::setContra(const string &value)
{
    contra = value;
}

string usuario::getUser() const
{
    return user;
}

void usuario::setUser(const string &value)
{
    user = value;
}


