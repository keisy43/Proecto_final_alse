#include "prueba.h"
#include "ui_prueba.h"
#include "aciertos.h"
#include "tiempod.h"
#include <QTimer>

int conteo=0;
double _nota=0.;
int _duracion;

prueba::prueba(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prueba)
{
    ui->setupUi(this);
    _timer = new QTimer(this);
    // Primero configuro los leds para que arranque en el estado 1
    // Estados :
    // 1- Prende boton 1
    // 2- Prende boton 2
    // 3- Prende boton 2
    // 4. Prende boton 4
    // 5. Prende boton 5
    // 6. Prende boton 6
    // 7. Prende boton 7
    // 8. Prende boton 8
    // 9. Prende boton 9
    // 10. Prende boton 10
    // 11. Prende boton 11
    // Fires:
    // 1 -> 1 1 seg.
    // 2 -> 1 1 seg.
    // 3 -> 1 1 seg.
    // 4 -> 1 1 seg.
    // 5 -> 1 1 seg.
    // 6 -> 1.



    rd = new QPixmap(":/images/RC_led.png");
    rl = new QPixmap(":/images/RD_led.png");

    ui->boton1->setIcon(*rd );
    ui->boton2->setIcon(*rd );
    ui->boton3->setIcon( *rd );
    ui->boton4->setIcon( *rd );
    ui->boton5->setIcon( *rd );
    ui->boton6->setIcon( *rd );
    ui->boton7->setIcon( *rd );
    ui->boton8->setIcon(*rd );
    ui->boton9->setIcon(*rd );
    ui->boton10->setIcon(*rd );
    ui->boton11->setIcon(*rd );
    _estado = 1;
    ui->cont->setText(QString::number(conteo));
    ui->cont_2->setText(QString::number(tiempo));

    connect(_timer, &QTimer::timeout, this, &prueba::cambio_estado );
    _timer->setInterval( 2000 );
    _timer->start();

}



prueba::~prueba()
{
    delete ui;
}


void prueba::cambio_estado(void){
    if(tiempo<=(_duracion-1)){
        switch ( _estado ) {
        case 1:
            _estado2=1;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rl );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );


            _timer->setInterval( 1000 );
            _timer->start();
            break;
        case 2:
            _estado2 = 2;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rl );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );
            _timer->setInterval( 1000 );
            _timer->start();
            break;
        case 3:
            _estado2 = 3;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rl );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd);
            _timer->setInterval( 1000 );
            _timer->start();
            break;
        case 4:
            _estado2 = 4;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rl );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );


            _timer->setInterval( 1000 );
            _timer->start();
            break;
        case 5:
            _estado2 = 5;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd);
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rl );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd);
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );
            _timer->setInterval( 1000 );
            _timer->start();

            break;
        case 6:
            _estado2 = 6;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rl );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );
            _timer->setInterval( 1000 );
            _timer->start();


            break;
        case 7:
            _estado2 = 7;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rl );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );

            _timer->setInterval( 1000 );
            _timer->start();

            break;
        case 8:
            _estado2 = 8;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rl );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );


            _timer->setInterval( 1000 );
            _timer->start();


            break;
        case 9:
            _estado2 = 9;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rl );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rd );


            _timer->setInterval( 1000 );
            _timer->start();


            break;
        case 10:
            _estado2 = 10;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rl );
            ui->boton11->setIcon(*rd );

            _timer->setInterval( 1000 );
            _timer->start();


            break;
        case 11:
            _estado2 = 11;
            _estado= rand()%10 +1;
            tiempo+=1;
            ui->cont_2->setText(QString::number (tiempo));
            ui->boton1->setIcon(*rd );
            ui->boton2->setIcon(*rd );
            ui->boton3->setIcon( *rd );
            ui->boton4->setIcon( *rd );
            ui->boton5->setIcon( *rd );
            ui->boton6->setIcon( *rd );
            ui->boton7->setIcon( *rd );
            ui->boton8->setIcon(*rd );
            ui->boton9->setIcon(*rd );
            ui->boton10->setIcon(*rd );
            ui->boton11->setIcon(*rl );
            _timer->setInterval( 1000 );
            _timer->start();


            break;


        default:
            break;


        }
    }else{
        _estado=20;
        ui->boton1->setIcon(*rd );
        ui->boton2->setIcon(*rd );
        ui->boton3->setIcon( *rd );
        ui->boton4->setIcon( *rd );
        ui->boton5->setIcon( *rd );
        ui->boton6->setIcon( *rd );
        ui->boton7->setIcon( *rd );
        ui->boton8->setIcon(*rd );
        ui->boton9->setIcon(*rd );
        ui->boton10->setIcon(*rd );
        ui->boton11->setIcon(*rd );
        resultados();
    }

}



void prueba::on_boton1_clicked()
{
    if(_estado2 == 1){
        conteo+=1;
        ui->cont->setText(QString::number (conteo));
        cambio_estado();

    }
}

void prueba::on_boton2_clicked()
{
    if(_estado2 == 2){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();
    }
}

void prueba::on_boton3_clicked()
{
    if(_estado2 == 3){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();
    }
};

void prueba::on_boton4_clicked()
{
    if(_estado2 == 4){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();
    }
}

void prueba::on_boton5_clicked()
{
    if(_estado2 == 5){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();

    }
}

void prueba::on_boton6_clicked()
{
    if(_estado2 == 6){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();

    }
}

void prueba::on_boton7_clicked()
{
    if(_estado2 == 7){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();

    }
}

void prueba::on_boton8_clicked()
{

    if(_estado2 == 8){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();

    }
}

void prueba::on_boton9_clicked()
{
    if(_estado2 == 9){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();
    }
}

void prueba::on_boton10_clicked()
{

    if(_estado2 == 10){
        conteo+=1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();
    }
}

void prueba::on_boton11_clicked()
{

    if(_estado2 == 11){
        conteo= conteo+1;
        ui->cont->setText(QString::number(conteo));
        cambio_estado();
    }

}
void prueba::resultados(){
    double c=5.0;
    _nota=(c/ (double(_duracion)))*conteo;
    aciertos a(this);
    a.setModal(true);

     a.show();
     a.exec();

}





