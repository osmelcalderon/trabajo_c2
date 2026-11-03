#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14
void subset_sum(vector<int>& nums, int n, int indice,  vector<int>& camino_actual, vector<vector<int>>& resultados, vector<bool>& usado) {
    
   // Caso base: si el camino ya tiene el mismo tamaño que nums, es una permutación completa
   if (camino_actual.size() == nums.size()) {
    resultados.push_back(camino_actual);
    return;
   }

    

    //el for al mismo tiempo hace de caso base
    for (int i = 0; i < (int)nums.size(); i++) {

        if (usado[i]) continue;

        // Saltar duplicados en el mismo nivel
         if (i > indice && nums[i] == nums[i - 1]) continue;
     
        // RAMA 1: incluir el elemento actual
        camino_actual.push_back(nums[i]);
        usado[i] = true; // Lo marcamos como usado
        subset_sum(nums, n, i + 1,  camino_actual,resultados,usado);  
        camino_actual.pop_back(); //Backtracking
        usado[i] = false; // Lo desmarcamos


    }
    
    
}

int main() {
    //vector<int> nums = { 1,1, 2, 3}; esta preparado tambien para evitar duplicados
    vector<int> nums = { 1, 2, 3};
    sort(nums.begin(),nums.end());
    int n = (int)nums.size();
    vector<int> camino;
    vector<vector<int>> resultados;
    vector<bool> usado(nums.size(), false); // Todo empieza en false

    int suma = 0;
    // Empezamos desde n-1 (el último índice del array)
     subset_sum(nums, n, 0, camino, resultados,usado);

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