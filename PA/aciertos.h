#ifndef ACIERTOS_H
#define ACIERTOS_H
#include "prueba.h"
#include <QDialog>

/**
 * @brief The QDialog class
 * Esta clase maneja la conexión con la bases de datos en
 * SQLite3 para almacenar permanentemente los datos en un archivo.
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

private slots:



private:
    Ui::aciertos *ui;
};

#endif // ACIERTOS_H
