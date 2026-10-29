#include <bits/stdc++.h>
using namespace std;

int objetivo;
vector<int> costos;
vector<int>  memo;  
const int INF = 1e9;

int costoMinimo(int j) { //inicio j=N   j es donde estoy, estoy al final
 
    // Caso base: estamos en el escalón 0, costo 0. Y el caso base es costoMinimo(0) = 0.
    if (j == 0) return 0;  //cuando j llegue al primer escalon q es 0 y donde el costo es 0
    
    // Memoización
     if (memo[j] != -1) return memo[j];
 
    int mejor = INF;   
        
    
     

    // Probamos los 3 posibles orígenes: j-1, j-2, j-3
    for (int i = max(0, j - 3); i < j; i++) {

        
        /*

          costoTotal_Salto = costos[j] + (j - i)²
          costoTotal_Salto = 
                   costo_escalón_destino(donde estoy) 
                 + penalización por distancia  (j - i)².   
        */

        int distancia  = (j-i);
        int costoSalto = costos[j-1] + distancia*distancia;

        mejor = min(mejor, costoMinimo(i)+costoSalto); //costo de la posicion anterior + costo de haber saltado hasta aqui
    }
      
      return memo[j] = mejor;
}

int main() {

    objetivo=4;
    costos = {1,2,3,4}; //15 costos de cada paso de escalera
    //costos = {1,100,1,1,1,100,1,1,100,1}; //6 costos de cada paso de escalera
    memo.assign(objetivo + 1, -1);

    int res =costoMinimo(objetivo); //min(costoMinimo(0), costoMinimo(1), costoMinimo(2));//  
    cout << "Minimo Costo subir Escalera: " <<  res << endl;  
   return 0; 
    
}

 /*
 
  n = 4, costs = [1,2,3,4]

  desde i=0, salto i+1, i+2, o i+3
  1+(1-0)^2= 1+1=2  *
  2+(2-0)^2= 2+4=6
  3+(3-0)^2= 3+9=12

 desde i=1, salto i+1, i+2, o i+3
  2+(2-1)^2= 2+1=3  *
  3+(3-1)^2= 3+4=7
  4+(4-1)^2= 4+9=13

desde i=2, salto i+1, i+2,   aqui no puedo saltar a i+3, porq se pasa del array q solo tiene 4 elementos
  3+(3-2)^2= 3+1=4
  4+(4-2)^2= 4+4=8  *
  
desde i=3, salto i+1,  aqui no puedo saltar a i+2, i+3, porq se pasa del array q solo tiene 4 elementos
  4+(4-3)^2= 4+1=5
  
  

 */ 
  
