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

/**
 * @brief regu::on_ingresar_clicked.
 * @details se asignan los datos ingresados en la ventana QDialog a unas variables
 * con las que se verifica si los valores ingresados estan en la
 * en la base de datos.
 */

void usuario::on_ingresar_clicked()
{
    _abrir=QSqlDatabase::addDatabase("QSQLITE");
    _abrir.setDatabaseName("/home/alseuser/superproyecto_alse/PA/_Datos");
    if(_abrir.open()){
        qDebug()<<"abrio";
    }
    else{
         qDebug()<<"no abrio";
    }

  QSqlQuery buscar;
  user=ui->usuario_2->text();
  contra=ui->contrase->text();
  sql.append("SELECT  * FROM DATOSU WHERE  _USUARIO = '"+ user+"' ");
  buscar.prepare(sql);
    if(buscar.exec()){
      qDebug()<<"consulta realizada";

      while (buscar.next()){
          contra2=buscar.value(5).toByteArray().constData();
          qDebug()<<contra2;
      }
     }
      else{
          qDebug()<<"error de consulta";
      }

    if(contra2==contra){

  menu a(this);
  a.setModal(true);
  a.show();
  a.exec();

}
}





