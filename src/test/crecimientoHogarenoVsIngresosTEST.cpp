#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(crecimientoHogaernoVSIngresos, test1) {

    int idx0,idx1,nro0,nro1;
    float evCmp0,evCmp1,evIng0,evIng1;

    eph_i t1i = {{685,2016,1,0,2,1,44,1,3,66,30319,-1},
                {685,2016,2,0,2,1,47,1,3,35,56314,4500},
                {685,2016,3,0,2,1,21,1,3,16,57314,0},
                {685,2016,4,0,2,1,14,0,0,-1,-1,0},
                {685,2016,5,0,2,2,12,0,0,-1,-1,0},
                {685,2016,6,0,2,2,9,0,0,-1,-1,0},
                {685,2016,7,0,2,1,8,0,0,-1,-1,0},
                {294,2016,1,1,2,1,37,1,3,35,10313,21000},
                {294,2016,2,0,2,2,37,1,3,56,80323,8500},
                {271,2016,1,0,2,1,49,1,3,0,36314,10000},
                {700,2016,1,1,2,1,57,1,1,50,7001,30000}};
    eph_h t1h = {{685,2016,2,4500,2},
          {294,2016,2,29500,2},
          {271,2016,2,10000,2},
          {700,2016,2,30000,2}};

    eph_i t2i = {{334,2017,1,1,2,1,36,1,3,60,40312,16300},
                {960,2017,1,0,2,1,51,1,3,4,55314,1280},
                {960,2017,2,0,2,1,20,1,3,60,53314,7000},
                {960,2017,3,0,2,2,19,0,0,-1,-1,0},
                {1366,2017,1,0,2,2,92,0,0,-1,-1,0},
                {1388,2017,1,1,2,2,67,1,3,25,11331,20000}};
    eph_h t2h = {{334,2017,2,16300,2},
          {960,2017,2,8280,2},
          {1366,2017,2,0,2},
          {1388,2017,2,20000,2}};

    lista_ev_hogares res = crecimientoHogarenoVsIngresos(t1i, t1h, t2i, t2h);
    lista_ev_hogares expected = {{1,0,-33.3,1},{2,-50.0,-44.7,1},{3,200.0,-17.2,1},{4,-85.7,-100.0,1}};

    EXPECT_EQ(expected.size(),res.size());

    for(int k=0;k < expected.size(); k++) {
        evolucion_hogar expEv = expected[k];
        evolucion_hogar resEv = res[k];

        // verificar nro cuartil
        idx0 = get<0>(expEv);
        idx1 = get<0>(resEv);
        EXPECT_EQ(idx0,idx1);
        // verificar evolucion componentes
        evCmp0 = floor(get<1>(expEv));
        evCmp1 = floor(get<1>(resEv));
        EXPECT_EQ(evCmp0,evCmp1);
        // verificar evolucion componentes
        evIng0 = floor(get<2>(expEv));
        evIng1 = floor(get<2>(resEv));
        EXPECT_EQ(evIng0,evIng1);
        // verificar nro cuartil
        nro0 = get<3>(expEv);
        nro1 = get<3>(resEv);
        EXPECT_EQ(nro0,nro1);
    }
}

TEST(crecimientoHogaernoVSIngresos, test2) {

    int idx0,idx1,nro0,nro1;
    float evCmp0,evCmp1,evIng0,evIng1;

    eph_h t1h;
    eph_i t1i;
    eph_h t2h;
    eph_i t2i;

    leerEncuesta ( "eph_Hogar_2016_CABA.csv", t1i , t1h );
    leerEncuesta ( "eph_Indiv_2016_CABA.csv" , t1i , t1h );

    leerEncuesta ( "eph_Hogar_2017_CABA.csv", t2i , t2h );
    leerEncuesta ( "eph_Indiv_2017_CABA.csv" , t2i , t2h );


    lista_ev_hogares res = crecimientoHogarenoVsIngresos(t1i, t1h, t2i, t2h);
    lista_ev_hogares expected = {{1,-2.13,27.2,205},{2,1.4,37.9,205},{3,6.9,54.3,205},{4,2.4,0.0,206}};

    EXPECT_EQ(expected.size(),res.size());

    for(int k=0;k < expected.size(); k++) {
        evolucion_hogar expEv = expected[k];
        evolucion_hogar resEv = res[k];

        // verificar nro cuartil
        idx0 = get<0>(expEv);
        idx1 = get<0>(resEv);
        EXPECT_EQ(idx0, idx1);
        // verificar evolucion componentes
        evCmp0 = floor(get<1>(expEv));
        evCmp1 = floor(get<1>(resEv));
        EXPECT_EQ(evCmp0, evCmp1);
        // verificar evolucion componentes
        evIng0 = floor(get<2>(expEv));
        evIng1 = floor(get<2>(resEv));
        EXPECT_EQ(evIng0, evIng1);
        // verificar nro cuartil
        nro0 = get<3>(expEv);
        nro1 = get<3>(resEv);
        EXPECT_EQ(nro0, nro1);
    }
}