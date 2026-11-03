/*
calcular la "cantidad de formas distintas" en que puede producir una suma de dinero x usando las monedas disponibles.
Por ejemplo, si las monedas son {2ⓜ,3ⓜ,5} y la suma deseada es 9, hay 8 maneras:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
*/


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Función que devuelve la cantidad de formas distintas
// de formar la cantidad 'x' con las monedas dadas.
int contarFormas(const vector<int>& monedas, int x) {
    int n = monedas.size();

    // Tabla DP: (n+1) filas x (x+1) columnas
    // DP[i][j] = cantidad de formas de formar 'j' usando las primeras 'i' monedas
    vector<vector<int>> DP(n + 1, vector<int>(x + 1, 0));

    // Caso base: formar la cantidad 0 tiene 1 forma (no usar ninguna moneda)
    for (int i = 0; i <= n; i++) {
        DP[i][0] = 1;
    }

    // Llenado de la tabla
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {

            // Si la moneda es más grande que la cantidad, no la podemos usar
            if (monedas[i - 1] > j) {
                DP[i][j] = DP[i - 1][j];
            } else {
                // Opción A: No usar la moneda i
                int no_usar = DP[i - 1][j];

                // Opción B: Usar la moneda i (y seguir pudiendo usarla)
                int usar = DP[i][j - monedas[i - 1]];

                // Sumamos ambas y aplicamos módulo
                DP[i][j] = (no_usar + usar) % MOD;
            }
        }
    }

    return DP[n][x];
}

int main() {
    //entrada
    int n, x;    cin >> n >> x;
   
    vector<int> monedas(n);
    for (int i = 0; i < n; i++) {
        cin >> monedas[i];
    }

    int resultado = contarFormas(monedas, x);

    cout << resultado << endl;

    return 0;
}