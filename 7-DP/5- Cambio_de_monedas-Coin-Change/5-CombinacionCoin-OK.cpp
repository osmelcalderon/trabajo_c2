/*
---En el 4--
Los resultados que te da el juez están diciendo dos cosas:
  WA (Wrong Answer): Respuesta es incorrecta en muchos casos. 
            Esto es porque estoy usando la versión que cuenta
            combinaciones (sin importar el orden), 
            pero el problema pide permutaciones (el orden SÍ importa).

 392 MB de memoria: Estoy usando demasiada memoria. 
         Esto es porque la tabla DP[i][j] es de tamaño (n+1) * (x+1).
         Con n=100 y x=10^6, eso son ~100 millones de enteros, 
         lo cual consume muchísima memoria.

         La solución es cambiar a la versión POR 
           una sola dimensión DP[j] 
           y recorrer las cantidades en el bucle externo.
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> monedas(n);
    for (int i = 0; i < n; i++) {
        cin >> monedas[i];
    }

    // DP[j] = número de formas de formar la cantidad j
    // Solo necesitamos un arreglo de tamaño x+1
    vector<int> DP(x + 1, 0);

    // Caso base: formar 0 tiene 1 forma (no usar ninguna moneda)
    DP[0] = 1;

    // Recorremos las cantidades (bucle externo)
    for (int j = 1; j <= x; j++) {
        // Para cada cantidad, probamos todas las monedas
        for (int i = 0; i < n; i++) {
            if (monedas[i] <= j) {
                DP[j] = (DP[j] + DP[j - monedas[i]]) % MOD;
            }
        }
    }

    cout << DP[x] << endl;

    return 0;
}