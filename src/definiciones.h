//
// Created by Pablo on 03/10/2017.
//

#ifndef UTILES_DEFINICIONES_H
#define UTILES_DEFINICIONES_H

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


// CONSTANTES

enum ItemInd {CODUSU,ANO4, COMPONENTE,NIVEL_ED,TRIMESTRE,GENERO,EDAD,ESTADO,CAT_OCUP,PP3E_TOT,PP04D_COD,P21};
enum ItemHogar {CODUSU_HOG,ANO4_HOG,TRIMESTRE_HOG,ITF,PROP};

// DEFINICIONES DE TIPO

typedef vector <int > individuo ;
typedef vector <int > hogar ;
typedef vector < individuo > eph_i ;
typedef vector <hogar > eph_h ;
typedef tuple <int ,float > nivel_ed_hogar ;
typedef vector < nivel_ed_hogar > lista_nivel_ed ;
typedef tuple <int ,float ,float ,int > evolucion_hogar ;
typedef vector < evolucion_hogar > lista_ev_hogares ;


#endif //UTILES_DEFINICIONES_H
