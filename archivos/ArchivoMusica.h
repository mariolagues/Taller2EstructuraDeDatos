#pragma once
#include "../estructuras/ListaCanciones.h"
#include <string>
using namespace std;

class ArchivoMusica {
public:
    static void cargarCanciones(string nombreArchivo, ListaCanciones& lista);
    static void guardarCanciones(string nombreArchivo, ListaCanciones& lista);
};