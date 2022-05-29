#ifndef CUENTO_H_INCLUDED
#define CUENTO_H_INCLUDED

#include "lectura.h"

class Cuento: public Lectura{
//atributos
private:
    string libro;
//metodos
public:
    //inicializa el cuento
    Cuento(string titulo, int minutos, int anio, Escritor* autor, string libro);

    //devuelve el libro al que pertenece el cuento
    std::string obtener_libro();

    //imprime por pantalla la informacion del cuento
    void mostrar();

    //destructor
    ~Cuento();
};


#endif // CUENTO_H_INCLUDED
