#ifndef PRUEBA_H
#define PRUEBA_H

#include <QDialog>
#include <QTimer>
#include "tiempod.h"
#include <string>
#include <sqlite3.h>
#include <vector>
#include "qstring.h"
#include "db_local.h"
/**
 *@class prueba
 *@brief Esta clase maneja la ventana de la prueba de agilidad para el paciente.
 */


/**
 * @brief conteo
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
 */
extern int conteo;
/**
 * @brief _nota
 * Es una variable externa tipo double que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
 */
extern double _nota;
/**
 * @brief _estado
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
 * @brief _estado2
 *Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
 */
extern int _estado, _estado2;
/**
 * @brief tiempo
 * Es una variable externa tipo entero que se declara de esta
 * manera para ser usada en varios archivos del proyecto de una manera fácil y cómoda retornando su valor asignado.
  */
extern int tiempo;
namespace Ui {

class prueba;
}

class prueba : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit prueba(QWidget *parent = 0);
    /**
     * EL destructor de la clase.
     *
     */
    ~prueba();
  void insertar();
  void resultados();
public slots:
    void cambio_estado(void );

    void on_boton1_clicked();
    void on_boton2_clicked();
    void on_boton3_clicked();
    void on_boton4_clicked();
    void on_boton5_clicked();
    void on_boton6_clicked();
    void on_boton7_clicked();
    void on_boton8_clicked();
    void on_boton9_clicked();
    void on_boton10_clicked();
    void on_boton11_clicked();





private:
    Ui::prueba *ui;
    /**
     *@brief _timer
     * Es un puntero tipo Qtimer.
     */
    QTimer  *_timer;
    /**
     * @brief rd
     * Es un punteroo tipo QPixmap.
     * @brief rl
     * Es un punteroo tipo QPixmap.
     */
    QPixmap *rd, *rl;

};

#endif // PRUEBA_H
