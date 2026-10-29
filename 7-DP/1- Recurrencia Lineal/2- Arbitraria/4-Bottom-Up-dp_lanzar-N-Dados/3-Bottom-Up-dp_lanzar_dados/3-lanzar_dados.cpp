#include <bits/stdc++.h>
using namespace std;


int n = 2;       // dados
int caras = 6;       // caras
int objetivo = 7;  // suma objetivo


const int MOD = 1e9 + 7; //Con n=10⁴

long long lanzar_dado(int objetivo, int n) {
     

        //vector<long long> dp(objetivo + 1,0);
        vector<vector<long long>> dp(n + 1, vector<long long>(objetivo + 1, 0));

        // Caso base: 0 dados, suma 0 → 1 forma
        dp[0][0] = 1;
    
        // Llenar la tabla dado por dado
        for (int dado = 1; dado <= n; dado++) { //1. Avanza fila por fila, cantidad de dados, 
             //Por cada dado hay un objetivo a verificar
            for (int obj = 1; obj <= objetivo; obj++) {  //2. Avanza columna por columna, subojetivo 1 hasta objetivo, 
                long long suma = 0; 
                
                for (int cara = 1; cara <= caras; cara++) { // 3. Suma las celdas de la fila anterior, cantidad de caras de dados
                    if (obj - cara >= 0) {
                        suma = (suma + dp[dado - 1][obj - cara]) % MOD;
                    }
                }                
                
                dp[dado][obj] = suma;
            }
        }

        return dp[n][objetivo] ;
}
  
int main() {
  cout << "Resultado: " << lanzar_dado(objetivo,n)  << endl;
  return 0;
}


/*
Bottom-Up (iterativo)
En el bucle
dado:	La fila de dp:	"¿Cuántos dados estoy considerando?"
obj:	La columna de dp:	"¿Qué suma quiero alcanzar?"
cara:	La suma interna:	"¿Cuál fue el último dado que cayó?"

*/