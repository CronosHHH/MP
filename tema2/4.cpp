// 4. Declare una variable v como un array de 100 enteros. 
// Escriba un trozo de código que recorra el array y modifique 
// todos los enteros negativos cambiándolos de signo. 
// No se permite usar el operador [], es decir, el recorrido se efectuará 
// usando aritmética de punteros y el bucle se controlará mediante un 
// contador entero.

#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;


const int MAX_VAL = 100;

void escribir_aleatoriamente_array(int &array[]){
    for(int i=0; i<MAX_VAL; i++){
        v[i]=(rand() % 19) - 9;
    } 
}
void leer_array(const int &array){
    int *p;
    for( p=&array[0] ; p<&array[0]+MAX_VAL; p++){
        cout<<*p<<" ";
    }
}

int main(){
    int v[MAX_VAL];
    escribir_aleatoriamente_array(v);
    leer_array(v);
    return 0;
}

