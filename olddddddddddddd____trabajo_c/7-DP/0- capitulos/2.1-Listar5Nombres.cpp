#include <bits/stdc++.h>
using namespace std;

void printName(int i, int n) {
    // Caso base: si i supera a n, detenemos la recursión
    if (i > n) {
        return;
    }
    
    cout << "osmel" << endl; // Imprime el nombre
    printName(i + 1, n);   // Llamada recursiva incrementando i
}

int main() {
    int n;
    cout << "Ingresa N: ";    cin >> n; //cantidad de veces
    
    // Llamada inicial con i = 1
    printName(1, n); 
    
    return 0;
}