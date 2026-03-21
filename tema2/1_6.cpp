// Dado un array de 10 elementos, haz un bucle que busque el maximo y el 
// mınimo (sin usar el operador[]). 
// Al acabar el bucle tendremos un puntero apuntando a cada uno de ellos.

#include <iostream>
using namespace std;

const int MAX_ELEM = 10;

int main(){
    int v[MAX_ELEM] = {13,12,5,2,4,6,65,4,23,4};
    int *pmax, *pmin;
    pmax = pmin = v; // es lo mismo que poner = &(v[0])
    for(int i=0; i<MAX_ELEM; i++){
        if(*(v+i)>*pmax) pmax = (v+i);
        if(*(v+i)<*pmin) pmin = (v+i);
    }
    cout << "\nEl valor max es: " << *pmax;
    cout << "\nEl valor min es: " << *pmin;
}

