#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

//-******************** este arbol ahora guarda expresiones (string)
//-******************** lo usaremos para convertir de prefija a infija

// Definición de la estructura del nodo
struct Nodo {
    string dato;   // ahora puede ser operador o número
    Nodo *izq;
    Nodo *der;
};

// Función para crear un nuevo nodo
Nodo* crearNodo(string d) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = d;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

///////////////////// Construir árbol desde una expresión prefija
Nodo* construirPrefija(vector<string>& tokens, int &i) {
    if (i >= tokens.size()) return nullptr;

    string token = tokens[i++];
    Nodo* nodo = crearNodo(token);

    // Si el token es un operador → necesita hijos
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        nodo->izq = construirPrefija(tokens, i);
        nodo->der = construirPrefija(tokens, i);
    }
    return nodo;
}

///////////////////// Mostrar el árbol de manera jerárquica (igual que antes)
void mostrarArbol(Nodo *arbol, int nivel) {
    if (arbol == nullptr) return; //si esta vacio no muestro nada

    mostrarArbol(arbol->der, nivel + 1); // primero la derecha

    for (int i = 0; i < nivel; i++) {
        cout << "   ";   // espacios para dar la impresión de niveles
    }
    cout << arbol->dato << endl;

    mostrarArbol(arbol->izq, nivel + 1); // luego la izquierda
}

///////////////////// Convertir a INFIX con paréntesis (ya tenías esta función)
string aInfija(Nodo *arbol) {
    if (arbol == nullptr) return "";
    // caso hoja → es un número u operando
    if (arbol->izq == nullptr && arbol->der == nullptr) return arbol->dato;
    // caso operador → pongo paréntesis
    return "(" + aInfija(arbol->izq) + " " + arbol->dato + " " + aInfija(arbol->der) + ")";
}

///////////////////// Recorridos (modifiqué inOrden para añadir paréntesis)
void preOrden(Nodo *arbol) {
    if (arbol == nullptr) return;
    cout << arbol->dato << " ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
}

// In-orden ahora imprime paréntesis alrededor de nodos operadores
void inOrden(Nodo *arbol) {
    if (arbol == nullptr) return;
    bool esOperador = (arbol->izq != nullptr || arbol->der != nullptr);
    if (esOperador) cout << "(";
    inOrden(arbol->izq);
    if (esOperador) cout << " " << arbol->dato << " ";
    else cout << arbol->dato;
    inOrden(arbol->der);
    if (esOperador) cout << ")";
}

void postOrden(Nodo *arbol) {
    if (arbol == nullptr) return;
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato << " ";
}

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
    // ejemplo: prefija → * + 3 4 - 5 2
    string entrada = "* + 3 4 - 5 2";
    cout << "Expresion prefija: " << entrada << endl;

    // separo tokens
    vector<string> tokens;
    stringstream ss(entrada);
    string t;
    while (ss >> t) tokens.push_back(t);

    int i = 0;
    Nodo* arbol = construirPrefija(tokens, i);

    cout << "\nArbol de la expresion:\n";
    mostrarArbol(arbol, 0);

    cout << "\nConvertida a INFIJA con parentesis:\n";
    cout << aInfija(arbol) << endl;

    cout << "\nRecorrido PREORDEN: ";
    preOrden(arbol); cout << endl;

    cout << "Recorrido INORDEN (con parentesis): ";
    inOrden(arbol); cout << endl;

    cout << "Recorrido POSTORDEN: ";
    postOrden(arbol); cout << endl;

    cout << "Recorrido POR NIVELES: ";
    porNiveles(arbol); cout << endl;

    return 0;
}
