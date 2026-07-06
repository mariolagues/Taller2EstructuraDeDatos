#include "BuscadorCanciones.h"
#include <cctype>

string BuscadorCanciones::convertirMinuscula(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = tolower(texto[i]);
    }

    return texto;
}

bool BuscadorCanciones::contieneTexto(string textoCompleto, string textoBuscado) {
    textoCompleto = convertirMinuscula(textoCompleto);
    textoBuscado = convertirMinuscula(textoBuscado);

    return textoCompleto.find(textoBuscado) != string::npos;
}

void BuscadorCanciones::buscar(string texto, ListaCanciones& canciones, ListaCanciones& resultados) {
    resultados.vaciar();

    if (texto == "") {
        return;
    }

    for (int i = 1; i <= canciones.getCantidad(); i++) {
        Cancion c = canciones.obtenerPorPosicion(i);

        if (contieneTexto(c.getNombre(), texto) || contieneTexto(c.getArtista(), texto)) {
            resultados.agregarFinal(c);
        }
    }
}