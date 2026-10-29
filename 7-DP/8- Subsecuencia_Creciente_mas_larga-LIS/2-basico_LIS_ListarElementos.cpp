#include <bits/stdc++.h>

using namespace std;

int LIS(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // dp[i] = longitud de la LIS que termina en i
    vector<int> parent(n, -1); //**para guardar elementos

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { //j = cada elemento anterior a i.
            if (arr[j] < arr[i]) {
                 if (dp[j] + 1 > dp[i]) {     //** Esto es para guardar elementos
                     dp[i] = dp[j] + 1;     //** Equivale a max(dp[i], dp[j]+1), puedo poner esta linea o la q esta comentada
                     parent[i] = j;          //** Solo aquí guardamos el padre
                 }
                //dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
    }

  
// AQUI EL LISTADO DE ELEMENTOS Reconstruir la LIS--- Listar elementos
            int endIndex = max_element(dp.begin(), dp.end()) - dp.begin();
            vector<int> lis;
            for (int i = endIndex; i != -1; i = parent[i]) {
                lis.push_back(arr[i]);
            }
            reverse(lis.begin(), lis.end());

            cout << "Elementos de la LIS: ";
            for (int x : lis) cout << x << " ";
            cout << endl;


    return *max_element(dp.begin(), dp.end()); //devuelve el valor mas grande
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Longitud de la LIS: " << LIS(arr) << endl;  // 5
    return 0;
}