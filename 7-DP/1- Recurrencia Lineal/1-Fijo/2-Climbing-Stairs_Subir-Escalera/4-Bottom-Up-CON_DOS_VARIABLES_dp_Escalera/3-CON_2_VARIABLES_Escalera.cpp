#include <bits/stdc++.h>
using namespace std;

/*Como el orden es 2, solo tengo q recordar 2 nada mas, entonces puedo usar 2 variables*/
int subir_escalera(int n) {
    if (n == 1) return 1; // solo hay 1 forma: [1]
    if (n == 2) return 2; // dos formas: [1,1] o [2]
    
    int anterior2 =1;   //dp[i-2]: formas de subir 1 escalón (el más viejo)
    int anterior1 =2;   // dp[i-1]: formas de subir 2 escalones (el más reciente)
    
    for (int i = 3; i <= n; i++)    {
        int actual = anterior1 + anterior2;    
        anterior2=anterior1;  // el más reciente pasa a ser el viejo
        anterior1=actual;  // el nuevo pasa a ser el más reciente
        
    }
    return anterior1;  
}

int main() {
    int n=5;
    cout << "Resultado: " << subir_escalera(n)  << endl;
    
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