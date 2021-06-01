#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <math.h>
#include <sstream>
#include <string>
#include <fstream>
#include <ctype.h>

#include "Funciones_TPI.h"

using namespace std;


void grabarEncuestaIH(vector < vector < int> > t, string nombreArchivo) {
    ofstream miArchivo;
    vector<int> item;
    miArchivo.open(nombreArchivo.c_str());
    if(miArchivo.is_open()) {
        for(int i=0;i<t.size();i++) {
            item = t[i];
            miArchivo << item[0];
            for(int j=1;j<item.size();j++) {
                miArchivo << "," << item[j];
            }
            miArchivo << endl;
        }
    }
    else{
        cout << "Error grabando el archivo." << endl;
    }
    miArchivo.close();
}


vector < vector < int> > leerEncuestaIH(string nombreArchivo) {

    char sep = ';';             // separador del csv
    ifstream miArchivo;
    vector < vector < int> > t;
    string line="";
    miArchivo.open(nombreArchivo.c_str(), ifstream::in);
    if(miArchivo.is_open()) {
        while (getline(miArchivo, line)) {
            vector<int> item;
            std::stringstream linestream(line);
            std::string value;
           while (getline(linestream, value, sep) ) {
                item.push_back(stoi(value));
            }
            t.push_back(item);
        }
        miArchivo.close();
    }
    else
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    return t;
}

void leerEncuesta ( string filename , eph_i & ti , eph_h & th ){

    bool esEncuestaHogar = "eph_H" == filename.substr(0,5);
    bool esEncuestaIndividuo = "eph_I" == filename.substr(0,5);
    string path = "datos/";

    if (esEncuestaHogar)
        th = leerEncuestaIH(path+filename);
    else if (esEncuestaIndividuo)
        ti = leerEncuestaIH(path+filename);
    else
        cout << "No se pudo determinar el tipo de encuesta " << endl;
}

void grabarEncuesta ( eph_i ti , eph_h th , string filename ){


    bool esEncuestaHogar = "eph_H" == filename.substr(0,5);
    bool esEncuestaIndividuo = "eph_I" == filename.substr(0,5);
    string path = "datos/";
    if (esEncuestaHogar)
        grabarEncuestaIH(th, path+filename);
    else if (esEncuestaIndividuo)
        grabarEncuestaIH(ti, path+filename);
    else
        cout << "No se pudo determinar el tipo de encuesta " << endl;

}