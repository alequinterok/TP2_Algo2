#ifndef POEMA_H_INCLUDED
#define POEMA_H_INCLUDED

#include "lectura.h"

class Poema: public Lectura{
//atributos
private:
    int versos;
//metodos
public:
    //inicializa el poema
    Poema(std::string titulo, int minutos, int anio, Escritor* autor, int versos);

    //devuelve la cantidad de versos del poema
    int obtener_versos();

    //imprime por pantalla la informacion del poema
    void mostrar();

    //destructor
    ~Poema();
};

#endif // POEMA_H_INCLUDED
