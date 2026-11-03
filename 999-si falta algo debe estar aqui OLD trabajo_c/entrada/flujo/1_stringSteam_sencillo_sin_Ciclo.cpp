#include <bits/stdc++.h>
using namespace std;

int main() {
    //Ejemplo 1
    string linea = "10 20 30"; // Cadena de texto normal
    stringstream ss(linea); // Convierte el string Linea en un "flujo"
    int x;
    ss >> x; // x = 10 (extrae primer número)
    ss >> x; // x = 20 (extrae segundo número)
    ss >> x; // x = 30 (extrae tercer número)

    cout <<"x se queda con el ultimo valor : "<< x <<"\n";

    //Ejemplo 2
    string texto = "42 100 3.14 Hola";
    stringstream flujo(texto);
    int a, b;
    float c;
    string d;
    flujo >> a >> b >> c >> d; // ¡Todo extraído ordenadamente!

    cout <<"a:"<<a << " b:"<< b <<" c:"<< c <<" d:"<< d <<"\n";
    
}