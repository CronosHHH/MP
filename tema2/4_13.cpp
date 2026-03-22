// Dadas las siguientes declaraciones
#include <iostream>

struct Electrica {
    char corriente[30];
    int voltios;
}

int main(){

Electrica *p = new Electrica(), *q = new Electrica();

//se pide averiguar qu ́e hacen cada una de las siguientes sentencias. ¿Hay alguna inv ́alida?
//a. 
strcpy(p->corriente,"ALTERNA"); 
//b.
p->voltios = q->voltios; // (*p).voltios mismo valor que (q*).voltios
//c. 
*p = *q; 
//Se copian todos los valores de los campos de q en el objeto apuntado por p.

//e. 
strcpy(p->corriente,"ALTA");
//Similar a la (a), sobreescribe el contenido de corriente con "ALTA".

//f.
p->corriente = q->voltios;
// MALLLLL
// Intenta asignar un entero (int) a un array de caracteres (char[30]). 
// Los arrays no son "asignables" directamente de esta forma.

//g. 
p = 54;
// MALLLLL
// Intenta asignar una dirección de memoria absoluta (entero) a un puntero 
// de tipo Electrica*. Requiere un cast explícito y suele ser una mala 
// práctica.

//d. 
p = q; 
// p ahora apunta a la misma dirección de memoria que q. Se pierde la 
// referencia al objeto original de p (fuga de memoria).

//h. 
*q = p;
// MALLLLLL
// Intenta asignar un puntero (Electrica*) a un objeto desreferenciado 
// (Electrica). Los tipos no coinciden.
}
