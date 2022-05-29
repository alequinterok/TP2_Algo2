#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED

#include <iostream>
#include "escritores.h"

const int MAYOR = 1;
const int MENOR = -1;
const int IGUAL = 0;

class Lectura{

protected:
    string titulo;
    int minutos;

    Escritor* autor;

    Lectura();

    /*
    *pre:
    *post: inicializa la lectura
    */
    Lectura (const string titulo, const int minutos, const int anio, Escritor* autor);


    /*
    *pre:
    *post: devuelve el nombre del titulo de la lectura
    */
    string obtener_titulo();
    /*
    *pre:
    *post: devuelve los minutos que tarda en leerse la lectura
    */
    int obtener_minutos();
    /*
    *pre:
    *post: devuelve el anio en que salio la lectura
    */
    int obtener_anio();
    /*
    *pre:
    *post: devuelve el puntero al escritor de la lectura
    */
    Escritor* obtener_autor();


public:
    int anio;

    /*
    *pre:
    *post: imprime por pantalla la informacion de la lectura
    */
    virtual void mostrar();


    /*
    *pre:
    *post: destructor virtual
    */
    virtual ~Lectura();

    /*
    * otra_lectura previamente inicializada
    * compara la lectura con otra_lectura segun en anio en que
    * salieron.
    * --> si el anio de lectura es mayor, devuelve MAYOR
    * --> si el anio de lectura es menor, devuelve MENOR
    * --> si son iguales devuelve IGUAL
    */
    int comparar_anios (Lectura otra_lectura);
};

#endif // LECTURA_H_INCLUDED
