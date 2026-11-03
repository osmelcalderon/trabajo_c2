#include <bits/stdc++.h>
using namespace std;

// Función que devuelve el mínimo número de monedas necesarias
// Retorna -1 si no es posible formar la cantidad exacta
int minimoMonedas(const vector<int>& monedas, int cantidad) {
    int n = monedas.size();

    // Tabla DP: (n+1) filas x (cantidad+1) columnas
    vector<vector<int>> DP(n + 1, vector<int>(cantidad + 1, INT_MAX)); //primera fila todos ∞

    // Caso base: formar la cantidad 0 requiere 0 monedas
    //primera columna todos 0
    for (int i = 0; i <= n; i++) {
        DP[i][0] = 0;
    }

    // Llenado de la tabla
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cantidad; j++) {

            /*	Si la moneda es más grande que lo que debemos pagar (X_n>c):
            	Es obvio que no podemos usar esa moneda porque nos pasaríamos del precio.
	            Solución: La ignoramos y resolvemos el problema usando solo las monedas anteriores.
                cambio(n, c) = cambio(n-1, c) es lo mismo --->  DP[i][j] = DP[i - 1][j];
                */
            if (monedas[i - 1] > j) { 
                DP[i][j] = DP[i - 1][j];
            } else { /*	Si la moneda es igual o más pequeña que lo que debemos pagar (X_n ≤ c):
                        Aquí tenemos dos opciones y debemos elegir la mejor (la que use menos monedas  
                       
                       caso A: Tomamos esa moneda (sumamos 1 al contador) y reducimos la deuda en su valor.
                          Seguimos teniendo la misma moneda disponible por si necesitamos más.
                               cambio(n, c - X_n) + 1---> DP[i][j - monedas[i - 1]];
                       
                       caso B (No usarla): usando solo las monedas anteriores.   DP[i][j] = DP[i - 1][j]      
                      */
                      
                int no_usar = DP[i - 1][j];  //monedas anteriores
                int usar = DP[i][j - monedas[i - 1]]; //rebajar c - Xn
                if (usar != INT_MAX) usar += 1;
                DP[i][j] = min(no_usar, usar); //minimo entre arriba y la q se uso
            }
        }
    }

    // Si sigue siendo INT_MAX, no se pudo formar
    if (DP[n][cantidad] == INT_MAX) return -1;
    return DP[n][cantidad]; //retorna la ultima casilla q trae resultado
}

int main() {
    vector<int> monedas = {2, 3, 7};
    int cantidad = 8;

    int resultado = minimoMonedas(monedas, cantidad);

    if (resultado == -1) {
        cout << "No es posible formar la cantidad exacta." << endl;
    } else {
        cout << "Minimo numero de monedas necesarias: " << resultado << endl;
    }

    return 0;
}