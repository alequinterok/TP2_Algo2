#ifndef HISTORICA_H_INCLUDED
#define HISTORICA_H_INCLUDED

#include "novela.h"

class Historica: public Novela{
//atributos
private:
    char* tema;
//metodos
public:

    //inicializa la novela historica
    Historica (std::string titulo, int minutos, int anio, Escritor* autor, char* tema_);

    //devuelve el tema de la novela historica
    char* obtener_tema();

    //imprime por pantalla la informacion de la novela historica
    void mostrar();

    //destructor
    ~Historica();
};


#endif // HISTORICA_H_INCLUDED
