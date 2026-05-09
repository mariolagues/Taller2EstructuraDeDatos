#include "Reproductor.h"
#include <iostream>
using namespace std;

Reproductor::Reproductor() {
    tieneActual = false;
    reproduciendo = false;
    aleatorio = false;
    repeticion = 0;
}

void Reproductor::cargarCanciones(ListaCanciones canciones) {
    cancionesRegistradas.copiarDesde(canciones);
    listaActual.copiarDesde(cancionesRegistradas);
    cargarEstado();
}

void Reproductor::iniciar() {
    char opcion;
    bool salir = false;

    do {
        mostrarMenu();
        cout << "Ingrese opcion: ";
        cin >> opcion;

        opcion = toupper(opcion);

        if (opcion == 'W') {
            reproducirPausar();
            guardarEstado();
        } else if (opcion == 'E') {
            pistaSiguiente();
            guardarEstado();
        } else if (opcion == 'Q') {
            pistaAnterior();
            guardarEstado();
        } else if (opcion == 'A') {
            menuListaActual();
            guardarEstado();
        } else if (opcion == 'L') {
            menuCancionesRegistradas();
            guardarEstado();
        } else if (opcion == 'S') {
            aleatorio = !aleatorio;

            if (aleatorio) {
                listaActual.mezclar();
                cout << "Modo aleatorio activado. Lista mezclada." << endl;
            } else {
                cout << "Modo aleatorio desactivado." << endl;
            }

            guardarEstado();
        } else if (opcion == 'R') {
            repeticion++;
            guardarEstado();
            if (repeticion > 2) {
                repeticion = 0;
            }
        } else if (opcion == 'X') {
            salir = true;
            guardarEstado();
        } else {
            cout << "Opcion invalida" << endl;
        }

        cout << endl;

    } while (!salir);
}

void Reproductor::mostrarMenu() {
    cout << "-----------------------------" << endl;

    if (tieneActual) {
        cout << textoEstado() << textoModos() << ": " << actual.getNombre() << endl;
        cout << "Artista: " << actual.getArtista() << endl;
        cout << "Album: " << actual.getAlbum() << " [" << actual.getAnio() << "]" << endl;
    } else {
        cout << "Reproduccion Detenida" << endl;
    }

    cout << "Opciones:" << endl;
    cout << "W - Reproducir/Pausar" << endl;
    cout << "Q - Pista Anterior" << endl;
    cout << "E - Pista Siguiente" << endl;
    cout << "S - Activar/Desactivar modo aleatorio" << endl;
    cout << "R - Repeticion" << endl;
    cout << "A - Ver lista de reproduccion actual" << endl;
    cout << "L - Listado de canciones" << endl;
    cout << "X - Salir" << endl;
}

void Reproductor::reproducirPausar() {
    if (!tieneActual) {
        pistaSiguiente();
    } else {
        reproduciendo = !reproduciendo;
    }
}

void Reproductor::pistaSiguiente() {
    if (cancionesRegistradas.estaVacia()) {
        return;
    }

    if (repeticion == 1 && tieneActual) {
        reproduciendo = true;
        return;
    }

    if (tieneActual) {
        historial.agregarFinal(actual);
    }

    if (listaActual.estaVacia()) {
        if (repeticion == 2) { 
            listaActual.copiarDesde(cancionesRegistradas);

            if (aleatorio) {
                listaActual.mezclar();
            }
        } else {
            reproduciendo = false;
            tieneActual = false;
            return;
        }
    }

    actual = listaActual.obtenerPrimero();
    listaActual.eliminarPrimero();

    tieneActual = true;
    reproduciendo = true;
}

void Reproductor::pistaAnterior() {
    if (historial.estaVacia()) {
        return;
    }

    if (repeticion == 1 && tieneActual) {
        reproduciendo = true;
        return;
    }

    if (tieneActual) {
        listaActual.agregarFinal(actual);
    }

    int posUltima = historial.getCantidad();
    actual = historial.obtenerPorPosicion(posUltima);
    historial.eliminarPorPosicion(posUltima);

    tieneActual = true;
    reproduciendo = true;
}

void Reproductor::mostrarListaActual() {
    if (!tieneActual) {
        cout << "Actual: Reproduccion Detenida" << endl;
    } else {
        cout << "Actual" << textoModos() << ": " << actual.toString() << endl;
    }

    cout << "Lista de reproduccion actual:" << endl;
    listaActual.mostrar();
}

void Reproductor::mostrarCancionesRegistradas() {
    cout << "Canciones registradas:" << endl;
    cancionesRegistradas.mostrar();
}

string Reproductor::textoEstado() {
    if (reproduciendo) {
        return "Reproduciendo";
    }

    return "En pausa";
}

string Reproductor::textoModos() {
    string texto = "";

    if (aleatorio || repeticion != 0) {
        texto += " (";

        if (aleatorio) {
            texto += "S";
        }

        if (aleatorio && repeticion != 0) {
            texto += "-";
        }

        if (repeticion == 1) {
            texto += "R1";
        } else if (repeticion == 2) {
            texto += "RA";
        }

        texto += ")";
    }

    return texto;
}
void Reproductor::menuCancionesRegistradas() {
    string opcion;
    bool volver = false;

    do {
        cout << endl;
        cout << "Canciones registradas:" << endl;
        cancionesRegistradas.mostrar();

        cout << endl;
        cout << "Opciones:" << endl;
        cout << "R<num> - Reproducir cancion seleccionada" << endl;
        cout << "A<num> - Agregar cancion al final de la lista actual" << endl;
        cout << "N - Agregar nueva cancion" << endl;
        cout << "D<num> - Eliminar cancion seleccionada" << endl;
        cout << "V - Volver" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        char accion = toupper(opcion[0]);

        if (accion == 'V') {
            volver = true;
        } else if (accion == 'N') {
            agregarCancionNueva();
        } else {
            int numero = 0;

            if (opcion.length() > 1) {
                numero = stoi(opcion.substr(1));
            }

            if (accion == 'R') {
                reproducirCancionPorPosicion(numero);
                volver = true;
            } else if (accion == 'A') {
                agregarCancionALista(numero);
            } else if (accion == 'D') {
                eliminarCancionPorPosicion(numero);
            } else {
                cout << "Opcion invalida" << endl;
            }
        }

    } while (!volver);
}

void Reproductor::agregarCancionNueva() {
    string nombre;
    string artista;
    string album;
    string ubicacion;
    int anio;
    int duracion;

    cin.ignore();

    cout << "Nombre de la cancion: ";
    getline(cin, nombre);

    cout << "Artista: ";
    getline(cin, artista);

    cout << "Album: ";
    getline(cin, album);

    cout << "Anio: ";
    cin >> anio;

    cout << "Duracion en segundos: ";
    cin >> duracion;

    cin.ignore();

    cout << "Ubicacion del archivo: ";
    getline(cin, ubicacion);

    int nuevoId = cancionesRegistradas.getCantidad() + 1;

    Cancion nueva(nuevoId, nombre, artista, album, anio, duracion, ubicacion);

    cancionesRegistradas.agregarFinal(nueva);

    ArchivoMusica::guardarCanciones("../music_source.txt", cancionesRegistradas);

    cout << "Cancion agregada correctamente." << endl;
}

void Reproductor::eliminarCancionPorPosicion(int posicion) {
    if (posicion < 1 || posicion > cancionesRegistradas.getCantidad()) {
        cout << "Posicion invalida." << endl;
        return;
    }

    Cancion c = cancionesRegistradas.obtenerPorPosicion(posicion);
    cancionesRegistradas.eliminarPorPosicion(posicion);

    ArchivoMusica::guardarCanciones("../music_source.txt", cancionesRegistradas);

    cout << "Cancion eliminada: " << c.toString() << endl;
}

void Reproductor::reproducirCancionPorPosicion(int posicion) {
    if (posicion < 1 || posicion > cancionesRegistradas.getCantidad()) {
        cout << "Posicion invalida." << endl;
        return;
    }

    actual = cancionesRegistradas.obtenerPorPosicion(posicion);
    tieneActual = true;
    reproduciendo = true;

    listaActual.vaciar();

    for (int i = 1; i <= cancionesRegistradas.getCantidad(); i++) {
        if (i != posicion) {
            listaActual.agregarFinal(cancionesRegistradas.obtenerPorPosicion(i));
        }
    }
    if (aleatorio) {
        listaActual.mezclar();
    }

    cout << "Reproduciendo: " << actual.toString() << endl;
}

void Reproductor::agregarCancionALista(int posicion) {
    if (posicion < 1 || posicion > cancionesRegistradas.getCantidad()) {
        cout << "Posicion invalida." << endl;
        return;
    }

    Cancion c = cancionesRegistradas.obtenerPorPosicion(posicion);
    listaActual.agregarFinal(c);

    cout << "Cancion agregada a la lista actual: " << c.toString() << endl;
}
void Reproductor::cargarEstado() {
    bool existe = ArchivoEstado::cargarEstado("../status.cfg", cancionesRegistradas,
                                             actual, tieneActual, reproduciendo,
                                             aleatorio, repeticion);

    if (!existe) {
        guardarEstado();
    }
}

void Reproductor::guardarEstado() {
    ArchivoEstado::guardarEstado("../status.cfg", actual, tieneActual,
                                 reproduciendo, aleatorio, repeticion);
}
void Reproductor::menuListaActual() {
    string opcion;
    bool volver = false;

    do {
        cout << endl;

        if (tieneActual) {
            cout << "Actual" << textoModos() << ": " << actual.toString() << endl;
        } else {
            cout << "Actual: Reproduccion Detenida" << endl;
        }

        cout << "Lista de reproduccion actual:" << endl;
        listaActual.mostrar();

        cout << endl;
        cout << "Opciones:" << endl;

        if (!listaActual.estaVacia()) {
            cout << "S<num> - Saltar a la cancion seleccionada" << endl;
        }

        cout << "V - Volver al menu principal" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        char accion = toupper(opcion[0]);

        if (accion == 'V') {
            volver = true;
        } else if (accion == 'S') {
            if (opcion.length() <= 1) {
                cout << "Debe ingresar una posicion. Ejemplo: S2" << endl;
            } else {
                int posicion = stoi(opcion.substr(1));
                saltarCancionListaActual(posicion);
                guardarEstado();
                volver = true;
            }
        } else {
            cout << "Opcion invalida." << endl;
        }

    } while (!volver);
}
void Reproductor::saltarCancionListaActual(int posicion) {
    if (listaActual.estaVacia()) {
        cout << "La lista actual esta vacia." << endl;
        return;
    }

    if (posicion < 1 || posicion > listaActual.getCantidad()) {
        cout << "Posicion invalida." << endl;
        return;
    }

    if (tieneActual) {
        historial.agregarFinal(actual);
    }

    for (int i = 1; i < posicion; i++) {
        listaActual.eliminarPrimero();
    }

    actual = listaActual.obtenerPrimero();
    listaActual.eliminarPrimero();

    tieneActual = true;
    reproduciendo = true;

    cout << "Ahora reproduciendo: " << actual.toString() << endl;
}