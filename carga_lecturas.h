#ifndef LISTAS_CARGA_LECTURAS_H
#define LISTAS_CARGA_LECTURAS_H
#include <iostream>
#include <string>
#include "lista.h"
#include "archivo.h"
#include "lectura.h"
#include "novela.h"
#include "cuento.h"
#include "poema.h"
#include "historica.h"

const string CUENTO = "C";
const string POEMA = "P";
const string NOVELA = "N";


class Carga_lecturas {
//atributos
private:
    Archivo archivo;
    Lista<Lectura>* lista;
    Lista<Escritor>* lista_escritores;
    string tipo;
    Lectura* lectura;
    /*Poema* poema;
    Cuento* cuento;
    Novela* novela;
    Historica* historica;*/
//metodos
public:

    explicit Carga_lecturas(string nombre_archivo, Lista<Escritor>* escritores);

    //carga una lista de lecturas
    void cargar_lista(string nombre_archivo);

    Lista<Lectura>* obtener_lista();

private:

    //crea una lectura
    void crear_lectura();

    Escritor* asignar_escritor(string escritor_str);
};



#endif //LISTAS_CARGA_LECTURAS_H