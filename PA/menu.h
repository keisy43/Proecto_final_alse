#ifndef MENU_H
#define MENU_H

#include <QDialog>

/**
 *@class  menu
 *@brief Esta clase maneja la conexión con la ventana de diálogo que nos permite elegir
 * entre ingresar un paciente para hacerle la prueba de agilidad o
 * registrar uno nuevo.
 */

namespace Ui {

class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit menu(QWidget *parent = 0);
    /**
     * EL destructor de la clase.
     *
     */
    ~menu();

public slots:


    void on_RegistrarPaciente_clicked();

    void on_ingresarPaciente_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
