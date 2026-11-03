#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <string>  
using namespace std;

/*
Árbol Binario (Binary Tree) - VERSIÓN COMPLETA
Características principales:
- Estructura jerárquica: Cada nodo puede tener hasta 2 hijos (izquierdo y derecho)
- Nodo raíz: El nodo superior del árbol
- Nodos hoja: Nodos que no tienen hijos
- Subárboles: Cada nodo es raíz de un subárbol
*/

// Definición del nodo del árbol
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
    
    // Constructor para facilitar la creación
    Nodo(int valor) {
        dato = valor;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

// ============ INSERCIÓN ============

// Insertar en un Árbol Binario de Búsqueda (ABB)
void insertarABB(Nodo*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new Nodo(valor);
        cout << "Insertado " << valor << " en el arbol" << endl;
        return;
    }
    
    if (valor < raiz->dato) {
        cout << valor << " es menor que " << raiz->dato << ", va a la izquierda" << endl;
        insertarABB(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        cout << valor << " es mayor que " << raiz->dato << ", va a la derecha" << endl;
        insertarABB(raiz->derecho, valor);
    } else {
        cout << "El valor " << valor << " ya existe en el arbol" << endl;
    }
}

// Insertar en posición específica (para árbol binario normal, no ABB)
void insertarPosicion(Nodo*& raiz, int valor, string direccion) {
    if (raiz == nullptr) {
        raiz = new Nodo(valor);
        cout << "Insertado " << valor << " como raiz" << endl;
        return;
    }
    
    queue<Nodo*> cola;
    cola.push(raiz);
    
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        
        if (direccion == "izquierda" && actual->izquierdo == nullptr) {
            actual->izquierdo = new Nodo(valor);
            cout << "Insertado " << valor << " a la izquierda de " << actual->dato << endl;
            return;
        }
        if (direccion == "derecha" && actual->derecho == nullptr) {
            actual->derecho = new Nodo(valor);
            cout << "Insertado " << valor << " a la derecha de " << actual->dato << endl;
            return;
        }
        
        if (actual->izquierdo != nullptr) cola.push(actual->izquierdo);
        if (actual->derecho != nullptr) cola.push(actual->derecho);
    }
    cout << "No se encontro un lugar para insertar" << endl;
}

// ============ BUSQUEDA ============

// Buscar un elemento en el árbol
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

// Buscar y mostrar la ruta al nodo
bool buscarConRuta(Nodo* raiz, int valor, string ruta) {
    if (raiz == nullptr) {
        return false;
    }
    
    if (raiz->dato == valor) {
        cout << "Valor " << valor << " encontrado. Ruta: " << ruta << " Raiz" << endl;
        return true;
    }
    
    if (buscarConRuta(raiz->izquierdo, valor, ruta + " Izquierda ->")) {
        return true;
    }
    return buscarConRuta(raiz->derecho, valor, ruta + " Derecha ->");
}

// ============ ELIMINACIÓN ============

// Encontrar el nodo con valor mínimo (más a la izquierda)
Nodo* encontrarMinimo(Nodo* raiz) {
    Nodo* actual = raiz;
    while (actual && actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

// Encontrar el nodo con valor máximo (más a la derecha)
Nodo* encontrarMaximo(Nodo* raiz) {
    Nodo* actual = raiz;
    while (actual && actual->derecho != nullptr) {
        actual = actual->derecho;
    }
    return actual;
}

// Eliminar un elemento del árbol
bool eliminar(Nodo*& raiz, int valor) {
    if (raiz == nullptr) {
        cout << "Valor " << valor << " no encontrado" << endl;
        return false;
    }
    
    if (valor < raiz->dato) {
        return eliminar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        return eliminar(raiz->derecho, valor);
    } else {
        // Nodo encontrado
        cout << "Eliminando " << valor << endl;
        
        // Caso 1: Nodo sin hijos (hoja)
        if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
            delete raiz;
            raiz = nullptr;
        }
        // Caso 2: Nodo con un solo hijo (derecho)
        else if (raiz->izquierdo == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->derecho;
            delete temp;
        }
        // Caso 3: Nodo con un solo hijo (izquierdo)
        else if (raiz->derecho == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->izquierdo;
            delete temp;
        }
        // Caso 4: Nodo con dos hijos
        else {
            Nodo* temp = encontrarMinimo(raiz->derecho);
            raiz->dato = temp->dato;
            eliminar(raiz->derecho, temp->dato);
        }
        return true;
    }
}

// Eliminar todas las hojas del árbol
int eliminarHojas(Nodo*& raiz) {
    if (raiz == nullptr) return 0;
    
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        delete raiz;
        raiz = nullptr;
        return 1;
    }
    
    return eliminarHojas(raiz->izquierdo) + eliminarHojas(raiz->derecho);
}

// ============ RECORRIDOS DEL ÁRBOL ============

// 1. Recorrido Preorden (Raíz - Izquierdo - Derecho)
void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    
    cout << raiz->dato << " ";
    preorden(raiz->izquierdo);
    preorden(raiz->derecho);
}

// 2. Recorrido Inorden (Izquierdo - Raíz - Derecho)
void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    
    inorden(raiz->izquierdo);
    cout << raiz->dato << " ";
    inorden(raiz->derecho);
}

// 3. Recorrido Postorden (Izquierdo - Derecho - Raíz)
void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    
    postorden(raiz->izquierdo);
    postorden(raiz->derecho);
    cout << raiz->dato << " ";
}

// 4. Recorrido por Niveles (BFS)
void recorridoPorNiveles(Nodo* raiz) {
    if (raiz == nullptr) {
        cout << "Arbol vacio" << endl;
        return;
    }
    
    queue<Nodo*> cola;
    cola.push(raiz);
    
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        
        cout << actual->dato << " ";
        
        if (actual->izquierdo != nullptr) cola.push(actual->izquierdo);
        if (actual->derecho != nullptr) cola.push(actual->derecho);
    }
}

// 5. Recorrido por niveles CON formato (mostrar nivel por nivel)
void recorridoPorNivelesFormateado(Nodo* raiz) {
    if (raiz == nullptr) {
        cout << "Arbol vacio" << endl;
        return;
    }
    
    queue<Nodo*> cola;
    cola.push(raiz);
    int nivel = 0;
    
    while (!cola.empty()) {
        int nivelSize = cola.size();
        cout << "Nivel " << nivel << ": ";
        
        for (int i = 0; i < nivelSize; i++) {
            Nodo* actual = cola.front();
            cola.pop();
            cout << actual->dato << " ";
            
            if (actual->izquierdo != nullptr) cola.push(actual->izquierdo);
            if (actual->derecho != nullptr) cola.push(actual->derecho);
        }
        cout << endl;
        nivel++;
    }
}

// 6. Recorrido en espiral (zigzag)
void recorridoEspiral(Nodo* raiz) {
    if (raiz == nullptr) return;
    
    stack<Nodo*> pila1; // derecha a izquierda
    stack<Nodo*> pila2; // izquierda a derecha
    
    pila1.push(raiz);
    
    while (!pila1.empty() || !pila2.empty()) {
        while (!pila1.empty()) {
            Nodo* actual = pila1.top();
            pila1.pop();
            cout << actual->dato << " ";
            
            if (actual->derecho != nullptr) pila2.push(actual->derecho);
            if (actual->izquierdo != nullptr) pila2.push(actual->izquierdo);
        }
        
        while (!pila2.empty()) {
            Nodo* actual = pila2.top();
            pila2.pop();
            cout << actual->dato << " ";
            
            if (actual->izquierdo != nullptr) pila1.push(actual->izquierdo);
            if (actual->derecho != nullptr) pila1.push(actual->derecho);
        }
    }
}

// ============ PROPIEDADES DEL ÁRBOL ============

// 1. Altura del árbol (máxima profundidad)
int altura(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    
    int alturaIzq = altura(raiz->izquierdo);
    int alturaDer = altura(raiz->derecho);
    
    return max(alturaIzq, alturaDer) + 1;
}

// 2. Profundidad de un nodo específico
int profundidad(Nodo* raiz, int valor, int prof = 0) {
    if (raiz == nullptr) return -1;
    
    if (raiz->dato == valor) return prof;
    
    int profIzq = profundidad(raiz->izquierdo, valor, prof + 1);
    if (profIzq != -1) return profIzq;
    
    return profundidad(raiz->derecho, valor, prof + 1);
}

// ============ LONGITUD DE CAMINO ============

// 1. Longitud de Camino Interna (suma de profundidades de todos los nodos)
int longitudCaminoInterna(Nodo* raiz, int profundidad = 0) {
    if (raiz == nullptr) return 0;
    
    // Profundidad del nodo actual + suma de profundidades de sus hijos
    return profundidad + 
           longitudCaminoInterna(raiz->izquierdo, profundidad + 1) +
           longitudCaminoInterna(raiz->derecho, profundidad + 1);
}

// 2. Longitud de Camino Externa (suma de profundidades de todos los NULL)
int longitudCaminoExterna(Nodo* raiz, int profundidad = 0) {
    if (raiz == nullptr) return profundidad;
    
    return longitudCaminoExterna(raiz->izquierdo, profundidad + 1) +
           longitudCaminoExterna(raiz->derecho, profundidad + 1);
}

// 3. Longitud de Camino Total = Interna + Externa
int longitudCaminoTotal(Nodo* raiz) {
    return longitudCaminoInterna(raiz) + longitudCaminoExterna(raiz);
}

// 4. Longitud de Camino a un nodo específico
int longitudCaminoNodo(Nodo* raiz, int valor, int profundidad = 0) {
    if (raiz == nullptr) return -1;
    
    if (raiz->dato == valor) return profundidad;
    
    int caminoIzq = longitudCaminoNodo(raiz->izquierdo, valor, profundidad + 1);
    if (caminoIzq != -1) return caminoIzq;
    
    return longitudCaminoNodo(raiz->derecho, valor, profundidad + 1);
}

// 5. Longitud de Camino PROMEDIO
double longitudCaminoPromedio(Nodo* raiz) {
    int totalNodos = contarNodos(raiz);
    if (totalNodos == 0) return 0;
    
    return (double)longitudCaminoInterna(raiz) / totalNodos;
}

// 6. Mostrar profundidades de todos los nodos
void mostrarProfundidades(Nodo* raiz, int profundidad = 0) {
    if (raiz == nullptr) return;
    
    cout << "Nodo " << raiz->dato << " -> Profundidad: " << profundidad << endl;
    
    mostrarProfundidades(raiz->izquierdo, profundidad + 1);
    mostrarProfundidades(raiz->derecho, profundidad + 1);
}

// 7. Longitud de Camino desde la raíz hasta cada hoja
void caminosHastaHojas(Nodo* raiz, string camino = "", int longitud = 0) {
    if (raiz == nullptr) return;
    
    // Agregar el nodo actual al camino
    camino += to_string(raiz->dato) + " ";
    
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        // Es una hoja
        cout << "Camino a hoja " << raiz->dato << ": " << camino << "(longitud: " << longitud << ")" << endl;
    } else {
        caminosHastaHojas(raiz->izquierdo, camino, longitud + 1);
        caminosHastaHojas(raiz->derecho, camino, longitud + 1);
    }
}

// 8. Longitud de Camino entre DOS nodos
int distanciaEntreNodos(Nodo* raiz, int valor1, int valor2) {
    Nodo* lca = encontrarLCA(raiz, valor1, valor2);
    if (lca == nullptr) return -1;
    
    int dist1 = longitudCaminoNodo(lca, valor1, 0);
    int dist2 = longitudCaminoNodo(lca, valor2, 0);
    
    return dist1 + dist2;
}

// 9. Encontrar la hoja más cercana a la raíz (menor longitud de camino)
pair<int, int> hojaMasCercana(Nodo* raiz, int profundidad = 0) {
    if (raiz == nullptr) return {-1, -1};
    
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        return {raiz->dato, profundidad};
    }
    
    pair<int, int> izquierda = hojaMasCercana(raiz->izquierdo, profundidad + 1);
    pair<int, int> derecha = hojaMasCercana(raiz->derecho, profundidad + 1);
    
    if (izquierda.first == -1) return derecha;
    if (derecha.first == -1) return izquierda;
    
    if (izquierda.second < derecha.second) return izquierda;
    return derecha;
}

// 10. Encontrar la hoja más lejana (mayor longitud de camino)
pair<int, int> hojaMasLejana(Nodo* raiz, int profundidad = 0) {
    if (raiz == nullptr) return {-1, -1};
    
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        return {raiz->dato, profundidad};
    }
    
    pair<int, int> izquierda = hojaMasLejana(raiz->izquierdo, profundidad + 1);
    pair<int, int> derecha = hojaMasLejana(raiz->derecho, profundidad + 1);
    
    if (izquierda.first == -1) return derecha;
    if (derecha.first == -1) return izquierda;
    
    if (izquierda.second > derecha.second) return izquierda;
    return derecha;
}

// 3. Nivel de un nodo (igual que profundidad, pero contando desde 1)
int nivel(Nodo* raiz, int valor, int niv = 1) {
    if (raiz == nullptr) return -1;
    
    if (raiz->dato == valor) return niv;
    
    int nivIzq = nivel(raiz->izquierdo, valor, niv + 1);
    if (nivIzq != -1) return nivIzq;
    
    return nivel(raiz->derecho, valor, niv + 1);
}

// 4. Contar número de nodos
int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    
    return 1 + contarNodos(raiz->izquierdo) + contarNodos(raiz->derecho);
}

// 5. Contar nodos internos (con al menos un hijo)
int contarNodosInternos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    
    if (raiz->izquierdo != nullptr || raiz->derecho != nullptr) {
        return 1 + contarNodosInternos(raiz->izquierdo) + contarNodosInternos(raiz->derecho);
    }
    return contarNodosInternos(raiz->izquierdo) + contarNodosInternos(raiz->derecho);
}

// 6. Contar número de nodos hoja (sin hijos)
int contarHojas(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        return 1;
    }
    
    return contarHojas(raiz->izquierdo) + contarHojas(raiz->derecho);
}

// 7. Contar nodos con un solo hijo
int contarNodosUnHijo(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    
    int contador = 0;
    if ((raiz->izquierdo == nullptr && raiz->derecho != nullptr) ||
        (raiz->izquierdo != nullptr && raiz->derecho == nullptr)) {
        contador = 1;
    }
    
    return contador + contarNodosUnHijo(raiz->izquierdo) + contarNodosUnHijo(raiz->derecho);
}

// 8. Contar nodos con dos hijos
int contarNodosDosHijos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    
    int contador = 0;
    if (raiz->izquierdo != nullptr && raiz->derecho != nullptr) {
        contador = 1;
    }
    
    return contador + contarNodosDosHijos(raiz->izquierdo) + contarNodosDosHijos(raiz->derecho);
}

// 9. Encontrar valor mínimo (en ABB)
int encontrarMinimoABB(Nodo* raiz) {
    if (raiz == nullptr) return -1e9;
    
    if (raiz->izquierdo == nullptr) return raiz->dato;
    return encontrarMinimoABB(raiz->izquierdo);
}

// 10. Encontrar valor máximo (en ABB)
int encontrarMaximoABB(Nodo* raiz) {
    if (raiz == nullptr) return 1e9;
    
    if (raiz->derecho == nullptr) return raiz->dato;
    return encontrarMaximoABB(raiz->derecho);
}

// 11. Ancho del árbol (máximo número de nodos en un nivel)
int anchoArbol(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    
    queue<Nodo*> cola;
    cola.push(raiz);
    int maxAncho = 0;
    
    while (!cola.empty()) {
        int nivelSize = cola.size();
        maxAncho = max(maxAncho, nivelSize);
        
        for (int i = 0; i < nivelSize; i++) {
            Nodo* actual = cola.front();
            cola.pop();
            
            if (actual->izquierdo != nullptr) cola.push(actual->izquierdo);
            if (actual->derecho != nullptr) cola.push(actual->derecho);
        }
    }
    return maxAncho;
}

// 12. Diámetro del árbol (ruta más larga entre dos nodos)
int diametroArbol(Nodo* raiz, int& resultado) {
    if (raiz == nullptr) return 0;
    
    int alturaIzq = diametroArbol(raiz->izquierdo, resultado);
    int alturaDer = diametroArbol(raiz->derecho, resultado);
    
    resultado = max(resultado, alturaIzq + alturaDer);
    
    return max(alturaIzq, alturaDer) + 1;
}

int diametro(Nodo* raiz) {
    int resultado = 0;
    diametroArbol(raiz, resultado);
    return resultado;
}

// 13. Verificar si es un Árbol Binario Completo
bool esCompleto(Nodo* raiz) {
    if (raiz == nullptr) return true;
    
    queue<Nodo*> cola;
    cola.push(raiz);
    bool hayHueco = false;
    
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        
        if (actual->izquierdo != nullptr) {
            if (hayHueco) return false;
            cola.push(actual->izquierdo);
        } else {
            hayHueco = true;
        }
        
        if (actual->derecho != nullptr) {
            if (hayHueco) return false;
            cola.push(actual->derecho);
        } else {
            hayHueco = true;
        }
    }
    return true;
}

// 14. Verificar si es un Árbol Binario Perfecto
bool esPerfecto(Nodo* raiz) {
    int h = altura(raiz);
    int totalNodos = contarNodos(raiz);
    return totalNodos == pow(2, h) - 1;
}

// 15. Verificar si es un Árbol Binario Lleno (Full Binary Tree)
bool esLleno(Nodo* raiz) {
    if (raiz == nullptr) return true;
    
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) return true;
    
    if (raiz->izquierdo != nullptr && raiz->derecho != nullptr) {
        return esLleno(raiz->izquierdo) && esLleno(raiz->derecho);
    }
    
    return false;
}

// 16. Verificar si es un Árbol Binario Balanceado (diferencia de altura <= 1)
int esBalanceadoHelper(Nodo* raiz, bool& balanceado) {
    if (raiz == nullptr) return 0;
    
    int alturaIzq = esBalanceadoHelper(raiz->izquierdo, balanceado);
    int alturaDer = esBalanceadoHelper(raiz->derecho, balanceado);
    
    if (abs(alturaIzq - alturaDer) > 1) {
        balanceado = false;
    }
    
    return max(alturaIzq, alturaDer) + 1;
}

bool esBalanceado(Nodo* raiz) {
    bool balanceado = true;
    esBalanceadoHelper(raiz, balanceado);
    return balanceado;
}

// 17. Verificar si es un Árbol Binario de Búsqueda (ABB)
bool esABB(Nodo* raiz, int min = -1e9, int max = 1e9) {
    if (raiz == nullptr) return true;
    
    if (raiz->dato < min || raiz->dato > max) return false;
    
    return esABB(raiz->izquierdo, min, raiz->dato - 1) &&
           esABB(raiz->derecho, raiz->dato + 1, max);
}

// 18. Suma de todos los nodos
int sumaNodos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    return raiz->dato + sumaNodos(raiz->izquierdo) + sumaNodos(raiz->derecho);
}

// 19. Promedio de los nodos
double promedioNodos(Nodo* raiz) {
    int total = sumaNodos(raiz);
    int cantidad = contarNodos(raiz);
    if (cantidad == 0) return 0;
    return (double)total / cantidad;
}

// 20. Verificar si dos árboles son idénticos
bool sonIdenticos(Nodo* raiz1, Nodo* raiz2) {
    if (raiz1 == nullptr && raiz2 == nullptr) return true;
    if (raiz1 == nullptr || raiz2 == nullptr) return false;
    
    return (raiz1->dato == raiz2->dato) &&
           sonIdenticos(raiz1->izquierdo, raiz2->izquierdo) &&
           sonIdenticos(raiz1->derecho, raiz2->derecho);
}

// 21. Copiar el árbol (crear un duplicado)
Nodo* copiarArbol(Nodo* raiz) {
    if (raiz == nullptr) return nullptr;
    
    Nodo* nuevaRaiz = new Nodo(raiz->dato);
    nuevaRaiz->izquierdo = copiarArbol(raiz->izquierdo);
    nuevaRaiz->derecho = copiarArbol(raiz->derecho);
    
    return nuevaRaiz;
}

// 22. Espejo del árbol (invertir izquierda y derecha)
void espejoArbol(Nodo*& raiz) {
    if (raiz == nullptr) return;
    
    swap(raiz->izquierdo, raiz->derecho);
    espejoArbol(raiz->izquierdo);
    espejoArbol(raiz->derecho);
}

// 23. Verificar si el árbol es simétrico (espejo de sí mismo)
bool esSimetricoHelper(Nodo* izquierdo, Nodo* derecho) {
    if (izquierdo == nullptr && derecho == nullptr) return true;
    if (izquierdo == nullptr || derecho == nullptr) return false;
    
    return (izquierdo->dato == derecho->dato) &&
           esSimetricoHelper(izquierdo->izquierdo, derecho->derecho) &&
           esSimetricoHelper(izquierdo->derecho, derecho->izquierdo);
}

bool esSimetrico(Nodo* raiz) {
    if (raiz == nullptr) return true;
    return esSimetricoHelper(raiz->izquierdo, raiz->derecho);
}

// 24. Encontrar el ancestro común más bajo (LCA)
Nodo* encontrarLCA(Nodo* raiz, int valor1, int valor2) {
    if (raiz == nullptr) return nullptr;
    
    if (raiz->dato == valor1 || raiz->dato == valor2) return raiz;
    
    Nodo* lcaIzq = encontrarLCA(raiz->izquierdo, valor1, valor2);
    Nodo* lcaDer = encontrarLCA(raiz->derecho, valor1, valor2);
    
    if (lcaIzq != nullptr && lcaDer != nullptr) return raiz;
    
    return (lcaIzq != nullptr) ? lcaIzq : lcaDer;
}

// 25. Calcular la distancia entre dos nodos
int distanciaEntreNodos(Nodo* raiz, int valor1, int valor2) {
    Nodo* lca = encontrarLCA(raiz, valor1, valor2);
    
    int dist1 = profundidad(lca, valor1);
    int dist2 = profundidad(lca, valor2);
    
    return dist1 + dist2;
}

// ============ VISUALIZACIÓN ============

// Mostrar árbol de forma jerárquica (con niveles)
void mostrarJerarquico(Nodo* raiz, int nivel = 0, string lado = "Raiz") {
    if (raiz == nullptr) return;
    
    // Mostrar el nodo actual con indentación
    for (int i = 0; i < nivel; i++) {
        cout << "    ";
    }
    cout << lado << ": " << raiz->dato << endl;
    
    // Recorrer hijos
    mostrarJerarquico(raiz->izquierdo, nivel + 1, "Izq");
    mostrarJerarquico(raiz->derecho, nivel + 1, "Der");
}

// Mostrar árbol visualmente (más bonito)
void mostrarArbolVisual(Nodo* raiz, int espacio = 0, int incremento = 5) {
    if (raiz == nullptr) return;
    
    espacio += incremento;
    
    // Procesar hijo derecho primero (para que se vea inclinado)
    mostrarArbolVisual(raiz->derecho, espacio);
    
    // Mostrar nodo actual
    cout << endl;
    for (int i = incremento; i < espacio; i++) {
        cout << " ";
    }
    cout << raiz->dato << endl;
    
    // Procesar hijo izquierdo
    mostrarArbolVisual(raiz->izquierdo, espacio);
}

// ============ OPERACIONES ADICIONALES ============

// Vaciar todo el árbol
void vaciarArbol(Nodo*& raiz) {
    if (raiz == nullptr) return;
    
    vaciarArbol(raiz->izquierdo);
    vaciarArbol(raiz->derecho);
    delete raiz;
    raiz = nullptr;
}

// Crear árbol de ejemplo predefinido
void crearArbolEjemplo(Nodo*& raiz) {
    vaciarArbol(raiz);
    raiz = new Nodo(50);
    raiz->izquierdo = new Nodo(30);
    raiz->derecho = new Nodo(70);
    raiz->izquierdo->izquierdo = new Nodo(20);
    raiz->izquierdo->derecho = new Nodo(40);
    raiz->derecho->izquierdo = new Nodo(60);
    raiz->derecho->derecho = new Nodo(80);
    cout << "Arbol de ejemplo creado (50,30,70,20,40,60,80)" << endl;
}

// ============ MENU PRINCIPAL ============

int main() {
    Nodo* raiz = nullptr;
    Nodo* raizCopia = nullptr;
    int opcion, valor, valor2, resultado;
    bool bandera;
    
    do {
        cout << "\n╔══════════════════════════════════════════════════════════════╗" << endl;
        cout << "║              ARBOL BINARIO - TODAS LAS PROPIEDADES             ║" << endl;
        cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
        cout << "\n--- INSERCION Y ELIMINACION ---" << endl;
        cout << "1.  Insertar en ABB" << endl;
        cout << "2.  Insertar en posicion especifica" << endl;
        cout << "3.  Eliminar elemento" << endl;
        cout << "4.  Eliminar todas las hojas" << endl;
        cout << "5.  Buscar elemento" << endl;
        cout << "6.  Buscar elemento con ruta" << endl;
        
        cout << "\n--- RECORRIDOS ---" << endl;
        cout << "7.  Recorrido Preorden" << endl;
        cout << "8.  Recorrido Inorden" << endl;
        cout << "9.  Recorrido Postorden" << endl;
        cout << "10. Recorrido por Niveles (BFS)" << endl;
        cout << "11. Recorrido por Niveles Formateado" << endl;
        cout << "12. Recorrido en Espiral (Zigzag)" << endl;
        
        cout << "\n--- PROPIEDADES BASICAS ---" << endl;
        cout << "13. Mostrar arbol (Jerarquico)" << endl;
        cout << "14. Mostrar arbol (Visual)" << endl;
        cout << "15. Altura del arbol" << endl;
        cout << "16. Profundidad de un nodo" << endl;
        cout << "17. Nivel de un nodo" << endl;
        cout << "18. Cantidad de nodos" << endl;
        cout << "19. Cantidad de nodos internos" << endl;
        cout << "20. Cantidad de hojas" << endl;
        cout << "21. Cantidad de nodos con un hijo" << endl;
        cout << "22. Cantidad de nodos con dos hijos" << endl;
        cout << "23. Valor minimo del arbol" << endl;
        cout << "24. Valor maximo del arbol" << endl;
        cout << "25. Ancho del arbol" << endl;
        cout << "26. Diametro del arbol" << endl;
        cout << "27. Suma de todos los nodos" << endl;
        cout << "28. Promedio de los nodos" << endl;
        
        cout << "\n--- VERIFICACIONES ---" << endl;
        cout << "29. Verificar si es Arbol Binario Completo" << endl;
        cout << "30. Verificar si es Arbol Binario Perfecto" << endl;
        cout << "31. Verificar si es Arbol Binario Lleno" << endl;
        cout << "32. Verificar si es Arbol Balanceado" << endl;
        cout << "33. Verificar si es Arbol Binario de Busqueda (ABB)" << endl;
        cout << "34. Verificar si es Simetrico" << endl;
        
        cout << "\n--- OPERACIONES AVANZADAS ---" << endl;
        cout << "35. Copiar arbol" << endl;
        cout << "36. Crear espejo del arbol" << endl;
        cout << "37. Encontrar ancestro comun mas bajo (LCA)" << endl;
        cout << "38. Distancia entre dos nodos" << endl;
        cout << "39. Crear arbol de ejemplo" << endl;
        cout << "40. Vaciar arbol" << endl;
        cout << "41. Salir" << endl;
        cout << "\nSeleccione: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                insertarABB(raiz, valor);
                break;
            case 2: {
                cout << "Valor a insertar: ";
                cin >> valor;
                cout << "Lado (izquierda/derecha): ";
                string lado;
                cin >> lado;
                insertarPosicion(raiz, valor, lado);
                break;
                }
            case 3:
                cout << "Valor a eliminar: ";
                cin >> valor;
                eliminar(raiz, valor);
                break;
            case 4:
                resultado = eliminarHojas(raiz);
                cout << "Se eliminaron " << resultado << " hojas" << endl;
                break;
            case 5:
                cout << "Valor a buscar: ";
                cin >> valor;
                bandera = buscar(raiz, valor);
                if (bandera) cout << "El valor " << valor << " SI existe en el arbol" << endl;
                else cout << "El valor " << valor << " NO existe en el arbol" << endl;
                break;
            case 6:
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarConRuta(raiz, valor, "");
                break;
            case 7:
                cout << "Recorrido Preorden: ";
                preorden(raiz);
                cout << endl;
                break;
            case 8:
                cout << "Recorrido Inorden: ";
                inorden(raiz);
                cout << endl;
                break;
            case 9:
                cout << "Recorrido Postorden: ";
                postorden(raiz);
                cout << endl;
                break;
            case 10:
                cout << "Recorrido por Niveles: ";
                recorridoPorNiveles(raiz);
                cout << endl;
                break;
            case 11:
                recorridoPorNivelesFormateado(raiz);
                break;
            case 12:
                cout << "Recorrido en Espiral: ";
                recorridoEspiral(raiz);
                cout << endl;
                break;
            case 13:
                cout << "\n--- ARBOL (JERARQUICO) ---" << endl;
                mostrarJerarquico(raiz);
                break;
            case 14:
                cout << "\n--- ARBOL (VISUAL) ---" << endl;
                mostrarArbolVisual(raiz);
                cout << endl;
                break;
            case 15:
                cout << "Altura del arbol: " << altura(raiz) << endl;
                break;
            case 16:
                cout << "Valor para profundidad: ";
                cin >> valor;
                resultado = profundidad(raiz, valor);
                if (resultado != -1) cout << "Profundidad: " << resultado << endl;
                else cout << "Nodo no encontrado" << endl;
                break;
            case 17:
                cout << "Valor para nivel: ";
                cin >> valor;
                resultado = nivel(raiz, valor);
                if (resultado != -1) cout << "Nivel: " << resultado << endl;
                else cout << "Nodo no encontrado" << endl;
                break;
            case 18:
                cout << "Cantidad de nodos: " << contarNodos(raiz) << endl;
                break;
            case 19:
                cout << "Cantidad de nodos internos: " << contarNodosInternos(raiz) << endl;
                break;
            case 20:
                cout << "Cantidad de hojas: " << contarHojas(raiz) << endl;
                break;
            case 21:
                cout << "Cantidad de nodos con un hijo: " << contarNodosUnHijo(raiz) << endl;
                break;
            case 22:
                cout << "Cantidad de nodos con dos hijos: " << contarNodosDosHijos(raiz) << endl;
                break;
            case 23:
                if (raiz == nullptr) cout << "Arbol vacio" << endl;
                else cout << "Valor minimo: " << encontrarMinimoABB(raiz) << endl;
                break;
            case 24:
                if (raiz == nullptr) cout << "Arbol vacio" << endl;
                else cout << "Valor maximo: " << encontrarMaximoABB(raiz) << endl;
                break;
            case 25:
                cout << "Ancho del arbol: " << anchoArbol(raiz) << endl;
                break;
            case 26:
                cout << "Diametro del arbol: " << diametro(raiz) << endl;
                break;
            case 27:
                cout << "Suma de todos los nodos: " << sumaNodos(raiz) << endl;
                break;
            case 28:
                cout << "Promedio de los nodos: " << promedioNodos(raiz) << endl;
                break;
            case 29:
                if (esCompleto(raiz)) cout << "SI es un arbol binario completo" << endl;
                else cout << "NO es un arbol binario completo" << endl;
                break;
            case 30:
                if (esPerfecto(raiz)) cout << "SI es un arbol binario perfecto" << endl;
                else cout << "NO es un arbol binario perfecto" << endl;
                break;
            case 31:
                if (esLleno(raiz)) cout << "SI es un arbol binario lleno (Full)" << endl;
                else cout << "NO es un arbol binario lleno (Full)" << endl;
                break;
            case 32:
                if (esBalanceado(raiz)) cout << "SI es un arbol balanceado" << endl;
                else cout << "NO es un arbol balanceado" << endl;
                break;
            case 33:
                if (esABB(raiz)) cout << "SI es un Arbol Binario de Busqueda (ABB)" << endl;
                else cout << "NO es un Arbol Binario de Busqueda (ABB)" << endl;
                break;
            case 34:
                if (esSimetrico(raiz)) cout << "SI es un arbol simetrico" << endl;
                else cout << "NO es un arbol simetrico" << endl;
                break;
            case 35:
                raizCopia = copiarArbol(raiz);
                cout << "Arbol copiado exitosamente" << endl;
                cout << "Copia mostrada (visual):" << endl;
                mostrarArbolVisual(raizCopia);
                break;
            case 36:
                cout << "Arbol original:" << endl;
                mostrarArbolVisual(raiz);
                espejoArbol(raiz);
                cout << "Arbol reflejado (espejo):" << endl;
                mostrarArbolVisual(raiz);
                break;
            case 37:
                cout << "Primer valor: ";
                cin >> valor;
                cout << "Segundo valor: ";
                cin >> valor2;
                {
                    Nodo* lca = encontrarLCA(raiz, valor, valor2);
                    if (lca != nullptr) cout << "Ancestro comun mas bajo: " << lca->dato << endl;
                    else cout << "No se encontro ancestro comun" << endl;
                }
                break;
            case 38:
                cout << "Primer valor: ";
                cin >> valor;
                cout << "Segundo valor: ";
                cin >> valor2;
                resultado = distanciaEntreNodos(raiz, valor, valor2);
                if (resultado != -2) cout << "Distancia entre " << valor << " y " << valor2 << ": " << resultado << endl;
                else cout << "Uno o ambos nodos no existen" << endl;
                break;
            case 39:
                crearArbolEjemplo(raiz);
                break;
            case 40:
                vaciarArbol(raiz);
                cout << "Arbol vaciado por completo" << endl;
                break;
            case 41:
                vaciarArbol(raiz);
                if (raizCopia != nullptr) vaciarArbol(raizCopia);
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while(opcion != 41);
    
    return 0;
}