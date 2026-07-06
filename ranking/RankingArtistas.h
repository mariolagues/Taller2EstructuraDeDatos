#pragma once
#include "../estructuras/ListaCanciones.h"
#include "../modelo/ArtistaRanking.h"

class RankingArtistas {
private:
    ArtistaRanking* artistas;
    int cantidadArtistas;
    int capacidad;

    ArtistaRanking* heap;
    int cantidadHeap;

    int buscarArtista(string nombre);
    bool esMayor(ArtistaRanking a, ArtistaRanking b);

    void insertarHeap(ArtistaRanking artista);
    ArtistaRanking extraerMaximo();
    void subir(int posicion);
    void bajar(int posicion);

public:
    RankingArtistas(int capacidad);
    ~RankingArtistas();

    void generarTop10(ListaCanciones& canciones, ArtistaRanking resultado[], int& cantidadResultado);
};