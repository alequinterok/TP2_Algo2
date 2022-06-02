#ifndef TP2__MENU_H
#define TP2__MENU_H

#include <iostream>

using namespace std;

#include<cstdlib>
#include<ctime>
#include "novela.h"
#include "historica.h"
#include "poema.h"
#include "cuento.h"
#include "lista.h"
#include "carga_escritores.h"
#include "carga_lecturas.h"
#include "cola.h"

const int PRIMER_OPCION = 1;
const int ULTIMA_OPCION = 13;

const char SI = 's';
const char NO = 'n';


class Menu {
private:
    Lista<Lectura> *lecturas;
    Lista<Escritor> *escritores;
    Cola* cola;

public:
    // Pre: -
    // Post: Constructor de la clase menu
    Menu(string archivo_lecturas, string archivo_esctritores);

    // Pre: -
    // Post: Imprime por pantalla las opciones que tiene el usuario en el menu
    void imprimir_opciones();

    // Pre: -
    // Post: Imprime por pantalla un mensaje para volver al menu
    void mensaje_para_volver_al_menu();

    // Pre: Debe pasarse una opcion valida, de tipo int y dentro del margen de opciones
    // Post: Devuelve true si la opcion elegida esta entre la PRIMER_OPCION y la ULTIMA_OPCION
    bool opcion_valida(int opcion);

    // Pre: Debe pasarse una opcion valida, de tipo int y dentro del margen de opciones
    // Post: Devuelve true si el numero esta dentro del 1 y la cantidad de escritores en la lista.
    bool escritor_valido (int numero);

    // Pre: El texto debe ser un string valido
    // Post: Devuelve true si el tipo es CUENTO o POEMA o NOVELA
    bool tipo_valido(string texto);

    // Pre: Debe pasarse un genero valido y de tipo string
    // Post: evuelve true si el genero es valido y false en caso contrario
    bool genero_valido(string genero);

    // Pre: -
    // Post: Devuelve un puntero a un escritor nuevo creado por el usuario
    Escritor* nuevo_escritor(bool lectura);

    // Pre: -
    // Post: Ejecuta el menu por pantalla interactiva
    void ejecutar_menu();

    // Pre: -
    // Post: Devuelve true si los caracteres de la cadena son números, false si no.
    static bool entrada_valida(string cadena);

    // Pre: -
    // Post: Pide al usuario que ingrese lo que esta en tipo hasta que el ingreso sea válido.
    static int input_numero(string tipo);

    // Pre: -
    // Post: Elimina una lectura elegida por el usuario
    void quitar_lectura();

    // Pre: -
    // Post: Cambia el dato del escritor segun lo que ingresa el usuario (Solo se puede cambiar la fecha de fallecimiento)
    void cambiar_dato_escritor();

    // Pre: -
    // Post: Imprime por pantalla las lecturas de la lista.
    void listar_lecturas();

    // Pre: -
    // Post: Imprime por pantalla los escritores de la lista.
    void listar_escritores();

    // Pre: -
    // Post: Imprime por pantalla las lecturas entre determinados años ingresados por el usuario.
    void lecturas_entre_anios();

    // Pre: -
    // Post: Imprime por pantalla las novelas de un determinado género ingresado por el usuario.
    void novela_de_genero();

    // Pre: -
    // Post: Imprime por pantalla las lecturas de un determinado escritor ingresado por el usuario.
    void lecturas_del_escritor();

    // Pre: -
    // Post: Imprime por pantalla una lectura de manera aleatoria y la marca como leida.
    void lectura_al_azar();

    // Pre: -
    // Post: Devuelve un genero valido
    Novela::Genero asignar_genero();

    // Pre: -
    // Post: Carga una nueva lectura a la lista de acuerdo a los datos ingresados por el usuario
    void cargar_nueva_lectura();

    // Pre: No puede haber dos escritores con el mismo nombre
    // Post:agrega un escritor a la lista de escritores con los datos ingresados por el usuario
    void agregar_escritor();

    // Pre: -
    // Post: Crea la cola de lecturas
    void crear_cola();

    // Pre: -
    // Post: Si la cola esta cargada, muestra la primer lectura de la cola, la marca como leida y la saca de la cola.
    void leer_una_lectura();

    // Pre: -
    // Post: Destructor de la clase menu
    ~Menu();
};


#endif //TP2__MENU_H
