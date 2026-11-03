#include <bits/stdc++.h>
using namespace std;

void print1ToN(int i, int n) {
    // Caso base
    if (i > n) {
        return;
    }
    
    cout << i << " ";    // Imprime el número actual
    print1ToN(i + 1, n); // Llamada recursiva
}

int main() {
    int n;
    cout << "Ingresa N: ";
    cin >> n;
    
    // Llamada inicial con i = 1
    print1ToN(1, n); 
    
    return 0;
}