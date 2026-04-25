////////////////////////////////////////////////////////////////////////////
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Operaciones bancarias
////////////////////////////////////////////////////////////////////////////

#ifndef OPERACION_H
#define OPERACION_H

#include <iostream>
#include <string>
#include <cmath>

class Operacion {
public:
    enum IDA { ///< enumerado con los posibles tipos de operación
        Inversion,
        Desinversion,
        Aporte
    };
private:

//    enum IDA : int { ///< enumerado, que indica la correspondencia con
//        ///< valor numérico. Toma 3 posibles valores
//        Inversion = 0,
//        Desinversion = 1,
//        Aporte = 2
//    };
    IDA _tipo; ///< identificador del tipo de operación 
    std::string _fecha; ///<  fecha en formato con año/mes/dia
    std::string _concepto; ///<  descripción del concepto de la operación 
    double _importe; ///<  importe en euros de la operacion, es positivo
    static const std::string OPERACION_XDEFECTO; ///<  operación por defecto
public:
    /**
     * @brief Constructor que crea una Operacion con los valores 
     * extraídos de línea (un string con el formato adecuado). 
     * @pre: se considera que linea es correcta, con un valor asignado 
     * a cada campo y separados por comas.
     * @param linea cadena de la que se extraen los cuatro campos. linea toma
     * un valor por defecto, el valor de la cadena static OPERACION_XDEFECTO.
     */
    Operacion(const std::string &linea = OPERACION_XDEFECTO);
    
    /**
     * Devuelve el valor del tipo de Operacion.
     * @return el valor del tipo de Operacion (Inversion, Desinversion o Aporte)
     */
    IDA getTipo() const;
    
    /**
     * Devuelve el concepto de la Operacion
     * @return Un string con el concepto de la Operacion
     */
    std::string getConcepto() const;
    
    /**
     * Devuelve la fecha de la Operacion
     * @return Un string con la fecha de la Operacion
     */
    std::string getFecha() const;
    
    /**
     * Devuelve el importe de la Operacion. El valor del importe puede 
     * ser positivo o negativo. Solo si la operación es de inversión, el valor
     * devuelto es negativo
     * @return un valor con el importe positivo o negativo.
     */
    double getImporte() const;
    
    /**
     * @brief Establece valores para cada uno de los campos de esta Operacion 
     * extraídos de linea, un string con el formato adecuado. 
     * @pre: se considera que la linea es correcta con un valor asignado 
     * a cada campo y separados por comas.
     * @param linea cadena de la que se extraen los cuatro campos.
     */
    void set(const std::string &linea);
    
    /**
     * @brief Devuelve un string obtenido como concatenación de cada uno de 
     * los campos del objeto Operacion (cada uno de ellos tipo convertido a 
     * string) y separados por comas.
     * @return Una cadena con la concatenación de los datos de esta Operacion
     */
    std::string toString() const;
};

#endif /* OPERACION_H */

