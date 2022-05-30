#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef struct nodo {
    string dato;
    struct nodo *siguiente;
} Nodo;

class Cola {

private:
    
    Nodo *frente;
    Nodo *fin;

public:
    // Pre: -
    // Post: Crea una cola vacia
    Cola();
    
    // Pre: -
    // Post: Destructor de la cola
    ~Cola();

    // Pre: El nodo a insertar no debe estar en la cola
    // Post: Inserta un elemento en la cola
    void insertar_cola(string);

    // Pre: -
    // Post: Muestra los elementos de la cola
    void mostrar();

    // Pre: -
    // Post: Quita el primer elemento de la cola
    string quitar();

    // Pre: -
    // Post: Devuelve true si la cola esta vacia
    bool cola_vacia();

};

#endif // COLA_H_INCLUDED 