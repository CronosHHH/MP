// ARCHIVO: ArrayDinamicoChar.cpp
// IMPLEMENTACIÓN: Lógica de gestión de memoria dinámica

#include "ArrayDinamicoChar.h"
#include <iostream>

using namespace std;

// // (a) Implementa inicializar
void inicializar(char* &array, int& nchar) {
    // Tu código aquí: asigna nullptr y nchar a 0
}

// // (b) Implementa liberar
void liberar(char* &array, int& nchar) {
    // Tu código aquí: usa delete[] y resetea puntero y contador
}

// // (c) Implementa mostrar
void mostrar(ostream& flujo, char* array, int nchar) {
    // Tu código aquí: recorre el array y envía a 'flujo'
}

// // (d) Implementa redimensionar
void redimensionar(char* &array, int& nchar, int incremento) {
    // Tu código aquí: 
    // 1. Crea un array temporal con el nuevo tamaño
    // 2. Copia los datos antiguos al nuevo
    // 3. Libera el array antiguo
    // 4. Apunta el puntero original al nuevo array
}

// // (e) Implementa aniadir
void aniadir(char* &array, int& nchar, char c) {
    // Tu código aquí: llama a redimensionar(..., 1) y añade 'c' al final
}

// // (f) leer (Dada por el enunciado)
void leer(istream& flujo, char* &array, int& nchar) {
    char caracter;
    liberar(array, nchar); // Empezamos de cero
    while(flujo.get(caracter)) {
        aniadir(array, nchar, caracter);
    }
}