#ifndef PACIENTE_H
#define PACIENTE_H

#include <QDialog>
#include <QString>
#include <string>
#include "qstring.h"
#include <string>
#include <QMainWindow>

/**
 * @brief docu
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
 */
extern int docu;
/**
 * @brief nomb
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
 */
extern int nomb;
using namespace std;
namespace Ui {
/**
 *@brief paciente
 * Esta clase maneja la verificación de un paciente en la base de datos.
 */
class paciente;
}

class paciente : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit paciente(QWidget *parent = 0);
    /**
     * EL destructor de la clase.
     *
     */
    ~paciente();


    string getNombre() const;
    void setNombre(const string &value);

    string getDoci() const;
    void setDoci(const string &value);

private slots:
    /**
     * @brief on_pushButton_clicked
     *
     */
    void on_pushButton_clicked();

private:
    Ui::paciente *ui;

    /**
     * @brief nombre
     * Es un atributo privado de la clase que sera utilizado
     * para guardar el nombre ingresado.
     */

    string nombre;

    /**
     * @brief doci
     * Es un atributo privado de la clase que sera utilizado para
     * guardar el documento de identidad ingresado.
     */

    string doci;


};

#endif // PACIENTE_H
