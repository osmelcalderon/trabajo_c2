#include <algorithm>
#include <iostream>
using namespace std;

// Comparador para orden inverso (encuentra el máximo)
bool mayor(float a, float b) {
    return a > b;  // Retorna true si a es mayor que b
}

// Comparador para orden normal (encuentra el mínimo)
bool menor(float a, float b) {
    return a < b;  // Retorna true si a es menor que b
}

int main() {
    float arr[] = {3.5, 1.2, 4.8, 2.1, 5.0, 0.5};
    int tamaño = sizeof(arr) / sizeof(arr[0]);  // Calcula tamaño automáticamente
    
    cout << "=== ARREGLO ORIGINAL ===" << endl;
    for(int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    // ===== ENCONTRAR EL MÍNIMO =====
    float *minPtr = min_element(arr, arr + tamaño); //Dirección
    float minimo = *minPtr; //Valor mínimo
    int posMin = minPtr - arr; //Pos_memoria_min-Pos_memoria_primero
    
    cout << "=== MÍNIMO ===" << endl;
    cout << "Valor mínimo: " << minimo << endl;
    cout << "Posición: " << posMin << endl;
    cout << "Dirección: " << minPtr << endl << endl;
    
    // ===== ENCONTRAR EL MÁXIMO (usando comparador 'mayor') =====
    float *maxPtr = min_element(arr, arr + tamaño, mayor);
    float maximo = *maxPtr;
    int posMax = maxPtr - arr;
    
    cout << "=== MÁXIMO ===" << endl;
    cout << "Valor máximo: " << maximo << endl;
    cout << "Posición: " << posMax << endl;
    cout << "Dirección: " << maxPtr << endl << endl;
    
    // ===== ENCONTRAR EL MÍNIMO EXPLÍCITAMENTE =====
    float *minPtr2 = min_element(arr, arr + tamaño, menor);
    float minimo2 = *minPtr2;
    
    cout << "=== VERIFICACIÓN ===" << endl;
    cout << "Mínimo (con menor): " << minimo2 << endl;
    cout << "Máximo (con mayor): " << maximo << endl;
    
    return 0;
}

/*

// Forma general
*min_element(inicio, fin);

// Donde:
// - inicio: puntero/iterador al primer elemento
// - fin: puntero/iterador a UNA POSICIÓN DESPUÉS del último elemento

min_element es la combinación de:
 min_element: una función de la biblioteca estándar 
              de C++ (en <algorithm>) que encuentra el mínimo en un rango

     *     : el operador de desreferencia (indirección) que obtiene 
              el valor apuntado por el iterador
*/