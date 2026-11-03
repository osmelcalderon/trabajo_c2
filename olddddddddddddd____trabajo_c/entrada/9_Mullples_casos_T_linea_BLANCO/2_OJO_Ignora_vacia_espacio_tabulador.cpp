#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (t--) {
        string line;

        // Ignora líneas vacías, con espacios o tabuladores
        do {
            getline(cin, line);
        } while (line.find_first_not_of(" \t") == string::npos);

        // procesamos la línea
        stringstream flujo(line);
        string palabra;

        while (flujo >> palabra) {
            cout << palabra << endl;
        }

        cout << "---" << endl;
    }

    return 0;
}

/*

string::npos:   
        Constante especial q significa "no se encontró nada". no encontró coincidencias.
usada con:
    find()
    find_first_not_of()
    find_first_of()
/////////

Si quieres ignorar también espacios o tabs:

while (line.find_first_not_of(' ') == string::npos)

O más robusto:

do {
    getline(cin, line);
} while (line.find_first_not_of(" \t") == string::npos);

👉 Esto ignora líneas con espacios o tabs.

////////////////
line.find_first_not_of(" \t") == string::npos
    Busca el primer carácter que NO sea espacio o tab
    Si no encuentra ninguno, toda la línea es basura (espacios/tab) → se repite


*/