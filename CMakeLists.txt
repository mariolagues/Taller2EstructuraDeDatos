cmake_minimum_required(VERSION 4.2)
project(Taller1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller1 main.cpp
        modelo/Cancion.h
        modelo/Cancion.cpp
        estructuras/NodoCancion.h
        estructuras/NodoCancion.cpp
        estructuras/ListaCanciones.h
        estructuras/ListaCanciones.cpp
        archivos/ArchivoMusica.h
        archivos/ArchivoMusica.cpp
        reproductor/Reproductor.h
        reproductor/Reproductor.cpp
        archivos/ArchivoEstado.h
        archivos/ArchivoEstado.cpp)
