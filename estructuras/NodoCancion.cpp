#include "NodoCancion.h"

NodoCancion::NodoCancion(Cancion dato) {
    this->dato = dato;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Cancion NodoCancion::getDato() {
    return dato;
}

NodoCancion* NodoCancion::getSiguiente() {
    return siguiente;
}

NodoCancion* NodoCancion::getAnterior() {
    return anterior;
}

void NodoCancion::setSiguiente(NodoCancion* siguiente) {
    this->siguiente = siguiente;
}

void NodoCancion::setAnterior(NodoCancion* anterior) {
    this->anterior = anterior;
}