/**

Haz un programa que lea de la entrada est ́andar el n ́umero de elementos que tendr ́a un
array de enteros, y dos enteros para el rango (m ́ınimo, m ́aximo) de posibles valores que
tomar ́an los elementos del array. 

El programa rellenar ́a el array con n ́umeros aleatorios
enteros en el rango proporcionado, y posteriormente lo mostrar ́a en la salida est ́andar. El
programa contendr ́a las siguientes funciones:

La funci ́on main para probar que todo funciona de forma correcta.
La funci ́on imprimirArray para mostrar en la salida est ́andar el n ́umero de elementos
(y un salto de l ́ınea a continuaci ́on) y los elementos de un array de enteros (separados
por espacios en blanco).
La funci ́on generarArray que recibe un array de enteros, el n ́umero de elementos a
usar y un rango de valores (m ́ınimo, m ́aximo) y lo rellena con n ́umeros aleatorios en
el rango proporcionado.
**/

/*

Para el problema necesitamos generar números aleatorios en un rango específico. 
Para esto, podemos usar la función rand()
Y para que ese numero se ajuste a un numero ENTERO entre el min y el max, 
podemos usar la siguiente fórmula:
int numero_aleatorio = min + rand() % (max - min + 1);

si sabemos que % 6 siempre dará un resultado entre 0 y 5.
ya que el resto de dividir por 6 solo puede ser 0, 1, 2, 3, 4 o 5.



*/

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

using namespace std;

const int TAMANO_MAX = 100;


void generarArray(int numeros[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        numeros[i] = min + rand() % (max - min + 1);
    }
}

void imprimirArray(int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
}

int main() {

    // Semilla para generar números aleatorios diferentes cada vez
    srand(time(0));

    int numeros[TAMANO_MAX];
    int n, min, max;

    cout << "Introduce numero de elementos: ";
    cin >> n;
    cout << "Introduce rango (minimo y maximo): ";
    cin >> min >> max;

    generarArray(numeros, n, min, max);
    imprimirArray(numeros, n);

    return 0;
}