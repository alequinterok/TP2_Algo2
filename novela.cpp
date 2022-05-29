#include "novela.h"

Novela::Novela(std::string titulo, int minutos, int anio, Escritor* autor, string genero ) : Lectura(titulo,minutos,anio,autor) {
    this->genero = genero;
};

std::string Novela::obtener_genero() {
    return genero;
}

void Novela::mostrar(){
    Lectura::mostrar();
    cout << "-Tipo: Novela" << endl;
    cout << " -Genero: " << genero << endl;

}

Novela::~Novela(){

    if (autor != NULL) {
            autor->decrementar_cant_lecturas();
    }

}
