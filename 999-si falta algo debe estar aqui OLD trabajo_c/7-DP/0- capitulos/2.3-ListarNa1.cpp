#include <bits/stdc++.h>
using namespace std;

void printNTo1(int i, int n) {
    // Caso base: si i baja de 1, detenemos la recursión
    if (i < 1) {
        return;
    }
    
    cout << i << " ";    // Imprime el número actual
    printNTo1(i - 1, n); // Llamada recursiva decrementando i
}

int main() {
   int n=5;
    
    // Llamada inicial con i = n
    printNTo1(n, n); 
    
    return 0;
}