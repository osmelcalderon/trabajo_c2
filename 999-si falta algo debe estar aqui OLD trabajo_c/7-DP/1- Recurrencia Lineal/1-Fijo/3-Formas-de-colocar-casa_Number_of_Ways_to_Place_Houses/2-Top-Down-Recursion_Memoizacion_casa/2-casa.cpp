#include <bits/stdc++.h>
using namespace std;
 
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

    long long colocar_casa(int n, vector<long long>& memo) {
        if (n == 0) return 1; // Hay 1 sola forma cuando no hay terrenos: 1=dejarlo vacío
        if (n == 1) return 2; // hay 2 formas (se queda vacío o se pone una casa)

    if (memo[n]!=-1) { //  verifica caché
        return memo[n];
    }

    return memo[n]= (colocar_casa(n - 1,memo) + colocar_casa(n - 2,memo)) % MOD;
}

int main() {
    int n=2;
    vector<long long> memo(n + 1, -1); //relleno en -1 el vector memo
    long long k = colocar_casa(n,memo);
    cout << "Resultado: " << (k * k) % MOD   << endl;
    return 0;
}


/*
no tomar dos elementos adyacentes" en una fila de n posiciones. La recurrencia es: Fibonnanci
 casos base
 if (n == 0) return 1;	Hay 1 forma con 0 terrenos: dejarlo vacío	
 if (n == 1) return 2;	Hay 2 formas con 1 terreno: vacío o casa	

 Comprobemos manualmente n = 2 (terrenos 1 y 2):
    [ ][ ] → vacío
    [🏠][ ] → casa solo en el 1
    [ ][🏠] → casa solo en el 2
    [🏠][🏠] → ❌ inválido (adyacentes)
 
    Son 3 formas válidas. Por eso f(2) debe dar 3, y para eso necesitamos f(0) = 1.

colocar_casa(5)
├── colocar_casa(4)
│   ├── colocar_casa(3)
│   │   ├── colocar_casa(2)
│   │   │   ├── colocar_casa(1) → 2
│   │   │   └── colocar_casa(0) → 1
│   │   │   = 3
│   │   └── colocar_casa(1) → 2
│   │   = 5
│   └── colocar_casa(2) → 3  (ya en memo, no recalcula)
│   = 8
└── colocar_casa(3) → 5      (ya en memo, no recalcula)
= 13

*/