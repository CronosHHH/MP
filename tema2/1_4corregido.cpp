#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

const int MAX_VAL = 100;

// Función para llenar el array (aquí usamos [] por comodidad, 
// lo importante es el procesamiento posterior)

//LO MAS IMPORTANTE
// En la declaración de parámetros, int* array y int array[] son equivalentes.
// En el cuerpo de la función, *array es igual a array[0], no a todo el array.

// int array[MAX_ELEM];
// se crea -> puntero a entero: int *ptr;
// ptr = &array[0]
// DONDE: 
// array[0] es quivalente a *array ( y a  *(&array[0])   ) 
// array es equivalente a &array[0]

// LA FUNCION RECIBE EL VALOR APUNTADO
void escribir_aleatoriamente_array(int *array) {
    for (int i = 0; i < MAX_VAL; i++) {
        *(array + i) = (rand() % 19) - 9; // Aritmética de punteros
    }
}

// CASO LA FUNCION RECIBE PUNTERO
void leer_array(const int *array) {
    for (int i = 0; i < MAX_VAL; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Semilla para números aleatorios reales
    int v[MAX_VAL];

    escribir_aleatoriamente_array(v);
    
    cout << "Array original:" << endl;
    leer_array(v);

    // --- BLOQUE SOLICITADO POR EL EJERCICIO ---
    // Recorrer y cambiar signo a negativos usando aritmética de punteros
    int *p = v; // Apuntamos al inicio del array
    for (int i = 0; i < MAX_VAL; i++) {
        if (*(p + i) < 0) {
            *(p + i) = -(*(p + i)); // Cambiamos el signo
        }
    }
    // ------------------------------------------

    cout << "\nArray modificado (sin negativos):" << endl;
    leer_array(v);

    return 0;
}