#ifndef ETPH_EJERCICIOS_H
#define ETPH_EJERCICIOS_H

#include <iostream>
#include <vector>
#include <math.h>
#include <tuple>
#include "definiciones.h"
#include <stdlib.h>

using namespace std;

// IGNACIO HERRERA 274/18
// FERNANDO REGERT 282/15


/* Funciones auxiliares */
//Ejercicio 1: esEncuestaValida  [TEST OK]
bool esMatrizIndividuo(eph_i ti);
bool esMatrizHogar(eph_h th);
bool individuoValido(individuo ind);
bool individuosValidos(eph_i ti);
bool hogarValido(hogar hog);
bool hogaresValidos(eph_h th);
bool individuosDistintos(eph_i ti);
bool hogaresUnicos (eph_h th);
bool mismoPeriodo (eph_i ti, eph_h th);
bool individuoConHogar(individuo i, eph_h th);
bool individuosConHogar(eph_i ti, eph_h th);
bool hogarConIndividuo(hogar h, eph_i ti);
bool hogaresConIndividuos(eph_i ti, eph_h th);
int cumIngresoIndividual(eph_i ti, int codusu);
bool ingresoHogarEnRango(eph_i ti, eph_h th);
bool tablasCompatibles(eph_i ti, eph_h th);
// Ejercicio 2: mayorIngresoPorPersonaActiva  [TEST OK]
bool esElActivoDeMayorIngreso(individuo p, eph_i ti);
individuo activoDeMayorIngreso(eph_i ti);
// Ejercicio 3: canHogaresNoPropMiemMay3  [TEST OK]
bool esProp(hogar h);
int compHogar(hogar h, eph_i ti);
// Ejercicio 4: generoGPosiblesClientes [TEST OK]
bool hogarConUnSoloHabitante(hogar h, eph_h ti);
individuo individuoDelHogar(hogar h, eph_h ti);
bool esUniversitario(individuo i);
bool esMenorDe45(individuo i);
bool esTrabajadorActivo(individuo i);
bool esPerfilBuscado(hogar h, eph_i ti);
bool hogarSoloGeneroG(hogar h, eph_i ti, int g);
int cantidadHogaresXGenero(eph_i ti, eph_h th, int g);
int cantidadHogaresXNoGenero(eph_i ti, eph_h th, int g);
//Ejercicio 5: ordenarPorITF  [TEST OK]
void swapTI(eph_i & ti, int a, int b);
int findITF(individuo i, eph_h th);
int findMaxITFPosition (eph_i ti, eph_h th, int d, int h);
void ordenarSegunITF (eph_i & ti, eph_h th);
void desempateSegunCODUSU(eph_i & ti, eph_h th);
int findMinComp (eph_i ti, int d, int h);
void ordenarSegunComponente(eph_i & ti);
// Ejercicio 6: nivelEducativoXHogar [TEST OK]
bool esMaxNivelEducativo (int ne, hogar h, eph_i ti);
int cantHogaresNivelEducativo(int ne, eph_h th, eph_i ti);
// Ejercicio 7: crecimientoGoarenoVsIngresos [TEST OK]
bool sonDistintosTrimestres(eph_i ti1, eph_i ti2, eph_h th1, eph_h th2);
eph_h hogaresOrdenadosPorITFyCODUSU(eph_h t);
int limIzquierdoCuartil(eph_h th, int c);
int limDerechoCuarti(eph_h th, int c);
float promedIngHogarCuart(eph_h th, int c);
float promedCompHogarCuart(eph_i ti, eph_h th, int c);
int promCasosCuartil(eph_h th1, eph_h th2, int c);

/* Enunciados principales */
bool esEncuestaValida ( eph_i ti , eph_h th );
hogar mayorIngresoPorPersonaActiva ( eph_i ti , eph_h th );
float porcHogaresNoPropMiemMay3 ( eph_i ti , eph_h th );
bool generoGPosiblesClientes ( eph_i ti , eph_h th , int g);
void ordenarPorITF ( eph_i & ti , eph_h th );
lista_nivel_ed nivelEducativoXHogar ( eph_i ti , eph_h th );
lista_ev_hogares crecimientoHogarenoVsIngresos ( eph_i ti1 , eph_h th1 , eph_i ti2 ,eph_h th2 );

#endif //ETPH_EJERCICIOS_H
