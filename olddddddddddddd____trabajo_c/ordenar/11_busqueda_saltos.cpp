#include <iostream>
using namespace std;

// FUNCIÓN DE BÚSQUEDA POR SALTOS
int busquedaPorSaltos(int array[], int n, int x) {
    int k = 0;  // Empiezo en la primera posición
    
    // b es el tamaño del salto: empieza grande y se hace chiquito
    for (int b = n/2; b >= 1; b /= 2) {
        // Mientras no me salga del arreglo Y al saltar encuentre un número menor o igual al que busco
        while (k + b < n && array[k + b] <= x) {
            k += b;  // ¡SALTA!
        }
    }
    
    // Al final, k es donde terminé. Si ahí está el número, ¡gané!
    if (array[k] == x) {
        return k;  // Retorna la posición donde está
    } else {
        return -1; // Retorna -1 si no lo encontró
    }
}

int main() {
    int numeros[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = 8;
    
    // Probar varios números
    int buscar[] = {10, 14, 2, 16, 5, 20};
    
    for (int i = 0; i < 6; i++) {
        int resultado = busquedaPorSaltos(numeros, n, buscar[i]);
        
        cout << "Buscando " << buscar[i] << ": ";
        if (resultado != -1) {
            cout << "✅ Encontrado en posición " << resultado << endl;
        } else {
            cout << "❌ No encontrado" << endl;
        }
    }
    
    return 0;
}

/*
b = n/2:  b empieza en la mitad del arreglo
b >= 1:    Mientras b sea mayor o igual a 1
b /= 2:    En cada vuelta, divide b por 2
	
n=tamaño del arreglo
¿Puedo sumar k+b<n sin salirme del arreglo?

array[k + b] <= x: El número al que voy a saltar ¿es menor o igual que el número que busco?

*/