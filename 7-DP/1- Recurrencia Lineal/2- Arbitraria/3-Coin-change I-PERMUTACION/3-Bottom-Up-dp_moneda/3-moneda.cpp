#include <bits/stdc++.h>
using namespace std;
 
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

    long long cambio_moneda(int objetivo, vector<int> &monedas) { 
    
      if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
            
        
        vector<long long> dp(objetivo + 1,0);
        dp[0]=1; // caso base: 1 forma de sumar 0

        //Permutacion
        // objetivo afuera......   Monedas adentro
        
        for (int t = 1; t <= objetivo; t++) {
            for (int i = 0; i < (int)monedas.size(); i++) {
                if (monedas[i] <= t) {   
                  dp[t] = (dp[t] + dp[t - monedas[i]]) % MOD;
                }
            }
        }    
        return dp[objetivo];
}

int main() {
    vector<int> monedas = {1, 2, 3};
    int objetivo=4;
    cout << "Resultado: " << cambio_moneda(objetivo,monedas)  << endl;
}


/*
Bottom-Up (iterativo)

Con monedas = {1, 2, 3}, objetivo = 4:

dp[0] = 1

t=1:
  i=0: 1 ≤ 1 → dp[1] += dp[0] = 1
  i=1: 2 > 1 → no
  i=2: 3 > 1 → no
  dp[1] = 1

t=2:
  i=0: 1 ≤ 2 → dp[2] += dp[1] = 1
  i=1: 2 ≤ 2 → dp[2] += dp[0] = 1 → 2
  i=2: 3 > 2 → no
  dp[2] = 2

t=3:
  i=0: 1 ≤ 3 → dp[3] += dp[2] = 2
  i=1: 2 ≤ 3 → dp[3] += dp[1] = 1 → 3
  i=2: 3 ≤ 3 → dp[3] += dp[0] = 1 → 4
  dp[3] = 4

t=4:
  i=0: 1 ≤ 4 → dp[4] += dp[3] = 4
  i=1: 2 ≤ 4 → dp[4] += dp[2] = 2 → 6
  i=2: 3 ≤ 4 → dp[4] += dp[1] = 1 → 7
  dp[4] = 7
Resultado: 7. Correcto para permutaciones. 


        */