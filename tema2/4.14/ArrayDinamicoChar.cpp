// ARCHIVO: ArrayDinamicoChar.cpp
// IMPLEMENTACIÓN: Lógica de gestión de memoria dinámica

#include "ArrayDinamicoChar.h"
#include <iostream>

using namespace std;

// // (a) Implementa inicializar
void inicializar(char* &array, int& nchar) {
    // Tu código aquí: asigna nullptr y nchar a 0
    array = nullptr;
    nchar = 0;
}

// // (b) Implementa liberar
void liberar(char* &array, int& nchar) {
    // Tu código aquí: usa delete[] y resetea puntero y contador
    delete[] array;
    array = nullptr;
    nchar = 0;
}

// // (c) Implementa mostrar
void mostrar(ostream& flujo, char* array, int nchar) {
    // Tu código aquí: recorre el array y envía a 'flujo'
    for (int i=0; i<nchar ;i++){
        flujo = array[i];
    }
}

// // (d) Implementa redimensionar
void redimensionar(char* &array, int& nchar, int incremento) {
    // Tu código aquí: 
    // 1. Crea un array temporal con el nuevo tamaño
    // ~ La única forma de obtener un espacio de un tamaño que 
    // ~ decidimos mientras el programa corre es usando new.
    char* arraytemp = new char[nchar+incremento];

    // 2. Copia los datos antiguos al nuevo
    for(int i=0;i<nchar;i++){
        arraytemp[i]= array[i];
    }

    // 3. Libera el array antiguo
    delete[] array;

    // 4. Apunta el puntero original al nuevo array
    array = arraytemp;
    nchar += incremento;

}

// // (e) Implementa aniadir
void aniadir(char* &array, int& nchar, char c) {
    // Tu código aquí: llama a redimensionar(..., 1) y añade 'c' al final
    redimensionar(array, nchar, 1);
    // & Añade el carácter al final
    array[nchar-1]= c;
}

// // (f) leer (Dada por el enunciado)
void leer(istream& flujo, char* &array, int& nchar) {
    char caracter;
    liberar(array, nchar); // Empezamos de cero
    while(flujo.get(caracter)) {
        aniadir(array, nchar, caracter);
    }
}