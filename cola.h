#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Cola{
protected:
    struct Nodo{
        string dato;
        Nodo *sig;
    };
    Nodo *frente;
    Nodo *final;
public:
    Cola();
    ~Cola();
    void insertar(string);
    string quitar();
    string peek();
    bool vacia();
    void mostrar();
};

#endif // COLA_H_INCLUDED 