#include <bits/stdc++.h>
using namespace std;


int n = 2;       // dados
int caras = 6;       // caras
int objetivo = 7;  // suma objetivo


const int MOD = 1e9 + 7; //Con n=10⁴

//Permutacion- el orden importa
//este ejercicio es igual que el primero suma de combinaciones

//n cantidad de dados
//k cantidad de caras que tiene los dados
//objetivo

//n: pasarlo como parámetro representa la cantidad de dados que todavía faltan por lanzar.

    long long lanzar_dados(int objetivo, int n) {

        /*
            // 1) Si el objetivo se volvió negativo, no hay forma de recuperarlo
           Si en algún momento el target restante se vuelve negativo, no hay forma de recuperarlo, así que se devuelve 0. 
           Por ejemplo cuando lanzo 4 dados y mi objetivo es 7, imaginate que el primer dado caiga 6, el segundo caiga 4, para que voy a continuar si ya 7-6-4=negativo
        */
        if (objetivo < 0 ) return 0;

        /* Si ya no quedan dados, decides según el objetivo
        caso 1: Si ya usaste todos los dados y el target restante es 0, 
         encontraste 1 forma válida.
         Por ejemplo cuando lanzo 2 dados y mi objetivo es 7, imaginate que el primer dado caiga 5, el segundo caiga 2, pues  es valido porque 7-5-2=0 entonces se completo
        
        caso 2: Si el target restante es distinto de 0, no es una forma válida
        entonces encontre forma NO valida 0. 
         Por ejemplo cuando lanzo 2 dados y mi objetivo es 7, imaginate que el primer dado caiga 2, el segundo caiga 1, pues no es valido porque 7-2-1=4 entonces no se completo*/
         
        
        if (n == 0) return (objetivo == 0) ? 1 : 0;
     
           long long total = 0; //aqui voy guardando el acumulado
        
            for (int i = 1; i <= caras; i++) { // las caras de cada dado
                total = (total + lanzar_dados(objetivo - i, n - 1)) % MOD;
            }

            
            
        
        return total;
    }

    int main() {

  
    cout << "Resultado: " << lanzar_dados(objetivo,n)  << endl;
    
    return 0;


}


/*
¿Cómo funciona la recursión?
La idea es que, en cada llamada, eliges el resultado de un dado y reduces en uno la cantidad de dados que faltan.
La recurrencia es:

Donde:
- \(n\): dados que faltan por lanzar.
- \(t\): suma que falta conseguir.
- \(k\): cantidad de caras de cada dado.
- \(F(0,0)=1\): si no quedan dados y la suma pendiente es cero, encontraste una forma válida.
- \(F(0,t)=0\), cuando \(t\neq 0\): si no quedan dados y todavía falta sumar algo, no hay solución.
Importante: esta versión corrige la lógica, pero es muy lenta para los límites máximos porque repite muchos cálculos. Para resolver el problema de LeetCode de forma eficiente, debes agregar programación dinámica con memoización o utilizar una tabla de DP.



Para el problema Number of Dice Rolls With Target Sum, con n = 2, caras = 6 y objetivo = 7, 
el árbol recursivo es el siguiente. 
Cada llamada resta el resultado de un dado al objetivo y reduce la cantidad de dados restantes.


En cada nivel del árbol se lanza un dado. 
La rama representa el valor que sale en ese dado y el nuevo objetivo es la suma que todavía falta conseguir.
Ejemplo:
 2 dados, 6 caras, objetivo = 7

     7
  lance 1er dado   
      
  lance 2do dado   


combinacion_dado(2 dados, 6 caras, objetivo = 7)
├── combinacion_dado(1 dado, objetivo = 6)  // Sale 1
│   ├── combinacion_dado(0 dados, objetivo = 5) → 0
│   ├── combinacion_dado(0 dados, objetivo = 4) → 0
│   ├── combinacion_dado(0 dados, objetivo = 3) → 0
│   ├── combinacion_dado(0 dados, objetivo = 2) → 0
│   ├── combinacion_dado(0 dados, objetivo = 1) → 0
│   └── combinacion_dado(0 dados, objetivo = 0) → 1
│   = 1
├── combinacion_dado(1 dado, objetivo = 5)  // Sale 2
│   ├── combinacion_dado(0 dados, objetivo = 4) → 0
│   ├── combinacion_dado(0 dados, objetivo = 3) → 0
│   ├── combinacion_dado(0 dados, objetivo = 2) → 0
│   ├── combinacion_dado(0 dados, objetivo = 1) → 0
│   └── combinacion_dado(0 dados, objetivo = 0) → 1
│   └── combinacion_dado(0 dados, objetivo = -1) → 0
│   = 1
├── combinacion_dado(1 dado, objetivo = 4)  // Sale 3
│   └── combinacion_dado(0 dados, objetivo = 0) → 1
│       (Sale 4 en el segundo dado)
│   = 1
├── combinacion_dado(1 dado, objetivo = 3)  // Sale 4
│   └── combinacion_dado(0 dados, objetivo = 0) → 1
│       (Sale 3 en el segundo dado)
│   = 1
├── combinacion_dado(1 dado, objetivo = 2)  // Sale 5
│   └── combinacion_dado(0 dados, objetivo = 0) → 1
│       (Sale 2 en el segundo dado)
│   = 1
└── combinacion_dado(1 dado, objetivo = 1)  // Sale 6
    └── combinacion_dado(0 dados, objetivo = 0) → 1
        (Sale 1 en el segundo dado)
    = 1

= 1 + 1 + 1 + 1 + 1 + 1 = 6


Nota: en cada rama, la condición base es que, si no quedan dados, se devuelve 1 únicamente cuando el objetivo restante es 0; en cualquier otro caso se devuelve 0.
*/