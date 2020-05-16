#include "paciente.h"
#include "ui_paciente.h"
#include "tiempod.h"
#include "db_local.h"
#include "QDebug"
#include"QtSql/QSqlDatabase"
#include"QtSql/QSqlQuery"
#include"QtSql/qsqlquery.h"
#include"QtSql/QSqlError"

paciente::paciente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paciente)
{
    ui->setupUi(this);
// _abrir=QSqlDatabase::addDatabase("QSQLITE");
// _abrir.setDatabaseName("/home/alseuser/superproyecto_alse/PA/_Datos");
//  if(_abrir.open()){
//  qDebug()<<"abrio";
//  }
// else{
// qDebug()<<"no abrio";
// }

}

paciente::~paciente()
{
    delete ui;
}

/**
 * @brief regu::on_pushButton_clicked.
 * @details se asignan los datos ingresados en la ventana QDialog a unas variables
 * con las que se verifica si los valores ingresados estan en la
 * en la base de datos.
 */

void paciente::on_pushButton_clicked()
{
    paciente a;
    db_local ac;
    ac.abrirDB("/home/alseuser/Proecto_final_alse/PA/_Datos");
    a.setNombre(ui->nombrep->text().toStdString());
    a.setDoci(ui->idp->text().toStdString());
    if(ac.verificarpaciente(a)==true){
            tiempod a(this);
              a.show();
              a.exec();

    }
    ac.cerrarDB();

//    QSqlQuery buscara;


//     nombre=ui->nombrep->text();
//    doci=ui->idp->text();
//     qDebug()<<doci;
//     sql.append("SELECT  * FROM _DATOSDP WHERE ( _NOMBRE = '"+nombre +"'); ");
//      qDebug()<<sql;
//     buscara.prepare(sql);
//     if(buscara.exec()){
//         qDebug()<<"consulta realizada";

//        while (buscara.next()){

//          doci2=buscara.value(2).toByteArray().constData();
//          qDebug()<<doci2;
//        }
//      }
//       else{
//          qDebug()<<"error de consulta";
//         }

//     if(doci2==doci){

//
//   }

}

string paciente::getDoci() const
{
    return doci;
}

void paciente::setDoci(const string &value)
{
    doci = value;
}

string paciente::getNombre() const
{
    return nombre;
}

void paciente::setNombre(const string &value)
{
    nombre = value;
}
