#include <bits/stdc++.h>
using namespace std;

int N_escalones;
vector<int> costos;
vector<int>  memo;  


int subirEscalera(int num_escalon) { //inicio num_escalon=0
 
    // Caso base: hemos subido todos los escalones
    if (num_escalon >= N_escalones) return 0;
    
    // Memoización
     if (memo[num_escalon] != -1) return memo[num_escalon];
 
    
     int mejor;
     mejor= costos[num_escalon]+
            min(
                    subirEscalera(num_escalon+2),
                    subirEscalera(num_escalon+1)
            );
    
    
      
      return memo[num_escalon] = mejor;
}

int main() {

    costos = {10,15,20}; //15 costos de cada paso de escalera
    //costos = {1,100,1,1,1,100,1,1,100,1}; //6 costos de cada paso de escalera
    N_escalones= (int)(costos.size());

    memo.assign(N_escalones + 1, -1);

    int res =min(subirEscalera(0), subirEscalera(1));//  
    cout << "Minimo Costo subir Escalera: " <<  res << endl;  
   return 0; 
    
}

  
  
