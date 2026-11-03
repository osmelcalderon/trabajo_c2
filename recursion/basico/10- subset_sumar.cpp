#include <bits/stdc++.h>
using namespace std;

// subset sum (recorriendo de atrás hacia adelante)
void subset_sum(vector<int>& nums, int n, int indice, int suma, vector<int>& camino_actual) {
    
    // Caso base: cuando el índice es menor a 0, ya evaluamos todos los elementos
    if (indice == n) {
        camino_actual.push_back(suma); // Guardamos el subconjunto
       return ;
    }
    
    // RAMA 1: NO incluir el elemento actual
    // Solo llamamos a la recursión sin tocar camino_actual
    subset_sum(nums, n, indice + 1, suma+nums[indice], camino_actual);  
    // RAMA 2: SÍ incluir el elemento actual
    subset_sum(nums, n, indice + 1, suma, camino_actual); 

    
    
}

int main() {
    vector<int> nums = { 2, 3};
    int n = (int)nums.size();
    vector<int> camino;
    vector<int> resultados;
    int suma = 0;
    // Empezamos desde n-1 (el último índice del array)
     subset_sum(nums, n, 0,suma, camino);

    sort(camino.begin(), camino.end());
    for (const auto& x : camino) {
        cout << "[" << x << "]\n";
    }
   
    return 0;
}