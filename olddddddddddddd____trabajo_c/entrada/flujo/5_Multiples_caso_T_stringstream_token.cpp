#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  //“Ignora todo lo que haya en el buffer de entrada hasta encontrar un salto de línea (\n)”

    while (T--) {
        // Leemos una línea completa
        string linea;
        getline(cin, linea);

        // Creamos el flujo con la línea
        stringstream flujo(linea);

        string nombre;
        long long edad;
        long long dinero;

        // Extraemos los datos en orden
        flujo >> nombre >> edad >> dinero;

        //ojo ----TAMBIEN SE PUEDE ESCRIBIR  los datos en orden
        //flujo << 10 << " " << 20;

        // Mostramos resultado
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Dinero: " << dinero << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}


/*
 "ejemplo de trabajar con piezas individuales":

  stringstream flujo(cadena);
        long long dinero;
        long long edad;
        string nombre;
        flujo >> nombre >> edad >> dinero;




📌 Sintaxis básica
#include <sstream>
🔹 Crear desde una cadena
            stringstream flujo(cadena);
🔹 Leer datos (como con cin)
            string palabra;
            while (flujo >> palabra) {
                // usar palabra
            }
🔹 Escribir dentro del flujo
            stringstream flujo;
            flujo << 10 << " " << 20;
🔹 Obtener el contenido como string
            string resultado = flujo.str();
*/