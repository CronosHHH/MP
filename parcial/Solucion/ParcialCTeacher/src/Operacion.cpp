////////////////////////////////////////////////////////////////////////////
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autores: acid.ugr.es  acu.ugr.es
////////////////////////////////////////////////////////////////////////////

#include "Operacion.h"
using namespace std;

const std::string Operacion::OPERACION_XDEFECTO("Aporte,2025/04/23,DESCONOCIDO,0");

Operacion::Operacion(const string &linea) {
    set(linea);
}

Operacion::IDA Operacion::getTipo() const {
    return _tipo;
}

std::string Operacion::getConcepto() const {
    return _concepto;
}

std::string Operacion::getFecha() const {
    return _fecha;
}

double Operacion::getImporte() const {
    double importe = _importe;
    if (_tipo == Operacion::Inversion) // en caso de Inversion 
                                       // importe visible es negativo
        importe = -_importe;
    return importe;
}

void Operacion::set(const std::string &linea) {
    const int NFIELDS = 4;
    size_t pos, posn; // variables auxiliares usadas para inicializar los campos
    string data;
    pos = 0;
    for (int nfield = 0; nfield < NFIELDS; nfield++) {
        posn = linea.find(',', pos); // Buscar coma en el string
        if (posn != string::npos) {
            data = linea.substr(pos, posn - pos);
            pos = posn + 1;
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
}

string Operacion::toString() const {
    string result;
    result = "Aporte,";
    if (_tipo == Operacion::Inversion)
        result = "Inversion,";
    else if (_tipo == Operacion::Desinversion)
        result = "Desinversion,";
    result += _fecha + "," + _concepto + "," + std::to_string(getImporte());
    return result;
}


