#include "aciertos.h"
#include "ui_aciertos.h"
#include "prueba.h"
#include "menu.h"
#include "regpc.h"
#include <QString>
#include "paciente.h"

/**
 * @brief aciertos::aciertos
 * Es la función del constructor de la clase aciertos, en este controlamos lo que pasa al abrirse  la ventana.
 * @param parent es un puntero de tipo QWidget.
 *
 */
aciertos::aciertos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aciertos)
{
    ui->setupUi(this);



    if (_nota<3.0){
        ui->panel->setText("     ¡ Mal ! Debes esforzarte más.");

    }
    if (_nota>=3.0 && _nota<4.0 ){
        ui->panel->setText("   ¡ Muy bien ! Pero puedes mejorar.");
    }
    if (_nota>=4.0){
         ui->panel->setText("    ¡Felicitaciones! Lo hiciste muy bien.");
    }
    ui->ac->setText(QString::number(conteo));
    ui->valor->setText(QString::number(_nota));

}
/**
 * @brief aciertos::~aciertos
 * Es la función del destructor que controla lo que pasa al cerrarse la ventana.
 */
aciertos::~aciertos()
{
    delete ui;
}

/**
 * @brief aciertos::on_volvermenu_clicked
 * @details Esta función es una slot  que cierra la ventana y nos
 * devuelve a la venta de menu..
 */


void aciertos::on_volvermenu_clicked()
{
    this ->close();
    menu z(this);
    z.setModal(true);
    z.show();
    z.exec();
}

/**
 * @brief aciertos::on_salir_clicked
 * @details Esta función es una slot  que cierra la ventana
 * al hacer click en el botón de salir, cerrando así, el programa.
 */

void aciertos::on_salir_clicked()
{
     this->close();
}
