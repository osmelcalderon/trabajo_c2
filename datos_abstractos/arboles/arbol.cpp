#include <iostream>
using namespace std;

//-******************** esta fue mi primera opcion
//-******************** este arbol, no tenia padre, porq no necesitaba eliminar elementos, por tanto no requeria recorrer nodos

//https://www.youtube.com/watch?v=eZfXKHrMyo8&list=PLZtLVctMDUqiSizXYItJq7uTcIUHhYSQ0&index=20
// Definición de la estructura del nodo
struct Nodo {
    int dato;
    Nodo *izq;
    Nodo *der;
};

// Función para crear un nuevo nodo
Nodo* crearNodo(int n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

///////////////////// Función para insertar un nodo en el árbol
void insertarNodo(Nodo *&arbol, int n) {
    if (arbol == nullptr) {  // Árbol vacío → se inserta aquí
        arbol = crearNodo(n);
    } else {
        if (n < arbol->dato) {// Insertar en el subárbol izquierdo
            insertarNodo(arbol->izq, n);
        } else { // Insertar en el subárbol derecho
            insertarNodo(arbol->der, n);
        }
    }
}

///////////////////// Función para mostrar el árbol en pantalla de forma jerárquica
void mostrarArbol(Nodo *arbol, int nivel) {
    if (arbol == nullptr) return; //si esta vacio no muestro nada

    mostrarArbol(arbol->der, nivel + 1); // primero la derecha

    for (int i = 0; i < nivel; i++) {
        cout << "   ";   // espacios para dar la impresión de niveles
    }
    cout << arbol->dato << endl;

    mostrarArbol(arbol->izq, nivel + 1); // luego la izquierda
}

//////////////////////////Función de busqueda
bool busqueda(Nodo *arbol, int n) {
    if (arbol == nullptr) {
        return false; // Árbol vacío o llegamos a una rama sin encontrarlo
    }
    if (arbol->dato == n) { //si el elemento en el que estamos coincide, true
        return true; // Encontrado
    }

    if (n < arbol->dato) { //si el elemento que estamos buscando es menor al que estamos busca por izquierda
        return busqueda(arbol->izq, n); // Buscar en la izquierda
    } else { //si el elemento que estamos buscando es mayor al que estamos busca por derecha
        return busqueda(arbol->der, n); // Buscar en la derecha
    }
}

////////////////////PROFUNDIDAD/////////RECORRER TODO EL ARBOL(pre-orden, post-orden, in-orden)

//🔹 Recorrido en "Profundidad"    Pre-Orden (N – I – D)
void preOrden(Nodo *arbol) {
    if (arbol == nullptr) return;
    cout << arbol->dato << " ";   // 1. Visitar nodo
    preOrden(arbol->izq);         // 2. Recorrer izquierda
    preOrden(arbol->der);         // 3. Recorrer derecha
}

//🔹 Recorrido en "Profundidad"   Postorden (I – D – N)
void postOrden(Nodo *arbol) {
    if (arbol == nullptr) return;
    postOrden(arbol->izq);        // 1. Recorrer izquierda
    postOrden(arbol->der);        // 2. Recorrer derecha
    cout << arbol->dato << " ";   // 3. Visitar nodo
}



//🔹 Recorrido en "Profundidad"    In-Orden (I – N – D)
void inOrden(Nodo *arbol) {
    if (arbol == nullptr) return;
    inOrden(arbol->izq);          // 1. Recorrer izquierda
    cout << arbol->dato << " ";   // 2. Visitar nodo
    inOrden(arbol->der);          // 3. Recorrer derecha
}


////////////////////ANCHURA/////////RECORRER TODO EL ARBOL(pre-orden, post-orden, in-orden)
/*
🔹 Recorrido en anchura (BFS – por niveles)
Este recorrido visita los nodos nivel por nivel, de izquierda a derecha.
Se implementa usando una cola (queue):
*/

#include <queue>
void porNiveles(Nodo *arbol) {
    if (arbol == nullptr) return;

    queue<Nodo*> q;
    q.push(arbol);

    while (!q.empty()) {
        Nodo* actual = q.front(); 
        q.pop();

        cout << actual->dato << " ";

        if (actual->izq != nullptr) q.push(actual->izq);
        if (actual->der != nullptr) q.push(actual->der);
    }
}

// Programa principal
int main() {
    Nodo* arbol = nullptr;

    insertarNodo(arbol, 8);
    insertarNodo(arbol, 3);
    insertarNodo(arbol, 1);
    insertarNodo(arbol, 6);
    insertarNodo(arbol, 10);
    insertarNodo(arbol, 4);
    insertarNodo(arbol, 7);
    insertarNodo(arbol, 14);
    insertarNodo(arbol, 13);
    

    // mostrar el árbol en pantalla de forma jerárquica
    cout << "Árbol binario:" << endl;
    mostrarArbol(arbol, 0);
    
    cout << endl;

    // Bus árbol en pantalla de forma jerárquica
    int valor;
    cout << "\nIngrese valor a buscar: ";
    cin >> valor;

    if (busqueda(arbol, valor)) {
        cout << "El valor " << valor << " SÍ se encuentra en el árbol.\n";
    } else {
        cout << "El valor " << valor << " NO se encuentra en el árbol.\n";
    }

     // 
      cout << endl;

    cout << "Recorrido en PREORDEN: ";
    preOrden(arbol);
    cout << endl;

     cout << "Recorrido en INORDEN: ";
    inOrden(arbol);
    cout << endl;

    cout << "Recorrido en POSTORDEN: ";
    postOrden(arbol);
    cout << endl;

    cout << "Recorrido POR NIVELES: ";
    porNiveles(arbol);
    cout << endl;


    return 0;
}
