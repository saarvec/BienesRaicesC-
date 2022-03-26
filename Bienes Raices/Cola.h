#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <Casa.h>
#include <unistd.h>
using std::cout;
#include "Nodo.h" // definición de la clase Nodo
#include <Lista.h>

template< typename tipo >
class Cola /*: public Lista*/{
    friend class CFrame;
public:
    Cola(); // constructor
    ~Cola(); // destructor
    void insertarAlFinal( const tipo & );//Desencolar
    void insertarNodoAlFinal(  tipo*  );//Desencolar
    bool eliminarDelFrente( tipo & );//Encolar
    tipo eliminarDeCualquier( int &Pos );
    bool estaVacia() const;
    void imprimir() const;
private:
    Nodo< tipo > *PrimP; // apuntador al primer nodo
    Nodo< tipo > *UltP; // apuntador al último nodo
    // función utilitaria para asignar un nuevo nodo
    Nodo< tipo > *obtenerNuevoNodo( const tipo & );
};

// constructor predeterminado
template< typename tipo >
Cola< tipo >::Cola()
    : PrimP( 0 ), UltP( 0 ){ }

// destructor
template< typename tipo >
Cola< tipo >::~Cola(){
    if ( !estaVacia() ) // la Lista no está vacía
    {
        cout << "Destruyendo nodos ...\n";
        Nodo< tipo > *actualPtr = PrimP;
        Nodo< tipo > *tempPtr;
        while ( actualPtr != 0 ){ // elimina los nodos restantes
            tempPtr = actualPtr;
            cout << tempPtr->datos << "\t";
            actualPtr = actualPtr->sigPtr;
            delete tempPtr;
        } // fin de while
    } // fin de if
    cout << "Se destruyeron todos los nodos\n\n";
} // fin del destructor de Lista


// inserta un nodo al final de la lista
template< typename tipo >
void Cola< tipo >::insertarAlFinal( const tipo &valor ){
    Nodo< tipo > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo
    if ( estaVacia() ) // la Lista está vacía
        PrimP = UltP = nuevoPtr; // la nueva lista sólo tiene un nodo
    else{ // la Lista no está vacía
        UltP->sigPtr = nuevoPtr; // actualiza el nodo que antes era el último
        UltP = nuevoPtr; // nuevo último nodo
    } // fin de else
} // fin de la función insertarAlFinal



// inserta un nodo al final de la lista
template< typename tipo >
void Cola< tipo >::insertarNodoAlFinal(  tipo* valor ){
    Nodo< tipo > *nuevoPtr = valor; // nuevo nodo
    if ( estaVacia() ) // la Lista está vacía
        PrimP = UltP = nuevoPtr; // la nueva lista sólo tiene un nodo
    else{ // la Lista no está vacía
        UltP->sigPtr = nuevoPtr; // actualiza el nodo que antes era el último
        UltP = nuevoPtr; // nuevo último nodo
    } // fin de else
} // fin de la función insertarAlFinal


// elimina un nodo de la parte frontal de la lista
template< typename tipo >
bool Cola< tipo >::eliminarDelFrente( tipo &valor ){
    if ( estaVacia() ) // la Lista está vacía
        return false; // la eliminación no tuvo éxito
    else{
        Nodo< tipo > *tempPtr = PrimP; // contiene tempPtr a eliminar
        if ( PrimP == UltP )
            PrimP = UltP = 0; // no hay nodos después de la eliminación
        else
            PrimP = PrimP->sigPtr; // apunta al nodo que antes era el segundo
        valor = tempPtr->datos; // devuelve los datos que se van a eliminar
        delete tempPtr; // reclama el nodo que antes era el primero
        return true; // la eliminación tuvo éxito
    } // fin de else
} // fin de la función eliminarDelFrente


// ¿está la Lista vacía?
template< typename tipo >
bool Cola< tipo >::estaVacia() const{
    return PrimP == 0;
} // fin de la función estaVacia


// muestra el contenido de la Lista
template< typename tipo >
void Cola< tipo >::imprimir() const{
    if ( estaVacia() ) {// la Lista está vacía
        cout << "La lista esta vacia\n\n";
        return;
    } // fin de if
    Nodo< tipo > *actualPtr = PrimP;
    cout << "La lista es: ";
    while ( actualPtr != 0 ) {// obtiene los datos del elemento
        if( typeid(actualPtr->datos) == typeid(Casa*) ){
            actualPtr->datos->Imprimir();
        }else{
            cout << actualPtr->datos << "\t";
        }
        sleep(1);
        actualPtr = actualPtr->sigPtr;
    } // fin de while
    cout << "\n\n";
} // fin de la función imprimir


// devuelve el apuntador al nodo recién asignado
template< typename tipo >
Nodo< tipo > *Cola< tipo >::obtenerNuevoNodo(const tipo &valor ){
    return new Nodo< tipo >( valor );
} // fin de la función obtenerNuevoNodo


template <typename tipo>
tipo Cola <tipo>::eliminarDeCualquier( int &Pos ){

    int Cant = 0;
    Nodo <tipo> *actPtr = PrimP, *tempPtr, *tmpEnviar;

    do{
        Cant++;
        actPtr = actPtr->sigPtr;
    }while(actPtr != 0);

    if( Pos<=Cant ){
        cout<<"entró aqui";
        actPtr = PrimP;
        if ( Pos!=0 ){
            for(int i=1; i<Pos-1; i++){
                actPtr = actPtr->sigPtr;
            }
            tempPtr = actPtr->sigPtr;
            actPtr->sigPtr = tempPtr->sigPtr;
        }else{
            tempPtr = actPtr;
            PrimP = actPtr->sigPtr;
        }
//            valor = tempPtr->datos;
        //delete tempPtr;
        Casa * tmp = tempPtr->datos;
        delete tempPtr;
        //return true;


    return tmp;
}
}


#endif // COLA_H
