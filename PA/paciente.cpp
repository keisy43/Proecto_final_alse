#include "paciente.h"
#include "ui_paciente.h"
#include "tiempod.h"
#include "QDebug"
#include "db_local.h"

int docu;
int nomb;
/**
 * @brief paciente::paciente
 * Es la funcion del constructor que controla lo que pasa al abrirse  la ventana.
 * @param parent
 */
paciente::paciente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paciente)
{
    ui->setupUi(this);
}
/**
 * @brief paciente::~paciente
 * Es la funcion del destructor que controla lo que pasa al cerrarse la ventana.
 */
paciente::~paciente()
{
    delete ui;
}

/**
 * @brief paciente::on_pushButton_clicked
 * En esta funcion se asignan los datos ingresados en la ventana QDialog a unas variables
 * con las que se verifica si los valores ingresados estan en la
 * en la base de datos y si es asi se abre la ventana siguiente .
 */

void paciente::on_pushButton_clicked()
{
    this->hide();
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
    this->close();

}
/**
 * @brief paciente::getDoci
 * Es la funcion get de la variable doci que recupera o consigue el valor
 * asignado en la funcion set para ser utilizado despues.
 * @return el valor ingresado en la funcion set.
 */
string paciente::getDoci() const
{
    return doci;
}
/**
 * @brief paciente::setDoci
 * Es la funcion set de la variable doci que nos permite darle
 * un valor a esta.
 * @param value es un puntero tipo string.
 */
void paciente::setDoci(const string &value)
{
    doci = value;
    docu=atoi(doci.c_str());
}
/**
 * @brief paciente::getNombre
 * Es la funcion get de la variable nombre que recupera o consigue el valor
 * asignado en la funcion set para ser utilizado despues.
 * @return el valor ingresado en la funcion set.
 */

string paciente::getNombre() const
{
    return nombre;
}
/**
 * @brief paciente::setNombre
 * Es la funcion set de la variable nombre que nos permite darle
 * un valor a esta.
 * @param value es un puntero tipo string.
 */
void paciente::setNombre(const string &value)
{
    nombre = value;
    nomb=atoi(nombre.c_str());
}
