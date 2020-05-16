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
 * @param parent Es el nombre del usuario nuevo.
 *
 * @return Un valor boleano que describe si pudieron guardar los datos en la DB o no.
 */
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


/**
 * @brief usuario::on_Ru_clicked
 *
 */
void usuario::on_Ru_clicked()
{
  // sirve para mostrar la ventana emergente
   regu a(this);
    a.setModal( true );
    a.show();
    a.exec();
     this->hide();
}

/**
 * @brief regu::on_ingresar_clicked.
 *
 * @details se asignan los datos ingresados en la ventana QDialog a unas variables
 * con las que se verifica si los valores ingresados estan en la
 * en la base de datos.
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
        menu a(this);
         a.show();
         a.exec();

        this->hide();
    }
    else{
        ui->aviso->setText("Contraseña incorrecta");
    }
    bd.cerrarDB();
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





