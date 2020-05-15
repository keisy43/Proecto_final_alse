#ifndef PACIENTE_H
#define PACIENTE_H

#include <QDialog>
#include <QString>
#include <string>
#include "qstring.h"
#include "db_local.h"
#include <string>
#include <QMainWindow>
#include"QtSql/QSqlDatabase"
#include"QtSql/QSqlQuery"
#include"QtSql/qsqlquery.h"
#include"QtSql/QSqlError"


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

    QSqlDatabase _abrir;
    QString doci2;
    QString sql;
    QString nombre;
    QString doci;


};

#endif // PACIENTE_H
