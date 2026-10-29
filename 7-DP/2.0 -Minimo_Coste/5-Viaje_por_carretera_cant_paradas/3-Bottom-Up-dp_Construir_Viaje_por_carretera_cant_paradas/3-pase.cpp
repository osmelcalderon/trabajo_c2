#include <bits/stdc++.h>
using namespace std;
 
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

    long long suma_combinacion(int objetivo, vector<int> &elementos) { 
    
        if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
        if (objetivo < 0) return 0; // me pase, esa rama no aporta, cuenta como 0.
        
        vector<long long> dp(objetivo + 1,0);
        dp[0]=1; // caso base: 1 forma de sumar 0


        for (int t = 1; t <= objetivo; t++) {
            long long total = 0; //aqui voy guardando el acumulado
            for (int i = 0; i < (int)elementos.size(); i++) {
                if (elementos[i] <= t) { //solo usa elementos que caben ✔
                    total += dp[t - elementos[i]];
                }
            }
            dp[t] = total % MOD;
        }    
        return dp[objetivo];
}

int main() {
    vector<int> elementos = {1, 2, 3};
    int objetivo=4;
    cout << "Resultado: " << suma_combinacion(objetivo,elementos)  << endl;
}


/*
Bottom-Up (iterativo)
En lugar de ir de objetivo hacia abajo recursivamente, llenas una tabla dp desde 0 hasta objetivo.

Recurrencia

dp[0] = 1                          // 1 forma de sumar 0: no tomar nada
dp[t] = Σ dp[t - elementos[i]]     para todo i con elementos[i] ≤ t





*/

        /*
        hay un momento en que el objetivo llega hacer 1 en la recursividad de arrbiba hacia abajo
        porque va quitandole a los valores de la lista
        
        es como si en este ejercicio estuvieramos diciendole al objetivo, llegaras un instante a 
        que vas a ser sub-ojetivo, es decir, mientras mas pequeño te ponga, mas cerca de la
        solucion vas a estar
        por eso voy a comenzar desde donde menos valor va a obtener la variable objetivo
        es decir 1
        y ese 1 lo voy a comparar con cada caso de la lista los elementos = {1, 2, 3};
        si los elementos de la lista son menores iguales que ese subojetivo en este caso
        1 entonces se podra restar, sino no se resta
        asi sera y luego voy hacerlo con objetivo =2, hasta q objetivo llegue a 4, que es el objetivo
        realmente a cumplir, es decir,
        es como si fuera de abajo hacia arriba, haciendo calculo 
        

        */


         /*
        Bottom-Up (iterativo)
        =====================
        En vez de bajar con recursión desde 'objetivo' hasta 0, llenamos una tabla
        dp[] desde 0 hasta 'objetivo', en orden ascendente.

        Recurrencia:
            dp[0] = 1                        // 1 forma de sumar 0: no tomar nada
            dp[t] = Σ dp[t - elementos[i]]   para todo i con elementos[i] <= t

        ¿Por qué el for va de t = 1 hasta objetivo (menor a mayor)?
        -----------------------------------------------------------
        Porque dp[t] depende de dp[t - elementos[i]], y como elementos[i] >= 1,
        esos índices son SIEMPRE menores que t. Es decir, para calcular dp[t]
        necesito que dp[0], dp[1], ..., dp[t-1] ya estén listos.

        Ese es exactamente el mismo orden en que la recursión pura resolvía
        los subproblemas al volver de la pila: f(0) → f(1) → f(2) → ... → f(t).
        Bottom-up solo lo hace explícito con un for, sin usar la pila.


nums = [1, 2, 3],  objetivo = 4
dp[0] = 1

total = Σ dp[t - elementos[i]]  
 nota: total no es  1-1=0, 2-1=1... 
        sino que tienes que mirar dp[t - elementos[i]],  dp[1-1] = 0
        no el resultado de la resta suelta.
dp[t] = total
Es decir, para calcular dp[t]
        necesito que dp[0], dp[1], ..., dp[t-1] ya estén listos.
─────────────────────────────────────────────
t = 1
  i=0 → elementos[0]=1 ≤ 1 → total += dp[1-1] = dp[0] = 1
  i=1 → elementos[1]=2 > 1 → NO
  i=2 → elementos[2]=3 > 1 → NO
  total = 1
  dp[1] = 1

─────────────────────────────────────────────
t = 2
  i=0 → 1 ≤ 2 → total += dp[2-1] = dp[1] = 1
  i=1 → 2 ≤ 2 → total += dp[2-2] = dp[0] = 1
  i=2 → 3 > 2 → NO
  total = 1 + 1 = 2
  dp[2] = 2

─────────────────────────────────────────────
t = 3
  i=0 → 1 ≤ 3 → total += dp[3-1] = dp[2] = 2
  i=1 → 2 ≤ 3 → total += dp[3-2] = dp[1] = 1
  i=2 → 3 ≤ 3 → total += dp[3-3] = dp[0] = 1
  total = 2 + 1 + 1 = 4
  dp[3] = 4

─────────────────────────────────────────────
t = 4
  i=0 → 1 ≤ 4 → total += dp[4-1] = dp[3] = 4
  i=1 → 2 ≤ 4 → total += dp[4-2] = dp[2] = 2
  i=2 → 3 ≤ 4 → total += dp[4-3] = dp[1] = 1
  total = 4 + 2 + 1 = 7
  dp[4] = 7

        */