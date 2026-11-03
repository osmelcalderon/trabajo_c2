#include <bits/stdc++.h>
using namespace std;

int n;                          // tamaño del conjunto
vector<int> subset;   // aquí guardamos temporalmente cada subconjunto

// función recursiva
void search(int k) {
    if (k == n) {
        // caso base: ya decidimos sobre todos los elementos
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "}\n"; // mostramos el subconjunto actual
    } else {
        // 1️⃣ Opción: no incluir el elemento k
        search(k + 1);  

        // 2️⃣ Opción: incluir el elemento k
        subset.push_back(k); 
        search(k + 1); 

        // 🔄 limpieza (retroceso): quitamos k para volver atrás
        subset.pop_back();{ }

    }
}

int main() {
    n = 3; // conjunto {0, 1, 2}
    search(0); // comenzamos desde el primer elemento
    return 0;
}
