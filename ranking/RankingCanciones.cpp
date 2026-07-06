#include "RankingCanciones.h"

RankingCanciones::RankingCanciones(int capacidad) {
    this->capacidad = capacidad;
    this->cantidad = 0;
    this->heap = new Cancion[capacidad + 1];
}

RankingCanciones::~RankingCanciones() {
    delete[] heap;
}

bool RankingCanciones::esMayor(Cancion a, Cancion b) {
    if (a.getReproducciones() > b.getReproducciones()) {
        return true;
    }

    if (a.getReproducciones() < b.getReproducciones()) {
        return false;
    }

    if (a.getNombre() < b.getNombre()) {
        return true;
    }

    if (a.getNombre() > b.getNombre()) {
        return false;
    }

    return a.getArtista() < b.getArtista();
}

void RankingCanciones::insertar(Cancion cancion) {
    if (cantidad >= capacidad) {
        return;
    }

    cantidad++;
    heap[cantidad] = cancion;
    subir(cantidad);
}

void RankingCanciones::subir(int posicion) {
    while (posicion > 1) {
        int padre = posicion / 2;

        if (esMayor(heap[posicion], heap[padre])) {
            Cancion aux = heap[posicion];
            heap[posicion] = heap[padre];
            heap[padre] = aux;

            posicion = padre;
        } else {
            break;
        }
    }
}

Cancion RankingCanciones::extraerMaximo() {
    if (cantidad == 0) {
        return Cancion();
    }

    Cancion mayor = heap[1];

    heap[1] = heap[cantidad];
    cantidad--;

    bajar(1);

    return mayor;
}

void RankingCanciones::bajar(int posicion) {
    while (true) {
        int izquierdo = posicion * 2;
        int derecho = posicion * 2 + 1;
        int mayor = posicion;

        if (izquierdo <= cantidad && esMayor(heap[izquierdo], heap[mayor])) {
            mayor = izquierdo;
        }

        if (derecho <= cantidad && esMayor(heap[derecho], heap[mayor])) {
            mayor = derecho;
        }

        if (mayor != posicion) {
            Cancion aux = heap[posicion];
            heap[posicion] = heap[mayor];
            heap[mayor] = aux;

            posicion = mayor;
        } else {
            break;
        }
    }
}

void RankingCanciones::generarTop10(ListaCanciones& canciones, ListaCanciones& resultado) {
    resultado.vaciar();

    for (int i = 1; i <= canciones.getCantidad(); i++) {
        insertar(canciones.obtenerPorPosicion(i));
    }

    int limite = 10;

    if (canciones.getCantidad() < 10) {
        limite = canciones.getCantidad();
    }

    for (int i = 1; i <= limite; i++) {
        resultado.agregarFinal(extraerMaximo());
    }
}