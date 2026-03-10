#include <iostream>
#include <string>

class Pizza{
    private:
        std::string ingrediente1 = "nulo";
        std::string ingrediente2 = "nulo"; 

    public:
    
        //los getter parar poder obtener el dato privado
        //le ponemos const para recalcar que 
        //no modificamos el dato de ingrediente

        std::string getIngrediente1()const{
            return ingrediente1;
        }
        std::string getIngrediente2()const{
            return ingrediente2;
        }

        //los setter para poder modificar el dato privado
        void setIngrediente1(std::string _ingrediente1){
            ingrediente1 = _ingrediente1;
        }

        void setIngrediente2(std::string _ingrediente2){
            ingrediente2 = _ingrediente2;
        }

};


int main(){

    Pizza pizza1;

    // para sacar en pantalla los valores de la clase:
    //ESTO NO FUNCIONARIA:
    //std::cout << pizza1.ingrediente1 << "\n";    
    //std::cout << pizza1.ingrediente2 << "\n";

    std::cout << pizza1.getIngrediente1() << "\n";    
    std::cout << pizza1.getIngrediente2() << "\n";

    pizza1.setIngrediente1("peperoni");
    pizza1.setIngrediente2("tomate");

    std::cout << pizza1.getIngrediente1() << "\n";    
    std::cout << pizza1.getIngrediente2() << "\n";
    

    return 0;
}