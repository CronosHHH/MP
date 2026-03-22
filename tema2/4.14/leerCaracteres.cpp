// PROGRAMA: leerCaracteres.cpp
// OBJETIVO: Leer caracteres de un fichero o entrada estándar y guardarlos en un array dinámico.

#include <iostream>
#include <fstream> 
#include "ArrayDinamicoChar.h"

using namespace std;

int main(int argc, char* argv[]) {
    char* arraychar;
    int nCaracteres;

    // (a) Inicializar el array
    inicializar(arraychar, nCaracteres);

    if (argc == 1) {
        // Leer de la entrada estándar (cin)
        leer(cin, arraychar, nCaracteres);
    } else {
        // Leer del fichero pasado como argumento
        ifstream flujo;
        flujo.open(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
            return 1;
        }
        leer(flujo, arraychar, nCaracteres);
        flujo.close();
    }

    // (c) Mostrar el contenido
    mostrar(cout, arraychar, nCaracteres);

    // (b) Liberar memoria
    liberar(arraychar, nCaracteres);

    return 0;
}