#include <bits/stdc++.h>

using namespace std;

// Función recursiva con memoización.... Es menos eficiente q sin recursividad
int cambio(int i, int c, const vector<int>& monedas, vector<vector<int>>& memo) {
    // Caso base 1: Si la cantidad es 0, no necesitamos monedas
    if (c == 0) return 0;
    
    // Caso base 2: Si no quedan monedas y aún debemos pagar, es imposible
    if (i == 0) return INT_MAX;

    // Si ya calculamos este subproblema, lo devolvemos de inmediato
    if (memo[i][c] != -1) return memo[i][c];

    int resultado;

    // Si la moneda actual es más grande que la cantidad, no la usamos
    if (monedas[i - 1] > c) {
        resultado = cambio(i - 1, c, monedas, memo);
    } else {
        // Opción A: No usar la moneda
        int no_usar = cambio(i - 1, c, monedas, memo);
        
        // Opción B: Usar la moneda (restamos su valor y seguimos con la misma moneda)
        int usar = cambio(i, c - monedas[i - 1], monedas, memo);
        if (usar != INT_MAX) usar += 1; // Sumamos 1 por la moneda que acabamos de usar

        resultado = min(no_usar, usar);
    }

    // Guardamos el resultado en la memoria antes de devolverlo
    memo[i][c] = resultado;
    return resultado;
}

int main() {
    vector<int> monedas = {2, 3, 7};
    int cantidad = 8;
    int n = monedas.size();

    // Inicializamos la tabla de memoria con -1 (significa "no calculado")
    vector<vector<int>> memo(n + 1, vector<int>(cantidad + 1, -1));

    int resultado = cambio(n, cantidad, monedas, memo);

    if (resultado == INT_MAX) {
        cout << "No es posible formar la cantidad exacta." << endl;
    } else {
        cout << "Minimo numero de monedas necesarias: " << resultado << endl;
    }

    return 0;
}