#include "carga_escritores.h"

Carga_escritores::Carga_escritores(string nombre_archivo) {
    lista = new Lista<Escritor>;
    posicion = 0;
    cargar_lista(nombre_archivo);
}

void Carga_escritores::crear_escritor() {
    string datos[4] = {"","¿?","-1","-1"};
    posicion = (int)((archivo.leer_linea()[1])) - 48;

    int indice = 0;
    string dato;
    do{
        dato = archivo.leer_linea();
        if (dato != "" && indice < 4) {
            datos[indice] = dato;
        }
        indice++;
    }while(dato != "" && indice < 5 && !archivo.fin_de_archivo());

    escritor = new Escritor((string)datos[0],(string)datos[1],stoi(datos[2]),stoi(datos[3]));
}

void Carga_escritores::cargar_lista(string nombre_archivo) {
    archivo.abrir_archivo(nombre_archivo);
    do{
        crear_escritor();
        lista->alta(escritor,posicion);
    }while(!archivo.fin_de_archivo());
    archivo.cerrar_archivo();
}

//función de prueba :D
/*void Carga_escritores::mostrar_escritor() {
    Escritor escritor_ = lista->*obtener_dato_en(4);
    cout<<escritor_.obtener_nombre_apellido()<<endl;
    cout<<escritor_.obtener_nacionalidad()<<endl;
    cout<<escritor_.obtener_anio_nacimiento()<<endl;
    cout<<escritor_.obtener_anio_fallecimiento()<<endl;
    Escritor escritorr_ = lista->*obtener_dato_en(5);
    cout<<escritorr_.obtener_nombre_apellido()<<endl;
    cout<<escritorr_.obtener_nacionalidad()<<endl;
    cout<<escritorr_.obtener_anio_nacimiento()<<endl;
    cout<<escritorr_.obtener_anio_fallecimiento()<<endl;
}*/

Lista<Escritor>* Carga_escritores::obtener_lista() {
    return lista;
}
