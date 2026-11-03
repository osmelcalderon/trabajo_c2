#include <bits/stdc++.h>
using namespace std;
 
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

    long long combinacion_dado(int n, vector<long long>& memo) {
        if (n == 0) return 1;  // 1 forma: no lanzar nada (suma vacía)
        if (n < 0)  return 0; // no se puede construir una suma negativa

    if (memo[n]!=-1) { //  verifica caché 
        return memo[n];
    }

    long long total = 0;
    for (int cara = 1; cara <= 6; cara++) { //voy a ir restando cada cara del cara
        total = (total + combinacion_dado(n - cara,memo)) % MOD;
    }
    return memo[n]=total;

    
}

int main() {
    int n=2;
    vector<long long> memo(n + 1, -1); //relleno en -1 el vector memo
    cout << "Resultado: " << combinacion_dado(n,memo)   << endl;
    return 0;
}


/*
combinacion_dado(2, memo)
├── combinacion_dado(1, memo)
│   ├── combinacion_dado(0)  → 1
│   ├── combinacion_dado(-1) → 0
│   ├── combinacion_dado(-2) → 0
│   ├── combinacion_dado(-3) → 0
│   ├── combinacion_dado(-4) → 0
│   └── combinacion_dado(-5) → 0
│   = 1  → memo[1] = 1
├── combinacion_dado(0)  → 1
├── combinacion_dado(-1) → 0
├── combinacion_dado(-2) → 0
├── combinacion_dado(-3) → 0
└── combinacion_dado(-4) → 0
= 1 + 1 + 0 + 0 + 0 + 0 = 2  → memo[2] = 2

*/