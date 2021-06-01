#include "ejercicios.h"

// IGNACIO HERRERA 274/18
// FERNANDO REGERT 282/15

// Auxiliares - Ord(item)

// Individuos
int codusuI = int(ItemInd::CODUSU);
int ano4I = int(ItemInd::ANO4);
int trimestreI = int(ItemInd::TRIMESTRE);
int componente = int(ItemInd::COMPONENTE);
int nivel_ed = int(ItemInd::NIVEL_ED);
int estado = int(ItemInd::ESTADO);
int cat_ocup = int(ItemInd::CAT_OCUP);
int edad = int(ItemInd::EDAD);
int genero = int(ItemInd::GENERO);
int pp3e_tot = int(ItemInd::PP3E_TOT);
int pp04_cod = int(ItemInd::PP04D_COD);
int p21 = int(ItemInd::P21);
// Hogares
int itf = int(ItemHogar::ITF);
int ii7 = int(ItemHogar::PROP);
int codusuH = int(ItemHogar::CODUSU_HOG);
int trimestreH = int(ItemHogar::TRIMESTRE_HOG);
int ano4H = int(ItemHogar::ANO4_HOG);

/* EJERCICIO 1 */

/* Funciones auxiliares */
bool esMatrizIndividuo(eph_i ti){
    //(∀ i, j : Z)(0 ≤ i < |t| ∧ 0 ≤ j < |t|) −→ L |t[i]| = |t[j| ∧ |t[i]| = cantidadItemsIndividuo()
    bool res = true;
    for (int i = 0; i < ti.size(); ++i) {
        if (ti[i].size() != 12){
            res = false;
        }
    }
    return res;
}

bool esMatrizHogar(eph_h th){
    //(∀ i, j : Z)(0 ≤ i < |t| ∧ 0 ≤ j < |t|) −→ L |t[i]| = |t[j| ∧ |t[i]| = cantidadItemsHogar()
    bool res = true;
    for (int i = 0; i < th.size(); ++i) {
        if (th[i].size() != 5){
            res = false;
        }
    }
    return res;
}

bool individuoValido(individuo ind){
    vector<int> p = ind;
    bool res = true;
    // enum class ItemInd {CODUSU,ANO4, COMPONENTE,NIVEL_ED,TRIMESTRE,CH4,CH6,ESTADO,CAT_OCUP,PP3E_TOT,PP04D_COD,P21};
    // Se revisan predicados de especificacion, en caso de no cumplir uno, la variable res se modifica a false.
    // Codosu > 0, Componente > 0, Ano > 0
    if (p[codusuI] <= 0 || p[ano4I] <= 0 || p[componente] <= 0){
        res = false;
    }
    // Trimestre en rango
    if (1 > p[trimestreI] || p[trimestreI] > 4){
        res = false;
    }
    // Nivel_Ed en rango
    if (-1 > p[nivel_ed] || p[nivel_ed] > 1){
        res = false;
    }
    // Estado en rango
    if ((p[estado] < 0 && p[estado] != -1) || p[estado] > 1){
        res = false;
    }
    // catOcup EnRango
    if (-1 > p[cat_ocup] || p[cat_ocup] > 4){
        res = false;
    }
    // Edad en rango
    if (-1 > p[edad] || p[edad] > 110){
        res = false;
    }
    // PP3E_Tot ^ PP04D_COD>= -1
    if (p[pp3e_tot] < -1 || p[pp04_cod] < -1){
        res = false;
    }
    // P21 En rango
    if (-1 > p[p21]){
        res = false;
    }
    // ¬trabaja(p) −→ p[@P 21] <= 0
    if (p[estado] != 1 && p[p21] > 0){
        res = false;
    }
    // ¬trabaja(p) -> p[@P P 3E T ot] <= 0
    if (!(p[estado] == 1 || p[pp3e_tot] <= 0)){
         res = false;
     }
    // trabaja[p] -> p[@ch6] > 10
    if (p[estado] == 1 && p[edad] < 10) {
         res = false;
    }

    return res;
}

bool individuosValidos(eph_i ti){
    bool res = true;
    for (int i = 0; i < ti.size(); ++i) {
        if (!individuoValido(ti[i])) {
            res = false;
        }
    }
    return res;
}

bool hogarValido(hogar hog){
    vector<int> h = hog;
    bool res = true;
    // enum class ItemHogar {CODUSU,ANO4,TRIMESTRE,ITF,II7};
    // p[@Codusu] > 0 ∧ p[@Ano4] > 0 ^ p[@Itf ] ≥ 0
    if (h[codusuH] <= 0 || h[ano4H] <= 0 || h[itf] < 0) {
        res = false;
    }
    // ∧ trimestreEnRango(p[@trim])
    if (1 > h[trimestreH] || h[trimestreH] > 4) {
        res = false;
    }
    // pII7EnRango(p[@P ii7])
    if ((h[ii7] < 1 && h[ii7] != -1) || h[ii7] > 3) {
        res = false;
    }
    return res;
}

bool hogaresValidos(eph_h th){
    bool res = true;
    for (int h = 0; h < th.size(); ++h) {
        if (!hogarValido(th[h])){
            res = false;
        }
    }
    return res;
}

bool individuosDistintos(eph_i ti){
    // (∀ p1, p2 : individuo) p1 ∈ ti∧p2 ∈ ti ∧ p1 6 = p2 −→ L p1[@Codusu] 6 = p2[@Codusu] ∨ p1[@Componente] 6 = p2[@Componente]
    bool res = true;
    for (int i = 0; i < ti.size(); ++i) {
        for (int j = i+1; j < ti.size() ; ++j) {
            if (ti[i][codusuI] == ti[j][codusuI]) {
                if (ti[i][componente] == ti[j][componente]) {
                    res = false;
                }
            }
        }
    }
    return res;
}

bool hogaresUnicos (eph_h th){
    // (∀ p1, p2 : hogar) p1 ∈ th ∧ p2 ∈ th ∧ p1 6 = p2 −→ L p1[@Codusu] 6 = p2[@Codusu]
    bool res = true;
    for (int i = 0; i < th.size(); ++i) {
        for (int j = i+1; j < th.size(); ++j) {
            if (th[i][codusuH] == th[j][codusuH]){
                res = false;
            }
        }
    }
    return res;
}

bool mismoPeriodo (eph_i ti, eph_h th){
    bool res = true;
    for (int i = 0; i < ti.size(); ++i) {
        for (int h = 0; h < th.size(); ++h) {
            if (ti[i][ano4I] != th[h][ano4H] || ti[i][trimestreI] != th[h][trimestreH]){
                res = false;
            }
        }
    }
    return res;
}

bool individuoConHogar(individuo i, eph_h th){
    bool res = false;
    for (int h = 0; h < th.size(); ++h) {
        if (i[codusuI] == th[h][codusuH]){
            res = true;
        }
    }
    return res;
}

bool individuosConHogar(eph_i ti, eph_h th){
    bool res = true;
    for (int i = 0; i < ti.size(); ++i) {
        if(!individuoConHogar(ti[i], th)){
            res = false;
        }
    }
    return res;
}

bool hogarConIndividuo(hogar h, eph_i ti){
    bool res = false;
    for (int i = 0; i < ti.size(); ++i) {
        if (h[codusuH] == ti[i][codusuI]) {
            res = true;
            break;
        }
    }
    return res;
}

bool hogaresConIndividuos(eph_i ti, eph_h th){
    bool res = true;
    for (int h = 0; h < th.size(); ++h) {
        if (!hogarConIndividuo(th[h], ti)) {
            res = false;
        }
    }
    return res;
}

int cumIngresoIndividual(eph_i ti, int codusu){
    int res = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (ti[i][codusuI] == codusu){
            if(ti[i][p21] == -1){
                // Si no se responde en encuesta, no contar el "-1" como no responde, simplemente ignorarlo.
                continue;
            }
            res += ti[i][p21];
        }
    }
    return res;
}

bool ingresoHogarEnRango(eph_i ti, eph_h th){
    bool res = true;
    for (int h = 0; h < th.size(); ++h) {
        if (th[h][itf] > cumIngresoIndividual(ti, th[h][codusuH])) {
            res = false;
        }
    }
    return res;
}

bool tablasCompatibles(eph_i ti, eph_h th){
    return (mismoPeriodo(ti, th) && individuosConHogar(ti, th) && hogaresConIndividuos(ti, th) && ingresoHogarEnRango(ti, th));
}

// Resolucion Ejercicio
bool esEncuestaValida ( eph_i ti , eph_h th ) {
    bool res = esMatrizIndividuo(ti) && esMatrizHogar(th) && individuosDistintos(ti) && hogaresValidos(th) && hogaresUnicos(th) && individuosValidos(ti) && tablasCompatibles(ti, th);
    return res;
}

/* EJERCICIO 2 */

// Auxiliares
bool esElActivoDeMayorIngreso(individuo p, eph_i ti){
    bool res = true;
    for (int i = 0; i < ti.size(); ++i) {
        if (p[p21] < ti[i][p21]){
            res = false;
        }
    }
    return res;
}
// Se determina dentro de una tabla de invidiuos el individuo con mayor ingreso
individuo activoDeMayorIngreso(eph_i ti){
    individuo result;
    for (int i = 0; i < ti.size(); ++i) {
        if (esElActivoDeMayorIngreso(ti[i], ti)){
            result = ti[i];
            break;
        }
    }
    return result;
}

// Resolucion Ejercicio
hogar mayorIngresoPorPersonaActiva ( eph_i ti , eph_h th ){
    hogar result;
    individuo mayorActivo = activoDeMayorIngreso(ti);
    // for (int h : th.size()) ranged-based loop
    for (int h = 0; h < th.size(); ++h) {
        if (mayorActivo[codusuI] == th[h][codusuH]){
            result = th[h];
            break;
        }
    }
    return result;
}

/* EJERCICIO 3 */

// Auxiliares
bool esProp(hogar h){
    return h[ii7] == 1;
}

int compHogar(hogar h, eph_i ti){
    int res = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if(ti[i][codusuI] == h[codusuH]){
            res += 1;
        }
    }
    return res;
}

// Resolucion de ejercicio
float porcHogaresNoPropMiemMay3 (eph_i ti, eph_h th ){
    float res = 0.0;
    int hogaresNoPropMiemMay3 = 0;
    for (int h = 0; h < th.size(); ++h) {
        if (!esProp(th[h]) && compHogar(th[h], ti) >= 3){
            hogaresNoPropMiemMay3 += 1;
        }
    }
    res = float(hogaresNoPropMiemMay3) / float(th.size()) * 100;
    return res;
}

/* EJERCICIO 4 */

// Auxiliares
bool hogarConUnSoloHabitante(hogar h, eph_h ti){
    int individEnHogar = 0;
    for (int j = 0; j < ti.size(); ++j) {
        if (ti[j][codusuH] == h[codusuH]){
            individEnHogar += 1;
        }
    }
    return individEnHogar == 1;
}
individuo individuoDelHogar(hogar h, eph_h ti){
    individuo result;
    for (int i = 0; i < ti.size(); ++i) {
        if (h[codusuH] == ti[i][codusuI]){
            result = ti[i];
            break;
        }
    }
    return result;
}

bool esUniversitario(individuo i){
    return i[nivel_ed] == 1;
}

bool esMenorDe45(individuo i){
    return i[edad] < 45;
}

bool esTrabajadorActivo(individuo i){
    return i[estado] == 1;
}

bool esPerfilBuscado(hogar h, eph_i ti){
    bool res = false;
    // Primero chequear que hay un solo habitante, y almacenarlo en una variable para analizar los predicados correspondientes
    if (hogarConUnSoloHabitante(h, ti)){
        individuo habitante = individuoDelHogar(h, ti);
        res = esUniversitario(habitante) && esMenorDe45(habitante) && esTrabajadorActivo(habitante);
    }
    return res;
}

bool hogarSoloGeneroG(hogar h, eph_i ti, int g){
    bool res = true;
    for (int i = 0; i < ti.size(); ++i) {
        if (ti[i][codusuI] == h[codusuH]) {
            if (ti[i][genero] != g) {
                res = false;
                break;
            }
        }
    }
    return res;
}

int cantidadHogaresXGenero(eph_i ti, eph_h th, int g){
    int result = 0;
    for (int h = 0; h < th.size(); ++h) {
        if (esPerfilBuscado(th[h], ti)){
            if (hogarSoloGeneroG(th[h], ti, g)){
                result += 1;
            }
        }
    }
    return result;
}

int cantidadHogaresXNoGenero(eph_i ti, eph_h th, int g){
    int result = 0;
    for (int h = 0; h < th.size(); ++h) {
        if (esPerfilBuscado(th[h], ti)){
            if (!hogarSoloGeneroG(th[h], ti, g)){
                result += 1;
            }
        }
    }
    return result;
}


// Resolucion de ejercicio
bool generoGPosiblesClientes (eph_i ti, eph_h th, int g) {
    return cantidadHogaresXGenero(ti, th, g) > cantidadHogaresXNoGenero(ti, th, g);
}

/* EJERCICIO 5 */
// Algoritmo de ordenamiento utilizado: Selection Sort

// Auxiliares
// Swap para tabla individuos
void swapTI(eph_i & ti, int a, int b){
    individuo temp = ti[a];
    ti[a] = ti[b];
    ti[b] = temp;
}

// retorna el ITF del hogar, segun el individuo
int findITF(individuo i, eph_h th){
    int itf_i = 0;
    for (int h = 0; h < th.size(); ++h) {
        if (i[codusuI] == th[h][codusuH]){
            itf_i = th[h][itf];
            break;
        }
    }
    return itf_i;
}

// Busqueda del hogar con mayorITF en una secuencia. Utilizada para ordenar con ordenarSegunITF
int findMaxITFPosition (eph_i ti, eph_h th, int d, int h){
    int max = d;
    for (int i = d; i < h; ++i) {
        if(findITF(ti[max], th) < findITF(ti[i], th)){
            max = i;
        }
    }
    return max;
}
// Ordenar descendentemente segun ITF (Selection Sort)
void ordenarSegunITF (eph_i & ti, eph_h th){
    for (int i = 0; i < ti.size(); ++i){
        int maxITFPos = findMaxITFPosition(ti, th, i, ti.size());
        swapTI(ti, i, maxITFPos);
    }
}

//Ordenar ascendentemente segun CODUSU en caso de empate, PRE: Ya esta ordenada por ITF
void desempateSegunCODUSU(eph_i & ti, eph_h th){
    for (int i = 0; i < ti.size(); ++i) {
        // Idea: Insertion Sort
        for (int j = i; j > 0  && findITF(ti[j], th) == findITF(ti[j-1], th); --j) {
            if(ti[j][codusuI] < ti[j-1][codusuI]){
                swapTI(ti, j, j-1);
            }
        }
    }
}

// Busqueda del menor componente del hogar dentro de un determinado rango, suponiendo que ya esta ordenada por ITF (mismos codusu juntos)
int findMinComp (eph_i ti, int d, int h){
    int min = d;
    for (int i = d; i < h; ++i) {
        if(ti[min][codusuH] != ti[i][codusuH]){
            break;
        }
        if(ti[min][componente] > ti[i][componente]){
            min = i;
        }
    }
    return min;
}

//Ordenar ascendentemente segun Componente cada hogar
void ordenarSegunComponente(eph_i & ti){
    for (int i = 0; i < ti.size()-1; ++i) {
        int minCompPos = findMinComp(ti, i, ti.size());
        swapTI(ti, i, minCompPos);
    }
}

// Resolucion de ejercicio
void ordenarPorITF(eph_i & ti, eph_h th){
    ordenarSegunITF(ti, th);
    desempateSegunCODUSU(ti, th);
    ordenarSegunComponente(ti);
}

/* EJERCICIO 6 */

// Auxiliares
bool esMaxNivelEducativo(int ne, hogar h, eph_i ti){
    int max_nivel_ed = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (h[codusuH] == ti[i][codusuH]){
            if(ti[i][nivel_ed] > max_nivel_ed){
                max_nivel_ed = ti[i][nivel_ed];
            }
        }
    }
    return max_nivel_ed == ne;
}

int cantHogaresNivelEducativo(int ne, eph_h th, eph_i ti){
    int result = 0;
    for (int h = 0; h < th.size(); ++h) {
        if (esMaxNivelEducativo(ne, th[h], ti)){
            result += 1;
        }
    }
    return result;
}

// Resolucion de ejercicio
lista_nivel_ed nivelEducativoXHogar(eph_i ti, eph_h th){
    lista_nivel_ed result;
    for (int ne = 0; ne < 2; ++ne) {
        nivel_ed_hogar chunk = make_pair(ne, 100 * float(cantHogaresNivelEducativo(ne, th, ti)) / th.size());
        result.push_back(chunk);
    }
    return result;
}

/* EJERCICIO 7 */

// Auxiliares
bool sonDistintosTrimestres(eph_i ti1, eph_i ti2, eph_h th1, eph_h th2){
    bool res = true;
    if(ti1[0][trimestreI] == ti2[0][trimestreI]){
        res = false;
    }
    if(th1[0][trimestreH] == th2[0][trimestreH]){
        res = false;
    }
    return res;
}

eph_h hogaresOrdenadosPorITFyCODUSU(eph_h t){
    eph_h th = t;
    // Ordenar por ITF
    for (int h = 0; h < th.size(); ++h) {
        int max = h;
        for (int i = h; i < th.size(); ++i) {
            if(th[i][itf] > th[max][itf]){
                max = i;
            }
        }
        swap(th[h], th[max]);
    }
    // Ordenar por CODUSU
    for (int k = 0; k < th.size(); ++k) {
        // Idea: Insertion Sort
        for (int j = k; j > 0  && th[j][itf] == th[j-1][itf]; --j) {
            if(th[j][codusuI] < th[j-1][codusuI]){
                swap(th[j], th[j-1]);
            }
        }
    }
    return th;
}

int limIzquierdoCuartil(eph_h th, int c){
    return th.size() * (c-1) / 4;
}

int limDerechoCuarti(eph_h th, int c){
    return th.size() * c / 4;
}

float promedIngHogarCuart(eph_h th, int c){
    int ingresosTotales = 0;
    int hogaresEnCuartil = 0;
    // estaEnCuartil
    for (int i = limIzquierdoCuartil(th, c); i < limDerechoCuarti(th, c); ++i) {
        ingresosTotales += th[i][itf];
        hogaresEnCuartil += 1;
    }
    return float(ingresosTotales) / float(hogaresEnCuartil);
}

float promedCompHogarCuart(eph_i ti, eph_h th, int c){
    int componentes = 0;
    int hogaresEnCuartil = 0;
    // estaEnCuartil
    for (int h = limIzquierdoCuartil(th, c); h < limDerechoCuarti(th, c); ++h) {
        for (int i = 0; i < ti.size(); ++i) {
            if (ti[i][codusuI] == th[h][codusuH]){
                componentes += 1;
            }
        }
        hogaresEnCuartil += 1;
    }
    return float(componentes) / float(hogaresEnCuartil);
}

int promCasosCuartil(eph_h th1, eph_h th2, int c){
    int hogaresEncuestados = 0;
    for (int h = limIzquierdoCuartil(th1, c); h < limDerechoCuarti(th1,c); ++h) {
        hogaresEncuestados += 1;
    }
    for (int k = limIzquierdoCuartil(th2, c); k < limDerechoCuarti(th2,c); ++k) {
        hogaresEncuestados += 1;
    }
    return hogaresEncuestados / 2;
}

// Resolucion de ejercicio
lista_ev_hogares crecimientoHogarenoVsIngresos(eph_i ti1 , eph_h th1 , eph_i ti2 ,eph_h th2 ){
    lista_ev_hogares result;
    if (!sonDistintosTrimestres(ti1, ti2, th1, th2)){
        // tablas de hogares ordenadas
        eph_h tordh1 = hogaresOrdenadosPorITFyCODUSU(th1);
        eph_h tordh2 = hogaresOrdenadosPorITFyCODUSU(th2);

        for (int c = 1; c < 5; ++c) {
            evolucion_hogar cuartil;
            float promedioIng = 0;
            float promedioComp = 0;
            float promedioCasos = promCasosCuartil(tordh1, tordh2, c);

            float promedioIngH1 = promedIngHogarCuart(tordh1, c);
            float promedioCompH1 = promedCompHogarCuart(ti1, tordh1, c);
            float promedioIngH2 = promedIngHogarCuart(tordh2, c);
            float promedioCompH2 = promedCompHogarCuart(ti2, tordh2, c);

            if(promedioIngH1 > 0) {
                promedioIng = 100 * (promedioIngH2 - promedioIngH1) / promedioIngH1;
            }

            if(promedioCompH1 > 0){
                promedioComp = 100 * (promedioCompH2 - promedioCompH1) / promedioCompH1;
            }

            cuartil = make_tuple(c, promedioComp, promedioIng, promedioCasos);
            result.push_back(cuartil);
        }
    }else{
        cout << "Las encuestas no son validas pues coinciden en las fechas" << endl;
    }
    return result;
}

