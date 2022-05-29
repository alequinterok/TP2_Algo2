#ifndef LISTAS_CARGA_ESCRITORES_H
#define LISTAS_CARGA_ESCRITORES_H
#include "escritores.h"
#include "lectura.h"
#include "archivo.h"
#include "lista.h"

class Carga_escritores {
private:
    Archivo archivo;
    Escritor* escritor;
    int posicion;
    Lista<Escritor>* lista;

public:
    Carga_escritores(string nombre_archivo);

    void cargar_lista(string nombre_archivo);

    void crear_escritor();

    //esta es otra de prueba :D
    //void mostrar_escritor();

    Lista<Escritor>* obtener_lista();
};


#endif //LISTAS_CARGA_ESCRITORES_H
