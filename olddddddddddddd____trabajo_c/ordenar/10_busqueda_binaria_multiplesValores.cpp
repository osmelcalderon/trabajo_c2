#include <iostream>
#include <vector>
using namespace std;

// Función de búsqueda binaria recursiva
int busquedaBinariaRecursiva(const vector<int>& arr, int x, int a, int b) {
    // Caso base: no encontrado
    if (a > b) return -1;
    
    int k = a + (b - a) / 2;  // Elemento medio
    
    cout << "Buscando entre índices " << a << " y " << b;
    cout << ", medio = " << k << " (valor: " << arr[k] << ")" << endl;
    
    if (arr[k] == x) {
        cout << "  ✅ ¡ENCONTRADO!" << endl;
        return k;  // Encontrado
    }
    
    if (arr[k] > x) {
        cout << "  " << arr[k] << " > " << x << " → Buscar en IZQUIERDA" << endl;
        return busquedaBinariaRecursiva(arr, x, a, k - 1);  // Buscar en izquierda
    } else {
        cout << "  " << arr[k] << " < " << x << " → Buscar en DERECHA" << endl;
        return busquedaBinariaRecursiva(arr, x, k + 1, b);  // Buscar en derecha
    }
}

int main() {
    vector<int> numeros = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 72, 89};
    
    cout << "Arreglo: ";
    for (int num : numeros) cout << num << " ";
    cout << "\n\n";
    
    // Probar diferentes búsquedas
    int buscar[] = {23, 2, 89, 12, 50, 100};
    
    for (int x : buscar) {
        cout << "\n=== Buscando " << x << " ===" << endl;
        int resultado = busquedaBinariaRecursiva(numeros, x, 0, numeros.size() - 1);
        
        if (resultado != -1) {
            cout << "\n✅ " << x << " encontrado en índice " << resultado << endl;
        } else {
            cout << "\n❌ " << x << " no encontrado" << endl;
        }
        cout << "================\n" << endl;
    }
    
    return 0;
}