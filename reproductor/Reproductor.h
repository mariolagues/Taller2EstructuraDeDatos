#pragma once
#include "../estructuras/ListaCanciones.h"
#include "../archivos/ArchivoMusica.h"
#include "../archivos/ArchivoEstado.h"

class Reproductor {
private:
    ListaCanciones cancionesRegistradas;
    ListaCanciones listaActual;
    ListaCanciones historial;
    void menuCancionesRegistradas();
    void agregarCancionNueva();
    void eliminarCancionPorPosicion(int posicion);
    void reproducirCancionPorPosicion(int posicion);
    void agregarCancionALista(int posicion);

    Cancion actual;

    bool tieneActual;
    bool reproduciendo;
    bool aleatorio;
    int repeticion; // 0 desactivado, 1 repetir una, 2 repetir todas

public:
    Reproductor();
    void cargarEstado();
    void guardarEstado();

    void cargarCanciones(ListaCanciones canciones);

    void iniciar();
    void mostrarMenu();

    void reproducirPausar();
    void pistaSiguiente();
    void pistaAnterior();

    void mostrarListaActual();
    void mostrarCancionesRegistradas();
    
    void menuListaActual();
    void saltarCancionListaActual(int posicion);

    string textoEstado();
    string textoModos();
};