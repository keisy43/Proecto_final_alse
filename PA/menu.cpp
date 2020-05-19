#include "menu.h"
#include "ui_menu.h"
#include "regpc.h"
#include "prueba.h"
#include <QMenuBar>
#include "tiempod.h"
#include "paciente.h"

/**
 * @brief menu::menu
 * Es la función del constructor que controla lo que pasa al abrirse  la ventana.
 * @param parent Es un puntero tipo QWidget.
 */

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

}

/**
 * @brief menu::~menu
 * Es la función del destructor que controla lo que pasa al cerrarse la ventana.
 */

menu::~menu()
{
    delete ui;
}
/**
 * @brief menu::on_RegistrarPaciente_clicked
 * @details Esta función es una slot privada que cierra la ventana al hacer click
 * en el botón RegistrarPaciente y nos direcciona a la ventana de registrar paciente.
 */
void menu::on_RegistrarPaciente_clicked()
{
    this->hide();
    regpc a(this);
    a.setModal(true);
     a.show();
     a.exec();
     this->close();
}

/**
 * @brief menu::on_ingresarPaciente_clicked
 * @details Esta función es una slot privada que abre la ventana de verificación de paciente
 * al hacer click en el botón ingresarPaciente.
 */

void menu::on_ingresarPaciente_clicked()
{
    this->hide();
    paciente a(this);
    a.setModal(true);

     a.show();
     a.exec();
}
