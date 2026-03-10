#include <iostream>
#include <string>

class Pizza{
    public:
        std::string ingrediente1;
        std::string ingrediente2; 
    
        // creo el constructor con el mismo nombre que
        // la clase, y lo pongo en public
        Pizza(std::string a , std::string b){
            // si lo declarara con el mismo nombre 
            // ejem: (std::string ingrediente1 ; ...)
            // habría que poner:
            // this->ingrediente1 = ingrediente1;
            ingrediente1 = a;
            ingrediente2 = b;
        }
};


int main(){

    Pizza pizza1( "peperoni" , "tomate" );

    // para sacar en pantalla los valores de la clase:
    std::cout << pizza1.ingrediente1 << "\n";    
    std::cout << pizza1.ingrediente2 << "\n";

    return 0;
}