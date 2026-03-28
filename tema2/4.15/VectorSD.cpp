
#include "VectorSD.h"

/*
_____________________________________________________

class VectorSD {

int *info; // array dinámico de int

int util; // nº de enteros actualmente en el array

int capacidad; // capacidad del array
};
_____________________________________________________ 

donde info es un puntero que mantiene la dirección de una secuencia de enteros, util indica el número de
componentes usados de la secuencia y capacidad indica el número de posiciones reservadas de la memoria
dinámica para almacenar la secuencia de datos. La siguiente figura muestra un ejemplo de este tipo de
representación. 

-> diagram.png

(a) Constructor sin parámetros que inicialice una variable de tipo VectorSD reservando 10 casillas de
memoria dinámica y ponga el número de componentes usadas a 0.
*/

// en c++11 se podria poner: 
// VectorSD::VectorSD() : VectorSD(10) {}

VectorSD::VectorSD () {
    _capacidad = 10;
    _util = 0;
    _info = new int[_capacidad];
}

/* 
(b) Constructor de la clase que inicialice una variable de tipo VectorSD reservando n casillas de memoria
dinámica y ponga el número de componentes usadas a 0.
*/

// en c++11 se podria poner: 
// VectorSD::VectorSD(int capacidad)
//    : _info(new int[capacidad]), _util(0), _capacidad(capacidad) {}

VectorSD::VectorSD (int n) {
    _capacidad = n;
    _util = 0;
    _info = new int[_capacidad];
}

/*
(c) Método que nos devuelva el dato (int) almacenado en una determinada posición (int).
*/

int VectorSD::getDato(int posicion) const {
    return _info[posicion]; // tambien se podira poner _info[posicion]
}

/* 
(d) Método que devuelva el número de datos guardados actualmente en un objeto VectorSD.
*/
int VectorSD::nElementos() const {
    return _util;
}

/* 
(e) Método que añada un nuevo dato a un objeto VectorSD. Considerar el caso de que la inclusión del
nuevo valor sobrepase el número de elementos reservados. En este caso, realojar el array reservando
el doble de posiciones. 
*/
void VectorSD::aniadir(int dato){
    
    if( _util >= _capacidad ) {

        //Redimensionar el array el doble de posiciones
        
        // condicion ? valor_si_true : valor_si_false
        int n = (_capacidad == 0) ? 1 : _capacidad * 2;

        // no se puede poner aux[] = new int[n];
        int *aux = new int[n];

        for(int i=0; i< _util; i++){
            aux[i] = _info[i];
        }
        
        delete [] _info;
        _info = aux;
        _capacidad = n;
    }

    _info[_util] = dato;
    _util++;

}

/* 
(f) Método que copie el objeto VectorSD recibido como parámetro en el objeto actual. La copia debe
reservar memoria para almacenar solo las componentes usadas del array dinámico del objeto recibido
por parámetro. Recuerde, que en caso de que el objeto ya contenga memoria dinámica reservada,
debe liberarla antes. 
*/

void VectorSD::copia(const VectorSD &vector){


    // lo que buscamos, basicamente es liberar la memoria en heap que esta sin usar
    // por eso no podemos hacer VectorSD = vector

    // la capacidad será el util;
    int nueva_capacidad = vector.nElementos();

    // el constructor hace     _info = new int[_capacidad]; con la nueva_capacidad
    int *aux = new int[nueva_capacidad];

    for(int i=0; i <nueva_capacidad; i++){
        aux[i] = vector.getDato(i);
    }


    delete [] _info; // por si habia memoria reservada antes
    _info = aux;

    _capacidad = nueva_capacidad;
    _util = nueva_capacidad;



}

/* 
(g) Método que libere la memoria reservada por un objeto VectorSD.
*/

void VectorSD::liberar(){
    delete [] _info;
    // Buena práctica: dejar el objeto en estado consistente tras liberar
    _info = nullptr;
    _util = 0;
    _capacidad = 0;
}

/* 
(h) Método para mostrar los elementos de un objeto VectorSD (separados por blancos) en un flujo de
salida. Este método tendrá la siguiente forma:
*/

void VectorSD::mostrar(std::ostream& flujo) const {
    for(int i=0; i<_util;i++){
        flujo << _info[i] << " ";
    }
    flujo<<"\n";
}

/* 
(i) Método que recibe un flujo de entrada y carga uno a uno los datos enteros que contiene, en el objeto
VectorSD hasta que llega al final de la entrada.
*/

void VectorSD::leer(std::istream& flujo){
    int dato;
    while(flujo>>dato){
        aniadir(dato);
    }
}