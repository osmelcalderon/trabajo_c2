#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matriz;
bool dfs(int inicio, int destino, Matriz& grafo) {

    vector<bool> visitado(grafo.size(), false);
    stack<int> pila;

    pila.push(inicio);
    visitado[inicio] = true;

    while (!pila.empty()) {

        int u = pila.top();
        pila.pop();

        if (u == destino) { //AQUI comprobacion de nodo alcanzado
            return true;
        }

        for (int v : grafo[u]) {

            if (!visitado[v]) {
                visitado[v] = true;
                pila.push(v);
            }
        }
    }

    return false;
}

int main() {

    int N, M;
    cin >> N >> M;

    Matriz grafo(N);

    for (int i = 0; i < M; i++) {

        int X, Y;
        cin >> X >> Y;

        grafo[X].push_back(Y); //matriz de adyacencia pero en una sola direccion, porque es "GRAFO DIRIGIDO"
    }

    if (dfs(0, N - 1, grafo)) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}