#include "ListaCanciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

ListaCanciones::ListaCanciones() {
    primero = nullptr;
    ultimo = nullptr;
    cantidad = 0;
}

ListaCanciones::~ListaCanciones() {
    vaciar();
}

bool ListaCanciones::estaVacia() {
    return primero == nullptr;
}

int ListaCanciones::getCantidad() {
    return cantidad;
}

void ListaCanciones::agregarFinal(Cancion cancion) {
    NodoCancion* nuevo = new NodoCancion(cancion);

    if (estaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }

    cantidad++;
}

void ListaCanciones::mostrar() {
    if (estaVacia()) {
        cout << "Vacia" << endl;
        return;
    }

    NodoCancion* actual = primero;
    int contador = 1;

    while (actual != nullptr) {
        cout << contador << ". " << actual->getDato().toString() << endl;
        actual = actual->getSiguiente();
        contador++;
    }
}

Cancion ListaCanciones::obtenerPorPosicion(int posicion) {
    NodoCancion* actual = primero;
    int contador = 1;

    while (actual != nullptr) {
        if (contador == posicion) {
            return actual->getDato();
        }

        actual = actual->getSiguiente();
        contador++;
    }

    return Cancion();
}

Cancion ListaCanciones::obtenerPorId(int id) {
    NodoCancion* actual = primero;

    while (actual != nullptr) {
        if (actual->getDato().getId() == id) {
            return actual->getDato();
        }

        actual = actual->getSiguiente();
    }

    return Cancion();
}

Cancion ListaCanciones::obtenerPrimero() {
    if (estaVacia()) {
        return Cancion();
    }

    return primero->getDato();
}

void ListaCanciones::actualizarCancion(Cancion cancion) {
    NodoCancion* actual = primero;

    while (actual != nullptr) {
        if (actual->getDato().getId() == cancion.getId()) {
            actual->setDato(cancion);
            return;
        }

        actual = actual->getSiguiente();
    }
}

void ListaCanciones::eliminarPrimero() {
    if (estaVacia()) {
        return;
    }

    NodoCancion* borrar = primero;

    if (primero == ultimo) {
        primero = nullptr;
        ultimo = nullptr;
    } else {
        primero = primero->getSiguiente();
        primero->setAnterior(nullptr);
    }

    delete borrar;
    cantidad--;
}

void ListaCanciones::eliminarPorPosicion(int posicion) {
    if (estaVacia() || posicion < 1 || posicion > cantidad) {
        return;
    }

    if (posicion == 1) {
        eliminarPrimero();
        return;
    }

    NodoCancion* actual = primero;
    int contador = 1;

    while (actual != nullptr && contador < posicion) {
        actual = actual->getSiguiente();
        contador++;
    }

    if (actual == nullptr) {
        return;
    }

    NodoCancion* anterior = actual->getAnterior();
    NodoCancion* siguiente = actual->getSiguiente();

    if (anterior != nullptr) {
        anterior->setSiguiente(siguiente);
    }

    if (siguiente != nullptr) {
        siguiente->setAnterior(anterior);
    }

    if (actual == ultimo) {
        ultimo = anterior;
    }

    delete actual;
    cantidad--;
}

void ListaCanciones::eliminarPorId(int id) {
    NodoCancion* actual = primero;
    int posicion = 1;

    while (actual != nullptr) {
        if (actual->getDato().getId() == id) {
            eliminarPorPosicion(posicion);
            return;
        }

        actual = actual->getSiguiente();
        posicion++;
    }
}

void ListaCanciones::vaciar() {
    while (!estaVacia()) {
        eliminarPrimero();
    }
}

void ListaCanciones::copiarDesde(ListaCanciones& otra) {
    vaciar();

    for (int i = 1; i <= otra.getCantidad(); i++) {
        Cancion c = otra.obtenerPorPosicion(i);
        agregarFinal(c);
    }
}

void ListaCanciones::mezclar() {
    if (cantidad <= 1) {
        return;
    }

    srand(time(nullptr));

    ListaCanciones nuevaLista;

    while (!estaVacia()) {
        int posicionAleatoria = rand() % cantidad + 1;

        Cancion c = obtenerPorPosicion(posicionAleatoria);
        nuevaLista.agregarFinal(c);

        eliminarPorPosicion(posicionAleatoria);
    }

    copiarDesde(nuevaLista);
}