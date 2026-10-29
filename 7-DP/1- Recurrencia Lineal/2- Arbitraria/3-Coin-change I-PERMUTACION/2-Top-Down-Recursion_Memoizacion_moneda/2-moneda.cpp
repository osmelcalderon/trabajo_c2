#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; //Con n=10⁴

//permutacion
//memo es 1D por objetivo, que es lo correcto cuando el orden importa.
    long long cambio_moneda(int objetivo, vector<int> &monedas, vector<int> &memo) { 
        if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
        if (objetivo < 0 ) return 0;
        
        if (memo[objetivo]!=-1) return memo[objetivo];

        long long total = 0; //aqui voy guardando el acumulado
        for (int k = 0; k < (int)monedas.size(); k++) { 
            total += cambio_moneda(objetivo - monedas[k],monedas,memo);
            
        }
        

        return memo[objetivo]=total % MOD;
    }

    int main() {
    
    
    vector<int> monedas = {1, 2, 5};
    int objetivo=5;
    
    vector<int> memo(objetivo+ 1, -1); //relleno en -1 el vector memo
    cout << "Resultado: " << cambio_moneda(objetivo,monedas,memo)  << endl;
    
    return 0;
}


/*
Por qué el memo 1D está bien aquí
En permutaciones, el subproblema solo depende de cuánto te falta por sumar (objetivo), no de qué monedas ya usaste. 
Por eso memo[objetivo] es suficiente. No necesitas i como en combinaciones.

Esto es justo lo contrario del caso de combinaciones, donde el memo tenía que ser 2D [objetivo][i].
*/