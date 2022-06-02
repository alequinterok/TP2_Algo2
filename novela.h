#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED

#include "lectura.h"

//const string HISTORICA = "HISTORICA";

class Novela: public Lectura{
//atributos
public:
    enum Genero{DRAMA, COMEDIA, FICCION, SUSPENSO,TERROR, ROMANTICA, HISTORICA};
    Genero genero;
//metodos

    //inicializa la novela
    Novela(std::string titulo, int minutos, int anio, Escritor* autor, Genero genero );

    //devuelve el genero de la novela
    int obtener_genero() override;

    //imprime por pantalla la informaciòn de la novela
    void mostrar();

    //destructor
    ~Novela();
};


#endif // NOVELA_H_INCLUDED
