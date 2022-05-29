#include "lectura.h"

Lectura::Lectura(){};

Lectura::Lectura(const string titulo, const int minutos, const int anio, Escritor* autor){
    this->titulo = titulo;
    this->minutos = minutos;
    this->anio = anio;
    this->autor = autor;
    if (autor != NULL){
        this->autor->incrementar_cant_lecturas();
    }
}

string Lectura::obtener_titulo(){
    return titulo;
}

int Lectura::obtener_minutos(){
    return minutos;
}

int Lectura::obtener_anio(){
    return anio;
}

Escritor* Lectura::obtener_autor(){
    return autor;
}

int Lectura::comparar_anios (Lectura otra_lectura){
    int comparacion = MAYOR;

    if (anio < otra_lectura.anio){
        comparacion = MENOR;
    }else if (anio == otra_lectura.anio){
        comparacion = IGUAL;
    }

    return comparacion;
}

void Lectura::mostrar(){
    cout << "LECTURA:" << endl;
    cout << "- titulo: " << titulo << endl;
    cout << "- minutos en leerse: " << minutos << endl;
    cout << "- anio de publicacion: " << anio << endl;
    cout << "- autor: ";
    if (autor != NULL){
        autor->mostrar();
    }else{
        cout << "ANONIMO" << endl;
    }
}

Lectura::~Lectura(){
}
