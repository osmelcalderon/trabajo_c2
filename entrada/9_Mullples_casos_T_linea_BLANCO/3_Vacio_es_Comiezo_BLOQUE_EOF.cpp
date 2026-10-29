#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string linea;
    int caso = 1;
    while (getline(cin, linea)) {
        if (linea.empty()) {
            cout << "Fin del caso " << caso++ << endl;
            continue;
        }
        // Procesar la línea no vacía
        cout << "Línea: " << linea << endl;
    }

    return 0;
}

/*
No se ignorar líneas vacías, se usa para marcar que terminó un bloque/caso. Aquí vacío TIENE significado
Datos:
dato1 dato2
dato3 dato4
dato5 dato6
dato7 dato8
*/