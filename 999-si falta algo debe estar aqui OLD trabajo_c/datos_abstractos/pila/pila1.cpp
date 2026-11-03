#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/*
En una pila (estructura LIFO = Last In, First Out):
El último elemento que entró es el primero que sale
*/

struct Nodo { //aqui se declara el nodo
    int dato;
    Nodo *siguiente; //el puntero que apunta a un nodo
};

// Prototipos de funciones
void agregarPila(Nodo *&, int);
void eliminarPila(Nodo *&, int &);
void mostrarPila(Nodo *);
void verTop(Nodo *);
bool pilaVacia(Nodo *);

int main() {
    Nodo *pila = NULL;
    int opcion, valor, valorEliminado;
    
    do {
        cout << "\n--- MENU DE PILA (Dinamica) ---" << endl;
        cout << "1. Agregar elemento (push)" << endl;
        cout << "2. Eliminar elemento (pop)" << endl;
        cout << "3. Mostrar toda la pila" << endl;
        cout << "4. Ver elemento superior (top)" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Digite un numero: ";
                cin >> valor;
                agregarPila(pila, valor);
                break;
            case 2:
                eliminarPila(pila, valorEliminado);
                if(valorEliminado != -1) {
                    cout << "Elemento eliminado: " << valorEliminado << endl;
                }
                break;
            case 3:
                mostrarPila(pila);
                break;
            case 4:
                verTop(pila);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while(opcion != 5);
    
    getch();
    return 0;
}

/*
Paso 1: Crear el espacio en memoria para almacenar un nodo.
Paso 2: Cargar el valor dentro del nodo (dato).
Paso 3: Cargar el puntero pila dentro del nodo (*siguiente).
Paso 4: Asignar el nuevo nodo a pila.
*/
// Funcion para agregar un elemento a la pila
void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo(); //crea espacio de memoria
    nuevo_nodo->dato = n;          //guardar la info 
    nuevo_nodo->siguiente = pila;  //apuntar a donde esta la PILA
    pila = nuevo_nodo;             //La PILA recoge la ultima direccion creada    
    cout << "Elemento " << n << " agregado a la pila" << endl;
}

// Quitar elementos de una pila
//el elemento que está en la cima (el más reciente)
void eliminarPila(Nodo *&pila, int &n) {
    if(pilaVacia(pila)) {
        cout << "Error: La pila esta vacia, no se puede eliminar" << endl;
        n = -1;
    } else {
        Nodo *aux = pila; //guardo el puntero pila 
        n = aux->dato;   //el dato lo guardo
        pila = aux->siguiente; //y AHORA APUNTO AL ANTERIOR
        delete aux; //y elimino 
    }
}

// Funcion para verificar si la pila esta vacia
bool pilaVacia(Nodo *pila) {
    return (pila == NULL);
}

// Funcion para mostrar todos los elementos de la pila
void mostrarPila(Nodo *pila) {
    if(pilaVacia(pila)) {
        cout << "La pila esta vacia" << endl;
        return;
    }
    
    cout << "Contenido de la pila (superior -> inferior): ";
    Nodo *actual = pila;
    while(actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;  //recorro la pila
    }
    cout << endl;
}

// Funcion para ver el elemento superior sin eliminarlo
void verTop(Nodo *pila) {
    if(pilaVacia(pila)) {
        cout << "La pila esta vacia, no hay elemento superior" << endl;
    } else {
        cout << "Elemento superior de la pila: " << pila->dato << endl;
    }
}