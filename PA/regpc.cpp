#include "regpc.h"
#include "menu.h"
#include "ui_regpc.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <sqlite3.h>
#include <ctime>

int edad;

regpc::regpc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regpc)
{
    ui->setupUi(this);
    _bd.abrirDB("/home/alseuser/Proecto_final_alse/PA/_Datos");

}

regpc::~regpc()
{
    delete ui;
     _bd.cerrarDB();
}
/**
 * @brief regu::on_pushButton_clicked
 * @details se asignan los datos ingresados en la ventana QDialog a unas variables
 * que se le pasan por referencia a la funcion cargarpaciente para que guarde los valores
 * en la base de datos.
 */
void regpc::on_pushButton_clicked()
{

    nombre=ui->nombrep->text().toStdString();
    apellido=ui->apellidop_2->text().toStdString();
    docident = ui->docidtp->text().toStdString();
    dia= ui->dianac->text().toInt();
    mes= ui->mesnac->text().toInt();
    ano= ui->anionac->text().toInt();
    direccion= ui->direccion->text().toStdString();
    rz=ui->raza_2->text().toStdString();
    ningresos=ui->niveling->text().toStdString();

    fn=to_string (dia)+"-"+ to_string (mes)+"-"+to_string (ano);
    calcularedad();
   _bd.cargarpaciente(nombre,apellido,docident,fn ,gn, direccion,rz,ningresos);

   this->hide();



}
void regpc::calcularedad(){
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
        edad=(anioactual)-ano;
    }else{
        if(mes==(mesactual)){
            if(dia<(diaactual)){
                edad=(anioactual)-ano;
            }
            if(dia>(diaactual)){
                edad=(anioactual)-aniomenos;
            }
        }
        if (mes>mesactual){
            edad=(anioactual)-aniomenos;
        }
    }

    cout<<edad<<endl;





}
void regpc::on_generof_clicked()
{
    gn= ui->generof->text().toStdString();
}


void regpc::on_generom_clicked()
{
    gn= ui->generom->text().toStdString();
}

