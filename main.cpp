#include "escritores.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    Escritor Escritor;
   
    Escritor.definir_nombre_apellido("Juan Perez");
    Escritor.definir_nacionalidad("Argentina");
    Escritor.definir_anio_nacimiento(1955);
    Escritor.definir_anio_fallecimiento(1990);
   
    cout << "\nNombre del escritor: "<< Escritor.obtener_nombre_apellido() << endl;
    cout << "Nacionalidad escritor: "<< Escritor.obtener_nacionalidad() << endl;
    cout << "Anio de nacimiento: "<< Escritor.obtener_anio_nacimiento() << endl;
    cout << "Anio de fallecimiento: "<< Escritor.obtener_anio_fallecimiento() << endl;
    Escritor.modificar_anio_fallecimiento(2000);
    cout << "Anio de fallecimiento: "<< Escritor.obtener_anio_fallecimiento() << endl;
   
    return 0;
}