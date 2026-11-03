#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14
void subset_sum(vector<int>& nums, int indice, vector<vector<int>>& resultados) {
    
    
   // Caso base: si el camino ya tiene el mismo tamaño que nums, es una permutación completa
   if (indice == nums.size()) {
    resultados.push_back(nums);
    return;
   }

    

    //el for al mismo tiempo hace de caso base
    for (int i = indice; i < (int)nums.size(); i++) {

        // Swap: ponemos el elegido en la posición actual
        swap(nums[indice], nums[i]);  //es decir q cada indice lo voy a intercambiar con cada i=indice+1..n

        // Recursión: avanzamos al siguiente índice
        subset_sum(nums, indice + 1, resultados);

        // Backtracking: deshacemos el swap
        swap(nums[indice], nums[i]);

    }
    
    
}

int main() {
    //vector<int> nums = { 1,1, 2, 3}; esta preparado tambien para evitar duplicados
    vector<int> nums = { 1, 2, 3};
    sort(nums.begin(),nums.end());
    int n = (int)nums.size();
    
    vector<vector<int>> resultados;
    vector<bool> usado(nums.size(), false); // Todo empieza en false

    int suma = 0;
    // Empezamos desde n-1 (el último índice del array)
     subset_sum(nums, 0, resultados);

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