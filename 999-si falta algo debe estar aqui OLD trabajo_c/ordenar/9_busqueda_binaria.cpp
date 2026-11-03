#include <iostream>
#include <vector>
using namespace std;

int busquedaBinaria(vector<int>& arr, int x, int izquierda, int derecha) {
    if (izquierda > derecha) {
        return -1;
    }
    int medio = (izquierda + derecha) / 2;
    cout << "Medio = " << medio
         << " valor = " << arr[medio] << '\n';

    if (arr[medio] == x) { //si es el valor del medio lo encontro
        return medio;
    }

    if (arr[medio] < x) {
        return busquedaBinaria(arr, x, medio + 1, derecha); //busca a la derecha
    }

    return busquedaBinaria(arr, x, izquierda, medio - 1);  //busca a la izquierda
}

int main() {

    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45};
    int x = 23;
    int resultado = busquedaBinaria(arr, x, 0, arr.size() - 1);
    if (resultado != -1) {
        cout << "Encontrado en el indice "
             << resultado << '\n';
    }
    else {
        cout << "No encontrado\n";
    }

}



/*
Búsqueda binaria: Busca eficientemente un elemento en un arreglo ordenado
 en tiempo O(log n). En lugar de revisar uno por uno (búsqueda lineal), 
 va descartando la mitad del arreglo en cada paso.
*/