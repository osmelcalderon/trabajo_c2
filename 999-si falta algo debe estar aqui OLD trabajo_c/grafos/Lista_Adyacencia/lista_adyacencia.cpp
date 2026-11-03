//https://omegaup.com/arena/problem/Lista-de-Adyacencia
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lista(n); //lista de adyacencia

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        //aqui voy creando la lista de adyacencia
        lista[a].push_back(b); 
        lista[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        cout << i << ": ";

        for (int j = 0; j < lista[i].size(); j++) {
            if (j > 0)
                cout << "->";

            cout << lista[i][j];
        }

        cout << '\n';
    }

    return 0;
}