#ifndef REGPC_H
#define REGPC_H

#include <QDialog>
#include <string>
#include <sqlite3.h>
#include "db_local.h"
#include <vector>
/**
 * @brief edad
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
 */
extern int edad;

namespace Ui {
/**
 * @brief The regpc class
 * Esta clase maneja la conexión con la ventana de dialogo QDialog donde
 * se registran los datos de un paciente nuevo.
 *
 * @details
 */
class regpc;
}

class regpc : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit regpc(QWidget *parent = 0);
    /**
     * EL destructor de la clase.
     *
     */
    ~regpc();
    string nombre;     /*!< Es una variable en la que guardamos el nombre del paciente que se ingresa.  */
    string apellido;   /*!< Es una variable usada para guardar el apellido del paciente.   */
   string docident;    /*!< Es una variable que guarda el documento de identidad del paciente que se ingresó.  */
    string fn;         /*!< Es una variable que guarda la fecha de nacimiento del paciente, almacenando los dias mes y año ingresados.  */
    string direccion;  /*!< Es una variable que guarda la dirección del paciente que fue ingresada. */
    string gn;         /*!< Es una variable que guarda el género del paciente. */
    string rz;         /*!< Es una variable que guarda la raza del paciente.  */
    string ningresos;  /*!< Es una variable que guarda el nivel de ingresos del paciente.   */


    int ano;           /*!< Es una variable que guarda el año de nacimiento del paciente que fue ingresado. */
    int mes;           /*!< Es una variable que guarda el mes de nacimiento del paciente.  */
    int dia;           /*!< Es una variable que guarda el dia de nacimiento  del paciente.  */
    int anioac;        /*!< Es una variable que guarda el año actual dado por el sistema .  */
    int mesac;         /*!< Es una variable que guarda el mes actual dado por el sistema.   */
    int diaac;         /*!< Es una variable que guarda el dia actual dado por el sistema.   */
    int diaactual;     /*!< Es una variable que almacena el valor real del dia actual arrojado por el sistema. */
    int mesactual;     /*!< Es una variable que almacena el valor real del mes actual arrojado por el sistema. */
    int anioactual;    /*!< Es una variable que almacena el valor real del año actual arrojado por el sistema. */
    int aniomenos;     /*!< En esta variable se almacena el valor del año de nacimiento ingresado por el paciente y le suma uno para futuros cálculos */

private slots:
    void calcularedad();
    void on_pushButton_clicked();

    void on_generof_clicked();

    void on_generom_clicked();

private:
    Ui::regpc *ui;
    /**
   * @brief _bd
   * Se trata de una varible de la clase db_local que usamos para realizar varias operaciones relacionadas con la base de datos.
   */
  db_local _bd;

};

#endif // REGPC_H
