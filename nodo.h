#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

using namespace std;
template < typename Dato >

class Nodo{

private:

    Dato* dato;
    Nodo* siguiente;

public:

    /*
    *pre:
    *pos: construye un Nodo con el dato y le asigna como siguiente
    *     un null
    */
    Nodo (Dato* dato);

    /*
    *pre: nuevo_siguiente es una direccion a un nodo valida
    *pos: cambia el siguiente por el nuevo siguiente
    */
    void cambiar_siguiente (Nodo* nuevo_siguiente);

    /*
    *pre:
    *pos: devuelve el dato
    */
    Dato* obtener_dato ();

    /*
    *pre:
    *pos: devuelve la direccion del siguiente dato
    */
    Nodo* obtener_siguiente();

    //destructor
    //borra la memoria del puntero dato
    ~Nodo();

};

template < typename Dato >
Nodo<Dato>::Nodo (Dato* dato){
    this->dato = dato;
    siguiente = 0;
}

template < typename Dato >
void Nodo<Dato>::cambiar_siguiente(Nodo* nuevo_siguiente){
    this->siguiente = nuevo_siguiente;
}

template < typename Dato >
Dato* Nodo<Dato>::obtener_dato(){
    return dato;
}

template < typename Dato >
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}

template < typename Dato >
Nodo<Dato>::~Nodo(){
    delete dato;
}

#endif // NODO_H_INCLUDED
