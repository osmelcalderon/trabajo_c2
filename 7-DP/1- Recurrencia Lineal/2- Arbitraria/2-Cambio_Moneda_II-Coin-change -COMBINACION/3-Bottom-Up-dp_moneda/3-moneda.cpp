#include <bits/stdc++.h>
using namespace std;
 
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

    long long cambio_moneda(int objetivo, vector<int> &monedas) { 
    
      if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
      //if (objetivo < 0 || i >= (int)monedas.size()) return 0;
      
        
        vector<long long> dp(objetivo + 1,0);
        dp[0]=1; // caso base: 1 forma de sumar 0

        //Como el problema es de (combinaciones), el orden correcto es monedas afuera
        // objetivo adentro......   Es decir si invierte el orden de ciclos
        for (int i = 0; i < (int)monedas.size(); i++) {
            for (int t = monedas[i]; t <= objetivo; t++) {
                    //dp[t] +=  dp[t - monedas[i]];
                    dp[t] = (dp[t] + dp[t - monedas[i]]) % MOD;
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

dp inicial: [1, 0, 0, 0, 0]

Moneda 1:
  t=1: dp[1] += dp[0] → 1
  t=2: dp[2] += dp[1] → 1
  t=3: dp[3] += dp[2] → 1
  t=4: dp[4] += dp[3] → 1
  dp = [1, 1, 1, 1, 1]

Moneda 2:
  t=2: dp[2] += dp[0] → 2
  t=3: dp[3] += dp[1] → 2
  t=4: dp[4] += dp[2] → 3
  dp = [1, 1, 2, 2, 3]

Moneda 3:
  t=3: dp[3] += dp[0] → 3
  t=4: dp[4] += dp[1] → 4
  dp = [1, 1, 2, 3, 4]


  Resultado: dp[4] = 4. Correcto.



  *********
  for (int t = monedas[i]; t <= objetivo; t++) {
   
  Ejemplo con monedas = {1, 2, 3}:
     Moneda 1 → t empieza en 1.
     Moneda 2 → t empieza en 2.
     Moneda 3 → t empieza en 3.
     Si empezaras siempre en 1 tendrías que poner if (monedas[i] <= t) adentro. Al empezar en monedas[i], ese if sobra.

        */