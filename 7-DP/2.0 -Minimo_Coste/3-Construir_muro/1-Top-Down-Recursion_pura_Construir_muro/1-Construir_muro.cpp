#include <bits/stdc++.h>
using namespace std;

int n,m;  //n total, m cantidad de largos
vector<int> largos, costos;
vector<int> memo;
const int INF = 1e9;


int f(int n, vector<int> &memo) {
    if (n == 0) return 0;
    if (n < 0)  return INF;       

    if (memo[n] != -1) return memo[n];

    //aqui no hace falta buscar el proximo pedido porque va agarrar el presente y se mueve al proximo i
    int mejor = INF;
    for (int k = 0; k < m; k++) { //cantidad de largo, aunq el ejercicio dice 3
            mejor = min(mejor, costos[k] + f(n - largos[k],memo) );
    }
    return memo[n] = mejor;
    
}

 


int main() {
    // Valores por defecto del Ejemplo 2
    n=10;
    largos = {2, 3, 5}; //da15, el mejor es 2+2+2+2+2=10  3*5=15
                        //5+5=10  costo 8+8=16
                        //2+3+5=10,  costo seria 3+5+8=16
     costos  = {3,5,8}; 
    
     n=7;
     largos = {2, 4, 6}; //da -1, porq no se puede formar
     costos  = {3,5,7}; 

     n=11;
     largos = {1, 3, 5}; //da 15, 5+3+3=11 7+4+4=15
     costos  = {2,4,7}; 

     m = (int)largos.size();
    memo.assign(n + 1, -1);
    int res = f(n,memo);
    cout << "Costo mínimo: " << (res == INF ? -1 : res) << endl; // 15
    return 0;
}

/*

            10
    -2                    -3         -5  
    8                     7          5 
-2     -3 -5            -2 -3 -5   -2 -3 -5
6       5  3

-2 -3 -5
4  3  1

*/

    /*
    int pequeno = costos[0] + f(n-largos[0], memo);
    int mediano = costos[1] + f(n-largos[1], memo);
    int grande = costos[2] + f(n-largos[2], memo);
    return memo[n] = min({pequeno,mediano,grande});
    */