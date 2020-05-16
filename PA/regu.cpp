#include "regu.h"
#include "ui_regu.h"
#include "db_local.h"
#include "QDebug"
#include <iostream>
#include <sstream>
#include <string>
#include <sqlite3.h>

int edadus;
using namespace std;

regu::regu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regu)
{
    ui->setupUi(this);
    _db.abrirDB("/home/alseuser/Proecto_final_alse/PA/_Datos");

}

regu::~regu()
{
    delete ui;
      _db.cerrarDB();
}

/**
 * @brief regu::on_buttonBox_accepted
 * @details se asignan los datos ingresados en la ventana QDialog a unas variables
 * que se le pasan por referencia a la funcion cargarusuario para que guarde los valores
 * en la base de datos.
 */
void regu::on_buttonBox_accepted()
{

   name=ui->nombre->text().toStdString();
   lastname=ui->apellido->text().toStdString();
   doci=ui->docident->text().toStdString();
   dia=ui->dian->text().toInt();
   mes=ui->mesn->text().toInt();
   ano=ui->anion->text().toInt();
   user=ui->_nickname->text().toStdString();
   contra=ui->contra->text().toStdString();

   fn=to_string (dia)+"-"+ to_string (mes)+"-"+to_string (ano);
   calcularedad();
   _db.cargarusuario(name, lastname ,doci,fn,user,contra);

}

void regu::calcularedad(){
    cout<<fn<<endl;
    diasnaci=(ano*365)+(mes*30)+dia;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    mesac  =timePtr->tm_mon;
    anioac =timePtr->tm_year;
    diaac  =timePtr->tm_yday;


    diaactual=diaac-120;
    mesactual=mesac+1;
    anioactual=anioac+1900;
    aniomenos=ano+1;


    if (mes<(mesactual)){
        edadus=(anioactual)-ano;
    }else{
        if(mes==(mesactual)){
            if(dia<(diaactual)){
                edadus=(anioactual)-ano;
            }
            if(dia>(diaactual)){
                edadus=(anioactual)-aniomenos;
            }
        }
        if (mes>mesactual){
            edadus=(anioactual)-aniomenos;
        }
    }

    cout<<edadus<<endl;

}




