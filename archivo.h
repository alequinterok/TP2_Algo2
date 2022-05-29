#ifndef LISTAS_ARCHIVO_H
#define LISTAS_ARCHIVO_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Archivo {
//atributos
protected:
    ifstream archivo;
    string linea;

//metodos
public:

    //constructor
    Archivo();

    //abre el archivo
    void abrir_archivo(string nombre);

    //lee una linea y la retorna
    string leer_linea();

    //cierra el archivo
    void cerrar_archivo();

    //devuelve true si llego al fin del archivo
    bool fin_de_archivo();
};

#endif //LISTAS_ARCHIVO_H
