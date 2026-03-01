#include <iostream>

using namespace std;

const int MAX_ARRAY = 100;

// Prototipos ajustados al enunciado
void leerArray(int arr[], int dimension, int &n_util);
void imprimirArray(const int arr[], int n_util);
int busquedaSecuencialArray(int dato, const int arr[], int inicio, int fin);

int main() {
    int miArray[MAX_ARRAY];
    int n_util = 0;
    int numeroABuscar, posicion;

    // 1. Leer el array
    leerArray(miArray, MAX_ARRAY, n_util);

    // 2. Imprimir el array siguiendo el formato del enunciado
    cout << "Array leido:" << endl;
    imprimirArray(miArray, n_util);

    // 3. Solicitar número y buscar
    if (n_util > 0) {
        cout << "Introduce el numero entero a buscar: ";
        cin >> numeroABuscar;

        // Buscamos en todo el rango de elementos utiles (de 0 a n_util - 1)
        posicion = busquedaSecuencialArray(numeroABuscar, miArray, 0, n_util - 1);

        cout << "Posicion: " << posicion << endl;
    }

    return 0;
}

void leerArray(int arr[], int dimension, int &n_util) {
    // Corregido: Debe repetir mientras n_util sea mayor que la capacidad o menor que 0
    do {
        cout << "Numero de elementos del array? ";
        cin >> n_util;
    } while (n_util > dimension || n_util < 0);

    for (int i = 0; i < n_util; i++) {
        cout << "Elemento " << i << ": ";
        cin >> arr[i];
    }
}

void imprimirArray(const int arr[], int n_util) {
    // El enunciado pide mostrar el número de elementos y un salto de línea
    cout << n_util << endl;
    for (int i = 0; i < n_util; i++) {
        cout << arr[i] << (i == n_util - 1 ? "" : " ");
    }
    cout << endl;
}

// Corregido: El enunciado pide que RECIBA el dato y los índices, y DEVUELVA la posición
int busquedaSecuencialArray(int dato, const int arr[], int inicio, int fin) {
    for (int i = inicio; i <= fin; i++) {
        if (arr[i] == dato) {
            return i; // Retorna la posición si lo encuentra
        }
    }
    return -1; // Retorna -1 si no está
}