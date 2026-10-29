#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    
    string linea;
    while (getline(cin, linea)) {
        cout << linea << "\n";
    }    
    return 0;
}

/*
Ejemplo:
   entra datos infinitamente

Ctrl + Z (window)
Ctrl + D (Linux)

   ***ojo***: aqui no controlo las lineas en blanco, todas cuentan

Leer línea completa (strings con espacios). Leer múltiples líneas(Lee hasta EOF)
Si el problema trabaja con texto completo o frases
- Importan􀆡simo cuando hay espacios y necesitas todo el texto de cada línea, 
     no lo necesitas separado sino junto
*/