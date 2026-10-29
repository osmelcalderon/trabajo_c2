#include <bits/stdc++.h>
using namespace std;
 
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

    long long combinacion_dado(int n) {
        if (n == 0) return 1;  // 1 forma: no lanzar nada (suma vacía)
        

        vector<long long> dp(n + 1); 
        dp[0]=1; //no lanzar nada.  1 forma: suma vacía
 
         // Versión explícita (6 sumandos)
        for (int i = 1; i <= n; i++) {            // ← bucle principal
            //dp[i] =( dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6])  % MOD;
            //condiciones, para evitar q se valla fuera de rango
            if (i - 1 >= 0) dp[i] = (dp[i] + dp[i-1]) % MOD;
            if (i - 2 >= 0) dp[i] = (dp[i] + dp[i-2]) % MOD;
            if (i - 3 >= 0) dp[i] = (dp[i] + dp[i-3]) % MOD;
            if (i - 4 >= 0) dp[i] = (dp[i] + dp[i-4]) % MOD;
            if (i - 5 >= 0) dp[i] = (dp[i] + dp[i-5]) % MOD;
            if (i - 6 >= 0) dp[i] = (dp[i] + dp[i-6]) % MOD;
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