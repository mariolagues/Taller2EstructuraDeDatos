#pragma once
#include "NodoCancion.h"

class ListaCanciones {
private:
    NodoCancion* primero;
    NodoCancion* ultimo;
    int cantidad;

public:
    ListaCanciones();
    ~ListaCanciones();

    void mezclar();

    bool estaVacia();
    int getCantidad();

    void agregarFinal(Cancion cancion);
    void mostrar();

    Cancion obtenerPorPosicion(int posicion);
    Cancion obtenerPorId(int id);
    Cancion obtenerPrimero();

    void actualizarCancion(Cancion cancion);

    void eliminarPrimero();
    void eliminarPorPosicion(int posicion);
    void eliminarPorId(int id);
    void vaciar();

    void copiarDesde(ListaCanciones& otra);
};