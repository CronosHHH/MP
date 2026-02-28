/*
 * ENUNCIADO:
 * Haz un programa que lea el número de elementos (como máximo 100) para un array y
 * un conjunto de números enteros y los guarde en un array e indique cuál es el menor de todos.
 * Debe incluirse un programa principal (main) para probar las funciones implementadas. 
 * El programa contendrá las siguientes funciones:
 * * - La función main para probar que todo funciona de forma correcta.
 * - La función imprimirArray para mostrar en la salida estándar el número de elementos 
 * (y un salto de línea a continuación) y los elementos de un array de enteros 
 * (separados por espacios en blanco).
 * - La función leerArray para leer de la entrada estándar los elementos de un array. 
 * Para ello recibe como parámetro un array de enteros, su dimensión y el número de 
 * elementos útiles finalmente leídos (este último parámetro se pasa por referencia).
 * - La función buscarMinimoArray que reciba un array de enteros, y dos enteros 
 * (índices inicial y final del array donde buscar el mínimo) y devuelva la posición 
 * donde se encuentra el mínimo elemento del subarray que comienza en la posición 
 * inicial y acaba en la posición final (ambas inclusive).
 */

#include <iostream>

using namespace std;

// Constante para el tamaño máximo del array
const int MAX_ELEMENTOS = 100;

// Prototipos de funciones
void leerArray(int arr[], int dimension, int &n_utiles);
void imprimirArray(const int arr[], int n_utiles);
int buscarMinimoArray(const int arr[], int inicio, int fin);

int main() {
    int miArray[MAX_ELEMENTOS];
    int n_utiles = 0;

    // 1. Leer los datos
    leerArray(miArray, MAX_ELEMENTOS, n_utiles);

    // 2. Imprimir el array leído
    cout << "Array leído: ";
    imprimirArray(miArray, n_utiles);

    // 3. Buscar el mínimo si hay elementos
    if (n_utiles > 0) {
        int posMinimo = buscarMinimoArray(miArray, 0, n_utiles - 1);
        cout << "Mínimo: " << miArray[posMinimo] << endl;
    }

    return 0;
}

/**
 * Lee el número de elementos y cada uno de los valores del array.
 * El parámetro n_utiles se pasa por referencia para actualizar el valor original.
 */
void leerArray(int arr[], int dimension, int &n_utiles) {
    cout << "Número de elementos: ";
    cin >> n_utiles;

    // Validación para no exceder la dimensión máxima
    if (n_utiles > dimension) {
        n_utiles = dimension;
    }

    for (int i = 0; i < n_utiles; i++) {
        cout << "Elemento " << i << ": ";
        cin >> arr[i];
    }
}

/**
 * Muestra los elementos del array en la salida estándar.
 */
void imprimirArray(const int arr[], int n_utiles) {
    for (int i = 0; i < n_utiles; i++) {
        cout << arr[i] << (i == n_utiles - 1 ? "" : " ");
    }
    cout << endl;
}

/**
 * Busca la posición del valor mínimo en un rango dado.
 * Devuelve el índice del elemento.
 */
int buscarMinimoArray(const int arr[], int inicio, int fin) {
    int posMin = inicio;

    for (int i = inicio + 1; i <= fin; i++) {
        if (arr[i] < arr[posMin]) {
            posMin = i;
        }
    }

    return posMin;
}