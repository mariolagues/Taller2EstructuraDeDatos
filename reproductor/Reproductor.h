#pragma once
#include "../estructuras/ListaCanciones.h"
#include "../archivos/ArchivoMusica.h"
#include "../archivos/ArchivoEstado.h"
#include "../busqueda/BuscadorCanciones.h"

class Reproductor {
private:
    ListaCanciones cancionesRegistradas;
    ListaCanciones listaActual;
    ListaCanciones historial;

    Cancion actual;

    bool tieneActual;
    bool reproduciendo;
    bool aleatorio;
    int repeticion;

    void menuCancionesRegistradas();
    void agregarCancionNueva();
    void eliminarCancionPorPosicion(int posicion);
    void reproducirCancionPorPosicion(int posicion);
    void agregarCancionALista(int posicion);

    void registrarReproduccionActual();

    void menuBuscarCanciones();
    

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