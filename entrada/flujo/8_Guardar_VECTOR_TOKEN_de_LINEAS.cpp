#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (T--) {
        // Leemos una línea completa
        string linea;
        getline(cin, linea);

        
        vector<string> vector_palabras;

        // Separamos las palabras usando stringstream
        stringstream flujo(linea); 
        
        string palabra;

        while (flujo >> palabra) {  //recorro el flujo
            vector_palabras.push_back(palabra);  //guardo cada palabra en un vector
        }

        // Mostramos resultado
        cout << "Palabras separadas: ";
        for (string p : vector_palabras) {
            cout << "[" << p << "] ";
        }
        cout << endl;
    }

    return 0;
}

/*

2
osmel calderon bernal
Palabras separadas: [osmel] [calderon] [bernal]
fidel  genaro calderon martinez
Palabras separadas: [fidel] [genaro] [calderon] [martinez]



 stringstream: sirve para tratar una cadena (string) como si fuera un flujo de entrada/salida 
 (igual que cin o cout), lo que permite leer datos formateados desde texto 
 (por ejemplo, separar palabras, números o tokens de una línea) o 
 construir cadenas de forma cómoda; es especialmente útil cuando usas getline 
 y luego necesitas procesar esa línea paso a paso sin complicarte con parsing manual.



 "Un token": es una unidad mínima de información que se obtiene al dividir una cadena de texto 
 según ciertas reglas; por ejemplo, al procesar "hola mundo 123", cada palabra o número separado 
 por espacios ("hola", "mundo", "123") es un token. 
 En programación, los tokens sirven para analizar y entender el contenido de una entrada 
 (texto, código, datos), ya que permiten trabajar con piezas individuales en lugar 
 de con toda la cadena completa.


 "ejemplo de trabajar con piezas individuales":

  stringstream flujo(cadena);
        long long dinero;
        long long edad;
        string nombre;
        flujo >> nombre >> edad >> dinero;


*/