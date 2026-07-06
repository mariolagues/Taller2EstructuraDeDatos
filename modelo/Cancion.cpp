#include "Cancion.h"

Cancion::Cancion() {
    id = 0;
    nombre = "";
    artista = "";
    album = "";
    anio = 0;
    duracion = 0;
    ubicacion = "";
    reproducciones = 0;
}

Cancion::Cancion(int id, string nombre, string artista, string album,
                 int anio, int duracion, string ubicacion,
                 int reproducciones) {

    this->id = id;
    this->nombre = nombre;
    this->artista = artista;
    this->album = album;
    this->anio = anio;
    this->duracion = duracion;
    this->ubicacion = ubicacion;
    this->reproducciones = reproducciones;
}

int Cancion::getId() {
    return id;
}

string Cancion::getNombre() {
    return nombre;
}

string Cancion::getArtista() {
    return artista;
}

string Cancion::getAlbum() {
    return album;
}

int Cancion::getAnio() {
    return anio;
}

int Cancion::getDuracion() {
    return duracion;
}

string Cancion::getUbicacion() {
    return ubicacion;
}

int Cancion::getReproducciones() {
    return reproducciones;
}

void Cancion::setReproducciones(int reproducciones) {
    this->reproducciones = reproducciones;
}

void Cancion::aumentarReproducciones() {
    reproducciones++;
}

string Cancion::toString() {
    return nombre + " - " + artista;
}