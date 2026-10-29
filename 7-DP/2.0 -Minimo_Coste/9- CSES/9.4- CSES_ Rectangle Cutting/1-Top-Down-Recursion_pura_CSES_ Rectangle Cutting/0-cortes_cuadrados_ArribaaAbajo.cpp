#include <bits/stdc++.h>
using namespace std;

int a,b;

map<pair<int,int>, int> memo;
const int INF = 1e9;

int corte(int a_actual, int b_actual) { //inicio j=N   j es donde estoy, estoy al final
 
    // Caso base: ya es un cuadrado
    if (a_actual == b_actual) return 0;

      // Memoización
    auto clave = make_pair(a_actual, b_actual); //make_pair(a, b)  return memo[a_actual][b_actual];
    if (memo.count(clave)) return memo[clave]; 


     int mejor = INF;   

     // Cortes verticales: divido el ancho b en i y b-i
     //Cada corte genera dos subproblemas: 
    for (int i = 1; i < b_actual; i++) { 
      int costo = corte(a_actual,i)+corte(a_actual,b_actual-i)+1;
      mejor =  min(mejor, costo);  //
    }  
        
  // Cortes horizontales: divido el alto a en j y a-j
     for (int i = 1; i < a_actual; i++) { 
      int costo = corte(i,b_actual)+corte(a_actual-i,b_actual)+1;
      mejor =  min(mejor, costo);  //
    }          
        
  
    
      return memo[clave] = mejor;
      
}

int main() {

    a=3;b=5; //3
    memo.clear();   // <-- clear, no assign

    int res =corte(a,b); 
    if (res >= INF) cout << -1 << "\n";
    else            cout << res << "\n";
   return 0; 
    
}
