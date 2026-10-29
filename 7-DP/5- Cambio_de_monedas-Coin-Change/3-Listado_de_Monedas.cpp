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
            if (monedas[i - 1] > j) { //no usar, Si la moneda es más grande que lo que debemos pagar 
                DP[i][j] = DP[i - 1][j];
            } else { 
                int no_usar = DP[i - 1][j];  //monedas anteriores
                int usar = DP[i][j - monedas[i - 1]]; 
                if (usar != INT_MAX) usar += 1;
                DP[i][j] = min(no_usar, usar); 
            }
        }
    }

    // Si sigue siendo INT_MAX, no se pudo formar
    if (DP[n][cantidad] == INT_MAX) return -1;


// ==========================================
    // RECONSTRUCCIÓN: ¿Qué monedas se usaron?
    // ==========================================
    cout << "Monedas utilizadas: ";
    int i = n, j = cantidad;
    while (j > 0 && i > 0) {
        // Si el valor en DP[i][j] es igual al de arriba (DP[i-1][j]),
        // significa que NO usamos la moneda i.
        if (DP[i][j] == DP[i - 1][j]) {
            i--; // Nos movemos a la fila de arriba
        } else {
            // Si no es igual, significa que SÍ usamos la moneda i.
            cout << monedas[i - 1] << " ";
            j -= monedas[i - 1]; // Restamos su valor a la cantidad restante
            // Nos quedamos en la misma fila 'i' porque podemos repetir la moneda
        }
    }
    cout << endl;

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