#include <iostream>
#include "estructuras/ListaCanciones.h"
#include "archivos/ArchivoMusica.h"
#include "reproductor/Reproductor.h"

using namespace std;

int main() {
    ListaCanciones canciones;

    ArchivoMusica::cargarCanciones("../music_source.txt", canciones);

    Reproductor reproductor;
    reproductor.cargarCanciones(canciones);
    reproductor.iniciar();

    return 0;
}