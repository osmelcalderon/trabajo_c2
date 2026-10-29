#include <bits/stdc++.h>
using namespace std;

int n,x;
vector<int> pesos;
vector<int>  memo;  
const int INF = 1e9;

int minimoViaje(int i) { 
 
    // Caso base
    if (i == n) return 0;  //ya llegue
    
    // Memoización
     if (memo[i] != -1) return memo[i];
 
    int mejor = INF;   

    for (int j = i + 1; j <= min(n, i + 3); j++) {
        int distancia  = (j-i);
        int pesosalto = pesos[j-1] + distancia*distancia;
        mejor = min(mejor, minimoViaje(j)+pesosalto); //costo de la posicion anterior + costo de haber saltado hasta aqui
    }
      
      return memo[i] = mejor;
}

int main() {

    n=4; //cantidad de personas
    x=10;//peso maximo permitido del ascensor
    pesos = {4,8,6,1}; //cuanto pesa cada persona

    memo.assign(n + 1, -1);
    int res =minimoViaje(0); 
    cout << "Minimo Costo subir Escalera: " <<  res << endl;  
   return 0; 
    
}

 /*
 
  n = 4, costs = [1,2,3,4]
  
  Verificación rápida a mano (confirmando tu árbol)
minimoViaje(4) = 0 (caso base)

minimoViaje(3): solo j=4 → 4 + 1 + 0 = 5 → 5

minimoViaje(2):

j=3 → 3 + 1 + 5 = 9

j=4 → 4 + 4 + 0 = 8

→ 8

minimoViaje(1):

j=2 → 2 + 1 + 8 = 11

j=3 → 3 + 4 + 5 = 12

j=4 → 4 + 9 + 0 = 13

→ 11

minimoViaje(0):

j=1 → 1 + 1 + 11 = 13 ✅

j=2 → 2 + 4 + 8 = 14

j=3 → 3 + 9 + 5 = 17

→ 13

Coincide con tu análisis del árbol y con el esperado 13. ✅


 */ 
  
