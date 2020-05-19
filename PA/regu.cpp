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
/**
 * @brief regu::regu
 * Es la función del constructor que controla lo que pasa al abrirse  la ventana.
 * @param parent Es un puntero tipo QWidget.
 */
regu::regu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regu)
{
    ui->setupUi(this);


}
/**
 * @brief regu::~regu
 * Es la función del destructor que controla lo que pasa al cerrarse la ventana.
 */
regu::~regu()
{
    delete ui;

}

/**
 * @brief regu::on_buttonBox_accepted
 * @details Se asignan los datos ingresados en la ventana QDialog, referentes al usuario, a unas variables
 * que se le pasan por referencia a la función cargarusuario para que guarde los valores
 * en la base de datos, al hacer click en el boton okay.
 */
void regu::on_buttonBox_accepted()
{
_db.abrirDB("/home/alseuser/Proecto_final_alse/PA/_Datos");
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
   _db.cargarusuario(name, lastname ,fn, doci,user,contra);
 _db.cerrarDB();
}

/**
 * @brief regu::calcularedad
 * @details Esta función es usada para calcular la edad del usuario, para ello se usa la fecha
 * de nacimiento y la fecha actual, estas dos en dias, meses y años.
 * @return la edad del usuario.
 */

void regu::calcularedad(){
    cout<<fn<<endl;
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
