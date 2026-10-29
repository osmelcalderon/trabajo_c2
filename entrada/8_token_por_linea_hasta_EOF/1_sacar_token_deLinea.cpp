#include <bits/stdc++.h>
using namespace std;

int main() {

    string linea; 
       while (getline(cin, linea)) { 
           stringstream flujo(linea); 
           string palabra; 
           while (flujo >> palabra) { 
               // procesar datos } 
                cout << palabra << "\n";
           }
      }        

}    

/*
ctrl+Z para terminar

Leer hasta fin de línea (tokens variables)
"Leer hasta fin de línea" significa que lees una línea entera del teclado (o archivo) como un solo string, y luego dentro de esa línea vas extrayendo los números uno por uno.
¿Cuándo se usa?
• Cuando no sabes cuántos números vienen por línea
• Cuando las líneas 􀆟enen can􀆟dad variable de tokens
• Para problemas donde los datos están separados por espacios, pero en líneas de longitud variable

*/