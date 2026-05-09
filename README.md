# Reproductor de Música en C++

## Integrantes
- Mario Luis Lagues PAez

## Descripción
Aplicación de consola desarrollada en C++ para simular un reproductor de música.  
El programa carga canciones desde `music_source.txt`, permite reproducir, pausar, avanzar, retroceder, ver la lista actual, agregar/eliminar canciones y guardar el estado en `status.cfg`.

## Funcionalidades
- Cargar canciones desde archivo.
- Mostrar canciones registradas.
- Reproducir/pausar canción actual.
- Avanzar y retroceder pista.
- Ver lista de reproducción actual.
- Agregar canciones nuevas.
- Eliminar canciones.
- Modo aleatorio.
- Repetición de una canción o de toda la lista.
- Guardar estado del reproductor.

## Estructura del proyecto
```text
modelo/
  Cancion.h
  Cancion.cpp

estructuras/
  NodoCancion.h
  NodoCancion.cpp
  ListaCanciones.h
  ListaCanciones.cpp

archivos/
  ArchivoMusica.h
  ArchivoMusica.cpp
  ArchivoEstado.h
  ArchivoEstado.cpp

reproductor/
  Reproductor.h
  Reproductor.cpp

main.cpp
music_source.txt
status.cfg
