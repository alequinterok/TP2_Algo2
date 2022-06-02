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
    //constructor
    Menu(string archivo_lecturas, string archivo_esctritores);

    //imprime las opciones que tiene el usuario en el menu
    void imprimir_opciones();

    //imprime un mensaje para volver al menu
    void mensaje_para_volver_al_menu();

    //devuelve true si la opcion elegida esta entre la PRIMER_OPCION
    //y la ULTIMA_OPCION
    bool opcion_valida(int opcion);

    //devuelve true si el numero esta dentro del 1 y la cantidad
    //de escritores en la lista.
    bool escritor_valido (int numero);

    //devuelve true si el tipo es CUENTO o POEMA o NOVELA
    bool tipo_valido(string texto);

    //devuelve true si el genero es valido y false en caso contrario
    bool genero_valido(string genero);

    //devuelve un puntero a un escritor nuevo creado por el usuario
    Escritor* nuevo_escritor(bool lectura);

    //ejecuta el menu por pantalla interactiva
    void ejecutar_menu();

    // devuelve true si los caracteres de la cadena son números, false si no.
    static bool entrada_valida(string cadena);

    //pide al usuario que ingrese lo que esta en tipo hasta que el ingreso sea válido.
    static int input_numero(string tipo);

    //elimina una lectura elegida por el usuario
    void quitar_lectura();

    //cambia el dato del escritor segun lo que ingresa el usuario
    //(Solo se puede cambiar la fecha de fallecimiento)
    void cambiar_dato_escritor();

    //lista las lecturas.
    void listar_lecturas();

    //lista los escritores.
    void listar_escritores();

    //lista las lecturas entre determinados años ingresados por el usuario.
    void lecturas_entre_anios();

    //Lista las novelas de determinado género ingresado por el usuario.
    void novela_de_genero();

    //Lista las lecturas de un determinado escritor que ingresa el usuario.
    void lecturas_del_escritor();

    //muestra una lectura al azar y la marca como leida.
    void lectura_al_azar();

    //Devuelve un genero valido
    Novela::Genero asignar_genero();

    //carga una nueva lectura a la lista de acuerdo a los datos ingresados
    //por el usuario
    void cargar_nueva_lectura();

    //pre: No puede haber dos escritores con el mismo nombre
    //agrega un escritor a la lista de escritores con los datos
    //ingresados por el usuario
    void agregar_escritor();

    //crea la cola de lecturas
    void crear_cola();

    //Si la cola esta cargada, muestra la primer lectura de la cola,
    //la marca como leida y la saca de la cola.
    void leer_una_lectura();

    //destructor
    ~Menu();
};


#endif //TP2__MENU_H
