#include <iostream>
using namespace std;

int main() {

    int array[] = {4, 7, 1, 9, 3};
    int n = 5; //tamaño del array
    int x = 9; //valor a buscar

    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            cout << "Elemento encontrado en el indice: " << i << '\n';
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Elemento no encontrado\n";
    }

}

/*
búsqueda lineal: Complejidad de tiempo de este enfoque es O(n), 
 porque en el peor de los casos es necesario revisar todos 
 los elementos del arreglo.
*/