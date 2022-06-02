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

    Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);

    void modificar_anio_fallecimiento(int anio_fallecimiento);

    string obtener_nombre_apellido();

    string obtener_nacionalidad();

    int obtener_anio_nacimiento();

    int obtener_anio_fallecimiento();

    void mostrar();

    ~Escritor();
};

#endif // ESCRITORES_H_INCLUDED
