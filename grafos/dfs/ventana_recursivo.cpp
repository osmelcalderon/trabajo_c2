#include <bits/stdc++.h>
using namespace std;
//https://omegaup.com/arena/problem/ventanas
vector<vector<int>> grafo;
vector<bool> visitado;

int dfs(int u) {
    visitado[u] = true;
    int clicks = 1;
    for (int v : grafo[u]) {
        if (!visitado[v]) {
            clicks += dfs(v);
        }
    }
    return clicks;
}

//aqui es donde esta el truco, porque es un DFS con variante de geometria
bool cubre(int ventana, int fila, int columna,
           vector<int>& R1, vector<int>& S1,
           vector<int>& R2, vector<int>& S2) {

    return R1[ventana] <= fila &&
                  fila <= R2[ventana] &&
                  S1[ventana] <= columna &&
                  columna <= S2[ventana];
}


int main() {

    int N;
    cin >> N;

    vector<int> R1(N), S1(N), R2(N), S2(N);
    for (int i = 0; i < N; i++) {
        cin >> R1[i] >> S1[i] >> R2[i] >> S2[i];
    }

    grafo.resize(N);
    visitado.resize(N, false);

    // Construimos las dependencias
    for (int i = 0; i < N; i++) {

        // Botón de cerrar de la ventana i:
        // esquina superior derecha
        int fila = R1[i];
        int columna = S2[i];

        // Solo las ventanas abiertas DESPUÉS de i
        // pueden estar encima de ella.
       //las ventanas J son todas las que están encima de i
        for (int j = i + 1; j < N; j++) {
            if (cubre(j, fila, columna, R1, S1, R2, S2)) {
                grafo[i].push_back(j); //vamos creando una lista de adyacencia
            }
        }
    }
    cout << dfs(0) << endl;

    return 0;
}