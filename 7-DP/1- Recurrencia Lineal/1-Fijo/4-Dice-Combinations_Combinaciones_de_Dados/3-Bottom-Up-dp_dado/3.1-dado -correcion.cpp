#include <bits/stdc++.h>
using namespace std;
 
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

    long long combinacion_dado(int n) {
        if (n == 0) return 1;  // 1 forma: no lanzar nada (suma vacía)
        

        vector<long long> dp(n + 1); 
        dp[0]=1; //no lanzar nada.  1 forma: suma vacía
 
         // Versión con bucle (comentada) k-bonnanci
        for (int i = 1; i <= n; i++) {            // ← bucle principal
            for (int cara = 1; cara <= 6; cara++) { // ← bucle interno
                if (i - cara >= 0) {              // ← evita índices negativos, y me quito todos los if
                    dp[i] = (dp[i] + dp[i - cara]) % MOD;
                }
            }
        }
        return dp[n];
        

}

int main() {
    int n=2;
    cout << "Resultado: " << combinacion_dado(n)  << endl;
    return 0;
}


/*

*/