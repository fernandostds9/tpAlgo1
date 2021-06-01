#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;


TEST(porcHogaresNoPropMiemMay3, prueba1) {

    eph_i ti = {{250,2016,1,0,2,2,56,1,2,48,30113,1700},
                {666,2016,1,0,2,2,87,0,0,-1,-1,0},
                {666,2016,2,0,2,1,68,1,3,48,53313,8000},
                {666,2016,3,0,2,1,66,1,3,40,80323,9000},
                {359,2016,1,0,2,1,71,0,0,-1,-1,0},
                {280,2016,1,1,2,2,69,1,3,30,45331,10000},
                {761,2016,1,1,2,2,31,1,3,45,20312,30000}};
    eph_h th = {{250,2016,2,1700,2},
          {666,2016,2,17000,2},
          {359,2016,2,0,2},
          {280,2016,2,10000,2},
          {761,2016,2,30000,2}};

    float porcExpected = 20.0;

    EXPECT_EQ(floor(porcExpected), floor(porcHogaresNoPropMiemMay3(ti,th)));
}


TEST(porcHogaresNoPropMiemMay3, prueba2) {

    eph_i ti;
    eph_h th;

    // HAY 23 HOGARES QUE CUMPLEN PREDICADOS, SOBRE 50 HOGARES TOTALES, PORCEXPECTED DEBERIA SER 46.
    float porcExpected = 46.0;

    leerEncuesta ( "eph_Hogar_rnd_5.csv", ti , th );
    leerEncuesta ( "eph_Indiv_rnd_5.csv" , ti , th );

    EXPECT_EQ(floor(porcExpected), floor(porcHogaresNoPropMiemMay3(ti,th)));
}


TEST(porcHogaresNoPropMiemMay3, prueba21) {

    eph_i ti;
    eph_h th;

    float porcExpected = 30.0;

    leerEncuesta ( "eph_Hogar_rnd_6.csv", ti , th );
    leerEncuesta ( "eph_Indiv_rnd_6.csv" , ti , th );

    EXPECT_EQ(floor(porcExpected), floor(porcHogaresNoPropMiemMay3(ti,th)));
}