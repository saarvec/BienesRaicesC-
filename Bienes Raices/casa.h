#ifndef CASA_H
#define CASA_H

#include <QMainWindow>
#include <iostream>
#include <cstring>
#include <QInputDialog>
#include <QMessageBox>
using std::string;

class Casa : public QMainWindow
{
private:
    char *Codigo = new char[6];
        string Direccion, Color;
        short Nivel, Habitacion, Banio, Parqueo;
        float Precio;

public:
    Casa();
    Casa(char *newCodigo,string newDireccion,string newColor, short newNivel, short newHabitacion,
         short newBanio,short newParqueo, float newPrecio);

    char *getCodigo() const;
    void setCodigo(char *newCodigo);

    const string &getDireccion() const;
    void setDireccion(const string &newDireccion);

    const string &getColor() const;
    void setColor(const string &newColor);

    short getNivel() const;
    void setNivel(short newNivel);

    short getHabitacion() const;
    void setHabitacion(short newHabitacion);

    short getBanio() const;
    void setBanio(short newBanio);

    short getParqueo() const;
    void setParqueo(short newParqueo);

    float getPrecio() const;
    void setPrecio(float newPrecio);

    void Imprimir();

    void Leer();
};

#endif // CASA_H
