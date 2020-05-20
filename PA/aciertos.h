#ifndef ACIERTOS_H
#define ACIERTOS_H
#include "prueba.h"
#include <QDialog>
#include <QString>
#include <string>
#include "qstring.h"

/**
 * @class aciertos
 * @brief Esta clase maneja la conexión con la ventana de diálogo que
 * nos muestra los aciertos que tuvo el paciente en la prueba .
 *
 * @details
 */

namespace Ui {

class aciertos;
}

class aciertos : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit aciertos(QWidget *parent = 0);

    /**
     * EL destructor de la clase.
     *
     */
    ~aciertos();

public slots:



     void on_volvermenu_clicked();
     void on_salir_clicked();





private:
    Ui::aciertos *ui;
};

#endif // ACIERTOS_H
