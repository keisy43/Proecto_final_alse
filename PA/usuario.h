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
namespace Ui {
class usuario;
}

class usuario : public QMainWindow
{
    Q_OBJECT

public:

    explicit usuario(QWidget *parent = 0);
    ~usuario();



private slots:
    void on_Ru_clicked();
    void on_ingresar_clicked();


private:
    Ui::usuario *ui;
    QSqlDatabase _abrir;
    QString contra2;
    QString sql;
    QString user;
    QString contra;
};

#endif // USUARIO_H
