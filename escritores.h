#ifndef ESCRITORES_H_INCLUDED
#define ESCRITORES_H_INCLUDED

#include <string>

using namespace std;

const int SIGUE_VIVO = -1;

class Escritor{

private:
    string nombre_apellido;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;

public:
    Escritor();

    void definir_nombre_apellido(string);
    void definir_nacionalidad(string);
    void definir_anio_nacimiento(int);
    void definir_anio_fallecimiento(int);

    void modificar_anio_fallecimiento(int);
    
    string obtener_nombre_apellido();
    string obtener_nacionalidad();
    int obtener_anio_nacimiento();
    int obtener_anio_fallecimiento();

};

#endif // ESCRITORES_H_INCLUDED