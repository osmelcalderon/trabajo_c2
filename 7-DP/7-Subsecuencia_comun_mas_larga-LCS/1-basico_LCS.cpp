#include <bits/stdc++.h>

using namespace std;

// Estructura para devolver ambas tablas
struct ResultadoLCS {
    vector<vector<int> > c;  //Números (longitudes).	Para Saber cuánto mide la LCS
};

ResultadoLCS calcularLCS(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Crear tablas de tamaño (m+1) x (n+1) inicializadas en 0
    //¿Cuál es la longitud de la subsecuencia común más larga entre los primeros i caracteres de X y los primeros j caracteres de Y?
    //La celda c[m][n] (esquina inferior derecha) te da la LONGITUD de la LCS
    // La tabla c solo te dice cuánto mide, pero NO te dice cuáles son los caracteres.
    vector<vector<int> > c(m + 1, vector<int>(n + 1, 0)); 

    

    // Llenado de las tablas   c y b
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) { //compara cada x[i] = y[0..n]
                c[i][j] = c[i - 1][j - 1] + 1; //si coincide agarrar el diagonal (↖) y SUMO 1
            } 
            else if (c[i - 1][j] >= c[i][j - 1]) { //si casillaArriba>=casillaIzquierda
                c[i][j] = c[i - 1][j];   //agarra la casilla Arriba
            } 
            else {
                c[i][j] = c[i][j - 1]; //agarra casilla izquierda
            }
        }
    }

    return {c};
}


int main() {
    string X = "sprintime";
    string Y = "printing";

    ResultadoLCS resultado = calcularLCS(X, Y);

    cout << "Longitud de la LCS: " << resultado.c[X.length()][Y.length()] << endl;
    cout << endl;
    return 0;
}