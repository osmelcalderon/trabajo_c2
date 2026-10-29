#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; //Con n=10⁴

//el memo aqui es bidimensional, porque tiene que ir llevando la i a cuesta
    long long cambio_moneda(int objetivo, vector<int> &monedas, vector<vector<int>> &memo,int i) { // Formas válidas en UN lado con n terrenos
        if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
        if (objetivo < 0 || i >= (int)monedas.size()) return 0;
        
        //if (memo[objetivo]!=-1) return memo[objetivo];
        if (memo[objetivo][i] != -1) return memo[objetivo][i];


        long long total = 0; //aqui voy guardando el acumulado
        for (int k = i; k < (int)monedas.size(); k++) { // empiezo en i, no en 0  Esto evita contar permutaciones.
            total += cambio_moneda(objetivo - monedas[k],monedas,memo,k);// uso elemento[k], puedo repetirla → paso k
            
        }
        
        return memo[objetivo][i] = total;

       // return memo[objetivo]=total % MOD;
    }

    int main() {
    
    
    vector<int> monedas = {1, 2, 5};
    int objetivo=5;
    
    //vector<int> memo(objetivo+ 1, -1); //relleno en -1 el vector memo
    vector<vector<int>> memo(objetivo + 1,vector<int>(monedas.size() + 1, -1));
    cout << "Resultado: " << cambio_moneda(objetivo,monedas,memo,0)  << endl;
    
    return 0;
}


/*
Memoizacion: 
  Ahí guardas el valor para cada par (objetivo, i). Así no repites cálculos incorrectamente.
  el memo tiene que ser bidimensional: el resultado de un subproblema no depende solo del objetivo restante, sino también de i, que indica desde qué moneda puedes empezar a considerar.
Si usas memo[objetivo] solamente, estás mezclando estados como:
objetivo = 5, i = 0 → puedes usar monedas {1, 2, 5}
objetivo = 5, i = 1 → solo puedes usar {2, 5}
objetivo = 5, i = 2 → solo puedes usar {5}
Son problemas distintos y pueden dar resultados diferentes. Por eso necesitas memo[objetivo][i].

*/