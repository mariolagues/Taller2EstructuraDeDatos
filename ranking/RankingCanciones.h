#pragma once
#include "../estructuras/ListaCanciones.h"

class RankingCanciones {
private:
    Cancion* heap;
    int cantidad;
    int capacidad;

    void subir(int posicion);
    void bajar(int posicion);
    bool esMayor(Cancion a, Cancion b);

public:
    RankingCanciones(int capacidad);
    ~RankingCanciones();

    void insertar(Cancion cancion);
    Cancion extraerMaximo();

    void generarTop10(ListaCanciones& canciones, ListaCanciones& resultado);
};