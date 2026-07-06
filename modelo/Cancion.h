#pragma once

#include <string>
using namespace std;

class Cancion {
private:
    int id;
    string nombre;
    string artista;
    string album;
    int anio;
    int duracion;
    string ubicacion;

    int reproducciones;

public:
    Cancion();

    Cancion(int id, string nombre, string artista, string album,
             int anio, int duracion, string ubicacion,
             int reproducciones);

    int getId();
    string getNombre();
    string getArtista();
    string getAlbum();
    int getAnio();
    int getDuracion();
    string getUbicacion();

    int getReproducciones();

    void setReproducciones(int reproducciones);
    void aumentarReproducciones();

    string toString();
};