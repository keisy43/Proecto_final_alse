#ifndef USUARIO_H
#define USUARIO_H
#include "qstring.h"
#include <string>
#include <QMainWindow>
#include"QtSql/QSqlDatabase"
#include"QtSql/QSqlQuery"
#include"QtSql/qsqlquery.h"
#include"QtSql/QSqlError"
using namespace std;

/*!
 *\namespace QMainWindow
 * @brief The  usuario class llamada usuario.
 * @details Esta clase maneja la venta principal que es la primera que vemos
 * al abrir la aplicación.
 *\namespace QSqlDatabase
 * @brief es un tipo de variable que nos permite usar diferrentes funciones
 * de las DB.
 *\namespace QString
 * @brief es un tipo de variable que nos permite usar los valores que ingresamos
 * en las ventanas de Qt.
 * \namespace  QSqlQuery
 * @brief es un tipo de variable que nos permite usar los valores que ingresamos
 * en las ventanas de Qt.
 */

namespace Ui {
class usuario;
}

class usuario : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * EL constructor de la clase.
     *
     */
    explicit usuario(QWidget *parent=0);
    /**
     * EL destructor de la clase.
     *
     */
    ~usuario();



    string getUser() const;
    void setUser(const string &value);

    string getContra() const;
    void setContra(const string &value);

private slots:

    void on_Ru_clicked();
    void on_ingresar_clicked();

private:

    Ui::usuario *ui;
    string user;
    string contra;











/*!
 *\var _abrir
 * \var contra2
 * \var sql
 * \var user
 * \var contra
 */
    QSqlDatabase _abrir; /*!<  QSqlDatabase variable. nos permite abrir la base de datos. */
    QString contra2;    /*!<   QString variable. Guarda el valor que esta en la DB. */
    QString sql;     /*!<   QString variable. nos permite hacer la consulta. */
//    QString user;    /*!<   QString variable. Guarda el usuario ingresado. */
//    QString contra;  /*!<   QString variable. Guarda la contraseña ingresada. */
};

#endif // USUARIO_H
