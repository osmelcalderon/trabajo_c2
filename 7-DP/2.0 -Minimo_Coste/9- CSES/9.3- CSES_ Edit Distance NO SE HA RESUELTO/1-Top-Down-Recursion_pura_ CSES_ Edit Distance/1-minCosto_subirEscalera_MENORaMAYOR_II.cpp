#include <bits/stdc++.h>
using namespace std;

int N_escalones, objetivo;
vector<int> costos;
vector<int>  memo;  
const int INF = 1e9;

int subirEscalera(int num_escalon) { //inicio num_escalon=0
 
    // Caso base: estamos en el escalón 0, costo 0
    if (num_escalon == 0) return 0;
    
    // Memoización
     if (memo[num_escalon] != -1) return memo[num_escalon];
 
    int mejor = INF;   //INT_MAX / 2; 
        
    
    // Probamos los 3 posibles orígenes: i-1, i-2, i-3
    for (int j = max(0, num_escalon - 3); j < num_escalon; j++) {
        int salto = num_escalon - j;  //(i-j)            // salto=1,2,3.. cuántos escalones saltaste
        int costo = subirEscalera(j) + costos[num_escalon - 1] + salto * salto;    // costos[num_escalon-1] es el costo del escalón i (por el desfase 1-indexado)
        cout << "costo : " <<  costo << "  j : " <<  j << "  salto : " << salto << endl;
        mejor = min(mejor, costo);
    }
      
      return memo[num_escalon] = mejor;
}

int main() {

    objetivo=4;
    costos = {1,2,3,4}; //15 costos de cada paso de escalera
    //costos = {1,100,1,1,1,100,1,1,100,1}; //6 costos de cada paso de escalera
    N_escalones= (int)(costos.size());

    memo.assign(N_escalones + 1, -1);

    int res =subirEscalera(objetivo); //min(subirEscalera(0), subirEscalera(1), subirEscalera(2));//  
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
  
