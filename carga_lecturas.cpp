#include "carga_lecturas.h"
#include <string>

Carga_lecturas::Carga_lecturas(string nombre_archivo, Lista<Escritor>* escritores){
    archivo = Archivo();
    lista = new Lista<Lectura>;
    this->lista_escritores = escritores;
    cargar_lista(nombre_archivo);
}


Escritor* Carga_lecturas::asignar_escritor(string escritor_str) {
    Escritor* escritor;
    if(escritor_str == "ANONIMO") {
        escritor = NULL;
    }

    else {

        int referencia = (int)(escritor_str[1]) - 48;

        escritor = lista_escritores->obtener_dato_en(referencia);

    }
    return escritor;
}

void Carga_lecturas::crear_lectura(){
    tipo = archivo.leer_linea();
    string titulo = archivo.leer_linea();
    int minutos = stoi(archivo.leer_linea());
    int anio = stoi(archivo.leer_linea());

    if (tipo == CUENTO){
        string libro = archivo.leer_linea();
        string posible_escritor = archivo.leer_linea();
        Escritor* escritor = asignar_escritor(posible_escritor);
        lectura = new Cuento(titulo, minutos, anio, escritor, libro);

    }
    else if(tipo == POEMA){
        int versos = stoi(archivo.leer_linea());
        string posible_escritor = archivo.leer_linea();

        Escritor* escritor = asignar_escritor(posible_escritor);
        lectura = new Poema(titulo, minutos, anio, escritor, versos);

    }
    else{
        string genero = archivo.leer_linea();
        if (genero == HISTORICA){

            string tema_string = archivo.leer_linea();
            char* tema = new char [(int)tema_string.length() + 1];
            for (int i = 0; i < (int)tema_string.length() + 1; i++){
                tema[i] = tema_string[i];
            }

            string posible_escritor = archivo.leer_linea();
            Escritor* escritor = asignar_escritor(posible_escritor);
            lectura = new Historica(titulo, minutos, anio, escritor, tema);
        }else{
            string posible_escritor = archivo.leer_linea();
            Escritor* escritor = asignar_escritor(posible_escritor);

            lectura = new Novela(titulo, minutos, anio, escritor, genero);

        }
    }
}

void Carga_lecturas::cargar_lista(string nombre_archivo) {
    archivo.abrir_archivo(nombre_archivo);
    int posicion = 2;
    do{
        crear_lectura();
        if (lista->vacia()){
            lista->alta(lectura, 1);
        }
        else{
            // compara con la que está en la posición anterior
            int i = posicion - 1;
            // si es menor, compara con el anterior y asì hasta que llegue a uno que sea menor que este o al principio de la lista
            while (lectura->comparar_anios(*(lista->obtener_dato_en(i))) == MENOR && i>0){
                i--;
            }
            posicion++;
            //la agrega dsps de la lectura que es menor que la que queremos agregar
            lista->alta(lectura, i + 1);
        }
        archivo.leer_linea();
    }while(!archivo.fin_de_archivo());
    archivo.cerrar_archivo();
}

Lista<Lectura>* Carga_lecturas::obtener_lista(){
    return lista;
}
