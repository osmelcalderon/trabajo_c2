#include <iostream>
using namespace std;

/*

void intercambiar(float *a, float *b) 
intercambiar(&numeros[0], &numeros[4]);  /llamada, pasas    direccion de memoria

*/


// Función de intercambio básica
//se recibe direccion de memoria
void intercambiar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Función para imprimir arreglo
void imprimirArreglo(float arr[], int tamaño) {
    for(int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    float numeros[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int tamaño = 5;
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros, tamaño);
    
    // Intercambiar primero y último
    //recuerda que debes pasar direccion de memoria
    intercambiar(&numeros[0], &numeros[4]);
    cout << "Intercambiar posición 0 y 4: ";
    imprimirArreglo(numeros, tamaño);
    
    // Intercambiar segundo y cuarto
    intercambiar(&numeros[1], &numeros[3]);
    cout << "Intercambiar posición 1 y 3: ";
    imprimirArreglo(numeros, tamaño);
    
    return 0;
}