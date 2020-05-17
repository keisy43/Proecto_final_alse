
#include "usuario.h"
#include <iostream>
#include <sstream>
#include <QString>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "QDebug"
#include "prueba.h"
#include "paciente.h"

using namespace std;
db_local::db_local()
{
}
    /**
     * @brief db_local::abrirDB
     * @param path  Es la ubicación absoluta o relativa de la DB.    
     * @return Un valor booleano que describe si se pudo abrir la DB o no.
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
            return true;
        }
        cerrarDB();
    }

    /**
     * @brief db_local::cargarusuario
     * @param namenew Es el nombre del usuario nuevo que se desea registrar.
     * @param lastnamenew Es el apellido del usuario nuevo a registrar.
     * @param fnnew Es la fecha de nacimiento del usuario nuevo.
     * @param docinew Es el documento de identidad  del usuario nuevo.
     * @param usernew Es el nickname del usuario nuevo.
     * @param contranew Es la contraseña del usuario nuevo.
     * @return Un valor booleano que describe si pudieron guardar los datos en la DB o no.
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
            return true;
        }


      }


    /**
     * @brief db_local::verificarusuario
     * @param &z Es un puntero de la clase paciente que nos permite retornar los datos ingresados del usuario.
     *  @return Un valor booleano que describe si los datos ingresados si están en la DB o no.
     */

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
       sqlite3_close(db);
     return cont;
    }
   
   /**
       * @fn db_local::verfu
       * @brief Es la función llamada para verificar si los datos del usuario están en la base de datos, verificando así la existencia del usuario.
       * @param data Es un puntero de tipo void .
       * @param argv Es una variable de tipo char.
       * @param argc Es un puntero tipo entero
       * @param azColName
       *  @return Un valor entero que describe si los datos ingresados se encuentran en la DB o no.
       */
   
int db_local::verfu(void *data, int argc, char **argv, char **azColName){

    bool * a = (bool*) data ;
    *a=true;
    return 0;
 }
  
/**
   * @brief db_local::cargarpaciente
   * @param np Es el nombre del paciente nuevo.
   * @param appc Es el apellido del paciente nuevo.
   * @param fecha Es la fecha de nacimiento del paciente nuevo.
   * @param Doc Es el documento de identidad  del paciente nuevo.
   * @param genero Es el género del paciente nuevo.
   * @param raza Es la raza del paciente nuevo.
   * @param direccion Es la dirección del paciente nuevo.
   * @param nin Es el nivel de ingresos  del paciente nuevo.
   * @return Un valor booleano que describe si pudieron guardar los datos en la DB o no.
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
        sqlite3_close(db);
   }
   
   /**
    * @brief db_local::verificarpaciente
    * @param &p Es un puntero de la clase paciente que nos permite retornar los datos ingresados del paciente.
    *  @return Un valor booleano que describe si los datos ingresados están en la DB o no.
    */
   
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
           fprintf(stderr, "Opened1 database successfully\n");
           return true;
       }
       sqlite3_close(db);
     return cont;

   }
   
   /**
    * @fn db_local::verfpc
    * @brief Es la funcion llamada para verificar si los datos del paciente están en la base de datos.
    * @param data Es un puntero de tipo void .
    * @param argv Es una variable tipo char.
    * @param argc Es un puntero tipo entero.
    * @param azColName
    *  @return Un valor entero que describe si los datos ingresados están en la DB o no.
    */
   
   int db_local::verfpc(void *data, int argc, char **argv, char **azColName){
       bool * a = (bool*) data ;
         *a=true;
       return 0;
   }
   
   /**
    * @brief db_local::cargardatos
    * @param docu Es el número de documento del paciente que va a realizar la prueba.
    * @param conteo Es el número de aciertos que obtuvo el paciente en la prueba.
    * @param _estado2 Es el que indica el botón que se encuentra prendido.
    * @param tiempo Indica el tiempo que lleva transcurrido de la prueba.
    * @return Un valor boleano que describe si pudieron guardar los datos en la DB o no.
    */
   
   bool db_local::cargardatos(int docu, int conteo, int _estado2, int tiempo){
       char *zErrMsg = 0;
       int rc;
       std::stringstream sql;


    sql <<"INSERT INTO _DATOSPRUEBA ( _DOCIDENT,_ACIERTOS , _BOTON,_SEGUNDO ) VALUES (' ";
    sql << docu<<"','" << conteo<<"','"<< _estado2<<"','";
    sql << tiempo<<"');";
       std::cout << sql.str() << std::endl;

       rc = sqlite3_exec(db, sql.str().c_str(),0,0, &zErrMsg);

       if( rc != 0 ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
           return false;
       }
       else{
           fprintf(stderr, "Opened2 database successfully\n");
           return true;
       }
       cerrarDB();
   }

   /**
    * @brief db_local::cerrarDB
    * Esta función nos permite cerrar la base de datos.
    */

  bool db_local::cerrarDB(){
       std::cout << "cerrar." <<endl;
       sqlite3_close( db );
  }
