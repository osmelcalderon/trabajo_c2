#include <bits/stdc++.h>
using namespace std;

 // Formas de construir la suma n lanzando un cara (caras 1..6)

const int MOD = 1e9 + 7;  //Con n=10⁴, Fibonacci ya es enorme.

    long long combinacion_cara(int n) { // Formas válidas en UN lado con n terrenos
        if (n == 0) return 1;  // 1 forma: no lanzar nada (suma vacía)
        if (n < 0)  return 0; // no se puede construir una suma negativa

        // Versión explícita (6 sumandos)
        return ( combinacion_cara(n - 1) + combinacion_cara(n - 2) +combinacion_cara(n - 3) + combinacion_cara(n - 4) +combinacion_cara(n - 5) + combinacion_cara(n - 6) )  % MOD;
        
        // Versión con bucle (comentada) k-bonnanci
        /*
        long long total = 0;
        for (int cara = 1; cara <= 6; cara++) { //voy a ir restando cada cara del cara
            total = (total + combinacion_cara(n - cara)) % MOD;
        }
        return total;
        */

        
    }

    int main() {
    
    int n=2;
    
    cout << "Resultado: " << combinacion_cara(n)   << endl;
    
    return 0;
}


/*

No te preguntan: "¿cuántos lanzamientos?" 
Te preguntan: "¿cuántas combinaciones distintas de lanzamientos suman 3?" → 4.
    1 + 1 + 1    ← 3 lanzamientos
    1 + 2        ← 2 lanzamientos
    2 + 1        ← 2 lanzamientos
    3            ← 1 lanzamiento

solución
  ¿Es como k-Fibonacci? Sí, pero en lugar de sumar los 2 anteriores, sumas los 6 anteriores.
  ¿Qué técnica usar? Con n = 10⁶, la recursión pura explota. Necesitas bottom-up.
  ¿Puedo optimizar espacio? Sí, pero necesitas recordar 6 valores (no 2 como en Fibonacci). Aun así, es O(1) de espacio.
  ¿Cuicara con el módulo? Aplícalo en cada suma.

Pregunta clave: ¿cómo se relaciona formas(n) con los valores anteriores?
 Si el último lanzamiento fue:
   1 → vienes de n-1
   2 → vienes de n-2
   3 → vienes de n-3
   4 → vienes de n-4
   5 → vienes de n-5
   6 → vienes de n-6

Entonces: formas(n)=formas(n−1)+formas(n−2)+formas(n−3)+formas(n−4)+formas(n−5)+formas(n−6)
Caso base: 
  formas(0) = 1 (hay 1 forma de sumar 0: no lanzar nada, la "suma vacía").

  Verificación con n=3:
    formas(0) = 1
    formas(1) = 1 → 1
    formas(2) = formas(1) + formas(0) = 1 + 1 = 2 → 1+1, 2
    formas(3) = formas(2) + formas(1) + formas(0) = 2 + 1 + 1 = 4 ✅

combinacion_dado(2, memo)
├── combinacion_dado(1, memo)
│   ├── combinacion_dado(0)  → 1
│   ├── combinacion_dado(-1) → 0
│   ├── combinacion_dado(-2) → 0
│   ├── combinacion_dado(-3) → 0
│   ├── combinacion_dado(-4) → 0
│   └── combinacion_dado(-5) → 0
│   = 1  → memo[1] = 1
├── combinacion_dado(0)  → 1
├── combinacion_dado(-1) → 0
├── combinacion_dado(-2) → 0
├── combinacion_dado(-3) → 0
└── combinacion_dado(-4) → 0
= 1 + 1 + 0 + 0 + 0 + 0 = 2  → memo[2] = 2

*/