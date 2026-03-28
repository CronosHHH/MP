/* Queremos hacer un programa (mostrar.cpp) que lea los números enteros que tenemos almacenados en
un fichero de texto pasado al programa como argumento de main() (o bien de la entrada estándar si no
se pasa tal argumento) y que los cargue en un array dinámico VectorSD. 

El código de la función main()
se da a continuación.
*/

#include <iostream>
#include <fstream> // ifstream
#include "VectorSD.h"

using namespace std;

int main(int argc, char* argv[])
{
VectorSD v;
if (argc==1)
v.leer(cin);
else {
ifstream flujo;
flujo.open(argv[1]);
if (!flujo) {
    cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
return 1;
}
v.leer(flujo);
flujo.close();
}
v.mostrar(cout);
v.liberar(); // Libera la memoria dinámica reservada
}

/*  Como puede verse, el programa puede ser ejecutado de dos formas:
(a) Dando un argumento de entrada a main con el nombre del fichero de texto:
prompt> ./mostrar datos.txt
7 4 4 -3 13 16 16 -6 9 21
(b) Leyendo los datos de la entrada estándar:
prompt> cat datos.txt | ./mostrar
7 4 4 -3 13 16 16 -6 9 21
*/