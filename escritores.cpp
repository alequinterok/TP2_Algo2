#include "escritores.h"
#include <iostream>

using namespace std;

Escritor::Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento) {

    this->nombre_apellido = nombre_apellido;

    this->nacionalidad = nacionalidad;

    this->anio_nacimiento = anio_nacimiento;

    this->anio_fallecimiento = anio_fallecimiento;

    this->cantidad_lecturas = 0;

}

void Escritor::modificar_anio_fallecimiento(int anio_fallecimiento) {

    this->anio_fallecimiento = anio_fallecimiento;

}

string Escritor::obtener_nombre_apellido(){
    return nombre_apellido;
}

string Escritor::obtener_nacionalidad() {

    return nacionalidad;

}

int Escritor::obtener_anio_nacimiento() {

    return anio_nacimiento;

}

int Escritor::obtener_anio_fallecimiento() {

    return anio_fallecimiento;

}

int Escritor::obtener_cant_lecturas(){
    return cantidad_lecturas;
}

void Escritor::mostrar(){
    cout << nombre_apellido << endl;
    cout << "  - nacionalidad: " << nacionalidad << endl;
    cout << "  - anio de nacimiento: " << anio_nacimiento << endl;;
    if (anio_fallecimiento != SIGUE_VIVO){
        cout << "  - anio de fallecimiento: " << anio_fallecimiento << endl;
    }
}

void Escritor::incrementar_cant_lecturas(){
    this->cantidad_lecturas = (this->cantidad_lecturas) + 1;
}

void Escritor::decrementar_cant_lecturas(){
  this->cantidad_lecturas = (this->cantidad_lecturas) - 1;
}

Escritor::~Escritor(){
}
