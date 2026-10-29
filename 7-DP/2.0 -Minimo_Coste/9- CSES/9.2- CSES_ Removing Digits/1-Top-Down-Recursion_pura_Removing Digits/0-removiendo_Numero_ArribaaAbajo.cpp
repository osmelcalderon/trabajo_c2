#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>  memo;  
const int INF = 1e9;

int restoDigito(int numActual) { //inicio j=N   j es donde estoy, estoy al final
 
    // Caso base: estamos en el escalón 0, costo 0. Y el caso base es restoDigito(0) = 0.
    if (numActual == 0) return 0;  //llegue, no falta nada
    if (numActual < 0) return INF;  //me pase, camino imposible
    
    // Memoización
     if (memo[numActual] != -1) return memo[numActual];

     int mejor = INF;   
     int Totaldigitos = (int)log10(numActual) + 1;

      for (int i = 0; i < Totaldigitos; i++)      {
        int digito=(numActual / (int)pow(10, i)) % 10;
        if (digito == 0) continue;  //restar 0 no avanza → ignorar
        int sub = restoDigito(numActual - digito);
        if (sub != INF)
        mejor =  min(mejor, 1+sub);  //
      }
  
    
      
      return memo[numActual] = mejor;
}

int main() {

    n=27; //5
    memo.assign(n + 1, -1);

    int res =restoDigito(n); 
    if (res >= INF) cout << -1 << "\n";
    else            cout << res << "\n";
   return 0; 
    
}
