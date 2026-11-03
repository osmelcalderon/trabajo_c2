#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//https://omegaup.com/arena/problem/L-OMI-Super-Agente
//BFS multifuente
void bfs(vector<string>& mapa, vector<vector<int>>& dist) {

    int M = mapa.size();
    int N = mapa[0].size();

    queue<pair<int, int>> q;

    // Todos los guardias son puntos iniciales
    //La parte que hace que sea simultáneo es esta
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            if (mapa[i][j] == 'G') {
                dist[i][j] = 0; //partir de 0, para contar luego
                q.push({i, j});
            }

        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {

        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            // Fuera del mapa
            if (nr < 0 || nr >= M || nc < 0 || nc >= N)
                continue;

            // Pared
            if (mapa[nr][nc] == '#')
                continue;

            // Ya visitada
            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[r][c] + 1;

            q.push({nr, nc});
        }
    }
}

int main() {

    int M, N;
    cin >> M >> N;

    vector<string> mapa(M);

    for (int i = 0; i < M; i++) {
        cin >> mapa[i];
    }

    // -1 significa que todavía no conocemos la distancia
    vector<vector<int>> dist(M, vector<int>(N, -1));

    bfs(mapa, dist);


    //finalmente encontrar el maximo
    int maximo = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            if (mapa[i][j] != '#') {
                maximo = max(maximo, dist[i][j]);
            }

        }
    }

    cout << maximo << '\n';

    /*
    // Mostrar distancias
    for (int i = 0; i < M; i++) {

        for (int j = 0; j < N; j++) {

            if (mapa[i][j] == '#')
                cout << "# ";
            else
                cout << dist[i][j] << " ";
        }

        cout << '\n';
    }*/

    return 0;
}