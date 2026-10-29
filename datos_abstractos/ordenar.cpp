#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// FUNCION PARA FUSIONAR (COMBINAR) DOS SUBARREGLOS ORDENADOS
// -------------------------------------------------------------
void fusionar(vector<int> &arr, int inicio, int medio, int fin) {
    // Crear dos subarreglos temporales
    vector<int> izquierda;
    vector<int> derecha;

    // Copiar los datos en los subarreglos
    for (int i = inicio; i <= medio; i++)
        izquierda.push_back(arr[i]);

    for (int i = medio + 1; i <= fin; i++)
        derecha.push_back(arr[i]);

    // Índices para recorrer los subarreglos
    int i = 0; // índice para izquierda
    int j = 0; // índice para derecha
    int k = inicio; // índice para el arreglo original

    // Fusionar mientras haya elementos en ambos subarreglos
    while (i < izquierda.size() && j < derecha.size()) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        } else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de izquierda (si los hay)
    while (i < izquierda.size()) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de derecha (si los hay)
    while (j < derecha.size()) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}

// -------------------------------------------------------------
// FUNCION RECURSIVA PARA DIVIDIR Y ORDENAR (MERGE SORT)
// -------------------------------------------------------------
void mergeSort(vector<int> &arr, int inicio, int fin) {
    if (inicio >= fin) {
        // Caso base: si el subarreglo tiene un solo elemento
        // ya está ordenado, no se hace nada.
        return;
    }

    // Calcular la posición del elemento medio
    int medio = (inicio + fin) / 2;

    // Ordenar recursivamente la mitad izquierda
    mergeSort(arr, inicio, medio);

    // Ordenar recursivamente la mitad derecha
    mergeSort(arr, medio + 1, fin);

    // Combinar las dos mitades ordenadas
    fusionar(arr, inicio, medio, fin);
}

// -------------------------------------------------------------
// FUNCION PRINCIPAL (main)
// -------------------------------------------------------------
int main() {
    // Arreglo de ejemplo
    vector<int> arreglo = {1, 3, 6, 2, 8, 2, 5, 9};

    cout << "Arreglo original:\n";
    for (int num : arreglo)
        cout << num << " ";
    cout << "\n\n";

    // Llamar a mergeSort para ordenar todo el arreglo
    mergeSort(arreglo, 0, arreglo.size() - 1);

    cout << "Arreglo ordenado con Merge Sort:\n";
    for (int num : arreglo)
        cout << num << " ";
    cout << "\n";

    return 0;
}
