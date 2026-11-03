#include <bits/stdc++.h>
using namespace std;

void printNTo1Backtrack(int i, int n) {
    // Caso base: si i supera a n, empezamos a retornar
    if (i > n) {
        return;
    }
    
    // Primero vamos hacia N
    printNTo1Backtrack(i + 1, n);
    
    // Al retornar, imprimimos. El último en llamar (N) es el primero en imprimir.
    cout << i << " "; 
}

int main() {
    int n=5;
    
    // Llamada inicial con i = 1
    printNTo1Backtrack(1, n); 
    
    return 0;
}