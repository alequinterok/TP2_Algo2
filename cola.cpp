#include "cola.h"

Cola::Cola() {
    frente = NULL;
    fin = NULL;
}


Cola::~Cola() {
    Nodo *aux;
    while(frente != NULL){
        aux = frente;
        frente = frente->siguiente;
        delete aux;
    }
}


void Cola::insertar_cola(string _dato) {
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->dato = _dato;
    nuevo_nodo->siguiente = NULL;

    if(cola_vacia()) {
        frente = nuevo_nodo;
    } 
    else {
        fin->siguiente = nuevo_nodo;
    }
    
    fin = nuevo_nodo;
}


void Cola::mostrar() {
    Nodo *aux = frente;
    while(aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }
}


string Cola::quitar() {
    if(frente == NULL) {
        return "";
    }
    
    else {
        Nodo *aux = frente;
        frente = frente->siguiente;
        string dato = aux->dato;
        delete aux;
        return dato;
    }
}


bool Cola::cola_vacia() {
    if(frente == NULL) {
        return true;
    }
    
    else {
        return false;
    }
}