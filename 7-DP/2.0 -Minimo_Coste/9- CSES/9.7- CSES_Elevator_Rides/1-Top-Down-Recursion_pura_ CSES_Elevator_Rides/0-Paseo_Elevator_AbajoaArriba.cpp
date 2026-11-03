#include <bits/stdc++.h>
using namespace std;

int n,x;
vector<int> pesos;
vector<int>  memo;  
const int INF = 1e9;

int minimoViaje(int capacidad_actual) { 
 
    // Caso base
    if (capacidad_actual == 0) return 0;  //ya llegue
    
    // Memoización
     if (memo[capacidad_actual] != -1) return memo[capacidad_actual];
 
    int mejor = INF;   

    for (int j = 0; j < n; j++) {
        mejor = 1+min(mejor, minimoViaje(capacidad_actual-pesos[j])); //costo de la posicion anterior + costo de haber saltado hasta aqui
    }
      
      return memo[n] = mejor;
}

int main() {

    n=4; //cantidad de personas
    x=10;//peso maximo permitido del ascensor
    pesos = {4,8,6,1}; //cuanto pesa cada persona

    memo.assign(n + 1, -1);
    int res =minimoViaje(x); 
    cout << "Minimo Costo subir Escalera: " <<  res << endl;  
   return 0; 
    
}

 
  
