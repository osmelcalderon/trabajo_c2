#include <bits/stdc++.h>
using namespace std;

int main() {
    string linea;
    vector<vector<int>> bloques; // Guarda TODOS los bloques/casos
    vector<int> bloque_actual; // Guarda el bloque/caso actual
    while (getline(cin, linea)) { // Leer líneas hasta EOF
        
        if (linea.empty()) { // Detecta líneas vacías(indica fin de bloque)
            if (!bloque_actual.empty()) { //reviso si variable bloque 􀆟ene datos(para indicar fin de caso)
                bloques.push_back(bloque_actual); // Guarda el bloque completo
                bloque_actual.clear();// Limpia para comenzar un nuevo bloque
            }
        }
        else {
            stringstream ss(linea); // Convierte la línea en flujo
            int x;
            while (ss >> x) { //separa cada token
                 bloque_actual.push_back(x); // Guarda los datos en el bloque actual
            }
        }
    }
    // (por si el archivo no termina con línea vacía). Guarda el úl􀆟mo bloque
    if (!bloque_actual.empty()) {
         bloques.push_back(bloque_actual);
    }
    // Impresión de los bloques guardados
    for (int i = 0; i < bloques.size(); i++) {
        cout << "Bloque " << i + 1 << ": ";
        for (int x : bloques[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}

/*
3. Patrón completo para leer bloques separados por línea en blanco
• detecta líneas vacías
• separa casos
• guarda TODOS los datos
• crea bloques de datos
datos
1 2 3 
4 5 

10 20 

7 8 9
*/