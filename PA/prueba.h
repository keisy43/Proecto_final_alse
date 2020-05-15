#ifndef PRUEBA_H
#define PRUEBA_H

#include <QDialog>
#include <QTimer>
#include "tiempod.h"

extern int conteo;
extern double _nota;
namespace Ui {
class prueba;
}

class prueba : public QDialog
{
    Q_OBJECT

public:
    explicit prueba(QWidget *parent = 0);
    ~prueba();

private slots:
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
    void resultados();




private:
    Ui::prueba *ui;
    QTimer  *_timer;
    char _estado;
    char _estado2;

    int tiempo=0;

      QPixmap *rd, *rl;
};

#endif // PRUEBA_H
