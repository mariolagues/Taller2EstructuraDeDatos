#pragma once
#include <string>
using namespace std;

class ArtistaRanking {
private:
    string nombre;
    int reproducciones;

public:
    ArtistaRanking();
    ArtistaRanking(string nombre, int reproducciones);

    string getNombre();
    int getReproducciones();

    void aumentar(int cantidad);
};