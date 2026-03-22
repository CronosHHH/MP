// ARCHIVO: ArrayDinamicoChar.h
// MODULO: Gestión de arrays dinámicos de caracteres

// g++ leerCaracteres.cpp ArrayDinamicoChar.cpp -o leerCaracteres

#ifndef ARRAYDINAMICOCHAR_H
#define ARRAYDINAMICOCHAR_H

#include <iostream>

// // (g) Estructura para la versión de Tipo de Dato Abstracto (Paso 1)
// struct VectorDinamicoChar {
//     char* arrayChar;
//     int nCaracteres;
// };

// // (h) Estructura con capacidad optimizada (Paso 2)
// struct VectorDinamicoChar {
//     char* arrayChar;
//     int nCaracteres;
//     int capacidad;
// };

// // (i) Versión con Clase (Paso 3)
// class VectorDinamicoChar {
//     char* arrayChar;
//     int nCaracteres;
//     int capacidad;
// };

// --- PROTOTIPOS DE LAS FUNCIONES ---

// // (a) inicializar: Inicializa el array dinámico y el contador.
void inicializar(char* &array, int& nchar);

// // (b) liberar: Libera la memoria dinámica ocupada por el array.
void liberar(char* &array, int& nchar);

// // (c) mostrar: Muestra en un flujo de salida los caracteres del array.
void mostrar(std::ostream& flujo, char* array, int nchar);

// // (d) redimensionar: Amplía el tamaño del array con un incremento determinado.
void redimensionar(char* &array, int& nchar, int incremento);

// // (e) aniadir: Añade un carácter al final, redimensionando previamente en +1.
void aniadir(char* &array, int& nchar, char c);

// // (f) leer: Lee caracteres uno a uno de un flujo y los guarda en el array.
void leer(std::istream& flujo, char* &array, int& nchar);

#endif