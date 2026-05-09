#pragma once
#include "../modelo/Cancion.h"
#include "../estructuras/ListaCanciones.h"
#include <string>
using namespace std;

class ArchivoEstado {
public:
    static void guardarEstado(string nombreArchivo, Cancion actual, bool tieneActual,
                              bool reproduciendo, bool aleatorio, int repeticion);

    static bool cargarEstado(string nombreArchivo, ListaCanciones& canciones,
                             Cancion& actual, bool& tieneActual,
                             bool& reproduciendo, bool& aleatorio, int& repeticion);
};