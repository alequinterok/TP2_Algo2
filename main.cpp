#include <iostream>

using namespace std;

#include "novela.h"
#include "historica.h"
#include "poema.h"
#include "cuento.h"
#include "lista.h"
#include "escritores.h"
#include "carga_escritores.h"
#include "carga_lecturas.h"

int main() {

    Lista<Escritor>* escritores = Carga_escritores("escritores.txt").obtener_lista();
    Lista<Lectura>* lecturas = Carga_lecturas("lecturas.txt", escritores).obtener_lista();

    for (int i = 1; i <= escritores->obtener_cantidad(); i++){

        Escritor esc = *(escritores->obtener_dato_en(i));
        cout << esc.obtener_nombre_apellido() << endl;
    }

    for (int i =1; i <= lecturas->obtener_cantidad(); i++){
        lecturas->obtener_dato_en(i)->mostrar();
    }

    delete lecturas;
    delete escritores;

    return 0;
}

