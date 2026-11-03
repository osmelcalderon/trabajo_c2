/*
1. Suma de los primeros N números (Sum of first N numbers)

A) Usando el Enfoque Parametrizado
•	Se pasa un acumulador sum y cuando i llega a 0, se imprime.
o	La función no retorna el valor final. Cuando llega al caso base, simplemente imprime el resultado que se fue acumulando en los parámetros y termina.


   */
#include <bits/stdc++.h>
using namespace std;

// i: número actual, sum: acumulador
void printSumParameterized(int i, int sum) {
    // Caso base: si i llega a 0, imprimimos y retornamos
    if (i < 1) {
        cout << sum << endl;  //imprime valor, no retorna valor
        return;
    }
    
    // Llamada recursiva: restamos 1 a i, y sumamos i al acumulador
    printSumParameterized(i - 1, sum + i);
}

int main() {
    int n = 3;
    // Llamada inicial: i = n, sum = 0
    printSumParameterized(n, 0); 
    return 0;
}
