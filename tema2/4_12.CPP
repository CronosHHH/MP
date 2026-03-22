// 12. Describa la salida del siguiente programa:

#include <iostream>

using namespace std;

int main () {
    int *p1, *p2;
    
    // Se reserva memoria para un entero. Digamos que es la Dirección A.
    p1 = new int;
    
    // El valor en la Dirección A es 42.
    *p1 = 42;

    // p2 ahora apunta también a la Dirección A.
    p2 = p1;

    cout << *p1 << " y " << *p2 << endl; //salen iguales

    // Se cambia el valor en la Dirección A a 53. 
    // Como p1 sigue apuntando ahí, él también "ve" el cambio.
    *p2 = 53;
    cout << *p1 << " y " << *p2 << endl; // Salida 2: 53 y 53

    // Se reserva un nuevo espacio de memoria. 
    // Digamos que es la Dirección B. p1 ahora apunta a B.
    p1 = new int;
    *p1 = 88; // El valor en la Dirección B es 88.
    cout << *p1 << " y " << *p2 << endl; // Salida 3: 88 y 53
    // p2 sigue apuntando a la Dirección A, que todavía tiene el valor 53.

    return 0;
}