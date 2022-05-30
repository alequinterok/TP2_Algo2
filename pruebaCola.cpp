#include <iostream>
#include <string>
#include "cola.h"

using namespace std;

int main() {
    Cola *cola = new Cola();
    Cola *cola2 = new Cola();

    cola->insertar_cola("hola");
    cola->insertar_cola("mundo");
    cola->mostrar();
    cout << cola->quitar() << endl;
    cola->mostrar();
    
    cola2->insertar_cola("hola");
    cola2->insertar_cola("mundo");
    cola2->mostrar();
    cout << cola2->quitar() << endl;
    cola2->mostrar();
    
    return 0;
}
