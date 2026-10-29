#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> monedas;
vector<int>  memo;  
const int INF = 1e9;

int cantidadMinima(int sumActual) { //inicio j=N   j es donde estoy, estoy al final
 
    // Caso base: estamos en el escalón 0, costo 0. Y el caso base es cantidadMinima(0) = 0.
    if (sumActual == 0) return 0;  //llegue, no falta nada
    if (sumActual < 0) return INF;  //me pase, camino imposible
    
    // Memoización
     if (memo[sumActual] != -1) return memo[sumActual];
 
    int mejor = INF;   
    for (int i = 0; i < n; i++)  {
      int sub = cantidadMinima(sumActual - monedas[i]);
      if (sub != INF)
        mejor =  min(mejor, 1+sub);  //minimo es con todos los resultados    
    }
    
    
    
      
      return memo[sumActual] = mejor;
}

int main() {

    n=3;x=11;
    monedas = {1,5,7}; //3 porq 5+5+1=11  y solo use 3
    memo.assign(x + 1, -1);

    int res =cantidadMinima(x); 
    if (res >= INF) cout << -1 << "\n";
    else            cout << res << "\n";
   return 0; 
    
}

 /*
 

 */ 
  
