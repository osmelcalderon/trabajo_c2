#include <iostream>
using namespace std;

// Definición de la estructura Nodo para la lista
struct Nodo {
    int dato;          // valor que guarda el nodo
    Nodo* siguiente;   // puntero al siguiente nodo de la lista
};


// Función para insertar un nuevo nodo en la lista de manera ordenada
// Se usan dos auxiliares: actual y anterior
void insertarOrdenado(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();     // 1. Crear un nodo en memoria dinámica
    nuevo->dato = valor;          // 2. Guardar el valor dentro del nodo
    //nuevo->siguiente = nullptr;   // 3. Inicialmente apunta a nada, NO ES NECESARIA

    // Auxiliares para recorrer la lista
    Nodo* actual = cabeza;        // Apunta al inicio de la lista
    Nodo* anterior = nullptr;     // Va un paso detrás de actual

    // 4. Buscar la posición correcta donde insertar el nuevo nodo
    // Mientras no lleguemos al final y el valor actual sea menor al que quiero insertar
    while (actual != nullptr && actual->dato < valor) {
        anterior = actual;        // Guardamos la posición anterior
        actual = actual->siguiente; // Avanzamos en la lista
    }

    // 5. Casos de inserción
    if (anterior == nullptr) {
        // Caso 1: Insertar al inicio (nuevo será la nueva cabeza)
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    } 
    else {
        // Caso 2: Insertar en medio o al final
        anterior->siguiente = nuevo; // conectar nodo anterior con el nuevo
        nuevo->siguiente = actual;   // conectar el nuevo con el siguiente
    }
}

// Función para mostrar los elementos de la lista
void mostrarLista(Nodo* cabeza) {
    Nodo* aux = cabeza;                // auxiliar para recorrer la lista
    while (aux != nullptr) {           // mientras no lleguemos al final
        cout << aux->dato << " -> ";   // mostrar el valor del nodo
        aux = aux->siguiente;          // avanzar al siguiente nodo
    }
    cout << "NULL\n";                  // marca el final de la lista
}

int main() {
    Nodo* lista = nullptr;   // Al inicio la lista está vacía

    // Insertamos valores de forma ordenada
    insertarOrdenado(lista, 30);
    insertarOrdenado(lista, 10);
    insertarOrdenado(lista, 20);
    insertarOrdenado(lista, 40);

    // Mostramos cómo quedó la lista
    mostrarLista(lista); 
    // Salida: 10 -> 20 -> 30 -> 40 -> NULL

    return 0;
}
