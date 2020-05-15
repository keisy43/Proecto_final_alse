#ifndef REGU_H
#define REGU_H

#include <QDialog>
#include"db_local.h"
#include "qstring.h"
#include <string>
/**
 * @brief The regu class
 * Esta clase maneja la conexión con la ventana de dialogo donde
 * se registran los datos de un usuario nuevo.
 *
 * @details
 */
extern int edadus;
namespace Ui {
class regu;
}

class regu : public QDialog
{
    Q_OBJECT

public:

    explicit regu(QWidget *parent = 0);
    ~regu();
    string user;       /*!< es una variable que guarda el nickname del usuario   */
    string contra;     /*!<  es una variable que guarda la contraseña del usuario   */
    string name;       /*!< es una variable que guarda el nombre del usuario   */
    string lastname;   /*!< es una variable que guarda el apellido del usuario   */
    string fn;         /*!< es una variable que guarda la fecha de nacimiento  del usuario   */
    string doci;       /*!< es una variable que guarda el documento de identidad del usuario   */
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

    void on_buttonBox_accepted();
    void calcularedad();

private:
    Ui::regu *ui;
    db_local _db;


};

#endif // REGU_H
