#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(generoGPosiblesClientes, testMujerFalse1) {

    eph_h ti = {{621,2016,1,0,2,1,35,1,3,24,20333,8000},
                {621,2016,2,0,2,2,12,0,0,-1,-1,0},
                {621,2016,3,0,2,2,5,0,0,-1,-1,0},
                {865,2016,1,0,2,1,77,0,0,-1,-1,0},
                {11,2016,4,0,2,1,22,1,3,24,20313,5000},
                {11,2016,5,0,2,2,25,1,3,16,41312,3500},
                {11,2016,6,0,2,2,17,0,0,-1,-1,0},
                {11,2016,1,0,2,1,53,1,3,50,82313,14000},
                {11,2016,2,0,2,1,55,0,0,-1,-1,0},
                {161,2016,1,1,2,2,72,0,0,-1,-1,0},
                {603,2016,1,1,2,2,47,1,3,12,55314,2500},
                {603,2016,2,0,2,2,19,0,0,-1,-1,0}};
    eph_h th = {{621,2016,2,8000,2},
          {865,2016,2,0,2},
          {11,2016,2,22500,2},
          {161,2016,2,0,2},
          {603,2016,2,2500,2}};

    EXPECT_EQ(false ,generoGPosiblesClientes(ti,th,2));
}

TEST(generoGPosiblesClientes, testMujerTrue1) {

    eph_h ti = {{250,2016,1,0,2,2,56,1,2,48,30113,1700},
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

    EXPECT_EQ(true ,generoGPosiblesClientes(ti,th,2));
}

TEST(generoGPosiblesClientes, testHombreFalse1) {

    eph_i ti;
    eph_h th;

    leerEncuesta ( "eph_Hogar_rnd_5.csv", ti , th );
    leerEncuesta ( "eph_Indiv_rnd_5.csv" , ti , th );

    EXPECT_EQ(false ,generoGPosiblesClientes(ti,th,1));
}

TEST(generoGPosiblesClientes, testMujerTrue2) {

    eph_i ti;
    eph_h th;

    leerEncuesta ( "eph_Hogar_rnd_6.csv", ti , th );
    leerEncuesta ( "eph_Indiv_rnd_6.csv" , ti , th );

    EXPECT_EQ(true ,generoGPosiblesClientes(ti,th,2));
}