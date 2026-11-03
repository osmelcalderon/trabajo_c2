#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> lineas;
    string linea;
    // Leer todo, y guardarlo todo en un vector
    while (getline(cin, linea)) {
        lineas.push_back(linea);
    }
    // Procesar ignorando comentarios y líneas vacías
    //proceso donde manualmente veo que trae línea por línea
    cout << "Líneas válidas:\n";
    for (const string& l : lineas) {
        if (!l.empty() && l[0] != '#') {
            cout << " " << l << '\n';
        }
    }
    return 0;
}

/*

13) Leer todo el input (casos raros)
Es leer TODO el archivo de entrada sin ninguna estructura predefinida, guardando cada línea en un vector para procesarlo manualmente después.
Algo así como: Trágate todo el archivo línea por línea, luego yo me encargo de entender qué hacer con esto
¿Cuándo se usa? (CASOS RAROS)
• Formato desconocido o variable
• Validación o preprocesamiento complejo
• Ignorar líneas inválidas o comentarios
• Reordenamiento necesario
*/