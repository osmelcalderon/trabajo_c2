#include <bits/stdc++.h>
using namespace std;

int objetivo;
vector<int> costos;
vector<int>  memo;  
const int INF = 1e9;

int costoMinimo(int i) { 
 
    // Caso base
    if (i == objetivo) return 0;  //ya llegue
    
    // Memoización
     if (memo[i] != -1) return memo[i];
 
    int mejor = INF;   

    for (int j = i + 1; j <= min(objetivo, i + 3); j++) {
        int distancia  = (j-i);
        int costoSalto = costos[j-1] + distancia*distancia;
        mejor = min(mejor, costoMinimo(j)+costoSalto); //costo de la posicion anterior + costo de haber saltado hasta aqui
    }
      
      return memo[i] = mejor;
}

int main() {

    objetivo=4; costos = {1,2,3,4}; //13 costos de cada paso de escalera
        objetivo=10; costos = {1,100,1,1,1,100,1,1,100,1}; //23
        objetivo=4; costos = {5,1,6,2}; //11
        objetivo=3; costos = {9,8,3}; //12
    memo.assign(objetivo + 1, -1);

    int res =costoMinimo(0); //min(costoMinimo(0), costoMinimo(1), costoMinimo(2));//  
    cout << "Minimo Costo subir Escalera: " <<  res << endl;  
   return 0; 
    
}

 /*
 
  n = 4, costs = [1,2,3,4]
  
  Verificación rápida a mano (confirmando tu árbol)
costoMinimo(4) = 0 (caso base)

costoMinimo(3): solo j=4 → 4 + 1 + 0 = 5 → 5

costoMinimo(2):

j=3 → 3 + 1 + 5 = 9

j=4 → 4 + 4 + 0 = 8

→ 8

costoMinimo(1):

j=2 → 2 + 1 + 8 = 11

j=3 → 3 + 4 + 5 = 12

j=4 → 4 + 9 + 0 = 13

→ 11

costoMinimo(0):

j=1 → 1 + 1 + 11 = 13 ✅

j=2 → 2 + 4 + 8 = 14

j=3 → 3 + 9 + 5 = 17

→ 13

Coincide con tu análisis del árbol y con el esperado 13. ✅


 */ 
  
