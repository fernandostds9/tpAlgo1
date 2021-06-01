#ifndef UTILES_FUNCIONES_TPI_H
#define UTILES_FUNCIONES_TPI_H

#include <iostream>
#include <vector>
#include <fstream>
#include "definiciones.h"

using namespace std;

void grabarEncuestaIH(vector < vector < int> > t, string nombreArchivo);
vector < vector < int> > leerEncuestaIH(string nombreArchivo);
void leerEncuesta ( string filename , eph_i & ti , eph_h & th );
void grabarEncuesta ( eph_i ti , eph_h th , string filename );

#endif //UTILES_FUNCIONES_TPI_H