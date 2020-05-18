#ifndef DB_LOCAL_H
#define DB_LOCAL_H


#include "usuario.h"
#include <string>
#include <sqlite3.h>
#include "prueba.h"
#include "paciente.h"

using namespace std;

/**
 * @brief The db_Local class
 * Esta clase maneja la conexión con la bases de datos en
 * SQLite3 para almacenar permanentemente los datos en un archivo.
 *
 * @details
 */

class db_local{

   private:

     sqlite3 *db;
     static int verfu(void *data, int argc, char **argv, char **azColName);
     static int verfpc(void *data, int argc, char **argv, char **azColName);

    public:

     db_local();
     bool abrirDB( string path );
     bool cargarusuario(  string namenew, string lastnamenew, string fnnew,string docinew,string usernuevo,string contranew
             );
     bool cargarpaciente(string np,string appc,string Doc,string fecha,string genero,string raza,string direccion,string nin,int edad);
     bool cargardatos(int docu, int conteo , int _estado2, int seg);
     bool verificarusuario(usuario &z);
     bool verificarpaciente(paciente &p);
     bool cerrarDB();

};

#endif // DB_LOCAL_H
