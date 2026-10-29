#include <iostream>
using namespace std;

/*
Lista Doblemente Enlazada (Doubly Linked List)
Características principales:
Cada nodo tiene dos punteros: siguiente y anterior
la lista es eficiente en recorridos directos(hacia ADELANTE Y ATRAZ)

Recorrido bidireccional: Se puede avanzar y retroceder
Referencias: Se guarda puntero a la cabeza y también a la cola (opcional)
*/

// Definición del nodo (tiene dos punteros)
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;  // ← PUNTERO ADICIONAL para ir hacia atrás
};

// Insertar al inicio
void insertarInicio(Nodo*& cabeza, Nodo*& cola, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    nuevo->anterior = nullptr;
    
    if (cabeza == nullptr) {
        // Lista vacía
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
    cout << "Insertado " << valor << " al inicio" << endl;
}

// Insertar al final
void insertarFinal(Nodo*& cabeza, Nodo*& cola, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    nuevo->anterior = cola;
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
    cout << "Insertado " << valor << " al final" << endl;
}

// Insertar en posición específica (0 = inicio)
void insertarPosicion(Nodo*& cabeza, Nodo*& cola, int valor, int posicion) {
    if (posicion < 0) {
        cout << "Posicion invalida" << endl;
        return;
    }
    
    if (posicion == 0) {
        insertarInicio(cabeza, cola, valor);
        return;
    }
    
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    Nodo* actual = cabeza;
    for (int i = 0; i < posicion && actual != nullptr; i++) {
        actual = actual->siguiente;
    }
    
    if (actual == nullptr) {
        // Si la posición es igual al tamaño, insertar al final
        insertarFinal(cabeza, cola, valor);
        return;
    }
    
    // Insertar antes de 'actual'
    nuevo->siguiente = actual;
    nuevo->anterior = actual->anterior;
    
    if (actual->anterior != nullptr) {
        actual->anterior->siguiente = nuevo;
    }
    actual->anterior = nuevo;
    
    cout << "Insertado " << valor << " en posicion " << posicion << endl;
}

// Eliminar al inicio
void eliminarInicio(Nodo*& cabeza, Nodo*& cola, int &valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia, no se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    Nodo* aux = cabeza;
    valor = aux->dato;
    cabeza = cabeza->siguiente;
    
    if (cabeza != nullptr) {
        cabeza->anterior = nullptr;
    } else {
        // La lista quedó vacía
        cola = nullptr;
    }
    
    delete aux;
    cout << "Eliminado " << valor << " del inicio" << endl;
}

// Eliminar al final
void eliminarFinal(Nodo*& cabeza, Nodo*& cola, int &valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia, no se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    Nodo* aux = cola;
    valor = aux->dato;
    cola = cola->anterior;
    
    if (cola != nullptr) {
        cola->siguiente = nullptr;
    } else {
        // La lista quedó vacía
        cabeza = nullptr;
    }
    
    delete aux;
    cout << "Eliminado " << valor << " del final" << endl;
}

// Eliminar por valor (primera ocurrencia)
bool eliminarValor(Nodo*& cabeza, Nodo*& cola, int valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    
    Nodo* actual = cabeza;
    while (actual != nullptr && actual->dato != valor) {
        actual = actual->siguiente;
    }
    
    if (actual == nullptr) {
        cout << "Valor " << valor << " no encontrado" << endl;
        return false;
    }
    
    // Si es el primer nodo
    if (actual->anterior == nullptr) {
        eliminarInicio(cabeza, cola, valor);
        return true;
    }
    
    // Si es el último nodo
    if (actual->siguiente == nullptr) {
        eliminarFinal(cabeza, cola, valor);
        return true;
    }
    
    // Nodo en medio
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;
    delete actual;
    cout << "Eliminado " << valor << " de la lista" << endl;
    return true;
}

// Eliminar en posición específica
void eliminarPosicion(Nodo*& cabeza, Nodo*& cola, int posicion, int &valor) {
    if (cabeza == nullptr || posicion < 0) {
        cout << "No se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    if (posicion == 0) {
        eliminarInicio(cabeza, cola, valor);
        return;
    }
    
    Nodo* actual = cabeza;
    for (int i = 0; i < posicion && actual != nullptr; i++) {
        actual = actual->siguiente;
    }
    
    if (actual == nullptr) {
        cout << "Posicion fuera de rango" << endl;
        valor = -1;
        return;
    }
    
    // Si es el último
    if (actual->siguiente == nullptr) {
        eliminarFinal(cabeza, cola, valor);
        return;
    }
    
    // Nodo en medio
    valor = actual->dato;
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;
    delete actual;
    cout << "Eliminado " << valor << " de posicion " << posicion << endl;
}

// Buscar un elemento (desde el inicio)
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

// Buscar un elemento (desde el final - característica única de lista doble)
bool buscarElementoReverso(Nodo* cola, int valor) {
    Nodo* actual = cola;
    int posicion = 0;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            cout << "Valor " << valor << " encontrado (desde el final) en posicion " << posicion << endl;
            return true;
        }
        actual = actual->anterior;
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

// Mostrar lista de inicio a fin (adelante)
void mostrarListaAdelante(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo* actual = cabeza;
    cout << "Inicio -> ";
    while (actual != nullptr) {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

// Mostrar lista de fin a inicio (atrás) - característica única de lista doble
void mostrarListaAtras(Nodo* cola) {
    if (cola == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo* actual = cola;
    cout << "Final -> ";
    while (actual != nullptr) {
        cout << actual->dato << " <-> ";
        actual = actual->anterior;
    }
    cout << "NULL" << endl;
}

// Vaciar toda la lista
void vaciarLista(Nodo*& cabeza, Nodo*& cola) {
    while (cabeza != nullptr) {
        Nodo* aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    cola = nullptr;
    cout << "Lista vaciada por completo" << endl;
}

// Menu principal
int main() {
    Nodo* cabeza = nullptr;  // Apunta al primer nodo
    Nodo* cola = nullptr;    // Apunta al último nodo (característica de lista doble)
    int opcion, valor, posicion, valorEliminado;
    
    do {
        cout << "\n--- MENU LISTA DOBLEMENTE ENLAZADA ---" << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posicion" << endl;
        cout << "4. Eliminar al inicio" << endl;
        cout << "5. Eliminar al final" << endl;
        cout << "6. Eliminar por valor" << endl;
        cout << "7. Eliminar por posicion" << endl;
        cout << "8. Buscar elemento (adelante)" << endl;
        cout << "9. Buscar elemento (atras)" << endl;
        cout << "10. Mostrar lista (inicio -> final)" << endl;
        cout << "11. Mostrar lista (final -> inicio)" << endl;
        cout << "12. Obtener tamaño" << endl;
        cout << "13. Vaciar lista" << endl;
        cout << "14. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                insertarInicio(cabeza, cola, valor);
                break;
            case 2:
                cout << "Valor: ";
                cin >> valor;
                insertarFinal(cabeza, cola, valor);
                break;
            case 3:
                cout << "Valor: ";
                cin >> valor;
                cout << "Posicion: ";
                cin >> posicion;
                insertarPosicion(cabeza, cola, valor, posicion);
                break;
            case 4:
                eliminarInicio(cabeza, cola, valorEliminado);
                break;
            case 5:
                eliminarFinal(cabeza, cola, valorEliminado);
                break;
            case 6:
                cout << "Valor a eliminar: ";
                cin >> valor;
                eliminarValor(cabeza, cola, valor);
                break;
            case 7:
                cout << "Posicion: ";
                cin >> posicion;
                eliminarPosicion(cabeza, cola, posicion, valorEliminado);
                break;
            case 8:
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarElemento(cabeza, valor);
                break;
            case 9:
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarElementoReverso(cola, valor);
                break;
            case 10:
                mostrarListaAdelante(cabeza);
                break;
            case 11:
                mostrarListaAtras(cola);
                break;
            case 12:
                cout << "Tamaño: " << obtenerTamaño(cabeza) << endl;
                break;
            case 13:
                vaciarLista(cabeza, cola);
                break;
            case 14:
                vaciarLista(cabeza, cola);
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while(opcion != 14);
    
    return 0;
}