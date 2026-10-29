#include <iostream>
using namespace std;

/*
Árbol Binario de Búsqueda (ABB)
El árbol mantiene siempre la propiedad de ABB:
- Nodos izquierdos son MENORES
- Nodos derechos son MAYORES

*/

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
    
    // Constructor
    Nodo(int valor) {
        dato = valor;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

// 1. Insertar un nodo en el árbol(recursividad)
void insertar(Nodo*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new Nodo(valor); //raiz->dato=valor,raiz->izquierdo=nul, raiz->derecho=null
        cout << "Nodo " << valor << " insertado correctamente" << endl;
        return;
    }
    
    if (valor < raiz->dato) { //menor=izquierda
        cout << valor << " es menor que " << raiz->dato << ", va a la izquierda" << endl;
        insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) { // mayor=derecha
        cout << valor << " es mayor que " << raiz->dato << ", va a la derecha" << endl;
        insertar(raiz->derecho, valor);
    } else { //en caso que el valor ya exista
        cout << "El valor " << valor << " ya existe en el arbol" << endl;
    }
}

// 2. Mostrar el árbol completo (forma jerárquica)
void mostrarArbol(Nodo* raiz, int nivel = 0, string lado = "Raiz") {
    if (raiz == nullptr) {
        if (nivel == 0) {
            cout << "El arbol esta vacio" << endl;
        }
        return;
    }
    
    // Identación según el nivel
    for (int i = 0; i < nivel; i++) {
        cout << "    ";
    }
    cout << lado << ": " << raiz->dato << endl;
    
    // Mostrar hijos
    mostrarArbol(raiz->izquierdo, nivel + 1, "Izq");
    mostrarArbol(raiz->derecho, nivel + 1, "Der");
}

// 3. Buscar un nodo específico
bool buscar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return false;
    }
    
    if (raiz->dato == valor) {
        return true;
    } else if (valor < raiz->dato) {
        return buscar(raiz->izquierdo, valor);
    } else {
        return buscar(raiz->derecho, valor);
    }
}

// ============ RECORRIDOS DEL ÁRBOL en profundidad (preorden, inorden,postorden )============

//4-  Recorrido Preorden (Raíz - Izquierdo - Derecho)
void recorrerArbol_Preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    
    cout << raiz->dato << " ";
    recorrerArbol_Preorden(raiz->izquierdo);
    recorrerArbol_Preorden(raiz->derecho);
}

//5- Recorrer el árbol (Inorden - muestra los valores ordenados)
// Recorrido Inorden (Izquierdo - Raíz - Derecho)
void recorrerArbol_Inorden(Nodo* raiz) {
    if (raiz == nullptr) {
        return;
    }
    
    recorrerArbol_Inorden(raiz->izquierdo);
    cout << raiz->dato << " ";
    recorrerArbol_Inorden(raiz->derecho);
}

// 6. Recorrido Postorden (Izquierdo - Derecho - Raíz)
//recorre por el lado mas izquierdo posible
void recorrerArbol_postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    
    recorrerArbol_postorden(raiz->izquierdo);
    recorrerArbol_postorden(raiz->derecho);
    cout << raiz->dato << " ";
}

// 6. Borrar un nodo del árbol
Nodo* encontrarMinimo(Nodo* raiz) {
    Nodo* actual = raiz;
    while (actual && actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

bool borrar(Nodo*& raiz, int valor) {
    if (raiz == nullptr) {
        cout << "Valor " << valor << " no encontrado" << endl;
        return false;
    }
    
    if (valor < raiz->dato) {
        return borrar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        return borrar(raiz->derecho, valor);
    } else {
        cout << "Borrando nodo " << valor << endl;
        
        // Caso 1: Nodo sin hijos (hoja)
        if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
            delete raiz;
            raiz = nullptr;
        }
        // Caso 2: Nodo solo con hijo derecho
        else if (raiz->izquierdo == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->derecho;
            delete temp;
        }
        // Caso 3: Nodo solo con hijo izquierdo
        else if (raiz->derecho == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->izquierdo;
            delete temp;
        }
        // Caso 4: Nodo con dos hijos
        else {
            Nodo* temp = encontrarMinimo(raiz->derecho);
            raiz->dato = temp->dato;
            borrar(raiz->derecho, temp->dato);
        }
        return true;
    }
}

// Función para vaciar el árbol (liberar memoria)
void vaciarArbol(Nodo*& raiz) {
    if (raiz == nullptr) return;
    
    vaciarArbol(raiz->izquierdo);
    vaciarArbol(raiz->derecho);
    delete raiz;
    raiz = nullptr;
}

// Menu principal
int main() {
    Nodo* raiz = nullptr;
    int opcion, valor;
    bool encontrado;
    
    do {
        cout << "\n╔════════════════════════════════════════╗" << endl;
        cout << "║     ARBOL BINARIO DE BUSQUEDA (ABB)    ║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
        cout << "\n1. Insertar un nodo" << endl;
        cout << "2. Mostrar el arbol completo" << endl;
        cout << "3. Buscar un nodo especifico" << endl;
        cout << "4. Recorrer el arbol (Pre-orden)" << endl;
        cout << "5. Recorrer el arbol (Inorden)" << endl;
        cout << "6. Recorrer el arbol (Postorden)" << endl;
        cout << "7. Borrar un nodo" << endl;
        cout << "8. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                insertar(raiz, valor);
                break;
                
            case 2:
                cout << "\n--- ARBOL COMPLETO ---" << endl;
                mostrarArbol(raiz);
                break;
                
            case 3:
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                encontrado = buscar(raiz, valor);
                if (encontrado) {
                    cout << "El valor " << valor << " SI existe en el arbol" << endl;
                } else {
                    cout << "El valor " << valor << " NO existe en el arbol" << endl;
                }
                break;

            case 4:
                if (raiz == nullptr) {
                    cout << "El arbol esta vacio" << endl;
                } else {
                    cout << "Recorrido Pre-orden (valores ordenados): ";
                    recorrerArbol_Preorden(raiz);
                    cout << endl;
                }
                break;

            case 5:
                if (raiz == nullptr) {
                    cout << "El arbol esta vacio" << endl;
                } else {
                    cout << "Recorrido Inorden (valores ordenados): ";
                    recorrerArbol_Inorden(raiz);
                    cout << endl;
                }
                break;
            case 6:
                if (raiz == nullptr) {
                    cout << "El arbol esta vacio" << endl;
                } else {
                    cout << "Recorrido Post-orden (valores ordenados): ";
                    recorrerArbol_postorden(raiz);
                    cout << endl;
                }
                break;    

                
                
            case 7:
                cout << "Ingrese el valor a borrar: ";
                cin >> valor;
                borrar(raiz, valor);
                break;
                
            case 8:
                vaciarArbol(raiz);
                cout << "Saliendo del programa..." << endl;
                break;
                
            default:
                cout << "Opcion no valida" << endl;
        }
    } while(opcion != 8);
    
    return 0;
}