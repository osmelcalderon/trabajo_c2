#include <bits/stdc++.h>
using namespace std;

int main() {

    //cin
    //Can􀆟dad desconocida de datos
    // No sabes cuántos nombres vendrán, solo que terminan con "END"
    string nombre;
    while (cin >> nombre && nombre != "END") {
        cout << "Registrando: " << nombre << '\n';
    }

    cout << "otro: "  << '\n';
    
    //getline
    //Procesar líneas hasta "END"
    string linea;
    while (getline(cin, linea) && linea != "FIN") {
        cout << "Línea: " << linea << '\n';
    }

    return 0; 

}

/*
Centinelas comunes "END", "FIN", "0", "-1", "***"

// 1. Centinela diferente
        while (cin >> s && s != "FIN")
        while (cin >> s && s != "***")
        while (cin >> s && s != "0") // 0 como centinela
// 2. Centinela case-insensitive
    while (cin >> s && s != "END" && s != "end")
// 3. Múltiples centinelas
    while (cin >> s && s != "END" && s != "EXIT" && s != "QUIT")
// 4. Para líneas completas
    while (getline(cin, linea) && linea != "END")
*/