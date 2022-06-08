#include "menu.h"

const string PATH_LECTURAS = "archivos/lecturas.txt";
const string PATH_ESCRITORES = "archivos/escritores.txt";

int main() {

    Menu menu(PATH_LECTURAS, PATH_ESCRITORES);

    menu.ejecutar_menu();

    return 0;
}

