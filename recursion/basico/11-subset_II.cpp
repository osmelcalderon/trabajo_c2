#include <bits/stdc++.h>
using namespace std;

// subset sum (recorriendo de atrás hacia adelante)
void subset_sum(vector<int>& nums, int n, int indice,  vector<int>& camino_actual, vector<vector<int>>& resultados) {
    
    // Caso base: cuando el índice es menor a 0, ya evaluamos todos los elementos
    /*if (indice == n) {
        resultados.push_back(camino_actual); // Guardamos el subconjunto
        return ;
    }*/

    resultados.push_back(camino_actual); // Guardamos cada nodo del árbol

    //el for al mismo tiempo hace de caso base
    for (int i = indice; i < (int)nums.size(); i++) {

        // ✅ Saltar duplicados en el mismo nivel
        if (i > indice && nums[i] == nums[i - 1]) continue;
     
        // RAMA 1: incluir el elemento actual
        camino_actual.push_back(nums[i]);
        subset_sum(nums, n, i + 1,  camino_actual,resultados);  
        camino_actual.pop_back(); //Backtracking

        // RAMA 2: SÍ incluir el elemento actual
        //subset_sum(nums, n, indice + 1, camino_actual,resultados); 
    }
    
    
}

int main() {
    vector<int> nums = { 1, 2, 2};
    sort(nums.begin(),nums.end());
    int n = (int)nums.size();
    vector<int> camino;
    vector<vector<int>> resultados;
    int suma = 0;
    // Empezamos desde n-1 (el último índice del array)
     subset_sum(nums, n, 0, camino, resultados);

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