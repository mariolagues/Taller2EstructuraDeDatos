#include "ArchivoEstado.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void ArchivoEstado::guardarEstado(string nombreArchivo, Cancion actual, bool tieneActual,
                                  bool reproduciendo, bool aleatorio, int repeticion) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo guardar status.cfg" << endl;
        return;
    }

    if (tieneActual) {
        archivo << "ACTUAL=" << actual.getId() << endl;
    } else {
        archivo << "ACTUAL=0" << endl;
    }

    archivo << "REPRODUCIENDO=" << reproduciendo << endl;
    archivo << "ALEATORIO=" << aleatorio << endl;
    archivo << "REPETICION=" << repeticion << endl;

    archivo.close();
}

bool ArchivoEstado::cargarEstado(string nombreArchivo, ListaCanciones& canciones,
                                 Cancion& actual, bool& tieneActual,
                                 bool& reproduciendo, bool& aleatorio, int& repeticion) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        return false;
    }

    string linea;
    int idActual = 0;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string parametro;
        string valor;

        getline(ss, parametro, '=');
        getline(ss, valor);

        if (parametro == "ACTUAL") {
            idActual = stoi(valor);
        } else if (parametro == "REPRODUCIENDO") {
            reproduciendo = stoi(valor) == 1;
        } else if (parametro == "ALEATORIO") {
            aleatorio = stoi(valor) == 1;
        } else if (parametro == "REPETICION") {
            repeticion = stoi(valor);
        }
    }

    archivo.close();

    if (idActual > 0) {
        actual = canciones.obtenerPorId(idActual);

        if (actual.getId() != 0) {
            tieneActual = true;
        } else {
            tieneActual = false;
            reproduciendo = false;
        }
    } else {
        tieneActual = false;
        reproduciendo = false;
    }

    return true;
}