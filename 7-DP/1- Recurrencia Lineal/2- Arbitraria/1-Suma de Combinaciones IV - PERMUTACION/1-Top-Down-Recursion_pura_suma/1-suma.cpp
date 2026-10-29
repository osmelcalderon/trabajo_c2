#include <bits/stdc++.h>
using namespace std;



const int MOD = 1e9 + 7; //Con n=10⁴

    long long suma_combinacion(int objetivo, vector<int> &elementos) { // Formas válidas en UN lado con n terrenos
        if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
        if (objetivo < 0) return 0; // me pase, esa rama no aporta, cuenta como 0.
        
        long long total = 0; //aqui voy guardando el acumulado
        for (int i = 0; i < (int)elementos.size(); i++) {
            total += suma_combinacion(objetivo - elementos[i],elementos);
        }
        
        return total % MOD;
    }

    int main() {
    
    //vector<int> dp(1000 + 1);
    vector<int> elementos = {1, 2, 3};
    int objetivo=4;
    
    cout << "Resultado: " << suma_combinacion(objetivo,elementos)  << endl;
    
    return 0;
}


/*

Entrada: nums = [1,2,3], objetivo = 4
nums = [1,2,3], target = 4

                                    4
                 ┌──────────────────┼──────────────────┐
                -1                 -2                 -3
                 3                  2                  1
          ┌──────┼──────┐      ┌────┼────┐             │
         -1     -2     -3     -1   -2   -3           -1
          2      1      0      1    0   ✗            0 ✔
     ┌────┼────┐   │  (1,3)✔ (2,1,1)(2,2)✔        (3,1)✔
    -1   -2   -3 -1            ✔
     1    0   ✗  0✔
   ┌──┤ (1,1,2)✔ (1,2,1)✔
  -1 -2 -3
   0   1  ✗
 (1,1,1,1)✔ │
          -1
           0✔
        (1,1,1,1)? no → (1,1,1,1) ya contado arriba



4
├── -1 → 3
│   ├── -1 → 2
│   │   ├── -1 → 1
│   │   │   └── -1 → 0 ✔  (1,1,1,1)
│   │   └── -2 → 0 ✔  (1,1,2)
│   ├── -2 → 1
│   │   └── -1 → 0 ✔  (1,2,1)
│   └── -3 → 0 ✔  (1,3)
├── -2 → 2
│   ├── -1 → 1
│   │   └── -1 → 0 ✔  (2,1,1)
│   └── -2 → 0 ✔  (2,2)
└── -3 → 1
    └── -1 → 0 ✔  (3,1)

Total: 7
*/