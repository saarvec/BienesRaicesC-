#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <Casa.h>
#include <unistd.h>
using std::cout;
#include "Nodo.h" // definición de la clase Nodo

template< typename tipo >
class Lista{
    friend class CFrame;
public:
    Lista(); // constructor
    ~Lista(); // destructor
    void insertarAlFrente( const tipo & );
    void insertarAlFinal( const tipo & );
    bool eliminarDelFrente( tipo & );
    bool eliminarDelFinal( tipo & );
    tipo eliminarDeCualquier( int &Pos );
    bool estaVacia() const;
    void imprimir() const;
private:
    Nodo< tipo > *primeroPtr; // apuntador al primer nodo
    Nodo< tipo > *ultimoPtr; // apuntador al último nodo
    // función utilitaria para asignar un nuevo nodo
    Nodo< tipo > *obtenerNuevoNodo( const tipo & );
}; // fin de la clase Lista

// constructor predeterminado
template< typename tipo >
Lista< tipo >::Lista()
    : primeroPtr( 0 ), ultimoPtr( 0 ){ }

// destructor
template< typename tipo >
Lista< tipo >::~Lista(){
    if ( !estaVacia() ) // la Lista no está vacía
    {
        cout << "Destruyendo nodos ...\n";
        Nodo< tipo > *actualPtr = primeroPtr;
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

// inserta un nodo al frente de la lista
template< typename tipo >
void Lista< tipo >::insertarAlFrente( const tipo &valor ){
    Nodo< tipo > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo
    if ( estaVacia() ) // la Lista está vacía
        primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
    else{ // la Lista no está vacía
        nuevoPtr->sigPtr = primeroPtr; // apunta el nuevo nodo al nodo que antes era el primero
        primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
    } // fin de else
} // fin de la función insertarAlFrente

// inserta un nodo al final de la lista
template< typename tipo >
void Lista< tipo >::insertarAlFinal( const tipo &valor ){
    Nodo< tipo > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo
    if ( estaVacia() ) // la Lista está vacía
        primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
    else{ // la Lista no está vacía
        ultimoPtr->sigPtr = nuevoPtr; // actualiza el nodo que antes era el último
        ultimoPtr = nuevoPtr; // nuevo último nodo
    } // fin de else
} // fin de la función insertarAlFinal

// elimina un nodo de la parte frontal de la lista
template< typename tipo >
bool Lista< tipo >::eliminarDelFrente( tipo &valor ){
    if ( estaVacia() ) // la Lista está vacía
        return false; // la eliminación no tuvo éxito
    else{
        Nodo< tipo > *tempPtr = primeroPtr; // contiene tempPtr a eliminar
        if ( primeroPtr == ultimoPtr )
            primeroPtr = ultimoPtr = 0; // no hay nodos después de la eliminación
        else
            primeroPtr = primeroPtr->sigPtr; // apunta al nodo que antes era el segundo
        valor = tempPtr->datos; // devuelve los datos que se van a eliminar
        delete tempPtr; // reclama el nodo que antes era el primero
        return true; // la eliminación tuvo éxito
    } // fin de else
} // fin de la función eliminarDelFrente

// elimina un nodo de la parte final de la lista
template< typename tipo >
bool Lista< tipo >::eliminarDelFinal( tipo &valor ){
    if ( estaVacia() ) // la Lista está vacía
        return false; // la eliminación no tuvo éxito
    else{
        Nodo< tipo > *tempPtr = ultimoPtr; // contiene tempPtr a eliminar
        if ( primeroPtr == ultimoPtr ) // la Lista tiene un elemento
            primeroPtr = ultimoPtr = 0; // no hay nodos después de la eliminación
        else{
            Nodo< tipo > *actualPtr = primeroPtr;
            // localiza el penúltimo elemento
            while ( actualPtr->sigPtr != ultimoPtr )
                actualPtr = actualPtr->sigPtr; // se desplaza al siguiente nodo
            ultimoPtr = actualPtr; // elimina el último nodo
            actualPtr->sigPtr = 0; // ahora éste es el último nodo
        } // fin de else
        valor = tempPtr->datos; // devuelve el valor del nodo que antes era el último
        delete tempPtr; // reclama el nodo que antes era el último
        return true; // la eliminación tuvo éxito
    } // fin de else
} // fin de la función eliminarDelFinal

// ¿está la Lista vacía?
template< typename tipo >
bool Lista< tipo >::estaVacia() const{
    return primeroPtr == 0;
} // fin de la función estaVacia

// devuelve el apuntador al nodo recién asignado
template< typename tipo >
Nodo< tipo > *Lista< tipo >::obtenerNuevoNodo(const tipo &valor ){
    return new Nodo< tipo >( valor );
} // fin de la función obtenerNuevoNodo

// muestra el contenido de la Lista
template< typename tipo >
void Lista< tipo >::imprimir() const{
    if ( estaVacia() ) {// la Lista está vacía
        cout << "La lista esta vacia\n\n";
        return;
    } // fin de if
    Nodo< tipo > *actualPtr = primeroPtr;
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

template <typename tipo>
tipo Lista <tipo>::eliminarDeCualquier( int &Pos ){



        int Cant = 0;
        Nodo <tipo> *actPtr = primeroPtr, *tempPtr, *tmpEnviar;

        do{
            Cant++;
            actPtr = actPtr->sigPtr;
        }while(actPtr != 0);

        if( Pos<=Cant ){
            cout<<"entró aqui";
            actPtr = primeroPtr;
            if ( Pos!=0 ){
                for(int i=1; i<Pos-1; i++){
                    actPtr = actPtr->sigPtr;
                }
                tempPtr = actPtr->sigPtr;
                actPtr->sigPtr = tempPtr->sigPtr;
            }else{
                tempPtr = actPtr;
                primeroPtr = actPtr->sigPtr;
            }
//            valor = tempPtr->datos;
            //delete tempPtr;
            Casa * tmp = tempPtr->datos;
            delete tempPtr;
            //return true;


        return tmp;
    }
}

#endif
