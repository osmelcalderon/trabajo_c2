#include <bits/stdc++.h>
using namespace std;

int N_niveles, E_barra_energia, P_pociones;
vector<int> dificultad_nivel;
//map<pair<int,long long>, int> memo;   // <-- map
map<tuple<int,long long,int>, int> memo;   // (nivel, energía, pociones restantes) -> máx niveles

int maxNiveles(int num_niveles, long long Energia_actual, int Num_pocion_actual) { //inicio num_niveles=0,E_barra_energia
 
    // Caso base: hemos jugado todos los niveles
    if (num_niveles == N_niveles) return 0;
    
    // Memoización, TUPLA porque depende de 3 cosas num_niveles, Energia_actual, Num_pocion_actual
    
    
    auto clave = make_tuple(num_niveles, Energia_actual, Num_pocion_actual);
    if (memo.count(clave)) return memo[clave];

    
    int mejor = 0; 
    
    //1-avanzá sin tomar pocion: "si me alcanza sin cargar". (sin comprar gasolina)
    if (Energia_actual >= dificultad_nivel[num_niveles])  
        mejor = max(mejor, 1+ maxNiveles(num_niveles + 1, Energia_actual - dificultad_nivel[num_niveles],Num_pocion_actual )); 

    // 2)  Avanzar tomando pocion y jugar el nivel (si quedan pociones y alcanza con E)
        if (Num_pocion_actual > 0 && E_barra_energia >= dificultad_nivel[num_niveles]) {
            mejor = max(mejor, 1 + maxNiveles(num_niveles + 1, E_barra_energia - dificultad_nivel[num_niveles],Num_pocion_actual-1));
        }

        // 3) Terminar el speedrun aquí (no jugar más niveles),   Ya está cubierto por mejor = 0 (no sumamos nada)
      return memo[clave] = mejor;
}

int main() {

    N_niveles = 5; //cantidad de niveles
    E_barra_energia = 10; //Máximo de barra de energía .. Se restaura con cada posicion q tomes 
    P_pociones=1; // total de pociones (cada vez q me la tomo restaura completo a E al maximo)
    dificultad_nivel = {4, 5, 6, 3, 2}; //dificultades[i] de cada nivel y es también energía E  q gastas

    int res = maxNiveles(0, E_barra_energia, P_pociones);  // comienzo num_niveles 0, Energia_actual
    cout << "Máximo de niveles: " <<  res << endl;  // 2
   return 0; 
    
}

  
  
