#include <iostream>
using namespace std;


//-******************** esta fue mi 2da opcion
//-******************** este arbol, ya le incluyo padre, porq necesito eliminar elementos, (requiero recorrer nodos, cuando se elimine alguno) 
//entonces aqui cambio la "struct Nodo" y las funciones "crearNodo" e insertarNodo......... Todo lo demas se mantuvo igual

struct Nodo {
    int dato;
    Nodo *izq;
    Nodo *der;
    Nodo *padre; // nuevo puntero al padre   //*******cambio padre */
};

// Función para crear un nuevo nodo
Nodo* crearNodo(int n, Nodo* padre = nullptr) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    nuevo->padre = padre; // asignamos el padre   //*******cambio padre */
    return nuevo;
}

// Función para insertar un nodo en el árbol
void insertarNodo(Nodo *&arbol, int n, Nodo* padre = nullptr) {
    if (arbol == nullptr) {  // Árbol vacío → se inserta aquí
        arbol = crearNodo(n, padre);  //*******cambio padre */
    } else {
        if (n < arbol->dato) {// Insertar en el subárbol izquierdo
            insertarNodo(arbol->izq, n, arbol); // arbol actual es el padre  //*******cambio padre */
        } else { // Insertar en el subárbol derecho
            insertarNodo(arbol->der, n, arbol); // arbol actual es el padre  //*******cambio padre */
        }
    }
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/////////////////////////////////eliminarNodo (con padre)/////////////////////
                  //Usa el puntero padre para actualizar los enlaces de forma directa.
                  //Funciona con los 3 casos de eliminación:
                    //  hoja
                    //  un hijo
                    //  dos hijos (reemplazando con sucesor inorden)

// Función para buscar un nodo con un valor específico
Nodo* buscarNodo(Nodo* arbol, int n) {
    if (!arbol) return nullptr;         // Árbol vacío o nodo no encontrado
    if (arbol->dato == n) return arbol; // Nodo encontrado
    if (n < arbol->dato)
        return buscarNodo(arbol->izq, n); // Buscar en subárbol izquierdo
    else
        return buscarNodo(arbol->der, n); // Buscar en subárbol derecho
}



// Función para encontrar el nodo mínimo de un subárbol (sucesor inorden)
// devuelve al hijo más izquierdo posible
Nodo* minimo(Nodo* arbol) {
    //Si el árbol está vacío o el nodo actual no tiene hijo izquierdo, entonces este nodo es el mínimo;
    if (!arbol || !arbol->izq) return arbol; 
    // si no, sigue bajando por la izquierda.
    return minimo(arbol->izq);
}

// Función para eliminar un nodo del arbol
void eliminarNodo(Nodo* &arbol, int n) {
    Nodo* nodo = buscarNodo(arbol, n);
    if (nodo == nullptr) return; // seguridad, aunque ya debería existir
    

    // Caso 1: nodo hoja
    if (nodo->izq == nullptr && nodo->der == nullptr) {  //si izq=null y der=null entonce es hoja
        if (nodo->padre != nullptr) {  //dependiendo de si el es hijo(izq o der) entonces al padre indicarle as (izq o der) q es = null
            if (nodo->padre->izq == nodo) nodo->padre->izq = nullptr;
            else nodo->padre->der = nullptr;
        } else { //si el mismo es el padre
            arbol = nullptr; // el nodo era raíz
        }
        delete nodo;
    }
    // Caso 2: nodo con un hijo
    else if (nodo->izq == nullptr || nodo->der == nullptr) {  //si izq=null "O" der=null entonce tiene 1 hijo
        Nodo* hijo = (nodo->izq != nullptr) ? nodo->izq : nodo->der;  //aqui averiguo quien es el hijo, si la derecha o la izquierda
        hijo->padre = nodo->padre; //le asigno al hijo un nuevo padre, que va hacer el q antes era el abuelo
        if (nodo->padre != nullptr) { //si el que voy a eliminar tiene padre, entonces, a ese abuelo, le digo q se va a convertir en padre de (izq o der) del nuevo hijo
            if (nodo->padre->izq == nodo) nodo->padre->izq = hijo;
            else nodo->padre->der = hijo;
        } else {
            arbol = hijo; // el nodo era raíz
        }
        delete nodo;
    }
    // Caso 3: nodo con dos hijos
    else {
        Nodo* menor = minimo(nodo->der); // buscamos el nodo de la derecha y lo más izquierdo posible
        nodo->dato = menor->dato;        // reemplazamos el valor del nodo menor encontrado, por el que queremos eliminar
        eliminarNodo(arbol, menor->dato); // eliminamos el nodo menor(el más izquiero posible) 
    }
}



void destruirArbol(Nodo* arbol) {
    if (!arbol) return;
    destruirArbol(arbol->izq);
    destruirArbol(arbol->der);
    delete arbol;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////




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
    
    /*
    // Bus árbol en pantalla de forma jerárquica
    int valor;
    cout << "\nIngrese valor a buscar: ";
    cin >> valor;

    if (busqueda(arbol, valor)) {
        cout << "El valor " << valor << " SÍ se encuentra en el árbol.\n";
    } else {
        cout << "El valor " << valor << " NO se encuentra en el árbol.\n";
    }
    */

     // Recorridos
    cout << "PREORDEN: "; preOrden(arbol); cout << endl;
    cout << "INORDEN: "; inOrden(arbol); cout << endl;
    cout << "POSTORDEN: "; postOrden(arbol); cout << endl;
    cout << "POR NIVELES: "; porNiveles(arbol); cout << endl << endl;



    // Caso 1: eliminar hoja (13)
    eliminarNodo(arbol, 13);
    cout << "Tras eliminar hoja (13):" << endl;
    mostrarArbol(arbol, 0); cout << endl;

    // Caso 2: eliminar nodo con un hijo (14)
    eliminarNodo(arbol, 14);
    cout << "Tras eliminar nodo con un hijo (14):" << endl;
    mostrarArbol(arbol, 0); cout << endl;

    // Caso 3: eliminar nodo con dos hijos (8)
    eliminarNodo(arbol, 8);
    cout << "Tras eliminar nodo con dos hijos (8):" << endl;
    mostrarArbol(arbol, 0); cout << endl;

    //liberar todo el árbol al final del programa. Muy importante para evitar memory leaks.
     destruirArbol(arbol);


    return 0;
}
