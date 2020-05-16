#ifndef PACIENTE_H
#define PACIENTE_H

#include <QDialog>
#include <QString>
#include <string>
#include "qstring.h"

#include <string>
#include <QMainWindow>
#include"QtSql/QSqlDatabase"
#include"QtSql/QSqlQuery"
#include"QtSql/qsqlquery.h"
#include"QtSql/QSqlError"
/**
 * @brief The QDialog class
 * Esta clase maneja la conexión con la bases de datos en
 * SQLite3 para almacenar permanentemente los datos en un archivo.
 *
 * @details
 */

using namespace std;
namespace Ui {
class paciente;
}

class paciente : public QDialog
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit paciente(QWidget *parent = 0);
    /**
     * EL destructor de la clase.
     *
     */
    ~paciente();


    string getNombre() const;
    void setNombre(const string &value);

    string getDoci() const;
    void setDoci(const string &value);

private slots:
    void on_pushButton_clicked();

private:
    Ui::paciente *ui;

//    QSqlDatabase _abrir;
//    QString doci2;
//    QString sql;
    string nombre;
    string doci;


};

#endif // PACIENTE_H
