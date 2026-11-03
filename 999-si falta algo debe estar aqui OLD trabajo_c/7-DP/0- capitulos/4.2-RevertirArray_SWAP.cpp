#include <bits/stdc++.h>
using namespace std;

//aqui usa un swap con un VOID, pasa el arreglo
void reverseArray(int i, int arr[], int n) {
    // Caso base: llegamos a la mitad
    if (i >= n / 2) return;
    
    // SWAP usando la función nativa de C++
    swap(arr[i], arr[n - i - 1]);
    
    // Llamada recursiva
    reverseArray(i + 1, arr, n);
}

int main() {
    int n = 5;
    int arr[] = {1, 3, 5, 4, 2};
    
    reverseArray(0, arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}