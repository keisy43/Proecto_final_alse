#ifndef TIEMPOD_H
#define TIEMPOD_H

#include <QDialog>
/**
 *  @class tiempod
 * @brief Esta clase maneja la conexion con al ventana donde le preguntaremos al usuario la duracion de la
 * prueba de agilidad para el paciente.
*/

/**
 * @brief _duracion
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera facil y comoda retornando su valor asignado.

 */
extern int _duracion;
namespace Ui {

class tiempod;
}

class tiempod : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit tiempod(QWidget *parent = 0);
    /**
     * EL destructor de la clase.
     *
     */
    ~tiempod();



private slots:
    void on_buttonBox_accepted();


    void on_buttonBox_rejected();

private:
    Ui::tiempod *ui;


};

#endif // TIEMPOD_H
