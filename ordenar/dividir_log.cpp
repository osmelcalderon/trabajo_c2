#include <iostream>
using namespace std;

void dividir(int arr[], int izquierda, int derecha, int nivel) {
    // Imprimir sangría según el nivel
    for (int i = 0; i < nivel; i++)
        cout << "  ";
    
    // Imprimir el subarreglo actual
    cout << "nivel: " << nivel;
    cout << " [";
    for (int i = izquierda; i <= derecha; i++) {
        cout << arr[i];
        if (i < derecha) cout << " ";
    }
    cout << "]" << endl;
    
    // Si solo tiene 1 elemento, ya no se divide más (caso base)
    if (izquierda >= derecha) {
        return;
    }
    
    // Calcular la mitad y dividir
    int medio = izquierda + (derecha - izquierda) / 2;
    
    // Dividir izquierda y derecha
    dividir(arr, izquierda, medio, nivel + 1);
    dividir(arr, medio + 1, derecha, nivel + 1);
    //arreglo, izquierda, derecha, nivel
    //merge sort 
    //https://www.youtube.com/watch?v=tl74Gvi71s8
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    
    cout << "=== SOLO DIVISIONES (sin mezclar) ===" << endl;
    dividir(arr, 0, n - 1, 0);
    
    return 0;
}