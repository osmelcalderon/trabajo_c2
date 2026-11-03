#include <bits/stdc++.h>
using namespace std;
//subset sum
//https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12
int subset_sum(vector<int>& nums, int n, int indice, vector<int>& camino_actual, vector<vector<int>>& todos_losCaminos) {

      todos_losCaminos.push_back(camino_actual); //fuera porque quiero guardar todos
      if (indice==n) {
        return 1;
      }
    // recursión
        int suma=1; //comieza en 1, porq tengo en cuenta el vacio {}
     
        for (int i = indice; i < n; i++) {
            camino_actual.push_back(nums[i]); 
            suma+=subset_sum(nums, n,i+1,camino_actual,todos_losCaminos);  //elegir - izquierda
            camino_actual.pop_back(); //backtraking
        }
     return suma;
    
}


int main() {

    vector<int> nums = {1,2,3,4};
    int n=(int)nums.size();
    vector<int> camino;
    vector<vector<int>> resultados;
    //cout << subset_sum(nums, n, 0,{},{}) << "\n";  // 2
    //ordenar el array
    //sort(nums.begin(), nums.end());
    cout << subset_sum(nums, n, 0,camino,resultados) << "\n";  // 2

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

