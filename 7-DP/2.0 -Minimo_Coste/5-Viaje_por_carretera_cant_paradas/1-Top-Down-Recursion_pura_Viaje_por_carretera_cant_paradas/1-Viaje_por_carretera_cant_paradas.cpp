#include <bits/stdc++.h>
using namespace std;

int objetivo, combustibleInicial, destino;
vector<vector<int>> pos;              //ok  pos[0]=0, pos[1..m]=estaciones, pos[m+1]=D
map<pair<int,long long>, int> memo;   // <-- map, no vector

const int INF = 1e9;



int minCantidadParadas(int num_estacion, long long gasolina_actual) { //inicio num_estacion=0,combustibleInicial
    
    //caso base
    if (num_estacion == destino) return 0;   // llegamos al num_estacion de destino final 100
    
    // Memoización
    auto clave = make_pair(num_estacion, gasolina_actual); //make_pair(a, b) función crea (un par de dos valores) a partir de a y b, infiriendo automáticamente los tipos.
    if (memo.count(clave)) return memo[clave]; //devuelve 1 si esa clave ya existe en el mapa, 0 si no.     

    //0,20,50,80,100  es la distancia_Prox_Estacionancia a la siguiente estación (o al destino).
    int distancia_Prox_Estacion    = pos[num_estacion + 1][0]-pos[num_estacion][0];  //estaciones[i] = [posiciónᵢ, combustibleᵢ]
    int mejor = INF;
    
    //1-avanzá sin Parar: "si me alcanza sin cargar". (sin comprar gasolina)
    if (gasolina_actual >= distancia_Prox_Estacion)  
        mejor = min(mejor, minCantidadParadas(num_estacion + 1, gasolina_actual - distancia_Prox_Estacion)); 

    
    // 2) Avanzar parando (solo en estaciones reales, ni inicio ni destino)
            if (num_estacion != 0 && pos[num_estacion][1] > 0) {
                long long trasCarga = gasolina_actual+pos[num_estacion][1];  // tanque ilimitado: tomamos todo
                if (trasCarga >= distancia_Prox_Estacion) {
                    mejor = min(mejor, 1 + minCantidadParadas(num_estacion + 1, trasCarga - distancia_Prox_Estacion));
                }
            }

         
            return memo[clave] = mejor;

    //return memo[num_estacion][gasolina_actual] = mejor;
}

int main() {


    // Ejemplo 3
    objetivo = 100, combustibleInicial = 10;
    vector<vector<int>> estaciones = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};


     // Vector auxiliar: {posición, combustible}
    pos.clear();
    pos.push_back({0, combustibleInicial}); //inicio 
    for (auto e : estaciones) pos.push_back(e); //estaciones
    pos.push_back({objetivo, 0}); // destino final    
    destino = (int)pos.size() - 1;

    //memo.assign(pos.size(), vector<int>(D + 1, -1));
    memo.clear();   // <-- clear, no assign

    int res = minCantidadParadas(0, combustibleInicial);  // comienzo num_estacion 0, gasolina_actual
    //int res = minCantidadParadas(destino, combustibleInicial, estaciones);  // comienzo num_estacion 0, tanque lleno
    cout << "Costo mínimo: " << (res == INF ? -1 : res) << endl;  // 2
   return 0; 
    

    
}

  
    /*
// Ejemplo 1
int target1 = 1, startFuel1 = 1;
vector<vector<int>> stations1 = {};
cout << "Ejemplo 1: " << minRefuelStops(target1, startFuel1, stations1) << endl; // 0

// Ejemplo 2
int target2 = 100, startFuel2 = 1;
vector<vector<int>> stations2 = {{10, 100}};
cout << "Ejemplo 2: " << minRefuelStops(target2, startFuel2, stations2) << endl; // -1
*/
