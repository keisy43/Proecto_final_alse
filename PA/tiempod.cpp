#include "tiempod.h"
#include "ui_tiempod.h"
#include "prueba.h"
#include <QWidget>
#include <QString>

tiempod::tiempod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tiempod)
{
    ui->setupUi(this);
}

tiempod::~tiempod()
{
    delete ui;
}

void tiempod::on_buttonBox_accepted()
{
    if(ui->tiempop->text() != ""){
       _duracion= ui->tiempop->text().toInt() ;

       prueba a(this);
        a.setModal(true);

        a.show();
        a.exec();


    }else{
        ui->adver->setText("Ingrese un valor.");
    }

}

