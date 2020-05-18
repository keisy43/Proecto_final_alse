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
/**
 * @brief regpc::regpc
 * Es la función del constructor que controla lo que pasa al abrirse  la ventana.
 * @param parent Es un puntero tipo QWidget.
 */
 
regpc::regpc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regpc)
{
    ui->setupUi(this);
    _bd.abrirDB("/home/alseuser/Proecto_final_alse/PA/_Datos");

}
/**
 * @brief regpc::~regpc
 *  Es la función del destructor que controla lo que pasa al cerrarse la ventana.
 */
regpc::~regpc()
{
    delete ui;
     _bd.cerrarDB();
}
/**
 * @brief regpc::on_pushButton_clicked()
 * @details Se asignan los datos ingresados en la ventana QDialog, referentes a los datos del paciente,a unas variables
 * que se le pasan por referencia a la función cargarpaciente para que guarde los valores
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
   _bd.cargarpaciente(nombre,apellido,docident,fn ,gn, direccion,rz,ningresos,edad);
   this->hide();
   menu z(this);
   z.setModal(true);
   z.show();
   z.exec();



}
/**
 * @brief regpc::calcularedad
 * Esta función es usada para calcular la edad del paciente, para ello se usa la fecha
 * de nacimiento y la fecha actual, estas dos en dias, meses y años.
 * Y retorna la edad del paciente.
 */
void regpc::calcularedad(){
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

/**
 * @brief regpc::on_generof_clicked
 * En esta función lo que hacemos es guardar en la variable gn, referente al género de la persona,
 * mediante un radiobutton, en este caso se guarda el string "Femenino".
 */
void regpc::on_generof_clicked()
{
    gn= ui->generof->text().toStdString();
}

/**
 * @brief regpc::on_generom_clicked
 * En esta función lo que hacemos es guardar en la variable gn, referente al género de la persona,
 * mediante un radiobutton, en este caso se guarda el string "Masculino".
 */
void regpc::on_generom_clicked()
{
    gn= ui->generom->text().toStdString();
}

