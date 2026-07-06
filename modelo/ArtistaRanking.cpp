#include "ArtistaRanking.h"

ArtistaRanking::ArtistaRanking() {
    nombre = "";
    reproducciones = 0;
}

ArtistaRanking::ArtistaRanking(string nombre, int reproducciones) {
    this->nombre = nombre;
    this->reproducciones = reproducciones;
}

string ArtistaRanking::getNombre() {
    return nombre;
}

int ArtistaRanking::getReproducciones() {
    return reproducciones;
}

void ArtistaRanking::aumentar(int cantidad) {
    reproducciones += cantidad;
}