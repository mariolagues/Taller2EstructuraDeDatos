#include "RankingArtistas.h"

RankingArtistas::RankingArtistas(int capacidad) {
    this->capacidad = capacidad;
    this->cantidadArtistas = 0;
    this->cantidadHeap = 0;

    artistas = new ArtistaRanking[capacidad + 1];
    heap = new ArtistaRanking[capacidad + 1];
}

RankingArtistas::~RankingArtistas() {
    delete[] artistas;
    delete[] heap;
}

int RankingArtistas::buscarArtista(string nombre) {
    for (int i = 0; i < cantidadArtistas; i++) {
        if (artistas[i].getNombre() == nombre) {
            return i;
        }
    }

    return -1;
}

bool RankingArtistas::esMayor(ArtistaRanking a, ArtistaRanking b) {
    if (a.getReproducciones() > b.getReproducciones()) {
        return true;
    }

    if (a.getReproducciones() < b.getReproducciones()) {
        return false;
    }

    return a.getNombre() < b.getNombre();
}

void RankingArtistas::insertarHeap(ArtistaRanking artista) {
    cantidadHeap++;
    heap[cantidadHeap] = artista;
    subir(cantidadHeap);
}

void RankingArtistas::subir(int posicion) {
    while (posicion > 1) {
        int padre = posicion / 2;

        if (esMayor(heap[posicion], heap[padre])) {
            ArtistaRanking aux = heap[posicion];
            heap[posicion] = heap[padre];
            heap[padre] = aux;

            posicion = padre;
        } else {
            break;
        }
    }
}

ArtistaRanking RankingArtistas::extraerMaximo() {
    if (cantidadHeap == 0) {
        return ArtistaRanking();
    }

    ArtistaRanking mayor = heap[1];

    heap[1] = heap[cantidadHeap];
    cantidadHeap--;

    bajar(1);

    return mayor;
}

void RankingArtistas::bajar(int posicion) {
    while (true) {
        int izquierdo = posicion * 2;
        int derecho = posicion * 2 + 1;
        int mayor = posicion;

        if (izquierdo <= cantidadHeap && esMayor(heap[izquierdo], heap[mayor])) {
            mayor = izquierdo;
        }

        if (derecho <= cantidadHeap && esMayor(heap[derecho], heap[mayor])) {
            mayor = derecho;
        }

        if (mayor != posicion) {
            ArtistaRanking aux = heap[posicion];
            heap[posicion] = heap[mayor];
            heap[mayor] = aux;

            posicion = mayor;
        } else {
            break;
        }
    }
}

void RankingArtistas::generarTop10(ListaCanciones& canciones, ArtistaRanking resultado[], int& cantidadResultado) {
    cantidadArtistas = 0;
    cantidadHeap = 0;
    cantidadResultado = 0;

    for (int i = 1; i <= canciones.getCantidad(); i++) {
        Cancion c = canciones.obtenerPorPosicion(i);

        int pos = buscarArtista(c.getArtista());

        if (pos == -1) {
            artistas[cantidadArtistas] = ArtistaRanking(c.getArtista(), c.getReproducciones());
            cantidadArtistas++;
        } else {
            artistas[pos].aumentar(c.getReproducciones());
        }
    }

    for (int i = 0; i < cantidadArtistas; i++) {
        insertarHeap(artistas[i]);
    }

    int limite = 10;

    if (cantidadArtistas < 10) {
        limite = cantidadArtistas;
    }

    for (int i = 0; i < limite; i++) {
        resultado[i] = extraerMaximo();
        cantidadResultado++;
    }
}