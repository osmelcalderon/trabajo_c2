#include <bits/stdc++.h>
using namespace std;
    int subir_escalera(int n) {
        
    if (n == 1) return 1; // solo hay 1 forma: [1]
    if (n == 2) return 2; // dos formas: [1,1] o [2]


        return subir_escalera(n - 1) + subir_escalera(n - 2);
    }

    int main() {
    
    cout << "Resultado: " << subir_escalera(5)  << endl;
    
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