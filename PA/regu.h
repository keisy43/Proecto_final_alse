#ifndef REGU_H
#define REGU_H

#include <QDialog>
#include"db_local.h"
#include "qstring.h"
#include <string>
/*!
 * @brief The QDialog class
 * @details Esta clase denominada regu maneja la conexión con la ventana de dialogo donde
 * se registran los datos de un usuario nuevo.
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

    string user;       /*!< es una variable que guarda el nickname del usuario   */
    string contra;     /*!<  es una variable que guarda la contraseña del usuario   */
    string name;       /*!< es una variable que guarda el nombre del usuario   */
    string lastname;   /*!< es una variable que guarda el apellido del usuario   */
    string fn;         /*!< es una variable que guarda la fecha de nacimiento  del usuario   */
    string doci;       /*!< es una variable que guarda el documento de identidad del usuario   */
    int ano;           /*!< es una variable que guarda el nickname del usuario   */
    int mes;           /*!< es una variable que guarda el nickname del usuario   */
    int dia;           /*!< es una variable que guarda el nickname del usuario   */
    int anioac;        /*!< es una variable que guarda el nickname del usuario   */
    int mesac;         /*!< es una variable que guarda el nickname del usuario   */
    int diaac;         /*!< es una variable que guarda el nickname del usuario   */
    int diasnaci;      /*!< es una variable que guarda el nickname del usuario   */
    int diasact;       /*!< es una variable que guarda el nickname del usuario   */
    int edaddias;      /*!< es una variable que guarda el nickname del usuario   */
    int diaactual;     /*!< es una variable que guarda el nickname del usuario   */
    int mesactual;     /*!< es una variable que guarda el nickname del usuario   */
    int anioactual;    /*!< es una variable que guarda el nickname del usuario   */
    int aniomenos;

private slots:

    void on_buttonBox_accepted();
    void calcularedad();

private:
    Ui::regu *ui;
    db_local _db;


};

#endif // REGU_H
