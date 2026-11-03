#include <iostream>
#include <vector>
using namespace std;

// Condición:
// ¿El número es >= 16?   {2,3,4,5,8 ,12,16,23,38,45};
bool ok(int x) {
    return x >= 16;
}

// Búsqueda binaria recursiva
int busquedaBinaria(vector<int>& arr, int izquierda, int derecha) {

    if (izquierda > derecha) { //Ya no queda nada por revisar
        return izquierda;   //y en este momento izquierda queda apuntando exactamente al primer true.
    }

    int medio = (izquierda + derecha) / 2;

    cout << "Medio = " << medio
         << " valor = " << arr[medio] << '\n';

    if (ok(arr[medio])) {  //aqui pregunta si se paso q busque más a la izquierda
        // cumple -> buscar más a la izquierda
        return busquedaBinaria(arr, izquierda, medio - 1);
    }

    // no cumple -> buscar derecha
    return busquedaBinaria(arr, medio + 1, derecha);
}

int main() {

    vector<int> arr = {2,3,4,5,8,12,16,23,38,45};

    int indice = busquedaBinaria(arr, 0, arr.size() - 1);

    cout << "\nPrimer numero >= 16: "
         << arr[indice]
         << " en indice "
         << indice << '\n';
}


/*

O(log n)
La búsqueda binaria intenta encontrar dónde cambia de false a true.
Estás buscando el punto donde la condición cambia.

Imagina una fila de focos apagados y encendidos:
Índice:  0 1 2 3 4 5 6 7 8
Valor :  F F F F T T T T T
•	F = false 
•	T = true 
Aquí el cambio ocurre en el índice 4.
Eso significa:
ok(x) = false  si x < 4
ok(x) = true   si x >= 4
y queremos encontrar el PRIMER true.




*/