///////////////////////////////////////////////////////////////////////////
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
////////////////////////////////////////////////////////////////////////////

/** 
 * @file main.cpp
 * @author: 
 * Created on 9 de abril de 2025, 13:30
 */

/**
 * 
La empresa Unicornio realiza una serie de Operaciones de inversión, 
desinversión y aporte a lo largo de un determinado periodo de tiempo. Cada una
de estas operaciones resta o suma dinero al capital disponible (liquidez) de la 
empresa. El capital disponible es cero al inicio del periodo de tiempo.

Una operación tiene un tipo (inversión, desinversión o aporte), 
una fecha, un concepto y un importe que es siempre almacenado internamente 
(en un objeto de la clase Operacion) con un valor positivo. 
  - Una operación de inversión resta dinero al capital disponible.
  - Una operación de desinversión suma dinero al capital disponible.
  - Una operación de aporte suma dinero al capital disponible.
 
Al inicio de cada periodo de tiempo, se establece un capital mínimo, que es 
la liquidez que la empresa no tiene permitido superar inferiormente cuando 
va a realizar una operación de inversión. 

El objetivo de la función main() es leer de la entrada estándar las operaciones 
de un determinado periodo de tiempo, guardándolas en un vector dinámico 
(vectorOperaciones) de tipo Operacion, ejecutar aquellas que cumplan con la 
restricción de no dejar el capital disponible por debajo del mínimo, y mover a 
otro vector dinámimo de operaciones pendientes, vectorPendientes, aquellas 
operaciones que no se pudieron ejecutar por la anterior restricción. El programa 
mostrará información de las operaciones realizadas.
Se dispone pues de dos vectores dinámicos de operaciones, vectorOperaciones y  
vectorPendientes, y dos enteros, nOperaciones y nPendientes, que indican 
respectivamente el número de operaciones de tales vectores. 

Para realizar el programa se ayudará de la clase Operacion (COMPLETAMENTE 
TERMINADA Y QUE NO DEBE MODIFICARSE) y el módulo VectorOperacion. 

La función main() puede ejecutarse con un argumento OPCIONAL [ capitalMinimo ]
que es el capital mínimo disponible (liquidez) que la empresa debe tener para
poder hacer una inversión.
El capital mínimo es de 6000 en caso de que no se suministre dicho parámetro al
ejecutar el programa.
 
La función main() debe realizar los siguientes pasos:

1. Leer desde la entrada estándar todas las operaciones que la empresa tiene 
   apuntadas para el periodo de tiempo y almacenarlas en el vector dinámico
   vectorOperaciones.
2. Tratar de ejecutar las operaciones en el orden que se presentan en la 
   entrada estándar, siempre y cuando cumplan con la restricción de no dejar 
   la liquidez por debajo del capital mínimo. 

    2.1 Si la operación es de inversión, debe comprobar si esta se puede  
        ejecutar, esto es, si el capital disponible (liquidez) de la empresa 
        supera el capital mínimo establecido
      2.1.1 en caso de que se pueda ejecutar la operación, 
            actualiza la liquidez de la empresa
      2.1.2 en caso de que la operación no se pueda llevar a cabo, 
            se elimina la operación del vector de operaciones del periodo y se 
            añade al vector de operaciones pendientes.

3. Mostrar el vector de operaciones ejecutadas, 
   y el importe total calculado de tales operaciones. 
4. Mostrar el contenido  del vector de operaciones pendientes 
   y el importe total calculado de las operaciones pendientes. 

 Especificación de las TAREAS QUE DEBE REALIZAR:
  
1. RELLENAR nombre y apellidos tras el token @author. 
 
2. REVISAR las CABECERAS de las funciones externas de VectorOperaciones. 
   Nota: Se han de respetar tanto el número de parámetros como sus tipos. 
   La forma de pasar los argumentos (por valor, referencia, etc.) lo decides tú.

void leerVOperat (Operacion *v, int nOperaciones);
Operacion *reservarVOperat(int nOperaciones);
void liberarVOperat(Operacion *v);
void redimensionarVOperat(Operacion *v, int nOperaciones);
void agnadeOperacionVOperat(Operacion *v, int nOperaciones, Operacion nuevo);
void imprimirVOperat(const Operacion *v, int nOperaciones);
bool esEjecutableOperacion(double activoActual, Operacion ctd, double capitalMinimo);
void ejecutarVOperat(Operacion *vE, int nOperacionesE, Operacion *vP, int nOperacionesP, double capitalMinimo);
void eliminaOperacionVOperat(Operacion *v, int nOperaciones, int pos);
double calculaImporteVOperat(Operacion *v, int nOperaciones);

3. COMPLETAR el código de las funciones anteriores.

4. COMPLETAR el main(), que puede recibir el argumento opcional capitalMinimo. 

Se ha preparado el fichero data/input00.csv con el siguiente contenido:
Aporte,2025/01/09,Herencia americana,1200.0 
Inversion,2025/01/09,Cafetera Clunny,150.0 
Inversion,2025/01/10,Silla Fakir,230.31
Desinversion,2025/04/20,Alfombra voladora,550.01
Inversion,2025/01/13,Monitor ultrapanoramico para ver NetFilx,380.0
Desinversion,2025/04/11,Impresora lunar,600.01
Inversion,2025/02/10,Aire incondicionado,900.00
Inversion,2025/02/12,Microondas para ideas,95.5 
Inversion,2025/02/13,Extintor decorativo,70.9 
Desinversion,2025/04/12,Telefono pisapapeles,25.01 
FINAL
 
Ejemplo de ejecución 1: dist/Debug/GNU-Linux/parcialc < data/input00.csv 
==================================================
Capital minimo: 6000
Operaciones leidas: 
===================
10
Aporte,2025/01/09,Herencia americana,1200.000000
Inversion,2025/01/09,Cafetera Clunny,-150.000000
Inversion,2025/01/10,Silla Fakir,-230.310000
Desinversion,2025/04/20,Alfombra voladora,550.010000
Inversion,2025/01/13,Monitor ultrapanoramico para ver NetFilx,-380.000000
Desinversion,2025/04/11,Impresora lunar,600.010000
Inversion,2025/02/10,Aire incondicionado,-900.000000
Inversion,2025/02/12,Microondas para ideas,-95.500000
Inversion,2025/02/13,Extintor decorativo,-70.900000
Desinversion,2025/04/12,Telefono pisapapeles,25.010000
Operaciones ejecutadas:
=======================
4
Aporte,2025/01/09,Herencia americana,1200.000000
Desinversion,2025/04/20,Alfombra voladora,550.010000
Desinversion,2025/04/11,Impresora lunar,600.010000
Desinversion,2025/04/12,Telefono pisapapeles,25.010000
2375.03
Operaciones pendientes:
=======================
6
Inversion,2025/01/09,Cafetera Clunny,-150.000000
Inversion,2025/01/10,Silla Fakir,-230.310000
Inversion,2025/01/13,Monitor ultrapanoramico para ver NetFilx,-380.000000
Inversion,2025/02/10,Aire incondicionado,-900.000000
Inversion,2025/02/12,Microondas para ideas,-95.500000
Inversion,2025/02/13,Extintor decorativo,-70.900000
-1826.71
    
Ejemplo de ejecución 2: dist/Debug/GNU-Linux/parcialc 1000 < data/input00.csv 
=====================================================
Capital minimo: 1000
Operaciones leidas: 
===================
10
Aporte,2025/01/09,Herencia americana,1200.000000
Inversion,2025/01/09,Cafetera Clunny,-150.000000
Inversion,2025/01/10,Silla Fakir,-230.310000
Desinversion,2025/04/20,Alfombra voladora,550.010000
Inversion,2025/01/13,Monitor ultrapanoramico para ver NetFilx,-380.000000
Desinversion,2025/04/11,Impresora lunar,600.010000
Inversion,2025/02/10,Aire incondicionado,-900.000000
Inversion,2025/02/12,Microondas para ideas,-95.500000
Inversion,2025/02/13,Extintor decorativo,-70.900000
Desinversion,2025/04/12,Telefono pisapapeles,25.010000
Operaciones ejecutadas:
=======================
8
Aporte,2025/01/09,Herencia americana,1200.000000
Inversion,2025/01/09,Cafetera Clunny,-150.000000
Desinversion,2025/04/20,Alfombra voladora,550.010000
Inversion,2025/01/13,Monitor ultrapanoramico para ver NetFilx,-380.000000
Desinversion,2025/04/11,Impresora lunar,600.010000
Inversion,2025/02/12,Microondas para ideas,-95.500000
Inversion,2025/02/13,Extintor decorativo,-70.900000
Desinversion,2025/04/12,Telefono pisapapeles,25.010000
1678.63
Operaciones pendientes:
=======================
2
Inversion,2025/01/10,Silla Fakir,-230.310000
Inversion,2025/02/10,Aire incondicionado,-900.000000
-1130.31
        
Ejemplo de ejecución 3: dist/Debug/GNU-Linux/parcialc 600 < data/input00.csv 

Capital minimo: 600
Operaciones leidas: 
===================
10
Aporte,2025/01/09,Herencia americana,1200.000000
Inversion,2025/01/09,Cafetera Clunny,-150.000000
Inversion,2025/01/10,Silla Fakir,-230.310000
Desinversion,2025/04/20,Alfombra voladora,550.010000
Inversion,2025/01/13,Monitor ultrapanoramico para ver NetFilx,-380.000000
Desinversion,2025/04/11,Impresora lunar,600.010000
Inversion,2025/02/10,Aire incondicionado,-900.000000
Inversion,2025/02/12,Microondas para ideas,-95.500000
Inversion,2025/02/13,Extintor decorativo,-70.900000
Desinversion,2025/04/12,Telefono pisapapeles,25.010000
Operaciones ejecutadas:
=======================
9
Aporte,2025/01/09,Herencia americana,1200.000000
Inversion,2025/01/09,Cafetera Clunny,-150.000000
Inversion,2025/01/10,Silla Fakir,-230.310000
Desinversion,2025/04/20,Alfombra voladora,550.010000
Inversion,2025/01/13,Monitor ultrapanoramico para ver NetFilx,-380.000000
Desinversion,2025/04/11,Impresora lunar,600.010000
Inversion,2025/02/10,Aire incondicionado,-900.000000
Inversion,2025/02/13,Extintor decorativo,-70.900000
Desinversion,2025/04/12,Telefono pisapapeles,25.010000
643.82
Operaciones pendientes:
=======================
1
Inversion,2025/02/12,Microondas para ideas,-95.500000
-95.5      

VALGRIND
========
Se recomienda comprobar la ejecución de tu programa con valgrind de la 
siguiente forma:

valgrind --tool=memcheck --leak-check=full --track-origins=yes  dist/Debug/GNU-Linux/parcialc < data/input00.csv 
*/


#include <cstdlib>
#include <iostream>
#include "VectorOperacion.h"

using namespace std;

int main(int argc, char** argv) {
    //Declaración de variables

    Operacion *vectorOps, *vectorPendtes;
    int nOps, nPendtes;
    double liquidez;

    // inicializacion de variables
    nOps = nPendtes = 0;
    vectorOps = vectorPendtes = nullptr;
    double capitalMinimo = 6000.0;

    // Tratamiento del parámetro de main()

    if (argc == 2)
        capitalMinimo = stod(argv[1]);
    cout << "Capital minimo: " << capitalMinimo << endl;

    // leer todas las operaciones
    leerVOperat(vectorOps, nOps);

    // Se muestra el contenido de Operaciones leidas
    cout << "Operaciones leidas: " << endl;
    cout << "===================" << endl;
    imprimirVOperat(vectorOps, nOps);

    // Se trata de ejecutar las operaciones
    ejecutarVOperat(vectorOps, nOps, vectorPendtes, nPendtes, capitalMinimo);

    // Se muestra el contenido de Operaciones ejecutadas
    cout << "Operaciones ejecutadas:" << endl;
    cout << "=======================" << endl;

    imprimirVOperat(vectorOps, nOps);
    // se calcula y se muestra el importe total disponible
    liquidez = calculaImporteVOperat(vectorOps, nOps);
    cout << liquidez << endl;

    // Se muestra el contenido de Operaciones pendientes
    cout << "Operaciones pendientes:" << endl;
    cout << "=======================" << endl;
    imprimirVOperat(vectorPendtes, nPendtes);
    
    // se calcula y se muestra el importe total pendiente
    liquidez = calculaImporteVOperat(vectorPendtes, nPendtes);
    cout << liquidez << endl;
    
    // Liberar memoria dinámica si procede
    liberarVOperat(vectorOps);
    liberarVOperat(vectorPendtes);

    return 0;
}

