#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
/**
 *@brief La clase menu
 * Esta clase maneja la conexión con la ventana de diálogo que nos permite elegir
 * entre ingresar un paciente para hacerle la prueba de agilidad o
 * registrar uno nuevo.
 */
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

private slots:
    void on_pushButton_clicked();


    void on_prueba_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
