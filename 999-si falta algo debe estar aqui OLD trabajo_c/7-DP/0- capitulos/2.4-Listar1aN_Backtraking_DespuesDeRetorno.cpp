#include <bits/stdc++.h>
using namespace std;

void print1ToNBacktrack(int i, int n) {
    // Caso base: cuando llegamos a 0, empezamos a retornar
    if (i < 1) {
        return;
    }
    
    // Primero hacemos la llamada recursiva (vamos hacia el 0)
    print1ToNBacktrack(i - 1, n);
    
    // Al retornar de la llamada, imprimimos. 
    // Esto ocurre en orden 1, 2, 3... N
    cout << i << " "; 
}

int main() {
    int n=5;
    
    // Llamada inicial con i = n
    print1ToNBacktrack(n, n); 
    
    return 0;
}