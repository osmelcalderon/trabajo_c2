#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; //Con n=10⁴

//Permutacion- el orden importa
//este ejercicio es igual que el primero suma de combinaciones

    long long cambio_moneda(int objetivo, vector<int> &monedas) {
        if (objetivo == 0) return 1; // Encontre una combinación válida, cuenta como 1.
        if (objetivo < 0 ) return 0;
        
        
        long long total = 0; //aqui voy guardando el acumulado
        for (int k = 0; k < (int)monedas.size(); k++) { // 
            total += cambio_moneda(objetivo - monedas[k],monedas);
        }
        
        return total % MOD;
    }

    int main() {

        /*int n, x;
        cin >> n >> x;
    
        vector<int> monedas(n);
        for (int i = 0; i < n; i++) cin >> monedas[i];
    
        cout << "Resultado: " << cambio_moneda(x, monedas) << endl;
    
        return 0;
        */

    vector<int> monedas = {2, 3, 5};
    int objetivo=9; //salida 4
    
    //vector<int> monedas = {3};
    //int objetivo=2; //salida 0
    cout << "Resultado: " << cambio_moneda(objetivo,monedas)  << endl;
    
    return 0;


}


/*


*/