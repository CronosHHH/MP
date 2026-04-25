////////////////////////////////////////////////////////////////////////////
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autores: acu.ugr.es acid.ugr.es
// Para la ejecucion de una serie de Operaciones bancarias
////////////////////////////////////////////////////////////////////////////


#ifndef VECTOROPERACION_H
#define VECTOROPERACION_H

#include "Operacion.h"

// funciones externas

void leerVOperat (Operacion *v, int &nOperaciones);
Operacion *reservarVOperat(const int nOperaciones);
void liberarVOperat(Operacion *v);
void redimensionarVOperat(Operacion *v,  int& nOperaciones);
void agnadeOperacionVOperat(Operacion *v, int& nOperaciones, const Operacion& nuevo);
void imprimirVOperat(const Operacion *v, const int nOperaciones);
bool esEjecutableOperacion(double liquidezActual, const Operacion & ctd, const double capitalMinimo);
void ejecutarVOperat(Operacion *vE, int& nOperacionesE, Operacion *vP, int& nOperacionesP,const  double capitalMinimo);
void eliminaOperacionVOperat(Operacion *v, int& nOperaciones,  const int pos);
double calculaImporteVOperat(const Operacion *v, const int nOperaciones);

#endif /* VECTOROPERACION_H */

