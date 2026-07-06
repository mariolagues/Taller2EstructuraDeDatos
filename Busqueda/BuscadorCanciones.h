#pragma once
#include "../estructuras/ListaCanciones.h"
#include <string>
using namespace std;

class BuscadorCanciones {
public:
    static void buscar(string texto, ListaCanciones& canciones, ListaCanciones& resultados);

private:
    static string convertirMinuscula(string texto);
    static bool contieneTexto(string textoCompleto, string textoBuscado);
};