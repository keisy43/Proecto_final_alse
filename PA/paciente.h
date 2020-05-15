#ifndef PACIENTE_H
#define PACIENTE_H

#include <QDialog>
#include <QString>
#include <string>
#include "qstring.h"
#include <string>
#include <QMainWindow>
using namespace std;
namespace Ui {
class paciente;
}

class paciente : public QDialog
{
    Q_OBJECT

public:
    explicit paciente(QWidget *parent = 0);
    ~paciente();


private slots:
    void on_pushButton_clicked();

private:
    Ui::paciente *ui;
    string _nombre;
    int _id;


};

#endif // PACIENTE_H
