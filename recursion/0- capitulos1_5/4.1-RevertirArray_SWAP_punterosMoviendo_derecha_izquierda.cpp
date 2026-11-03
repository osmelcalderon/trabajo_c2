#include <iostream>
using namespace std;

// Función que recibe el puntero izquierdo (l), el derecho (r) y el arreglo
void f(int l, int r, int a[]) {
    // CASO BASE: Si la izquierda alcanza o supera a la derecha, se detiene
    if (l >= r) {
        return;
    }
    
    // 1. SWAP (Intercambiar los valores de los punteros actuales)
    swap(a[l], a[r]);
    
    // 2. Llamada recursiva moviendo los punteros: l avanza, r retrocede
    f(l + 1, r - 1, a);
}

int main() {
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    
    // Llamada inicial: l empieza en 0, r en el último índice (n-1)
    f(0, n - 1, a);
    
    // Imprimir el arreglo invertido
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}