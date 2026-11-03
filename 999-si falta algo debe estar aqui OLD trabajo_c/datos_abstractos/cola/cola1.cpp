#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/*
En una cola (estructura FIFO = First In, First Out):
El primer elemento que entra es el primero que sale
"agregar" por un extremo (Final), 
"obtener" por otro extremo (Frente)
*/

struct Nodo {
    int dato;
    Nodo *siguiente;
};

// Prototipos de funciones
void agregarCola(Nodo *&, Nodo *&, int);
void eliminarCola(Nodo *&, Nodo *&, int &);
void mostrarCola(Nodo *);
void verFront(Nodo *);
void verRear(Nodo *);
bool colaVacia(Nodo *);

int main() {
    Nodo *frente = NULL;  // Apunta al primer elemento (el que saldrá primero)
    Nodo *final = NULL;   // Apunta al último elemento (donde se agrega)
    int opcion, valor, valorEliminado;
    
    do {
        cout << "\n--- MENU DE COLA (Dinamica) ---" << endl;
        cout << "1. Agregar elemento (encolar)" << endl;
        cout << "2. Eliminar elemento (desencolar)" << endl;
        cout << "3. Mostrar toda la cola" << endl;
        cout << "4. Ver elemento frontal (front)" << endl;
        cout << "5. Ver elemento final (rear)" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Digite un numero: ";
                cin >> valor;
                agregarCola(frente, final, valor);
                break;
            case 2:
                eliminarCola(frente, final, valorEliminado);
                if(valorEliminado != -1) {
                    cout << "Elemento eliminado: " << valorEliminado << endl;
                }
                break;
            case 3:
                mostrarCola(frente);
                break;
            case 4:
                verFront(frente);
                break;
            case 5:
                verRear(final);
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while(opcion != 6);
    
    getch();
    return 0;
}

/*

Paso 1: Crear el espacio en memoria para almacenar un nodo.
Paso 2: Cargar el valor dentro del nodo (dato).
Paso 3: El nuevo nodo será el último, por lo tanto su *siguiente = NULL.
Paso 4: Si la cola está vacía, frente y final apuntan al nuevo nodo.
       Si no, el último nodo actual apunta al nuevo nodo y final se actualiza.
*/
void agregarCola(Nodo *&frente, Nodo *&final, int n) {
    Nodo *nuevo_nodo = new Nodo();  // Crear espacio en memoria
    nuevo_nodo->dato = n;           // Guardar  valor
    nuevo_nodo->siguiente = NULL;   // Será el último, apunta a NULL
    
    //asignar los PUNTEROS (frente y Fin)
    if(colaVacia(frente)) { // Si la cola está vacía, el nuevo nodo es el primero y el último
        frente = nuevo_nodo;
    } else { // Si ya hay elementos, el actual último apunta al nuevo nodo
        final->siguiente = nuevo_nodo; //El último nodo actual apunta al nuevo
    }
    final = nuevo_nodo;  // Actualizamos final
    cout << "Elemento " << n << " agregado a la cola" << endl;
}

/*

Paso 1: Verificar que la cola no esté vacía.
Paso 2: Guardar el nodo del frente en un auxiliar.
Paso 3: Guardar el valor del nodo.
Paso 4: Mover frente al siguiente nodo.
Paso 5: Eliminar el nodo auxiliar.
Paso 6: Si la cola quedó vacía, final también debe ser NULL.
*/
void eliminarCola(Nodo *&frente, Nodo *&final, int &n) {
    if(colaVacia(frente)) {
        cout << "Error: La cola esta vacia, no se puede eliminar" << endl;
        n = -1;
    } else {
        Nodo *aux = frente;     // Guardar el nodo del frente
        n = aux->dato;          // Guardar el valor
        
        frente = aux->siguiente; //Mover frente al siguiente
        
        // Paso 6: Si la cola quedó vacía, final también debe ser NULL
        if(frente == NULL) {
            final = NULL;
        }
        
        delete aux;             // Eliminar el nodo
    }
}

// Funcion para verificar si la cola esta vacia
bool colaVacia(Nodo *frente) {
    return (frente == NULL);
}

// Funcion para mostrar todos los elementos de la cola
void mostrarCola(Nodo *frente) {
    if(colaVacia(frente)) {
        cout << "La cola esta vacia" << endl;
        return;
    }
    
    cout << "Contenido de la cola (frente -> final): ";
    Nodo *actual = frente;
    while(actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente; //recorrer
    }
    cout << endl;
}

// Funcion para ver el elemento frontal (el primero que saldrá)
void verFront(Nodo *frente) {
    if(colaVacia(frente)) {
        cout << "La cola esta vacia, no hay elemento frontal" << endl;
    } else {
        cout << "Elemento frontal (primero en salir): " << frente->dato << endl;
    }
}

// Funcion para ver el elemento final (el último que entró)
void verRear(Nodo *final) {
    if(colaVacia(final)) {
        cout << "La cola esta vacia, no hay elemento final" << endl;
    } else {
        cout << "Elemento final (ultimo en entrar): " << final->dato << endl;
    }
}