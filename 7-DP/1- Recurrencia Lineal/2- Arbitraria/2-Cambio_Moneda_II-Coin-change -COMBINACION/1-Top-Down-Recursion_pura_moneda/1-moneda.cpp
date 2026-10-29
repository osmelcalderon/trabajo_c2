#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; //Con n=10⁴

//Se Añade un parámetro i que indique desde qué moneda puedes empezar.
// Así 2+2+1 solo se genera una vez (siempre tomando monedas de índice ≥ al actual):
//RECORDAR ES COMBINACION, ****NO PERMUTACION, POR TANTO EL ORDEN NO IMPORTA EN COMBINACION

    long long cambio_moneda(int objetivo, vector<int> &monedas, int i) {
        if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
        // me pase, esa rama no aporta, cuenta como 0.
        //o  no hay mas monedas
        if (objetivo < 0 || i >= (int)monedas.size()) return 0;
        
        
        long long total = 0; //aqui voy guardando el acumulado
        for (int k = i; k < (int)monedas.size(); k++) { // empiezo en i, no en 0  Esto evita contar permutaciones.
            total += cambio_moneda(objetivo - monedas[k],monedas,k);// uso elemento[k], puedo repetirla → paso k
            
        }
        
        return total % MOD;
    }

    int main() {
    
    
    vector<int> monedas = {1, 2, 5};
    int objetivo=5; //salida 4
    
    //vector<int> monedas = {3};
    //int objetivo=2; //salida 0
    cout << "Resultado: " << cambio_moneda(objetivo,monedas,0)  << endl;
    
    return 0;
}


/*

Entrada: 
 coins = [1,2,5], objetivo = 5

f(5, i=0)
├── k=0 (uso 1) → f(4, i=0)
│   ├── k=0 (uso 1) → f(3, i=0)
│   │   ├── k=0 (uso 1) → f(2, i=0)
│   │   │   ├── k=0 (uso 1) → f(1, i=0)
│   │   │   │   └── k=0 (uso 1) → f(0) ✔ (1,1,1,1,1)
│   │   │   └── k=1 (uso 2) → f(0) ✔ (1,1,1,2)
│   │   └── k=1 (uso 2) → f(1, i=1) ✗
│   └── k=1 (uso 2) → f(2, i=1)
│       └── k=1 (uso 2) → f(0) ✔ (1,2,2)
└── k=2 (uso 5) → f(0) ✔ (5)

Total: 4
*/