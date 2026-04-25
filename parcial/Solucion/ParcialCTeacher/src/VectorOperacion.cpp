////////////////////////////////////////////////////////////////////////////
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Para la ejecucion de una serie de Operaciones bancarias
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "VectorOperacion.h"

using namespace std;

/**
 * @brief Lee operaciones desde la entrada estándar y las añade al vector v, 
 * hasta encontrar FINAL (marca de fin de lectura) en el campo correspondiente a 
 * tipo de operación.
 * Cada vez que se lee una Operacion se añade al vector v de operaciones leídas,
 * un vector dinámico cuyo tamaño se ajusta a los datos leídos.
 * Se supone que los datos que va leer el programa están en un formato correcto
 * según el ejemplo que aparece en main.cpp
 * @param v un vector de operaciones.
 * El contenido del vector es de entrada/salida. El puntero v es de entrada/salida
 * @param nOperaciones número de operaciones del vector de operaciones.
 * Parámetro de entrada/salida
 */
void leerVOperat (Operacion *&v, int &nOperaciones){
    string linea;
    Operacion una;

    v = nullptr;
    nOperaciones = 0;  // inicialización
    
    getline(cin, linea);
    while(linea != "FINAL") {
        una.set(linea);
        agnadeOperacionVOperat(v, nOperaciones, una);
        getline(cin, linea);
    }
}

/**
 * @brief Muestra en la salida estándar el contenido del vector de operaciones en 
 * un formato predefinido.
 * @param v vector de operaciones.
 * El contenido del vector es de entrada. El puntero v es de entrada
 * @param nOperaciones número de elementos usados del vector v. Parametro de E/,  
 * no se modifica
 */
void imprimirVOperat(const Operacion *v, int nOperaciones){
    cout << nOperaciones << endl;
    for (int i = 0; i < nOperaciones; i++)
        cout << v[i].toString() << endl;
}

/**
 * @brief Trata de ejecutar una a una, cada una de las operaciones del
 * vector de Operaciones vE. Se asume una liquidez inicial de 0. 
 * Para cada operación comprueba si se puede ejecutar 
 *   en caso afirmativo actualiza la liquidez con el importe correspondiente 
 *      a la operación, 
 *   en caso contrario, 
 *     añade la operación en cuestión a las operaciones pendientes, y
 *     elimina dicha operación del vector de operaciones vE.
 * @param vE vector de operaciones.
 * El contenido del vector es de entrada/salida. El puntero vE es de entrada/salida
 * @param nOperacionesE  número de operaciones del vector de operaciones vE.
 * Parámetro de entrada/salida
 * @param vP vector de operaciones pendientes.
 * El contenido del vector es de entrada/salida. El puntero vP es de entrada/salida
 * @param nOperacionesP número de operaciones del vector de operaciones VP pendientes.
 * Parámetro de entrada/salida
 * @param capitalMinimo valor necesario para comprobar si se puede aplicar o no 
 * la operación. Parámetro de entrada.
 */
void ejecutarVOperat(Operacion *&vE, int & nOperacionesE,
        Operacion *&vP, int & nOperacionesP,
        double capitalMinimo) {
    double activo = 0;
    nOperacionesP = 0;
    vP = nullptr;

    for (int i = 0; i < nOperacionesE;)
        if (esEjecutableOperacion(activo, vE[i], capitalMinimo)) {
            activo +=  vE[i].getImporte();
            i++;
        } else {
            agnadeOperacionVOperat(vP, nOperacionesP,vE[i]);
            eliminaOperacionVOperat(vE, nOperacionesE, i);
        }
}

/**
 * @brief Reserva en memoria dinámica un vector de operaciones de tamaño nOperaciones.
 * @param nOperaciones número de operaciones a reservar para el vector de operaciones. 
 * Parámetro de entrada
 * @return dirección de inicio de la memoria reservada para el vector de 
 * operaciones. Si n<=0 devuelve nullptr
 */
Operacion* reservarVOperat(int nOperaciones) {
    Operacion *reserva;
    if (nOperaciones <= 0)
        reserva = nullptr;
    else{
        reserva = new Operacion[nOperaciones];
    }
    return reserva;

}
/**
 * @brief Libera la memoria dinámica alojada para el vector de operaciones v.
 * Tras liberar la memoria el puntero v queda con el valor nullptr
 * @param v un vector de operaciones.
 * El contenido del vector es de entrada/salida. El puntero v es de entrada/salida
 */
void liberarVOperat(Operacion *&v) {
    delete [] v;
    v = nullptr;
}

/** 
 * @brief Redimensiona el vector de Operaciones v en un nuevo espacio con 
 * capacidad para una operación más. Para ello crea un nuevo vector dinámico, 
 * de capacidad nOperaciones +1 y copia el vector dinámico actual en el nuevo 
 * espacio, dejando espacio para una operación adicional aún sin inicializar.
 * @param v un vector de operaciones. El contenido del vector es de entrada/salida. 
 * El puntero v es de entrada/salida
 * @param nOperaciones número de elementos usados del vector v. 
 * Parámetro de E/, no se modifica
 */
void redimensionarVOperat(Operacion *&v, int nOperaciones){
    Operacion *vAmpliado;
    vAmpliado = reservarVOperat(nOperaciones+1);
    for (int i=0; i < nOperaciones; i++)
        vAmpliado[i]=v[i];
    liberarVOperat(v);
    v=vAmpliado;
}

/**
 * @brief Añade la Operacion nuevo al final del vector de Operaciones, una vez 
 * redimensionado v, e incrementa el número de componentes. 
 * @param v vector de Operaciones donde se añade nuevo al final. 
 * El contenido del vector es de entrada/salida. El puntero v es de entrada/salida
 * @param nOperaciones número de operaciones que contiene el vector de operaciones v.
 * Parámetro de entrada/salida
 * @param nuevo Contenedor de entrada a insertar al final del vector de operaciones. 
 * Parámetro de entrada
 */
void agnadeOperacionVOperat(Operacion *&v, int &nOperaciones, const Operacion &nuevo){
    redimensionarVOperat(v, nOperaciones);
    v[nOperaciones++] = nuevo;
}

/**
 * @brief Comprueba si la liquidez actual soporta la aplicación del importe 
 * de la operacion @ctd y deja un margen positivo superior al capitalMinimo.
 * Esto es, si activoActual + Importe de @ctd >= capitalMinimo dependiendo 
 * del tipo de operación. Todos los importes son positivos excepto para el tipo 
 * Inversion.
 * @param liquidezActual cantidad a la que se suma el importe de la operación ctd.
 * Parámetro de entrada.
 * @param ctd Operacion con la que se calcula la actualizacion de la liquidez
 * actual (liquidezActual). 
 * Parámetro de entrada.
 * @param capitalMinimo, cantidad minima que debe de quedar de liquidez. 
 * Parámetro de entrada
 * @return true si la operación proporcionada puede realizarse con la liquidez
 * actual; false en otro caso. 
 */
bool esEjecutableOperacion(double liquidezActual,
        const Operacion &ctd, double capitalMinimo){
    bool ok = true;
//    if (!ctd.getTipo()) 
    if (ctd.getTipo() == Operacion::IDA::Inversion) // comprueba si getTipo es Inversion
        if (liquidezActual + ctd.getImporte() < capitalMinimo )
            ok = false;      
    return ok;
}

/**
 * @brief Devuelve el importe calculado total obtenido con la ejecución de cada una 
 * de las operaciones que hay en el vector de operaciones v. No hay que cambiar 
 * de signo, la consulta del importe da el valor adecuado. Siempre se suma.
 * @param v un vector de operaciones.
 * El contenido del vector es de entrada. El puntero v es de entrada
 * @param nOperaciones número de operaciones que contiene el vector de operaciones v.
 * Parámetro de entrada
 * @return capital total obtenido como suma de importes de cada uno
 * de las operaciones que hay en el vector de operaciones v
 */
double calculaImporteVOperat(const Operacion *v, int nOperaciones){
    double total = 0.0;
    for (int i=0; i < nOperaciones; i++)
        total += v[i].getImporte();
 
    return total;
}

/**
 * @brief Elimina la Operacion situada en la posición pos del vector v, de forma
 * que se mantenga el mismo orden relativo del resto de Operaciones. No es necesario
 * redimensionar el espacio de memoria, y es necesario actualizar el contador al 
 * número de operaciones útiles en el vector.
 * Si la posición pos no es correcta, la función no hará ninguna acción sobre
 * el vector de Operaciones v
 * @param v vector de Operaciones. 
 * El contenido del vector es de entrada/salida. El puntero v es de entrada
 * @param nOperaciones número de Operaciones que contiene el vector de Operaciones v.
 * Parámetro de entrada/salida 
 * @param pos posición de la Operacion a eliminar. Parámetro de entrada/salida 
 */
void eliminaOperacionVOperat(Operacion *v, int &nOperaciones, int pos) {
    if (pos >= 0 && pos<nOperaciones) { // Comprueba que posición pos es correcta

        for(int i=pos+1; i<nOperaciones; i++){
            v[i-1] = v[i];
        }
        nOperaciones--;
    }
}