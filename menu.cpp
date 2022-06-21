#include "menu.h"

Menu::Menu(string archivo_lecturas, string archivo_escritores) {
    escritores = Carga_escritores(archivo_escritores).obtener_lista();
    lecturas = Carga_lecturas(archivo_lecturas, escritores).obtener_lista();
    cola = new Cola;
}

void Menu::imprimir_opciones(){
    cout << "+-----------------------------------------------------------------------------------+" << endl;
    cout << "| Menu principal:                                                                   |" << endl;
    cout << "|                                                                                   |" << endl;
    cout << "| 1) Agregar una nueva lectura a la lista.                                          |" << endl;
    cout << "| 2) Quitar una lectura de la lista.                                                |" << endl;
    cout << "| 3) Agregar un escritor.                                                           |" << endl;
    cout << "| 4) Cambiar dato de un escritor.                                                   |" << endl;
    cout << "| 5) Listar los escritores.                                                         |" << endl;
    cout << "| 6) Sortear una lectura random para leer.                                          |" << endl;
    cout << "| 7) Listar todas las lecturas.                                                     |" << endl;
    cout << "| 8) Listar las lecturas entre determinados años.                                   |" << endl;
    cout << "| 9) Listar las lecturas de un determinado escritor.                                |" << endl;
    cout << "| 10) Listar las novelas de determinado género.                                     |"  << endl;
    cout << "| 11) Cola de lecturas no leidas ordenada por tiempo de lectura, de menor a mayor.  |" << endl;
    cout << "| 12) Leer la primera lectura de la cola.                                           |" << endl;
    cout << "| 13) Salir.                                                                        |" << endl;
    cout << "|                                                                                   |"<< endl;
    cout << "+-----------------------------------------------------------------------------------+" << endl;
}

void Menu::mensaje_para_volver_al_menu(){
    string basura;
    cout << "\n Ingrese cualquier tecla para volver al menu: ";
    cin >> basura;
}

bool Menu::opcion_valida(int opcion){
    return (opcion >= PRIMER_OPCION && opcion <= ULTIMA_OPCION);
}

void Menu::ejecutar_menu(){
    system("clear");
    cout << "-- MENU -- \n" <<endl;

    imprimir_opciones();

    int opcion = input_numero("Ingrese la opcion que desee ");
    while (!opcion_valida(opcion)){
        cout << "Esa opcion no existe. Intentelo de nuevo.\n";
        opcion = input_numero("Ingrese la opcion que desee ");
    }

    system("clear");

    if (opcion == 1) {
        cargar_nueva_lectura();
    }
    else if (opcion == 2) {
        quitar_lectura();
    }
    else if (opcion == 3) {
        agregar_escritor();
    }
    else if (opcion == 4) {
        cambiar_dato_escritor();
    }
    else if (opcion == 5) {
        listar_escritores();
    }
    else if (opcion == 6) {
        lectura_al_azar();
    }
    else if (opcion == 7) {
        listar_lecturas();
    }
    else if (opcion == 8) {
        lecturas_entre_anios();
    }
    else if (opcion == 9) {
        lecturas_del_escritor();
    }
    else if (opcion == 10) {
        novela_de_genero();
    }
    else if (opcion == 11) {
        crear_cola();
    }
    else if (opcion == 12) {
        leer_una_lectura();
    }
    else
        cout << "\nHasta luego!" <<endl;

}

bool Menu::entrada_valida(string cadena) {
    bool es_numerico = true;

    for(char i : cadena){
        if( '0' > i || '9' < i )
            es_numerico = false;
    }

    return es_numerico;
}

int Menu::input_numero(string texto) {
    string numero_str;

    cout << texto << ": ";
    cin >> numero_str;
    while(!entrada_valida(numero_str)){
        cout << "entrada inválida" << endl;
        cout << "Ingrese " << texto << ": ";
        cin >> numero_str;
    }

    return stoi(numero_str);
}

void Menu::listar_lecturas() {
    cout << "LISTA DE LECTURAS \n" << endl;
    
    for (int i = 1; i <= lecturas->obtener_cantidad(); i++){
        lecturas->obtener_dato_en(i)->mostrar();
    }

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::listar_escritores() {
    cout << "LISTA DE ESCRITORES \n" << endl;

    for (int i = 1; i <= escritores->obtener_cantidad(); i++){

        Escritor esc = *(escritores->obtener_dato_en(i));
        cout << i << endl;
        esc.mostrar();
    }

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::lecturas_entre_anios() {
    cout << "LECTURAS ENTRE ANIOS \n" << endl;    

    int anio_i = input_numero("Ingrese el año inicial");
    int anio_f = input_numero("Ingrese el año final");

    if (anio_i < anio_f){
        int posicion = 1;

        while (posicion <= lecturas->obtener_cantidad() &&
               lecturas->obtener_dato_en(posicion)->obtener_anio() < anio_i) {
            posicion++;
        }

        if (posicion <= lecturas->obtener_cantidad()) {
            cout << "\nLecturas publicadas entre los años " << anio_i << " y " << anio_f << ": " << endl;

            while (posicion <= lecturas->obtener_cantidad() &&
                   lecturas->obtener_dato_en(posicion)->obtener_anio() <= anio_f) {
                lecturas->obtener_dato_en(posicion)->mostrar();
                posicion++;
            }

        }else{
            cout << "\nNo se encontraron lecturas entre esos años." << endl;
        }

    }else{
        cout << "\nEl año inicial es mayor al año final." <<endl;
    }

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::novela_de_genero() {
    cout << "NOVELAS DE UN GENERO \n" << endl;

    cout << "1- DRAMA\n2- COMEDIA\n3- FICCION\n4- SUSPENSO\n5- TERROR\n6- ROMANTICA\n7- HISTORICA"<< endl;

    int genero;
    do{
        genero = input_numero("Ingrese el número asociado al genero deseado");
    }while (1 > genero || CANTIDAD_GENEROS < genero);

    cout << "\nNovelas del genero " << genero << ": " << endl;

    for (int i = 1; i <= lecturas->obtener_cantidad(); i++){
        if(lecturas->obtener_dato_en(i)->obtener_genero() == (genero - 1))
            lecturas->obtener_dato_en(i)->mostrar();
    }

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::lecturas_del_escritor() {
    cout << "LECTURAS DE UN ESCRITOR \n" << endl;

    cout << "\nEscritores:" << endl;

    for (int i = 1; i <= escritores->obtener_cantidad(); i++){
        cout << i << ") " << escritores->obtener_dato_en(i)->obtener_nombre_apellido()<<endl;
    }

    int escritor_int;
    do {
        escritor_int = input_numero("Ingrese el número asociado al escritor deseado");
    }
    while (0 >= escritor_int || escritores->obtener_cantidad()< escritor_int);

    string escritor = escritores->obtener_dato_en(escritor_int)->obtener_nombre_apellido();

    cout << "\nLecturas escritas por "<< escritor << ": " << endl;

    int cantidad = 0;

    for (int i = 1; i <= lecturas->obtener_cantidad(); i++){

        if(lecturas->obtener_dato_en(i)->obtener_autor() != NULL &&
           (string)lecturas->obtener_dato_en(i)->obtener_autor()->obtener_nombre_apellido() == escritor){

            lecturas->obtener_dato_en(i)->mostrar();
            cantidad++;

        }
    }

    if(cantidad == 0)
        cout << "\nNo se encontraron lecturas escritas por este escritor. "<<endl;

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

bool Menu::escritor_valido(int numero){
    return (numero >= 1 &&
            numero <= escritores->obtener_cantidad());
}

void Menu::quitar_lectura (){
    cout << "QUITAR LECTURA \n" << endl;

    for (int i = 1; i <= lecturas->obtener_cantidad(); i++){
        cout << i << ") ";
        cout << lecturas->obtener_dato_en(i)->obtener_titulo();

        if (lecturas->obtener_dato_en(i)->obtener_autor() != NULL){
            cout << " de " << lecturas->obtener_dato_en(i)->obtener_autor()->obtener_nombre_apellido() << endl;
        }else{
            cout << endl;
        }
    }

    cout << "\n";

    int posicion = input_numero("numero de lectura que quiere borrar");

    char confirmacion;
    cout << "Esta seguro que quiere borrar ";
    cout << lecturas->obtener_dato_en(posicion)->obtener_titulo();
    cout << " de " << lecturas->obtener_dato_en(posicion)->obtener_autor()->obtener_nombre_apellido();
    cout << "? (ingrese s para si o n para no) ";
    cin >> confirmacion;
    while (confirmacion!= SI && confirmacion!= NO){
        cout << "(ingrese s para si o n para no)" << endl;
        cin >> confirmacion;
    }

    if (confirmacion == SI){
        lecturas->baja(posicion);
    }
    cout << "-- lectura borrada" << endl;

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::cambiar_dato_escritor (){

    cout << "CAMBIAR DATO DE ESCRITOR \n" << endl;
    for (int i = 1; i <= escritores->obtener_cantidad(); i++){

        cout << i << ") ";
        Escritor esc = *(escritores->obtener_dato_en(i));
        cout << esc.obtener_nombre_apellido() << endl;
    }
    int posicion;
    int anio_fallecimiento;

    posicion = input_numero("el numero del escritor que quiere modificar");

    while (!escritor_valido(posicion)){
        cout << "Ese no es un escritor valido. Intentelo de nuevo."<<endl;
        cout << "Ingrese el numero del escritor que quiere modificar: ";
        cin >> posicion;
    }
    cout << "\nPuede modificar el anio de fallecimiento \n";

    anio_fallecimiento = input_numero("Ingrese el anio de fallecimiento");

    int anio_nacimiento = escritores->obtener_dato_en(posicion)->obtener_anio_nacimiento();
    if (anio_nacimiento != ANIO_DESCONOCIDO){
        while (anio_fallecimiento < anio_nacimiento) {
            cout << "\nEl año de fallecimiento no puede ser menor que el año de nacimiento." << endl;
            anio_fallecimiento = input_numero("Ingrese el anio de fallecimiento");
        }
    }


    escritores->obtener_dato_en(posicion)->modificar_anio_fallecimiento(anio_fallecimiento);

    cout << "\n-- fecha de fallecimiento modificada QEPD --" << endl;

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::lectura_al_azar() {
    srand((unsigned int)time(nullptr));

    int numero = 1 + rand()%(lecturas->obtener_cantidad()-1);

    cout << "\nSe leerá la siguiente lectura, elegida al azar: "<< endl;
    lecturas->obtener_dato_en(numero)->mostrar();
    lecturas->obtener_dato_en(numero)->leer();

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

Escritor* Menu::nuevo_escritor (bool lectura){
    if (!lectura){
        cout << "NUEVO ESCRITOR \n" << endl;
    }

    Escritor* nuevo = NULL;

    string nuevo_nombre;
    cout << "Nombre del ";
    if(lectura){
        cout << "autor (ingrese ANONIMO para autores anonimos): ";
    }else{
        cout << "escritor: ";
    }
    cin.ignore();
    getline(cin, nuevo_nombre);

    if (nuevo_nombre != "ANONIMO"){
        bool escritor_existente = false;
        int i = 1;
        while (!escritor_existente &&
               (i <= escritores->obtener_cantidad())){
            nuevo = escritores->obtener_dato_en(i);
            i++;
            if (nuevo_nombre == nuevo->obtener_nombre_apellido()){
                escritor_existente = true;
            }
        }
        if (escritor_existente){
            cout << "\n" << "-- escritor reconocido --" << "\n" << endl;
            nuevo->mostrar();
        }else{
            string nacionalidad;

            cout << "Nacionalidad: ";
            cin >> nacionalidad;

            int anio_nacimiento = input_numero("Anio de nacimiento (En caso de no tener dato, ingrese 1)");
            if (anio_nacimiento == 1){
                anio_nacimiento = ANIO_DESCONOCIDO;
            }
            int anio_fallecimiento = input_numero("Anio de fallecimiento (En caso de no tener dato, ingrese 1)");
            if (anio_fallecimiento == 1){
                anio_fallecimiento = SIGUE_VIVO;            
            }

            if (anio_nacimiento != ANIO_DESCONOCIDO){
                while (anio_fallecimiento != SIGUE_VIVO && anio_fallecimiento < anio_nacimiento) {
                    cout << "\nEl año de fallecimiento no puede ser menor que el año de nacimiento." << endl;
                    anio_fallecimiento = input_numero("Anio de fallecimiento");
                }
            }

            nuevo = new Escritor(nuevo_nombre, nacionalidad, anio_nacimiento, anio_fallecimiento);
            escritores->alta(nuevo, escritores->obtener_cantidad() + 1);

            if(!lectura)
                cout << "\n -- Nuevo escritor agregado \n" << endl;
        }
    }

    return nuevo;

}

bool Menu::tipo_valido (string tipo){
    return (tipo == CUENTO ||
            tipo == POEMA ||
            tipo == NOVELA);
}

bool Menu::genero_valido(string genero){
    return (genero == "DRAMA" ||
            genero == "COMEDIA" ||
            genero == "FICCION" ||
            genero == "SUSPENSO" ||
            genero == "TERROR" ||
            genero == "ROMANTICA" ||
            genero == "HISTORICA");
}

Novela::Genero Menu::asignar_genero(){
    string genero_str;
    cout << "Genero de la novela ";
    cout << "(puede ser DRAMA, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA): ";
    cin >> genero_str;

    while (!genero_valido(genero_str)){
        cout << "Ese genero no existe. Intentelo de nuevo."<<endl;
        cin >> genero_str;
    }

    Novela::Genero genero;

    if(genero_str == "DRAMA")
        genero = Novela::DRAMA;
    else if(genero_str == "COMEDIA")
        genero = Novela::COMEDIA;
    else if(genero_str == "FICCION")
        genero = Novela::FICCION;
    else if(genero_str == "SUSPENSO")
        genero = Novela::SUSPENSO;
    else if(genero_str == "TERROR")
        genero = Novela::TERROR;
    else if(genero_str == "ROMANTICA")
        genero = Novela::ROMANTICA;
    else if (genero_str == "HISTORICA")
        genero = Novela::HISTORICA;


    return genero;
}

void Menu::cargar_nueva_lectura (){

    cout << "NUEVA LECTURA \n" << endl;
    Lectura* nueva_lectura;
    Escritor* autor = nuevo_escritor(true);

    string tipo;
    string titulo;
    int minutos;
    int anio_publicacion;

    cout << "Tipo de lectura ";
    cout << "(ingrese C para cuento, P para poema o N para novela): ";
    cin >> tipo;
    while (!tipo_valido(tipo)){
        cout << "-- tipo no valido ";
        cout << "(ingrese C para cuento, P para poema o N para novela)" << endl;
        cout << "Tipo de lectura: ";
        cin >> tipo;
    }
    cin.ignore();

    cout << "Titulo: ";
    getline(cin, titulo);

    minutos = input_numero("Minutos estimados que demanda la lectura");

    anio_publicacion = input_numero("Anio de publicacion");

    if (tipo == CUENTO){
        cin.ignore();
        string titulo_libro;
        cout << "Libro en que esta publicado: ";
        getline(cin, titulo_libro);

        nueva_lectura = new Cuento(titulo, minutos, anio_publicacion,
                                   autor, titulo_libro);
    }else if (tipo == POEMA){
        int versos = input_numero("Cantidad de versos");

        nueva_lectura = new Poema(titulo, minutos, anio_publicacion,
                                  autor, versos);
    }else{
        Novela::Genero genero = asignar_genero();

        if (genero == Novela::HISTORICA){
            cin.ignore();
            string tema_aux;

            cout << "Breve indicacion sobre el tema historico que aborda: ";
            getline(cin, tema_aux);

            char* tema = new char [(int)tema_aux.length() + 1];
            for (int i = 0; i < (int)tema_aux.length() + 1; i++){
                tema[i] = tema_aux[i];
            }
            nueva_lectura = new Historica(titulo, minutos, anio_publicacion,
                                          autor, tema);
        }else{
            nueva_lectura = new Novela(titulo, minutos, anio_publicacion,
                                       autor, genero);
        }

    }

    int posicion = lecturas->obtener_cantidad();
    while (nueva_lectura->comparar(*(lecturas->obtener_dato_en(posicion))) == MENOR
           && posicion > 0){
        posicion--;
    }
    lecturas->alta(nueva_lectura, posicion + 1);

    cout << "\n" << "-- Nueva lectura agregada --" << endl;

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::agregar_escritor(){
    nuevo_escritor(false);

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::crear_cola() {


    while(!cola->cola_vacia()){
        cola->quitar();
    }


    int* orden = new int[lecturas->obtener_cantidad()-1];

    orden[0] = 1;

    for(int i = 2;i<lecturas->obtener_cantidad();i++){
        Lectura* lectura = lecturas->obtener_dato_en(i);
        orden[i-1] = i;
        int posicion = i - 1;
        int anterior = orden[posicion-1];

        while (lectura->comparar(*(lecturas->obtener_dato_en(anterior)),0) == MENOR && posicion > 0){
            orden[posicion-1] = i;
            orden[posicion] = anterior;
            posicion--;
            if (posicion>0)
                anterior = orden[posicion-1];
        }
    }


    for(int i = 0;i<(lecturas->obtener_cantidad()-1);i++){
        if(!(lecturas->obtener_dato_en(orden[i])->obtener_leida())) {
            cola->insertar_cola(new Lectura *(lecturas->obtener_dato_en(orden[i])));
        }
    }
    delete [] orden;
    cout<<"\nCola: "<<endl;
    cola->mostrar();

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

void Menu::leer_una_lectura() {
    if(cola->cola_vacia()){
        cout << "\nNo hay lecturas en la cola."<<endl;
    }
    else{
        cout<<"\nSe leerá la siguiente lectura: "<<endl;
        Lectura** primero = cola->obtener_primero();
        (*primero)->mostrar();
        (*primero)->leer();
        cola->quitar();
    }

    mensaje_para_volver_al_menu();
    ejecutar_menu();
}

Menu::~Menu() {
    delete cola;
    delete lecturas;
    delete escritores;
}
