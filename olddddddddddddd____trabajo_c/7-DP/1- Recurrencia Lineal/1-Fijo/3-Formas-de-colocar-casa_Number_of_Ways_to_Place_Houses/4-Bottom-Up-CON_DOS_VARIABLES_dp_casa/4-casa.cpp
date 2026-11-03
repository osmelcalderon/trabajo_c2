#include <bits/stdc++.h>
using namespace std;
    const int MOD = 1e9 + 7; //Con n=10⁴, Fibonacci ya es enorme.

/*Como el orden es 2, solo tengo q recordar 2 nada mas, entonces puedo usar 2 variables*/
long long colocar_casa(int n) {
    if (n == 0) return 1; // Hay 1 sola forma cuando no hay terrenos: 1=dejarlo vacío
    if (n == 1) return 2; // hay 2 formas (se queda vacío o se pone una casa)
   
       
    long long anterior2 =1;   //dp[i-2]: una sola forma cuando no hay terreno (el más viejo)
    long long anterior1 =2;   //dp[i-1]: hay 2 formas vacio o casa (el más reciente)
    
    for (int i = 2; i <= n; i++)    {
        long long actual = (anterior1 + anterior2) % MOD;    
        anterior2=anterior1;  // el más reciente pasa a ser el viejo
        anterior1=actual;  // el nuevo pasa a ser el más reciente
        
    }
    return anterior1;  
}

int main() {
    int n=2;
    
    long long k = colocar_casa(n);
    cout << "Resultado: " << (k * k) % MOD   << endl;
    return 0;
}


/*
 Tengo 2 maneras nada mas de subir a la escalera paso 1 o paso 2
   de arriba hacia abajo
    si estoy en 5 entonces vengo de 4 o de 3

climbStairs(5)
├── climbStairs(4)
│   ├── climbStairs(3)
│   │   ├── climbStairs(2) = 2   (base case)
│   │   └── climbStairs(1) = 1   (base case)
│   │   returns 2 + 1 = 3
│   └── climbStairs(2) = 2       (base case)
│   returns 3 + 2 = 5
└── climbStairs(3)               (recomputed from scratch)
    ├── climbStairs(2) = 2       (base case)
    └── climbStairs(1) = 1       (base case)
    returns 2 + 1 = 3
returns 5 + 3 = 8
*/