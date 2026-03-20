#include <iostream>
#include <string>

class Pizza{
    private:
        std::string ingrediente1;
        std::string ingrediente2; 

    public:

        //Pizza()= default;
        // si hago esto es que mejor no uso un constructor
        // ya que el constructor se usa para inicializar la clase
        // como a ti te venga en gana


        Pizza(const std::string& _ingrediente1, const std::string& _ingrediente2){
            // ingrediente1 = _ingrediente1; o mejor ->
            setIngrediente1(_ingrediente1);
            // ingrediente2 = _ingrediente2; o mejor ->
            setIngrediente2(_ingrediente2);
        }

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


    Pizza pizza1("queso", "jamón");

    std::cout << pizza1.getIngrediente1() << "\n";    
    std::cout << pizza1.getIngrediente2() << "\n";

    // para introducir los nuevos valores de la clase:
    //Antes haciamos:
    //pizza1.setIngrediente1("peperoni");
    //pizza1.setIngrediente2("tomate");
    //PERO ES mejor:
    pizza1.setIngrediente1("peperoni"); 
    pizza1.setIngrediente2("tomate");
    
    std::cout << pizza1.getIngrediente1() << "\n";    
    std::cout << pizza1.getIngrediente2() << "\n";
    

    return 0;
}