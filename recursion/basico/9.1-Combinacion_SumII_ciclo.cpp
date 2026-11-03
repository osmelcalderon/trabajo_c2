#include <bits/stdc++.h>
using namespace std;
//combinacion sum
//https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10

int combinacion_sum(vector<int>& nums, int objetivo, int indice, vector<int>& camino_actual, set<vector<int>>& todos_losCaminos) {
    


    // Caso base: encontramos una combinación
    if (objetivo == 0) {
         todos_losCaminos.insert(camino_actual);
         return 1;
    }

    // Caso base: nos pasamos restando
    if (objetivo < 0) return 0;

    // Caso base: se acabaron los elementos
    //este lo puedo eliminar, porq ya esta implicito en el for
    //if (indice == (int)nums.size()) return 0;
    
    // recursión
        int suma=0;
     
        for (int i = indice; i < (int)nums.size(); i++) {

            camino_actual.push_back(nums[i]); 
            // Elegir nums[indice] (reusar → mismo indice)
            suma+=combinacion_sum(nums, objetivo-nums[i],i+1,camino_actual,todos_losCaminos);  //elegir - izquierda
            camino_actual.pop_back(); //backtraking

        }
        

     
     return suma;
     
    
}


int main() {

    vector<int> nums = {1, 1, 1, 2, 2};
    int objetivo=4;
    vector<int> camino;
    set<vector<int>> resultados;
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