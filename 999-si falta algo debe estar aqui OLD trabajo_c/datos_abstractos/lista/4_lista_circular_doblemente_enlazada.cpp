#include <iostream>
using namespace std;

/*
Lista Circular Doblemente Enlazada (Circular Doubly Linked List)
Características principales:
- Dos enlaces: Cada nodo tiene punteros siguiente y anterior
- Es circular: El último nodo apunta al primero, y el primero apunta al último
- Recorrido bidireccional circular: Se puede avanzar y retroceder infinitamente
- Referencia: Se puede guardar un puntero a cualquier nodo (normalmente a la cabeza)

Ventajas de la Lista Circular Doblemente Enlazada:
- Recorrido bidireccional circular: Puedes avanzar y retroceder infinitamente
- Acceso eficiente: Puedes llegar a cualquier nodo desde cualquier dirección
- Sin NULL: Nunca encuentras un final, todo es circular
- Ideal para buffers circulares: Perfecto para colas circulares y planificadores
- Fácil inversión: Invertir la lista es trivial
¡Ahora tienes la lista más completa: circular y con doble enlace! Puedes recorrerla infinitamente en ambas direcciones.
*/

// Definición del nodo (tiene dos punteros)
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

// Insertar al inicio
void insertarInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    if (cabeza == nullptr) {
        // Lista vacía: el nuevo nodo se apunta a sí mismo
        cabeza = nuevo;
        nuevo->siguiente = cabeza;
        nuevo->anterior = cabeza;
    } else {
        Nodo* ultimo = cabeza->anterior; // Guardamos el último nodo
        
        // Conectar el nuevo nodo
        nuevo->siguiente = cabeza;
        nuevo->anterior = ultimo;
        
        // Actualizar los nodos existentes
        cabeza->anterior = nuevo;
        ultimo->siguiente = nuevo;
        
        // Actualizar cabeza
        cabeza = nuevo;
    }
    cout << "Insertado " << valor << " al inicio" << endl;
}

// Insertar al final
void insertarFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    if (cabeza == nullptr) {
        // Lista vacía: el nuevo nodo se apunta a sí mismo
        cabeza = nuevo;
        nuevo->siguiente = cabeza;
        nuevo->anterior = cabeza;
    } else {
        Nodo* ultimo = cabeza->anterior;
        
        // Conectar el nuevo nodo
        nuevo->siguiente = cabeza;
        nuevo->anterior = ultimo;
        
        // Actualizar los nodos existentes
        ultimo->siguiente = nuevo;
        cabeza->anterior = nuevo;
    }
    cout << "Insertado " << valor << " al final" << endl;
}

// Insertar en posición específica (0 = inicio)
void insertarPosicion(Nodo*& cabeza, int valor, int posicion) {
    if (posicion < 0) {
        cout << "Posicion invalida" << endl;
        return;
    }
    
    if (cabeza == nullptr) {
        if (posicion == 0) {
            insertarInicio(cabeza, valor);
        } else {
            cout << "Posicion fuera de rango (lista vacia)" << endl;
        }
        return;
    }
    
    if (posicion == 0) {
        insertarInicio(cabeza, valor);
        return;
    }
    
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    
    Nodo* actual = cabeza;
    for (int i = 0; i < posicion; i++) {
        actual = actual->siguiente;
        if (actual == cabeza) {
            cout << "Posicion fuera de rango" << endl;
            delete nuevo;
            return;
        }
    }
    
    // Insertar antes de 'actual'
    nuevo->siguiente = actual;
    nuevo->anterior = actual->anterior;
    
    actual->anterior->siguiente = nuevo;
    actual->anterior = nuevo;
    
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
    
    if (cabeza->siguiente == cabeza) {
        // Solo hay un nodo
        delete cabeza;
        cabeza = nullptr;
    } else {
        Nodo* ultimo = cabeza->anterior;
        
        // Actualizar cabeza al segundo nodo
        cabeza = cabeza->siguiente;
        
        // Conectar el nuevo inicio con el final
        cabeza->anterior = ultimo;
        ultimo->siguiente = cabeza;
        
        delete aux;
    }
    cout << "Eliminado " << valor << " del inicio" << endl;
}

// Eliminar al final
void eliminarFinal(Nodo*& cabeza, int &valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia, no se puede eliminar" << endl;
        valor = -1;
        return;
    }
    
    if (cabeza->siguiente == cabeza) {
        // Solo hay un nodo
        valor = cabeza->dato;
        delete cabeza;
        cabeza = nullptr;
        cout << "Eliminado " << valor << " del final" << endl;
        return;
    }
    
    Nodo* ultimo = cabeza->anterior;
    Nodo* nuevoUltimo = ultimo->anterior;
    
    valor = ultimo->dato;
    
    // Conectar el nuevo último nodo con la cabeza
    nuevoUltimo->siguiente = cabeza;
    cabeza->anterior = nuevoUltimo;
    
    delete ultimo;
    cout << "Eliminado " << valor << " del final" << endl;
}

// Eliminar por valor (primera ocurrencia)
bool eliminarValor(Nodo*& cabeza, int valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    
    // Caso especial: el valor está en la cabeza
    if (cabeza->dato == valor) {
        eliminarInicio(cabeza, valor);
        return true;
    }
    
    Nodo* actual = cabeza->siguiente;
    while (actual != cabeza) {
        if (actual->dato == valor) {
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
            delete actual;
            cout << "Eliminado " << valor << " de la lista" << endl;
            return true;
        }
        actual = actual->siguiente;
    }
    
    cout << "Valor " << valor << " no encontrado" << endl;
    return false;
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
    for (int i = 0; i < posicion; i++) {
        actual = actual->siguiente;
        if (actual == cabeza) {
            cout << "Posicion fuera de rango" << endl;
            valor = -1;
            return;
        }
    }
    
    valor = actual->dato;
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;
    delete actual;
    
    cout << "Eliminado " << valor << " de posicion " << posicion << endl;
}

// Buscar un elemento (hacia adelante)
bool buscarElementoAdelante(Nodo* cabeza, int valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    
    Nodo* actual = cabeza;
    int posicion = 0;
    do {
        if (actual->dato == valor) {
            cout << "Valor " << valor << " encontrado en posicion " << posicion << " (adelante)" << endl;
            return true;
        }
        actual = actual->siguiente;
        posicion++;
    } while (actual != cabeza);
    
    cout << "Valor " << valor << " no encontrado" << endl;
    return false;
}

// Buscar un elemento (hacia atrás)
bool buscarElementoAtras(Nodo* cabeza, int valor) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return false;
    }
    
    Nodo* actual = cabeza->anterior; // Empezar desde el último
    int posicion = obtenerTamaño(cabeza) - 1;
    int contador = 0;
    do {
        if (actual->dato == valor) {
            cout << "Valor " << valor << " encontrado en posicion " << posicion - contador << " (desde atras)" << endl;
            return true;
        }
        actual = actual->anterior;
        contador++;
    } while (actual != cabeza->anterior);
    
    cout << "Valor " << valor << " no encontrado" << endl;
    return false;
}

// Obtener tamaño de la lista
int obtenerTamaño(Nodo* cabeza) {
    if (cabeza == nullptr) return 0;
    
    int contador = 0;
    Nodo* actual = cabeza;
    do {
        contador++;
        actual = actual->siguiente;
    } while (actual != cabeza);
    
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
    do {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    cout << "(vuelve a cabeza)" << endl;
}

// Mostrar lista de fin a inicio (atrás)
void mostrarListaAtras(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    
    Nodo* actual = cabeza->anterior; // Empezar desde el último
    cout << "Final -> ";
    do {
        cout << actual->dato << " <-> ";
        actual = actual->anterior;
    } while (actual != cabeza->anterior);
    cout << "(vuelve a cola)" << endl;
}

// Mostrar lista con N vueltas (para demostrar circularidad)
void mostrarListaConVueltasAdelante(Nodo* cabeza, int vueltas) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    
    Nodo* actual = cabeza;
    int totalElementos = obtenerTamaño(cabeza);
    int totalMostrar = totalElementos * vueltas;
    
    cout << "Mostrando " << vueltas << " vuelta(s) completa(s) (adelante):" << endl;
    cout << "Inicio -> ";
    for (int i = 0; i < totalMostrar; i++) {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    cout << "(continua circularmente...)" << endl;
}

// Mostrar lista con N vueltas hacia atrás
void mostrarListaConVueltasAtras(Nodo* cabeza, int vueltas) {
    if (cabeza == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    
    Nodo* actual = cabeza->anterior;
    int totalElementos = obtenerTamaño(cabeza);
    int totalMostrar = totalElementos * vueltas;
    
    cout << "Mostrando " << vueltas << " vuelta(s) completa(s) (atras):" << endl;
    cout << "Final -> ";
    for (int i = 0; i < totalMostrar; i++) {
        cout << actual->dato << " <-> ";
        actual = actual->anterior;
    }
    cout << "(continua circularmente...)" << endl;
}

// Vaciar toda la lista
void vaciarLista(Nodo*& cabeza) {
    if (cabeza == nullptr) return;
    
    Nodo* actual = cabeza;
    Nodo* siguiente;
    do {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);
    
    cabeza = nullptr;
    cout << "Lista vaciada por completo" << endl;
}

// Menu principal
int main() {
    Nodo* cabeza = nullptr;  // Apunta al primer nodo
    int opcion, valor, posicion, valorEliminado, vueltas;
    
    do {
        cout << "\n--- MENU LISTA CIRCULAR DOBLEMENTE ENLAZADA ---" << endl;
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
        cout << "12. Mostrar lista con vueltas (adelante)" << endl;
        cout << "13. Mostrar lista con vueltas (atras)" << endl;
        cout << "14. Obtener tamaño" << endl;
        cout << "15. Vaciar lista" << endl;
        cout << "16. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                insertarInicio(cabeza, valor);
                break;
            case 2:
                cout << "Valor: ";
                cin >> valor;
                insertarFinal(cabeza, valor);
                break;
            case 3:
                cout << "Valor: ";
                cin >> valor;
                cout << "Posicion: ";
                cin >> posicion;
                insertarPosicion(cabeza, valor, posicion);
                break;
            case 4:
                eliminarInicio(cabeza, valorEliminado);
                break;
            case 5:
                eliminarFinal(cabeza, valorEliminado);
                break;
            case 6:
                cout << "Valor a eliminar: ";
                cin >> valor;
                eliminarValor(cabeza, valor);
                break;
            case 7:
                cout << "Posicion: ";
                cin >> posicion;
                eliminarPosicion(cabeza, posicion, valorEliminado);
                break;
            case 8:
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarElementoAdelante(cabeza, valor);
                break;
            case 9:
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarElementoAtras(cabeza, valor);
                break;
            case 10:
                mostrarListaAdelante(cabeza);
                break;
            case 11:
                mostrarListaAtras(cabeza);
                break;
            case 12:
                cout << "Numero de vueltas: ";
                cin >> vueltas;
                mostrarListaConVueltasAdelante(cabeza, vueltas);
                break;
            case 13:
                cout << "Numero de vueltas: ";
                cin >> vueltas;
                mostrarListaConVueltasAtras(cabeza, vueltas);
                break;
            case 14:
                cout << "Tamaño: " << obtenerTamaño(cabeza) << endl;
                break;
            case 15:
                vaciarLista(cabeza);
                break;
            case 16:
                vaciarLista(cabeza);
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while(opcion != 16);
    
    return 0;
}