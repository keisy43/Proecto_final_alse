#ifndef DATOSU_H
#define DATOSU_H
#include <string>
using namespace std;
class datosu
{
public:
    datosu();
    string getnombre() const;
    void setNombre(const string &nombre);

    string getapellido() const;
    void setApellido(const string &apellido);


    string getDireccion() const;
    void setDireccion(const string &value);

    string getFechan() const;
    void setFechan(const string &fechan);

    string getUser() const;
    void setUser(const string &value);

    string getContra() const;
    void setContra(const string &contra);

    string getDocident() const;
    void setDocident(const string &docident);

private:

    string  _nombre;
    string  _apellido;
    string  _docident;
    string  user;
    string  _fechan;
    string  _contra;
};

#endif // DATOSU_H
