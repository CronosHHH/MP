#include <iostream>
#include <string>

class Pizza{

    //Sino pongo public, por defecto sera "private" 
    public:
        std::string ingrediente1;
        std::string ingrediente2; 
        
}; // no olvidas el punto y coma al final de la clase

int main(){

    Pizza pizza1;

    pizza1.ingrediente1 = "peperoni";
    pizza1.ingrediente2 = "tomate";

    // para sacar en pantalla los valores de la clase:
    std::cout << pizza1.ingrediente1 << "\n";    
    std::cout << pizza1.ingrediente2 << "\n";

    return 0;
}