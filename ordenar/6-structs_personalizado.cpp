#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Punto { 
  int x, y; 
 // Operador < definido dentro del struct
  bool operator<(const Punto &p) { 
     if (x != p.x) 
            return x < p.x;  // Primero ordena por x
      else 
           return y < p.y; // Si x es igual, ordena por y
  } 
};


int main() {
    vector<Punto> puntos = {{3, 4}, {1, 2}, {3, 1}, {1, 5}, {2, 3}};
    
    cout << "Antes de ordenar:" << endl;
    for (auto p : puntos) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;
    
    
    //**** Ahora SÍ funciona porque definimos operator<  
    sort(puntos.begin(), puntos.end());
    
    cout << "Después de ordenar:" << endl;
    for (auto p : puntos) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;
    
    return 0;
}


/*

Cuando creas un struct, C++ no sabe cómo ordenar sus elementos,
por ello es que usamos "Operador de comparación"

//este es para igualdad , también se puede usar  >, ==, <=, etc.
bool operator==(const P &p) const {
    return x == p.x && y == p.y;
}
    
    

*/