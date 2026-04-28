#include <iostream>
#include <string>

using namespace std; 

struct tarjetaCred{
    int PAN;
    double dinero;
    string Titular;

    public: 
    /* yo aqui voy a recibir como entrada para modificar/crear 
    una tarjetaCred, con su _PAN ; _dinero ; _Titular ;
    */

    /* lo que se crea con esta funcion va a ser un string con los datos de
    tarjetaCred.
    */
        string toString() const {
            
        }   

};

/* ====  POSIBLE ENTRADA  ====
3
77777777777,1234.00,RENATO
88888888888,567890.00,PEPE
99999999999,123.00,JOSE
11111111111,2345.00,PAULA
*/

/* ====  POSIBLE ENTRADA  ====
Num. de clientes: 3
Los clientes son:
RENATO, PEPE, JOSE , MARIA
El que tiene mas dinero es: PEPE
*/

Operacion::Operacion(const string &linea) {
    set(linea);
}
/*
void Operacion::set(const std::string &linea) {
    const int NFIELDS = 3;

    string data;

    size_t pos, posn; // variables auxiliares usadas para inicializar los campos

    pos = 0; //PRIMERA POSICION
    for (int nfield = 0; nfield < NFIELDS; nfield++) {
        // Buscar coma en el string
        posn = linea.find(',', pos); // SEGUNDA POSICION
        if (posn != string::npos) { // rutina 
            data = linea.substr(pos, posn - pos); //COJE LO QUE BUSCA Y LO METE EN DATA
            pos = posn + 1; // INICIO SIGUIENTE PALABRA

            switch (nfield) {
                case 0:
                    if (data == "Inversion")
                        _tipo = Operacion::Inversion;
                    else if (data == "Aporte")
                        _tipo = Operacion::Aporte;
                    else 
                        _tipo = Operacion::Desinversion;
                    break;
                case 1:
                    _fecha = data;
                    break;
                case 2:
                    _concepto = data;
                    break;
        
            } // switch
        } // if
        else{   // Si no hay más comas, tomar el resto del string
            data = linea.substr(pos, linea.length() - pos);
            _importe = abs(stod(data));
        }
    } // for 
}*/






int main(int argc, char** argv){
    cout << "hola" << endl;
    
    return 0;
}


