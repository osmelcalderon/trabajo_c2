#include <bits/stdc++.h>
using namespace std;

int n; //cantidad de montañas
vector<long long> montanas;  //array de montañas
vector<int> memo;

int dfs(int pos_a) {  //la montaña q se va a comparar con todas(q estan en pos_b), va estar ubicada en pos_a  
    if (memo[pos_a] != -1) return memo[pos_a];   // memoización
    int mejor = 1;                             // al menos cuento 1 para cuando comparen si no aparece ninguno al menos desde donde parte
    for (int pos_b = 0; pos_b < n; pos_b++) {
        if (pos_b == pos_a) continue; //si esta revisando la misma montaña continua
        if (montanas[pos_a] <= montanas[pos_b]) continue; //si la montaña a la que voy a saltar es mayor o igual no puedo salar

        //gracias a esto el for va ir a la izq o a la derecha
        int izq_i = min(pos_a, pos_b) + 1; // el índice más a la izquierda de los dos.
        int der_i = max(pos_a, pos_b) - 1; //el índice más a la derecha de los 2

        bool valido = true;
        for (int k = izq_i; k <= der_i; k++) {
            if (montanas[k] >= montanas[pos_b]) {  //si hay alguna montaña intermedio mas grande q el final, rompe ciclo y valido no cuenta
                  valido = false; 
                  break; 
            }
        }

        
        if (!valido) continue; //HABIA montaña intermedia mas grande q la destino

        // Salto válido: recursión + backtracking implícito
        mejor = max(mejor, 1 + dfs(pos_b));
        
    }
    return memo[pos_a] = mejor;                  // guardo y devuelvo
}

int main() {
    /*
    cin >> n;
    montanas.resize(n);
    for (auto &x : montanas) cin >> x;
    */
    n=10;
    montanas = {20, 15, 17, 35, 25, 40, 12, 19, 13, 12};
    memo.assign(n, -1);

    int acumulado = 0;
    
    for (int i = 0; i < n; i++)  //recorriendo cada posicion del arreglo, para comparar cada uno con todos
        acumulado = max(acumulado, dfs(i)); //mi intencion es maximizar cantidad de montañas q puedo saltar 

    cout << acumulado << "\n";
}