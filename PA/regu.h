#ifndef REGU_H
#define REGU_H

#include <QDialog>
#include"db_local.h"
#include "qstring.h"
#include <string>
/*!
 *@class  regu
 * @brief Esta clase denominada regu maneja la conexión con la ventana de dialogo donde
 * se registran los datos de un usuario nuevo.
 */

/**
 * @brief edadus
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera facil y comoda retornando su valor asignado.

 */
extern int edadus;
namespace Ui {

class regu;
}

class regu : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit regu(QWidget *parent = 0);
    /**
     * EL destructor de la clase.
     *
     */
    ~regu();

    string user;       /*!< Es una variable que guarda el nickname del usuario.   */
    string contra;     /*!<  Es una variable que guarda la contraseña del usuario.   */
    string name;       /*!< Es una variable que guarda el nombre del usuario.   */
    string lastname;   /*!< Es una variable que guarda el apellido del usuario.   */
    string fn;         /*!< Es una variable que guarda la fecha de nacimiento  del usuario, almacenando los dias, el mes y el año, ingresados.  */
    string doci;       /*!< Es una variable que guarda el documento de identidad del usuario.   */
    
    int ano;           /*!< Es una variable que guarda el año de nacimiento del paciente que fue ingresado. */
    int mes;           /*!< Es una variable que guarda el mes de nacimiento del paciente.  */
    int dia;           /*!< Es una variable que guarda el dia de nacimiento  del paciente.  */
    int anioac;        /*!< Es una variable que guarda el año actual dado por el sistema .  */
    int mesac;         /*!< Es una variable que guarda el mes actual dado por el sistema.   */
    int diaac;         /*!< Es una variable que guarda el dia actual dado por el sistema.   */
    int diaactual;     /*!< Es una variable que almacena el valor real del dia actual arrojado por el sistema. */
    int mesactual;     /*!< Es una variable que almacena el valor real del mes actual arrojado por el sistema. */
    int anioactual;    /*!< Es una variable que almacena el valor real del año actual arrojado por el sistema. */
    int aniomenos;     /*!< En esta variable se almacena el valor del año de nacimiento ingresado por el paciente y le suma uno para futuros calculos */

private slots:

    void on_buttonBox_accepted();
    void calcularedad();

private:
    Ui::regu *ui;
    /**
   *@variable _db
   *@brief Se trata de una varible de la clase db_local que usamos para realizar varias operaciones relacionadas con la base de datos.
   */
    db_local _db;


};

#endif // REGU_H
