#include <iostream>
using namespace std;

/*
Lista Enlazada Simple (Singly Linked List)
Características principales:
Cada nodo tiene un único puntero siguiente que apunta al siguiente nodo o sucesor
la lista es eficiente en recorridos directos(hacia ADELANTE)

Recorrido unidireccional: Solo se puede avanzar hacia adelante, no hacia atrás
Referencia a la cabeza: Solo se guarda el puntero al primer nodo (cabeza)
*/

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;  // ← SOLO UN puntero (no tiene 'anterior'), por ello es que es simple porq solo camina adelante
};

// Función para insertar al inicio de la lista
void insertarInicio(Nodo*& cabeza, int valor) { //recibe el puntero original por referencia, por tanto en el exterior se va a ver el cambio
    Nodo* nuevo = new Nodo();   // 1. Crear nodo
    nuevo->dato = valor;        // 2. Asignar valor
    nuevo->siguiente = cabeza;  // 3. Enlazar con la lista
    cabeza = nuevo;             // 4. Mover cabeza al nuevo nodo
    cout << "Insertado " << valor << " al inicio" << endl;
}

// Insertar al final
void insertarFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    cout << "Insertado " << valor << " al final" << endl;
}

// Insertar en posición específica (0 = inicio)
void insertarPosicion(Nodo*& cabeza, int valor, int posicion) {
    if (posicion < 0) {
        cout << "Posicion invalida" << endl;
        return;
    }
    
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    if (posicion == 0) {
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        for (int i = 0; i < posicion - 1 && actual != nullptr; i++) {
            actual = actual->siguiente;
        }
        if (actual == nullptr) {
            cout << "Posicion fuera de rango" << endl;
            delete nuevo;
            return;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
    cout << "Insertado " << valor << " en posicion " << posicion << endl;
}

// Eliminar al inicio
void eliminarInicio(Nodo*& cabeza, int &valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia, no se puede eliminar" << endl;
        valor = -1;
        return;
    }
    Nodo* aux = cabeza;
    valor = aux->dato;
    cabeza = cabeza->siguiente;
    delete aux;
    cout << "Eliminado " << valor << " del inicio" << endl;
}

// Eliminar al final
void eliminarFinal(Nodo*& cabeza, int &valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia, no se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    if (cabeza->siguiente == nullptr) {
        valor = cabeza->dato;
        delete cabeza;
        cabeza = nullptr;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        valor = actual->siguiente->dato;
        delete actual->siguiente;
        actual->siguiente = nullptr;
    }
    cout << "Eliminado " << valor << " del final" << endl;
}

// Eliminar por valor (primera ocurrencia)
bool eliminarValor(Nodo*& cabeza, int valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    
    if (cabeza->dato == valor) {
        Nodo* aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
        cout << "Eliminado " << valor << " de la lista" << endl;
        return true;
    }
    
    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
        actual = actual->siguiente;
    }
    
    if (actual->siguiente == nullptr) {
        cout << "Valor " << valor << " no encontrado" << endl;
        return false;
    }
    
    Nodo* aux = actual->siguiente;
    actual->siguiente = aux->siguiente;
    delete aux;
    cout << "Eliminado " << valor << " de la lista" << endl;
    return true;
}

// Buscar un elemento
bool buscarElemento(Nodo* cabeza, int valor) {
    Nodo* actual = cabeza;
    int posicion = 0;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            cout << "Valor " << valor << " encontrado en posicion " << posicion << endl;
            return true;
        }
        actual = actual->siguiente;
        posicion++;
    }
    cout << "Valor " << valor << " no encontrado" << endl;
    return false;
}

// Obtener tamaño de la lista
int obtenerTamaño(Nodo* cabeza) {
    int contador = 0;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// Eliminar en posición específica
void eliminarPosicion(Nodo*& cabeza, int posicion, int &valor) {
    if (cabeza == nullptr || posicion < 0) {
        cout << "No se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    if (posicion == 0) {
        eliminarInicio(cabeza, valor);
        return;
    }
    
    Nodo* actual = cabeza;
    for (int i = 0; i < posicion - 1 && actual != nullptr; i++) {
        actual = actual->siguiente;
    }
    
    if (actual == nullptr || actual->siguiente == nullptr) {
        cout << "Posicion fuera de rango" << endl;
        valor = -1;
        return;
    }
    
    Nodo* aux = actual->siguiente;
    valor = aux->dato;
    actual->siguiente = aux->siguiente;
    delete aux;
    cout << "Eliminado " << valor << " de posicion " << posicion << endl;
}

// Vaciar toda la lista
void vaciarLista(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    cout << "Lista vaciada por completo" << endl;
}

// Mostrar lista (ya lo tienes)
void mostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

// Menu principal
int main() {
    Nodo* lista = nullptr;
    int opcion, valor, posicion, valorEliminado;
    
    do {
        cout << "\n--- MENU LISTA ENLAZADA SIMPLE ---" << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posicion" << endl;
        cout << "4. Eliminar al inicio" << endl;
        cout << "5. Eliminar al final" << endl;
        cout << "6. Eliminar por valor" << endl;
        cout << "7. Eliminar por posicion" << endl;
        cout << "8. Buscar elemento" << endl;
        cout << "9. Mostrar lista" << endl;
        cout << "10. Obtener tamaño" << endl;
        cout << "11. Vaciar lista" << endl;
        cout << "12. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                insertarInicio(lista, valor);
                break;
            case 2:
                cout << "Valor: ";
                cin >> valor;
                insertarFinal(lista, valor);
                break;
            case 3:
                cout << "Valor: ";
                cin >> valor;
                cout << "Posicion: ";
                cin >> posicion;
                insertarPosicion(lista, valor, posicion);
                break;
            case 4:
                eliminarInicio(lista, valorEliminado);
                break;
            case 5:
                eliminarFinal(lista, valorEliminado);
                break;
            case 6:
                cout << "Valor a eliminar: ";
                cin >> valor;
                eliminarValor(lista, valor);
                break;
            case 7:
                cout << "Posicion: ";
                cin >> posicion;
                eliminarPosicion(lista, posicion, valorEliminado);
                break;
            case 8:
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarElemento(lista, valor);
                break;
            case 9:
                mostrarLista(lista);
                break;
            case 10:
                cout << "Tamaño: " << obtenerTamaño(lista) << endl;
                break;
            case 11:
                vaciarLista(lista);
                break;
            case 12:
                vaciarLista(lista); // Limpiar memoria antes de salir
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while(opcion != 12);
    
    return 0;
}

/*
Ejecución paso a paso:
1. insertarInicio(lista, 10);
   Se crea un nodo en el heap (nuevo), con dato = 10.
   nuevo->siguiente = nullptr (porque cabeza estaba vacía).
   cabeza (o sea lista en el main) ahora apunta a ese nodo.

Stack:
   lista -> 0x1000

Heap:
   [0x1000: dato=10, siguiente=nullptr]

2. insertarInicio(lista, 20);

Se crea un nuevo nodo en heap (0x2000), con dato = 20.

nuevo->siguiente = cabeza → ahora apunta al nodo con 10.

cabeza (es decir lista) se actualiza para apuntar a 0x2000.

Stack:
   lista -> 0x2000

Heap:
   [0x2000: dato=20, siguiente=0x1000]
   [0x1000: dato=10, siguiente=nullptr]

3. insertarInicio(lista, 30);

Se crea otro nodo en heap (0x3000), con dato = 30.

nuevo->siguiente = cabeza → apunta al nodo con 20.

cabeza (lista) ahora apunta a 0x3000.

Stack:
   lista -> 0x3000

Heap:
   [0x3000: dato=30, siguiente=0x2000]
   [0x2000: dato=20, siguiente=0x1000]
   [0x1000: dato=10, siguiente=nullptr]

🔑 Idea clave

lista (la cabeza) es una sola variable en el stack.

Esa variable va cambiando su valor (la dirección que guarda).

Siempre apunta al último nodo insertado en el heap.

Los nodos viejos no se pierden porque cada nuevo->siguiente mantiene la "cadena" hacia atrás.
*/