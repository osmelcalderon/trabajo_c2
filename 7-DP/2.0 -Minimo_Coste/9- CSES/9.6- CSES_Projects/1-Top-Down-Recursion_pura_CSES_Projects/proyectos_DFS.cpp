#include <bits/stdc++.h>
using namespace std;

int n; //cantidad de montañas

vector<vector<int>> proyectos;

vector<int> memo;

int dfs(int fila_a) {  //
    if (memo[fila_a] != -1) return memo[fila_a];   // memoización
    int mejor = proyectos[fila_a][2];   // tomar i y quedarme
    
    
    for (int fila_b = 0; fila_b < n; fila_b++) {
        if (fila_b == fila_a) continue; //mismo proyecto
        if (proyectos[fila_b][0] > proyectos[fila_a][1]) 
            mejor = max(mejor, proyectos[fila_a][2] + dfs(fila_b)); // Salto válido: recursión + backtracking implícito
        
    }
    return memo[fila_a] = mejor;                  // guardo y devuelvo
}

int main() {
   
    n=4;
    proyectos = {
        {2, 4, 4},
        {3, 6, 6},
        {6, 8, 2},
        {5, 7, 3}
    };
    
    memo.assign(n, -1);

    int acumulado = 0;
    
    for (int i = 0; i < n; i++)  //cada proyecto
        acumulado = max(acumulado, dfs(i)); //maximizar ganancia de proyectos

    cout << acumulado << "\n";
}