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

/**
 * @brief usuario::usuario
 *Es la función del constructor que controla lo que pasa al abrirse  la ventana.
 * @param parent Es un puntero tipo QWidget.
 */
usuario::usuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usuario)
{
    ui->setupUi(this);
}
/**
 * @brief usuario::~usuario
 * Es la función del destructor que controla lo que pasa al cerrarse la ventana.
 */
usuario::~usuario()
{
    delete ui;

}


/**
 * @brief usuario::on_Ru_clicked
 * @details Esta función maneja la conexión con el botón "Ru" que al hacerle click
 * abrirá la ventana con el formulario para registrar a un usuario nuevo.
 */

void usuario::on_Ru_clicked()
{

    regu a(this);
    a.setModal( true );
    a.show();
    a.exec();

}
/**
 * @brief regu::on_ingresar_clicked.
 * @details En esta función se asignan los datos ingresados en la ventana QDialog a unas variables
 * con las que se verifica si los valores ingresados están en la
 * en la base de datos y si es así, se abre la ventana siguiente .
 */

void usuario::on_ingresar_clicked()
{

    usuario a;
    db_local bd;
    bd.abrirDB("/home/alseuser/Proecto_final_alse/PA/_Datos");
    a.setUser(ui->usuario_2->text().toStdString());
    a.setContra(ui->contrase->text().toStdString());
    if(bd.verificarusuario(a)==true){
         ui->aviso->setText("Bienvenido");
         this->close();
        menu a(this);
         a.show();
         a.exec();
         a.close();

        this->close();
    }
    else{
        ui->aviso->setText("Contraseña  o usuario incorrectos");
    }
    bd.cerrarDB();
}
/*!
 * @brief usuario::getContra()
 * @details Es la función get de la variable "contra" que recupera o consigue el valor
 * asignado en la función set para ser utilizado después.
 * @return El valor ingresado en la función set.
 */
string usuario::getContra() const
{
    return contra;
}
/**
 * @brief usuario::setContra
 * @details Es la función set de la variable "contra" que nos permite darle
 * un valor a esta.
 * @param value Es un puntero tipo string.
 */

void usuario::setContra(const string &value)
{
    contra = value;
}
/**
 * @brief usuario::getUser
 * @details Es la función get de la variable "user" que recupera o consigue el valor
 * asignado en la función set para ser utilizado después.
 * @return El valor ingresado en la función set.
 */
string usuario::getUser() const
{
    return user;
}
/**
 * @brief usuario::setUser
 * @details Es la función set de la variable "user" que nos permite darle
 * un valor a esta.
 * @param value Es un puntero tipo string.
 */
void usuario::setUser(const string &value)
{
    user = value;
}





