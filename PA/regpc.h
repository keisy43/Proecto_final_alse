#ifndef REGPC_H
#define REGPC_H

#include <QDialog>
#include <string>
#include <sqlite3.h>
#include "db_local.h"
#include <vector>
/**
 * @brief The regpc class
 * Esta clase maneja la conexión con la ventana de dialogo QDialog donde
 * se registran los datos de un paciente nuevo.
 *
 * @details
 */
extern int edad;

namespace Ui {
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
    string nombre;     /*!< es una variable que guarda el nombre del paciente  */
    string apellido;   /*!< es una variable que guarda el apellido del paciente   */
   string docident;   /*!< es una variable que guarda el documento de identidad del paciente  */
    string fn;          /*!< es una variable que guarda la fecha de nacimiento  del paciente  */
    string direccion;  /*!< es una variable que guarda la direccion del paciente  */
    string gn;         /*!< es una variable que guarda el genero del paciente  */
    string rz;         /*!< es una variable que guarda la raza del paciente  */
    string ningresos;  /*!< es una variable que guarda el nivel de ingresos del paciente   */


    int ano;
    int mes;
    int dia;
    int anioac;
    int mesac;
    int diaac;
    int diasnaci;
    int diasact;
    int edaddias;
    int diaactual;
    int mesactual;
    int anioactual;
    int aniomenos;

private slots:
    void calcularedad();
    void on_pushButton_clicked();

    void on_generof_clicked();

    void on_generom_clicked();

private:
    Ui::regpc *ui;
  db_local _bd;
};

#endif // REGPC_H
