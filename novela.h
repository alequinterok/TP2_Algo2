#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED

#include "lectura.h"

const string HISTORICA = "HISTORICA";

class Novela: public Lectura{
//atributos
public:
    string genero;
//metodos

    //inicializa la novela
    Novela(std::string titulo, int minutos, int anio, Escritor* autor, string genero );

    //devuelve el genero de la novela
    std::string obtener_genero();

    //imprime por pantalla la informaciòn de la novela
    void mostrar();

    //destructor
    ~Novela();
};


#endif // NOVELA_H_INCLUDED
