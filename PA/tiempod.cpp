#include "tiempod.h"
#include "ui_tiempod.h"
#include "prueba.h"
#include <QWidget>
#include <QString>
#include "menu.h"

/**
 * @brief tiempod::tiempod
 * Es la funcion del constructor que controla lo que pasa al abrirse  la ventana.
 * @param parent es un puntero tipo QWidget.
 */
tiempod::tiempod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tiempod)
{
    ui->setupUi(this);
}
/**
 * @brief tiempod::~tiempod
 * Es la funcion del destructor que controla lo que pasa al cerrarse la ventana.
 */
tiempod::~tiempod()
{
    delete ui;
}
/**
 * @brief tiempod::on_buttonBox_accepted
 * En esta función se define el tiempo de duracion de la prueba mediante el valor ingresado por el usuario.
 * Se retorna la variable entera duración.
 */

void tiempod::on_buttonBox_accepted()
{
    if(ui->tiempop->text() != ""){
       _duracion= ui->tiempop->text().toInt() ;
       this->close();
       prueba a(this);
        a.setModal(true);

        a.show();
        a.exec();
        this->close();


    }else{
        ui->adver->setText("Ingrese un valor.");
    }
}
/**
 * @brief tiempod::on_buttonBox_rejected
 * En esta función definimos lo ocurrido al dar click en el botón de "cancel", en esta
 * ocasión la ventana se cerrará y regresará a la ventana anterior.
 */
void tiempod::on_buttonBox_rejected()
{
    this->close();
    menu z(this);
    z.setModal(true);
    z.show();
    z.exec();
}
