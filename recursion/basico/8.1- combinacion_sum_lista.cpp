#include <bits/stdc++.h>
using namespace std;
//combinacion sum
//https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10

int combinacion_sum(vector<int>& nums, int objetivo, int indice, vector<int> camino_actual, vector<vector<int>>& todos_losCaminos) {
    
    // Caso base: se acabaron los elementos
    if (indice == (int)nums.size()) return 0;

    // Caso base: encontramos una combinación
    if (objetivo == 0) {
         todos_losCaminos.push_back(camino_actual);
         return 1;
    }

    // Caso base: nos pasamos restando
    if (objetivo < 0) return 0;

     // recursión
        int suma=0;
     
        camino_actual.push_back(nums[indice]); 
        // Elegir nums[indice] (reusar → mismo indice)
        suma+=combinacion_sum(nums, objetivo-nums[indice],indice,camino_actual,todos_losCaminos);  //elegir - izquierda
        camino_actual.pop_back(); //backtraking

        // No elegir nums[indice] (avanzar → indice + 1)
        suma+=combinacion_sum(nums, objetivo,indice+1,camino_actual,todos_losCaminos);  // no elegir - derecha
     
     return suma;
     
    
}


int main() {

    vector<int> nums = {2, 3, 6, 7};
    int objetivo=7;
    vector<int> camino;
    vector<vector<int>> resultados;
    //cout << combinacion_sum(nums, objetivo, 0,{},{}) << "\n";  // 2
    cout << combinacion_sum(nums, objetivo, 0,camino,resultados) << "\n";  // 2

    for (const auto& comb : resultados) {      // comb es vector<int>
        cout << "[";
        for (int i = 0; i < (int)comb.size(); i++) {
            cout << comb[i];
            if (i + 1 < (int)comb.size()) cout << ",";
        }
        cout << "]\n";
    }
    cout << "\n";
   
    return 0;
}

/*
siempre que yo pueda utilizar un elemento 2 veces, pues lo invoco 2 veces, en este caso dentro de un for
*/