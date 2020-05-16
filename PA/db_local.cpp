#include "db_local.h"
#include "usuario.h"
#include <iostream>
#include <sstream>
#include <QString>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "QDebug"

using namespace std;
db_local::db_local()
{
}
    /**
     * @brief db_local::abrirDB
     * @param path  Es la ubicación absoluta o relativa de la DB.    
     * @return Un valor boleano que describe si pudo abrir la DB o no.
     */

    bool db_local::abrirDB( string path ){
        char *zErrMsg = 0;
        int rc;

        /* Open database */
        rc = sqlite3_open( path.c_str() , &db);

        if( rc ) {
           fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
           return false;
        }
        else{
            fprintf(stderr, "Opened database successfully\n");
        }
        return true;
    }

    /**
     * @brief db_local::cargarusuario
     * @param namenew Es el nombre del usuario nuevo.
     * @param lastnamenew Es el apellido del usuario nuevo.
     * @param fnnew Es la fecha de nacimiento del usuario nuevo.
     * @param docinew Es el documento de identidad  del usuario nuevo.
     * @param usernew Es el nickname del usuario nuevo
     * @param contranew Es la contraseña del usuario nuevo
     * @return Un valor boleano que describe si pudieron guardar los datos en la DB o no.
     */

    bool db_local::cargarusuario(string namenew, string lastnamenew,string fnnew,string docinew,string usernuevo,string contranew)
    {
        char *zErrMsg = 0;
        int rc;
        std::stringstream sql;


     sql <<"INSERT INTO DATOSU ( NOMBRE ,_APELLIDO , _FECHAN,_DOCIDENT,_USUARIO, _CONTRA ) VALUES (' ";
     sql << namenew<<"','" << lastnamenew<<"','"<<fnnew<<"','";
     sql <<docinew<<"','"<<usernuevo<<"','"<<contranew<<"');";
        std::cout << sql.str() << std::endl;

        rc = sqlite3_exec(db, sql.str().c_str(),0,0, &zErrMsg);

        if( rc != 0 ){
           fprintf(stderr, "SQL error: %s\n", zErrMsg);
           sqlite3_free(zErrMsg);
            return false;
        }
        else{
            fprintf(stderr, "Opened database successfully\n");
        }
        return true;
      }




   bool db_local::verificarusuario(usuario &z){
       char *zErrMsg = 0;
       int rc;
       bool cont =false;
        std::stringstream sql;
       sql << "SELECT * FROM DATOSU WHERE ( _USUARIO = '" << z.getUser() <<"' "
            "AND  _CONTRA = '" << z.getContra() << "' );";

   std::cout << sql.str() << std::endl;
       rc = sqlite3_exec(db, sql.str().c_str() , verfu,(void*)&cont, &zErrMsg);

       if( &zErrMsg==0){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
           return false;
       }
       else{
           fprintf(stderr, "Opened database successfully\n");
       }
     return cont;
    }
   int db_local::verfu(void *data, int argc, char **argv, char **azColName){

 bool * a = (bool*) data ;
   *a=true;
 return 0;
 }
  /**
   * @brief db_local::cargarpaciente
   * @param np Es el nombre del paciente nuevo.
   * @param appc Es el apellido del paciente nuevo.
   * @param fecha Es la fecha de nacimiento del pciente nuevo.
   * @param Doc Es el documento de identidad  del paciente nuevo.
   * @param genero Es el genero del paciente nuevo.
   * @param raza Es la raza del paciente nuevo.
   * @param direccion Es la direccion del paciente nuevo.
   * @param nin Es el nuemero de ingresos  del paciente nuevo.
   * @return Un valor boleano que describe si pudieron guardar los datos en la DB o no.
   */
   bool db_local::cargarpaciente(string np,string appc,string Doc,string fecha,string genero,string raza,string direccion,string nin){
       char *zErrMsg = 0;
       int rc;
       std::stringstream sql;

    sql <<"INSERT INTO _DATOSDP ( _NOMBRE ,_APELLIDO , _DOCIDENT,_FECHAN,_GENERO, _RAZA,_DIRECCION,_NINGRESOS ) VALUES (' ";
    sql << np<<"','" << appc<<"','"<< Doc<<"','";
    sql <<fecha<<"','"<<genero<<"','"<<raza<<"','"<<direccion<<"','"<<nin<<"');";

       std::cout << sql.str() << std::endl;

       rc = sqlite3_exec(db, sql.str().c_str(),0,0, &zErrMsg);

       if( rc != 0 ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
           return false;
       }
       else{
          fprintf(stdout, "Records created successfully\n");      
       }
        return true;
   }
   bool db_local::verificarpaciente(paciente &p){
       char *zErrMsg = 0;
       int rc;
       bool cont =false;
        std::stringstream sql;
       sql << "SELECT * FROM _DATOSDP WHERE ( _NOMBRE = '" << p.getNombre()<<"' "
            "AND   _DOCIDENT = '" << p.getDoci() << "' );";

       std::cout << sql.str() << std::endl;

       rc = sqlite3_exec(db, sql.str().c_str() , verfpc,(void*)&cont, &zErrMsg);

       if( &zErrMsg==0){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
           return false;
       }
       else{
           fprintf(stderr, "Opened database successfully\n");
       }
     return cont;

   }
   int db_local::verfpc(void *data, int argc, char **argv, char **azColName){
       bool * a = (bool*) data ;
         *a=true;
       return 0;
   }
   bool db_local::cargardatos(string doc,string aciertos,string boton, int min,int seg){
       char *zErrMsg = 0;
       int rc;
       std::stringstream sql;


    sql <<"INSERT INTO _ADATOSPRUEBA ( _DOCIDENT,_ACIERTOS , _BOTON,_MINUTO,_SEGUNDO ) VALUES (' ";
    sql << doc<<"','" << aciertos<<"','"<< boton<<"','";
    sql << min<<"','"<<seg<<"');";
       std::cout << sql.str() << std::endl;

       rc = sqlite3_exec(db, sql.str().c_str(),0,0, &zErrMsg);

       if( rc != 0 ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
           return false;
       }
       else{
           fprintf(stderr, "Opened database successfully\n");
       }
       return true;
   }
   /**
    * @brief db_local::cerrarDB
    * Esta funcion nos permite cerrar la base de datos.
    */
  bool db_local::cerrarDB(){

       sqlite3_close( db );
  }
