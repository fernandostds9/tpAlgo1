#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(nivelEducativoXHogar, test1) {
	lista_nivel_ed exp = {{0,60.0},{1,40.0}};

    eph_i ti = {{956,2017,1,1,2,2,57,1,2,0,30133,-1},
            {956,2017,2,1,2,1,58,0,0,-1,-1,0},
            {956,2017,3,1,2,1,29,1,3,40,10333,-1},
            {956,2017,4,1,2,1,25,1,3,40,10333,-1},
            {1131,2017,1,1,2,1,32,1,3,32,92332,16000},
            {1131,2017,2,0,2,1,33,1,3,32,20332,18000},
            {1023,2017,1,0,2,2,51,1,3,55,40312,18000},
            {1023,2017,2,0,2,2,15,0,0,-1,-1,0},
            {833,2017,1,0,2,2,64,0,3,-1,-1,0},
            {1452,2017,1,0,2,1,31,1,2,70,80123,2000},
            {1452,2017,2,0,2,2,5,0,0,-1,-1,0}};
    eph_h th = {{956,2017,2,0,2},
            {1131,2017,2,34000,2},
            {1023,2017,2,18000,2},
            {833,2017,2,0,2},
            {1452,2017,2,2000,2}};

    lista_nivel_ed out;
    int idx0,idx1;
    float por0,por1;

    out = nivelEducativoXHogar ( ti , th );

    EXPECT_EQ(exp.size(),out.size());

    for(int k=0;k < exp.size(); k++) {
        nivel_ed_hogar expEd = exp[k];
        nivel_ed_hogar resEd = out[k];

        // verificar nivel codigo educativo
        idx0 = get<0>(expEd);
        idx1 = get<0>(resEd);
        EXPECT_EQ(idx0,idx1);
        // verificar porcentaje
        por0 = floor(get<1>(expEd));
        por1 = floor(get<1>(resEd));
        EXPECT_EQ(por0,por1);
    }

}

TEST(nivelEducativoXHogar, test2) {
    lista_nivel_ed exp = {{0,42.0},{1,58.0}};

    eph_i ti;
    eph_h th;

    lista_nivel_ed out;
    int idx0,idx1;
    float por0,por1;

    leerEncuesta ( "eph_Hogar_rnd_5.csv", ti , th );
    leerEncuesta ( "eph_Indiv_rnd_5.csv" , ti , th );

    out = nivelEducativoXHogar ( ti , th );

    EXPECT_EQ(exp.size(),out.size());

    for(int k=0;k < exp.size(); k++) {
        nivel_ed_hogar expEd = exp[k];
        nivel_ed_hogar resEd = out[k];

        // verificar nivel codigo educativo
        idx0 = get<0>(expEd);
        idx1 = get<0>(resEd);
        EXPECT_EQ(idx0,idx1);
        // verificar porcentaje
        por0 = floor(get<1>(expEd));
        por1 = floor(get<1>(resEd));
        EXPECT_EQ(por0,por1);
    }

}