#pragma once
#include "../modelo/Cancion.h"

class NodoCancion {
private:
    Cancion dato;
    NodoCancion* siguiente;
    NodoCancion* anterior;

public:
    NodoCancion(Cancion dato);

    Cancion getDato();
    NodoCancion* getSiguiente();
    NodoCancion* getAnterior();

    void setSiguiente(NodoCancion* siguiente);
    void setAnterior(NodoCancion* anterior);
};