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
 *Es la funcion del constructor que controla lo que pasa al abrirse  la ventana.
 * @param parent es un puntero tipo QWidget.
 */
usuario::usuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usuario)
{
    ui->setupUi(this);
}
/**
 * @brief usuario::~usuario
 * Es la funcion del destructor que controla lo que pasa al cerrarse la ventana.
 */
usuario::~usuario()
{
    delete ui;

}


/**
 * @brief usuario::on_Ru_clicked
 * Esta funcion maneja la conexion con el boton Ru que al hacerle click
 * abrira la ventana con el formulario para registrar a un usuario nuevo.
 */

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
 *
 * En esta funcion se asignan los datos ingresados en la ventana QDialog a unas variables
 * con las que se verifica si los valores ingresados estan en la
 * en la base de datos y si es asi se abre la ventana siguiente .
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
        ui->aviso->setText("Contraseña incorrecta");
    }
    bd.cerrarDB();
}
/*!
 * @brief usuario::getContra()
 * Es la funcion get de la variable doci que recupera o consigue el valor
 * asignado en la funcion set para ser utilizado despues.
 * @return el valor ingresado en la funcion set.
 */
string usuario::getContra() const
{
    return contra;
}
/**
 * @brief usuario::setContra
 * Es la funcion set de la variable doci que nos permite darle
 * un valor a esta.
 * @param value es un puntero tipo string.
 */

void usuario::setContra(const string &value)
{
    contra = value;
}
/**
 * @brief usuario::getUser
 * Es la funcion get de la variable doci que recupera o consigue el valor
 * asignado en la funcion set para ser utilizado despues.
 * @return el valor ingresado en la funcion set.
 */
string usuario::getUser() const
{
    return user;
}
/**
 * @brief usuario::setUser
 * Es la funcion set de la variable doci que nos permite darle
 * un valor a esta.
 * @param value es un puntero tipo string.
 */
void usuario::setUser(const string &value)
{
    user = value;
}





