#include "escritores.h"
#include <iostream>

using namespace std;

Escritor::Escritor() {

}


void Escritor::definir_nombre_apellido(string _nombre_apellido) {
    this->nombre_apellido = _nombre_apellido;
}


void Escritor::definir_nacionalidad(string _nacionalidad) {
    this->nacionalidad = _nacionalidad;
}


void Escritor::definir_anio_nacimiento(int _anio_nacimiento) {
    this->anio_nacimiento = _anio_nacimiento;
}


void Escritor::definir_anio_fallecimiento(int _anio_fallecimiento) {
    this->anio_fallecimiento = _anio_fallecimiento;
}


void Escritor::modificar_anio_fallecimiento(int nuevo_anio_fallecimiento) {
    this->anio_fallecimiento = nuevo_anio_fallecimiento;
}


string Escritor::obtener_nombre_apellido() {
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