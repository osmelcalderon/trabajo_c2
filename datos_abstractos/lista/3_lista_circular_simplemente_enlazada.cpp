#include <iostream>
using namespace std;

/*
Lista Circular Simplemente Enlazada (Circular Singly Linked List)
Características principales:
- Cada nodo tiene un único puntero siguiente
- El último nodo(<<Cola>>) apunta al primero(<<cabeza>>) (no apunta a NULL)
- Se puede dar vueltas infinitas( En forma de anillos)
- Referencia: Se guarda puntero al último nodo (cola) o al primero (cabeza)

Ventajas de la Lista Circular:
- No tiene NULL: Nunca encuentras un final
- Fácil acceso circular: Puedes dar vueltas infinitas
- Útil para colas circulares: Implementación eficiente de buffers circulares
- Se puede empezar desde cualquier nodo: Puedes recorrer toda la lista desde cualquier punto
¡Ahora tienes una lista que nunca termina (a menos que esté vacía)!

*/

// Definición del nodo (solo un puntero, como lista simple)
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Insertar al inicio
void insertarInicio(Nodo*& cola, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    if (cola == nullptr) {
        // Lista vacía: el nuevo nodo se apunta a sí mismo
        cola = nuevo;
        nuevo->siguiente = cola;
    } else {
        // El nuevo nodo apunta al primer nodo (cola->siguiente)
        nuevo->siguiente = cola->siguiente;
        // El último nodo (cola) apunta al nuevo nodo
        cola->siguiente = nuevo;
    }
    cout << "Insertado " << valor << " al inicio" << endl;
}

// Insertar al final
void insertarFinal(Nodo*& cola, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    if (cola == nullptr) {
        // Lista vacía: el nuevo nodo se apunta a sí mismo
        cola = nuevo;
        nuevo->siguiente = cola;
    } else {
        // El nuevo nodo apunta al primer nodo (cola->siguiente)
        nuevo->siguiente = cola->siguiente;
        // El último nodo (cola) apunta al nuevo nodo
        cola->siguiente = nuevo;
        // Actualizamos cola al nuevo nodo
        cola = nuevo;
    }
    cout << "Insertado " << valor << " al final" << endl;
}

// Insertar en posición específica (0 = inicio)
void insertarPosicion(Nodo*& cola, int valor, int posicion) {
    if (posicion < 0) {
        cout << "Posicion invalida" << endl;
        return;
    }
    
    if (cola == nullptr) {
        if (posicion == 0) {
            insertarInicio(cola, valor);
        } else {
            cout << "Posicion fuera de rango (lista vacia)" << endl;
        }
        return;
    }
    
    if (posicion == 0) {
        insertarInicio(cola, valor);
        return;
    }
    
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    Nodo* actual = cola->siguiente; // Empezamos desde el primer nodo
    for (int i = 0; i < posicion - 1; i++) {
        actual = actual->siguiente;
        if (actual == cola->siguiente) {
            cout << "Posicion fuera de rango" << endl;
            delete nuevo;
            return;
        }
    }
    
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    
    // Si insertamos después del último nodo, actualizamos cola
    if (actual == cola) {
        cola = nuevo;
    }
    
    cout << "Insertado " << valor << " en posicion " << posicion << endl;
}

// Eliminar al inicio
void eliminarInicio(Nodo*& cola, int &valor) {
    if (cola == nullptr) {
        cout << "Lista vacia, no se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    Nodo* aux = cola->siguiente; // Primer nodo
    valor = aux->dato;
    
    if (cola == cola->siguiente) {
        // Solo hay un nodo
        delete aux;
        cola = nullptr;
    } else {
        // El último nodo (cola) apunta al segundo nodo
        cola->siguiente = aux->siguiente;
        delete aux;
    }
    cout << "Eliminado " << valor << " del inicio" << endl;
}

// Eliminar al final
void eliminarFinal(Nodo*& cola, int &valor) {
    if (cola == nullptr) {
        cout << "Lista vacia, no se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    if (cola == cola->siguiente) {
        // Solo hay un nodo
        valor = cola->dato;
        delete cola;
        cola = nullptr;
        cout << "Eliminado " << valor << " del final" << endl;
        return;
    }
    
    // Buscar el nodo anterior al último
    Nodo* actual = cola->siguiente;
    while (actual->siguiente != cola) {
        actual = actual->siguiente;
    }
    
    // actual es el nodo anterior al último
    valor = cola->dato;
    actual->siguiente = cola->siguiente;
    delete cola;
    cola = actual; // Actualizamos cola al nuevo último nodo
    
    cout << "Eliminado " << valor << " del final" << endl;
}

// Eliminar por valor (primera ocurrencia)
bool eliminarValor(Nodo*& cola, int valor) {
    if (cola == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    
    // Caso especial: el valor está en el primer nodo
    if (cola->siguiente->dato == valor) {
        eliminarInicio(cola, valor);
        return true;
    }
    
    Nodo* actual = cola->siguiente;
    while (actual != cola) {
        if (actual->siguiente->dato == valor) {
            Nodo* aux = actual->siguiente;
            actual->siguiente = aux->siguiente;
            
            // Si eliminamos el último nodo, actualizamos cola
            if (aux == cola) {
                cola = actual;
            }
            
            delete aux;
            cout << "Eliminado " << valor << " de la lista" << endl;
            return true;
        }
        actual = actual->siguiente;
    }
    
    cout << "Valor " << valor << " no encontrado" << endl;
    return false;
}

// Eliminar en posición específica
void eliminarPosicion(Nodo*& cola, int posicion, int &valor) {
    if (cola == nullptr || posicion < 0) {
        cout << "No se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    if (posicion == 0) {
        eliminarInicio(cola, valor);
        return;
    }
    
    Nodo* actual = cola->siguiente;
    for (int i = 0; i < posicion - 1; i++) {
        actual = actual->siguiente;
        if (actual == cola->siguiente) {
            cout << "Posicion fuera de rango" << endl;
            valor = -1;
            return;
        }
    }
    
    if (actual->siguiente == cola->siguiente) {
        cout << "Posicion fuera de rango" << endl;
        valor = -1;
        return;
    }
    
    Nodo* aux = actual->siguiente;
    valor = aux->dato;
    actual->siguiente = aux->siguiente;
    
    // Si eliminamos el último nodo, actualizamos cola
    if (aux == cola) {
        cola = actual;
    }
    
    delete aux;
    cout << "Eliminado " << valor << " de posicion " << posicion << endl;
}

// Buscar un elemento
bool buscarElemento(Nodo* cola, int valor) {
    if (cola == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    
    Nodo* actual = cola->siguiente;
    int posicion = 0;
    do {
        if (actual->dato == valor) {
            cout << "Valor " << valor << " encontrado en posicion " << posicion << endl;
            return true;
        }
        actual = actual->siguiente;
        posicion++;
    } while (actual != cola->siguiente);
    
    cout << "Valor " << valor << " no encontrado" << endl;
    return false;
}

// Obtener tamaño de la lista
int obtenerTamaño(Nodo* cola) {
    if (cola == nullptr) return 0;
    
    int contador = 0;
    Nodo* actual = cola->siguiente;
    do {
        contador++;
        actual = actual->siguiente;
    } while (actual != cola->siguiente);
    
    return contador;
}

// Mostrar lista (una sola vuelta)
void mostrarLista(Nodo* cola) {
    if (cola == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    
    Nodo* actual = cola->siguiente;
    cout << "Cabeza -> ";
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != cola->siguiente);
    cout << "(vuelve a cabeza)" << endl;
}

// Mostrar lista con N vueltas (para demostrar circularidad)
void mostrarListaConVueltas(Nodo* cola, int vueltas) {
    if (cola == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    
    Nodo* actual = cola->siguiente;
    int elementosMostrados = 0;
    int totalElementos = obtenerTamaño(cola);
    int totalMostrar = totalElementos * vueltas;
    
    cout << "Mostrando " << vueltas << " vuelta(s) completa(s):" << endl;
    cout << "Inicio -> ";
    for (int i = 0; i < totalMostrar; i++) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "(continua circularmente...)" << endl;
}

// Vaciar toda la lista
void vaciarLista(Nodo*& cola) {
    if (cola == nullptr) return;
    
    Nodo* actual = cola->siguiente;
    while (actual != cola) {
        Nodo* aux = actual;
        actual = actual->siguiente;
        delete aux;
    }
    delete cola;
    cola = nullptr;
    cout << "Lista vaciada por completo" << endl;
}

// Menu principal
int main() {
    Nodo* cola = nullptr;  // Apunta al último nodo (cola->siguiente es la cabeza)
    int opcion, valor, posicion, valorEliminado, vueltas;
    
    do {
        cout << "\n--- MENU LISTA CIRCULAR SIMPLEMENTE ENLAZADA ---" << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posicion" << endl;
        cout << "4. Eliminar al inicio" << endl;
        cout << "5. Eliminar al final" << endl;
        cout << "6. Eliminar por valor" << endl;
        cout << "7. Eliminar por posicion" << endl;
        cout << "8. Buscar elemento" << endl;
        cout << "9. Mostrar lista (una vuelta)" << endl;
        cout << "10. Mostrar lista (N vueltas)" << endl;
        cout << "11. Obtener tamaño" << endl;
        cout << "12. Vaciar lista" << endl;
        cout << "13. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                insertarInicio(cola, valor);
                break;
            case 2:
                cout << "Valor: ";
                cin >> valor;
                insertarFinal(cola, valor);
                break;
            case 3:
                cout << "Valor: ";
                cin >> valor;
                cout << "Posicion: ";
                cin >> posicion;
                insertarPosicion(cola, valor, posicion);
                break;
            case 4:
                eliminarInicio(cola, valorEliminado);
                break;
            case 5:
                eliminarFinal(cola, valorEliminado);
                break;
            case 6:
                cout << "Valor a eliminar: ";
                cin >> valor;
                eliminarValor(cola, valor);
                break;
            case 7:
                cout << "Posicion: ";
                cin >> posicion;
                eliminarPosicion(cola, posicion, valorEliminado);
                break;
            case 8:
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarElemento(cola, valor);
                break;
            case 9:
                mostrarLista(cola);
                break;
            case 10:
                cout << "Numero de vueltas: ";
                cin >> vueltas;
                mostrarListaConVueltas(cola, vueltas);
                break;
            case 11:
                cout << "Tamaño: " << obtenerTamaño(cola) << endl;
                break;
            case 12:
                vaciarLista(cola);
                break;
            case 13:
                vaciarLista(cola);
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while(opcion != 13);
    
    return 0;
}