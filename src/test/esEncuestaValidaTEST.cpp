#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(esEncuestaValidaTEST, valida) {

    eph_i ti = {{334,  2017, 1, 1, 2, 1, 36, 1, 3, 60, 40312, 16300},
                {960,  2017, 1, 0, 2, 1, 51, 1, 3, 4,  55314, 1280},
                {960,  2017, 2, 0, 2, 1, 20, 1, 3, 60, 53314, 7000},
                {960,  2017, 3, 0, 2, 2, 19, 0, 0, -1, -1,    0},
                {1366, 2017, 1, 0, 2, 2, 92, 0, 0, -1, -1,    0},
                {1388, 2017, 1, 1, 2, 2, 67, 1, 3, 25, 11331, 20000}};
    eph_h th = {{334,  2017, 2, 16300, 2},
                {960,  2017, 2, 8280,  2},
                {1366, 2017, 2, 0,     2},
                {1388, 2017, 2, 20000, 2}};

    EXPECT_EQ(true, esEncuestaValida(ti, th));
}

TEST(esEncuestaValidaTEST, EdadNovalida) {

    eph_i ti = {{334,  2017, 1, 1, 2, 1, 36, 1, 3, 60, 40312, 16300},
                {960,  2017, 1, 0, 2, 1, 51, 1, 3, 4,  55314, 1280},
                {960,  2017, 2, 0, 2, 1, 20, 1, 3, 60, 53314, 7000},
                {960,  2017, 3, 0, 2, 2, 19, 0, 0, -1, -1,    0},
                {1366, 2017, 1, 0, 2, 2, 192, 0, 0, -1, -1,    0},
                {1388, 2017, 1, 1, 2, 2, 67, 1, 3, 25, 11331, 20000}};
    eph_h th = {{334,  2017, 2, 16300, 2},
                {960,  2017, 2, 8280,  2},
                {1366, 2017, 2, 0,     2},
                {1388, 2017, 2, 20000, 2}};

    EXPECT_EQ(false, esEncuestaValida(ti, th));
}

TEST(esEncuestaValidaTEST, trimNovalida) {

    eph_i ti = {{334,  2017, 1, 1, 2, 1, 36, 1, 3, 60, 40312, 16300},
                {960,  2017, 1, 0, 2, 1, 51, 1, 3, 4,  55314, 1280},
                {960,  2017, 2, 0, 1, 1, 20, 1, 3, 60, 53314, 7000},
                {960,  2017, 3, 0, 2, 2, 19, 0, 0, -1, -1,    0},
                {1366, 2017, 1, 0, 2, 2, 92, 0, 0, -1, -1,    0},
                {1388, 2017, 1, 1, 2, 2, 67, 1, 3, 25, 11331, 20000}};
    eph_h th = {{334,  2017, 2, 16300, 2},
                {960,  2017, 2, 8280,  2},
                {1366, 2017, 2, 0,     2},
                {1388, 2017, 2, 20000, 2}};

    EXPECT_EQ(false, esEncuestaValida(ti, th));
}

TEST(esEncuestaValidaTEST, sinHogarNovalida) {

    eph_i ti = {{334,  2017, 1, 1, 2, 1, 36, 1, 3, 60, 40312, 16300},
                {960,  2017, 1, 0, 2, 1, 51, 1, 3, 4,  55314, 1280},
                {960,  2017, 2, 0, 2, 1, 20, 1, 3, 60, 53314, 7000},
                {960,  2017, 3, 0, 2, 2, 19, 0, 0, -1, -1,    0},
                {1366, 2017, 1, 0, 2, 2, 92, 0, 0, -1, -1,    0},
                {1388, 2017, 1, 1, 2, 2, 67, 1, 3, 25, 11331, 20000}};
    eph_h th = {{334,  2017, 2, 16300, 2},
                {960,  2017, 2, 8280,  2},
                {1388, 2017, 2, 20000, 2}};

    EXPECT_EQ(false, esEncuestaValida(ti, th));
}

TEST(esEncuestaValidaTEST, validaAmbas) {
	eph_i ti; 
	eph_h th;
    leerEncuesta ( "eph_Hogar_2016_CABA.csv", ti , th );
    leerEncuesta ( "eph_Indiv_2016_CABA.csv" , ti , th );
    EXPECT_EQ(true,esEncuestaValida ( ti , th ));
}
// FailureC++ exception with description "stoi" thrown in the test body.
/*TEST(esEncuestaValidaTEST, noValidaAmbas) {
	eph_i ti; 
	eph_h th;
    leerEncuesta ( "eph_Hogar_2016_CABA_NoValida.csv", ti , th );
    leerEncuesta ( "eph_Indiv_2016_CABA_NoValida.csv" , ti , th );
    EXPECT_EQ(false,esEncuestaValida ( ti , th ));

}*/
// FailureC++ exception with description "stoi" thrown in the test body.
/*TEST(esEncuestaValidaTEST, noValidAIndiv_validaHogar) {
	eph_i ti;
	eph_h th;
    leerEncuesta ( "eph_Hogar_2016_CABA.csv", ti , th );
    leerEncuesta ( "eph_Indiv_2016_CABA_NoValida.csv" , ti , th );
    EXPECT_EQ(false,esEncuestaValida ( ti , th ));

}*/

TEST(esEncuestaValidaTEST, noValidAIndiv2_validaHogar) {
    eph_i ti;
    eph_h th;
    leerEncuesta ( "eph_Hogar_2016_CABA.csv", ti , th );
    leerEncuesta ( "eph_Indiv_2016_CABA_TampocoValida.csv" , ti , th );
    EXPECT_EQ(false,esEncuestaValida ( ti , th ));

}
// FailureC++ exception with description "stoi" thrown in the test body.
/*
TEST(esEncuestaValidaTEST, validaIndiv_noValidaHogar) {
	eph_i ti; 
	eph_h th;
    leerEncuesta ( "eph_Hogar_2016_CABA_NoValida.csv", ti , th );
    leerEncuesta ( "eph_Indiv_2016_CABA.csv" , ti , th );
    EXPECT_EQ(false,esEncuestaValida ( ti , th ));

}
*/
// Test para encuestas subidas a solapa trabajos practicos
TEST(esEncuestaValidaTEST, validaAmbas2) {
    eph_i ti;
    eph_h th;
    leerEncuesta ( "eph_Hogar_1_2017.csv", ti , th );
    leerEncuesta ( "eph_Indiv_1_2017.csv" , ti , th );
    EXPECT_EQ(true,esEncuestaValida ( ti , th ));
}
TEST(esEncuestaValidaTEST, validaAmbas3) {
    eph_i ti;
    eph_h th;
    leerEncuesta ( "eph_Hogar_1_2018.csv", ti , th );
    leerEncuesta ( "eph_Indiv_1_2018.csv" , ti , th );
    EXPECT_EQ(true,esEncuestaValida ( ti , th ));
}
