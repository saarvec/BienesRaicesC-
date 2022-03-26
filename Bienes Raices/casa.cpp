#include "casa.h"

Casa::Casa()
{
    strcpy(this->Codigo,"");
        this->Direccion = "";
        this->Color = "";
        this->Nivel = 0;
        this->Habitacion = 0;
        this->Banio = 0;
        this->Parqueo = 0;
        this->Precio = 0;
}

Casa::Casa(char *newCodigo, std::string newDireccion, std::string newColor, short newNivel, short newHabitacion, short newBanio, short newParqueo, float newPrecio)
{

    this->Codigo = newCodigo;
       this->Direccion = newDireccion;
       this->Color = newColor;
       this->Nivel = newNivel;
       this->Habitacion = newHabitacion;
       this->Banio = newBanio;
       this->Parqueo = newParqueo;
       this->Precio = newPrecio;
}

char *Casa::getCodigo() const
{
    return Codigo;

}
void Casa::setCodigo(char *newCodigo)
{
    Codigo = newCodigo;
}

const string &Casa::getDireccion() const
{
    return Direccion;
}

void Casa::setDireccion(const string &newDireccion)
{
    Direccion = newDireccion;
}

const string &Casa::getColor() const
{
    return Color;
}

void Casa::setColor(const string &newColor)
{
    Color = newColor;
}

short Casa::getNivel() const
{
    return Nivel;
}

void Casa::setNivel(short newNivel)
{
    Nivel = newNivel;
}

short Casa::getHabitacion() const
{
    return Habitacion;
}

void Casa::setHabitacion(short newHabitacion)
{
    Habitacion = newHabitacion;
}

short Casa::getBanio() const
{
    return Banio;
}

void Casa::setBanio(short newBanio)
{
    Banio = newBanio;
}

short Casa::getParqueo() const
{
    return Parqueo;
}

void Casa::setParqueo(short newParqueo)
{
    Parqueo = newParqueo;
}

float Casa::getPrecio() const
{
    return Precio;
}

void Casa::setPrecio(float newPrecio)
{
    Precio = newPrecio;
}
void Casa::Imprimir()
{
    std::cout<<"\nCódigo: "<<getCodigo()
             <<"\nDirección: "<<getDireccion()
             <<"\nColor: "<<getColor()
             <<"\nNivel: "<<getNivel()
             <<"\nHabitaciones: "<<getHabitacion()
             <<"\nBaños: "<<getBanio()
             <<"\nParqueo: "<<getParqueo()
             <<"\nPrecio: "<<getPrecio()
             <<"\n\n";
}

void Casa::Leer()
{
    this->Codigo=strcpy(Codigo,QInputDialog::getText(this,".:.Ingreso.:.","Ingrese la nueva casa: ").toStdString().c_str());
    this->Direccion =QInputDialog::getText(this,".:.Dirección.:.","Ingrese la dirección: ").toStdString();
    this->Color =QInputDialog::getText(this,".:.Color.:.","Ingrese el Color : ").toStdString();
    this->Nivel =QInputDialog::getText(this,".:.Niveles.:.","Ingrese los Niveles: ").toShort();
    this->Habitacion = QInputDialog::getText(this,".:.Habitaciones.:.","Ingrese la Cantidad de Habitaciones: ").toShort();
    this->Banio = QInputDialog::getText(this,".:.Baños.:.","Ingrese la Cantidad de Baños: ").toShort();
    this->Parqueo =QInputDialog::getText(this,".:.Parqueos.:.","Ingrese la Cantidad de Parqueos: ").toShort();
    this->Precio = QInputDialog::getText(this,".:.Precio.:.","Ingrese El Precio: ").toFloat();

}
