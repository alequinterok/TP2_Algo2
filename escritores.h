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
    //PRE: -
    //POST: Crea un escritor
    Escritor();
    
    //PRE: El parametro pasado debe ser de tipo string
    //POST: Define el nombre y apellido del escritor
    void definir_nombre_apellido(string);
    
    //PRE: El parametro pasado debe ser de tipo string
    //POST: Define la nacionalidad del escritor
    void definir_nacionalidad(string);

    //PRE: El parametro pasado debe ser de tipo int
    //POST: Define el año de nacimiento del escritor
    void definir_anio_nacimiento(int);
    
    //PRE: El parametro pasado debe ser de tipo int
    //POST: Define el año de fallecimiento del escritor
    void definir_anio_fallecimiento(int);

    //PRE: El parametro pasado debe ser de tipo int
    //POST: Modifica el valor anio_fallecimiento por el pasado como parametro
    void modificar_anio_fallecimiento(int);
    
    //PRE: -
    //POST: Devuelve el nombre y apellido del escritor
    string obtener_nombre_apellido();
    
    //PRE: -
    //POST: Devuelve la nacionalidad del escritor
    string obtener_nacionalidad();
    
    //PRE: -
    //POST: Devuelve el año de nacimiento del escritor
    int obtener_anio_nacimiento();
    
    //PRE: -
    //POST: Devuelve el año de fallecimiento del escritor
    int obtener_anio_fallecimiento();

};

#endif // ESCRITORES_H_INCLUDED