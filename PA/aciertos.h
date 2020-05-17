#ifndef ACIERTOS_H
#define ACIERTOS_H
#include "prueba.h"
#include <QDialog>


namespace Ui {
/**
 * @class aciertos
 * @brief Esta clase maneja la conexion con la ventana de dialogo que
 * nos muestra los aciertos que tuvo el paciente en la prueba .
 *
 * @details
 */
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

private slots:

    void on_volvermenu_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::aciertos *ui;
};

#endif // ACIERTOS_H
