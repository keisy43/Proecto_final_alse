#ifndef ACIERTOS_H
#define ACIERTOS_H
#include "prueba.h"
#include <QDialog>


namespace Ui {
class aciertos;
}

class aciertos : public QDialog
{
    Q_OBJECT

public:
    explicit aciertos(QWidget *parent = 0);
    ~aciertos();

private slots:



private:
    Ui::aciertos *ui;
};

#endif // ACIERTOS_H
