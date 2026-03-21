/*

Implemente las siguientes funciones sobre cadenas de caracteres estilo C usando 
aritmética de punteros(sin usar el operador []):

(a) Función compararCadenas que compara dos cadenas. Devuelve un valor negativo 
si la primera es más pequeña, positivo si es más grande y cero si son iguales.

(b) Función insertarCadena que inserte una cadena dentro de otra, en una posición dada.
Se supone que hay suficiente memoria en la cadena de destino.

Se supone que no es necesario pasar el tamaño de las cadenas (recordad que el 
carácter nulo delimita el final de la cadena) ---> caracter nulo = /n

*/

#include <iostream>
using namespace std;

// @values 0, 1, -1
int compararCadenas(char *ptr1, char *ptr2){
    while(*ptr1 != '\0' || *ptr1 != '\0'){
        ptr1++;
        ptr2++;
    }
    if(*ptr1 != '\0'){
        if(ptr2 != '\0'){
            return 0; // iguales
        } else return -1; // primera mas peq
    } else return 1; // primera mas grande
}

insertarCadena(char *ptr1, char *ptr2){
    char *vgrande, *vpeq;
    if (insertarCadena(*ptr1, *ptr2) = 1){ vgrande = ptr1 ; vpeq = ptr2;
    } else { vgrande = ptr2 ; vpeq = ptr1;
    };

    while (*vpeq != '\0'){
        
    }
}

int main(){

    char v = "hola, ";
    char w = "mundo"

    compararCadenas();
    insertarCadena();

    return 0;
}