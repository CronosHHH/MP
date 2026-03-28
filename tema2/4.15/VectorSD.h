
#include <iostream>

#ifndef VECTORSH_H
#define VECTORSH_H

/* info es un puntero que mantiene la dirección de una secuencia de enteros, util indica el número de
componentes usados de la secuencia y capacidad indica el número de posiciones reservadas de la memoria
dinámica para almacenar la secuencia de datos. La siguiente figura muestra un ejemplo de este tipo de
representación. 

-> diagram.png

*/

class VectorSD {

    private:

int *_info; // array dinámico de int

int _util; // nº de enteros actualmente en el array

int _capacidad; // capacidad del array

    public:

/* Debemos construir este tipo de dato abstracto escribiendo los ficheros VectorSD.h y VectorSD.cpp.
Añadir a la clase los siguientes constructores y métodos:

(a) Constructor sin parámetros que inicialice una variable de tipo VectorSD reservando 10 casillas de
memoria dinámica y ponga el número de componentes usadas a 0.
*/

VectorSD ();

/* 
(b) Constructor de la clase que inicialice una variable de tipo VectorSD reservando n casillas de memoria
dinámica y ponga el número de componentes usadas a 0.
*/

VectorSD ( int n);

/*
(c) Método que nos devuelva el dato (int) almacenado en una determinada posición (int).
*/


int getDato(int posicion) const;

/* 
(d) Método que devuelva el número de datos guardados actualmente en un objeto VectorSD.
*/
int nElementos() const;

/* 
(e) Método que añada un nuevo dato a un objeto VectorSD. Considerar el caso de que la inclusión del
nuevo valor sobrepase el número de elementos reservados. En este caso, realojar el array reservando
el doble de posiciones. 
*/
void aniadir(int dato);

/* 
(f) Método que copie el objeto VectorSD recibido como parámetro en el objeto actual. La copia debe
reservar memoria para almacenar solo las componentes usadas del array dinámico del objeto recibido
por parámetro. Recuerde, que en caso de que el objeto ya contenga memoria dinámica reservada,
debe liberarla antes. 
*/

void copia(const VectorSD &vector);

/* 
(g) Método que libere la memoria reservada por un objeto VectorSD.
*/

void liberar();
/* 
(h) Método para mostrar los elementos de un objeto VectorSD (separados por blancos) en un flujo de
salida. Este método tendrá la siguiente forma:
*/

void mostrar(ostream& flujo);
/* 
(i) Método que recibe un flujo de entrada y carga uno a uno los datos enteros que contiene, en el objeto
VectorSD hasta que llega al final de la entrada.
*/

void leer(istream& flujo);

};

#endif // VECTORSH_H