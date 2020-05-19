#ifndef USUARIO_H
#define USUARIO_H
#include "qstring.h"
#include <string>
#include <QMainWindow>
/**
 *@class usuario
 * @brief esta clase maneja la verificacion de usuario que se realiza
 * en la ventana principal.
 */

/*!
 *\namespace QMainWindow
 * @brief Esta clase maneja la venta principal que es la primera que vemos
 * al abrir la aplicación.
 *\namespace QString
 * @brief es un tipo de variable que nos permite usar los valores que ingresamos
 * en las ventanas de Qt.

 * \namespace ui
 * @brief

  */

using namespace std;


namespace Ui {

class usuario;
}

class usuario : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit usuario(QWidget *parent=0);
    /**
     * EL destructor de la clase.
     *
     */
    ~usuario();



    string getUser() const;
    void setUser(const string &value);

    string getContra() const;
    void setContra(const string &value);

private slots:

    void on_Ru_clicked();
    void on_ingresar_clicked();

private:

    Ui::usuario *ui;
    string user;
    string contra;

};

#endif // USUARIO_H
