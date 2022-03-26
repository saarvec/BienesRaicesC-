#ifndef NODO_H
#define NODO_H

template <typename tipo> class Lista;
template <typename tipo> class Cola;
template <typename tipo>
class Nodo {
    friend class Lista <tipo>;
    friend class Cola<tipo>;
    friend class CFrame;

public:
    Nodo ( const tipo & );
    tipo obtenerDatos() const;
private:
    tipo datos;
    Nodo <tipo> *sigPtr;
};

template< typename tipo >
Nodo < tipo >::Nodo ( const tipo &info )
    : datos( info ), sigPtr( 0 ){ }

template< typename tipo >
tipo Nodo < tipo >::obtenerDatos() const
{
    return datos;
}
#endif

