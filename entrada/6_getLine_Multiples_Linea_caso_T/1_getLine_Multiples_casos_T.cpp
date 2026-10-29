#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    
    string linea;
    int N;
    cin >> N;
    cin.ignore(); //antes de un getline es importante, para quitar el ultimo /n
    
    while(N--){
        getline(cin, linea);
            cout << linea << "\n";
    }
    return 0;
}

/*
Ejemplo:
   Entre 5 oraciones

   ***ojo***: aqui no controlo las lineas en blanco, todas cuentan

Leer línea completa (strings con espacios). Leer múltiples líneas(Lee hasta EOF)
Si el problema trabaja con texto completo o frases
- Importan􀆡simo cuando hay espacios y necesitas todo el texto de cada línea, 
     no lo necesitas separado sino junto
*/