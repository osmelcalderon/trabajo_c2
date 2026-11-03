#include <bits/stdc++.h>
using namespace std;

// subset sum (recorriendo de atrás hacia adelante)
int subset_sum(vector<int>& nums, int n, int indice, vector<int>& camino_actual, vector<vector<int>>& todos_losCaminos) {
    cout << "indice: " << indice << "\n\n";

    // Caso base: cuando el índice es menor a 0, ya evaluamos todos los elementos
    if (indice < 0) {
        todos_losCaminos.push_back(camino_actual); // Guardamos el subconjunto
        return 1;
    }
    
    int suma = 0;
    
    // RAMA 1: NO incluir el elemento actual
    // Solo llamamos a la recursión sin tocar camino_actual
    suma += subset_sum(nums, n, indice - 1, camino_actual, todos_losCaminos);  
    
    // RAMA 2: SÍ incluir el elemento actual
    camino_actual.push_back(nums[indice]); // Lo agregamos al camino
    suma += subset_sum(nums, n, indice - 1, camino_actual, todos_losCaminos); 
    camino_actual.pop_back(); // Backtracking: lo quitamos para volver atrás
    
    return suma;
}

int main() {
    vector<int> nums = { 2, 3};
    int n = (int)nums.size();
    vector<int> camino;
    vector<vector<int>> resultados;
    
    // Empezamos desde n-1 (el último índice del array)
    cout << "Total de subconjuntos: " << subset_sum(nums, n, n - 1, camino, resultados) << "\n\n";

    for (const auto& comb : resultados) {
        cout << "[";
        for (int i = 0; i < (int)comb.size(); i++) {
            cout << comb[i];
            if (i + 1 < (int)comb.size()) cout << ",";
        }
        cout << "]\n";
    }
   
    return 0;
}