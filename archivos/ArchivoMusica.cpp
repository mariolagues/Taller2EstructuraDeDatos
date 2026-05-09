#include "ArchivoMusica.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void ArchivoMusica::cargarCanciones(string nombreArchivo, ListaCanciones& lista) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se encontro el archivo " << nombreArchivo << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea)) {
        if (linea == "") {
            continue;
        }

        for (int i = 0; i < linea.length(); i++) {
            if (linea[i] == ';' || linea[i] == ':' || linea[i] == '-') {
                linea[i] = ',';
            }
        }

        stringstream ss(linea);
        string partes[7];
        string parte;
        int contador = 0;

        while (getline(ss, parte, ',') && contador < 7) {
            partes[contador] = parte;
            contador++;
        }

        if (contador == 7) {
            int id = stoi(partes[0]);
            string nombre = partes[1];
            string artista = partes[2];
            string album = partes[3];
            int anio = stoi(partes[4]);
            int duracion = stoi(partes[5]);
            string ubicacion = partes[6];

            Cancion c(id, nombre, artista, album, anio, duracion, ubicacion);
            lista.agregarFinal(c);
        }
    }

    archivo.close();
}
void ArchivoMusica::guardarCanciones(string nombreArchivo, ListaCanciones& lista) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo guardar el archivo " << nombreArchivo << endl;
        return;
    }

    for (int i = 1; i <= lista.getCantidad(); i++) {
        Cancion c = lista.obtenerPorPosicion(i);

        archivo << c.getId() << ","
                << c.getNombre() << ","
                << c.getArtista() << ","
                << c.getAlbum() << ","
                << c.getAnio() << ","
                << c.getDuracion() << ","
                << c.getUbicacion();

        if (i < lista.getCantidad()) {
            archivo << endl;
        }
    }

    archivo.close();
}