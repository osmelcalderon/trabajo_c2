#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string entrada = 
R"(########
#S.....#
#.###.#
#.#...#
#.#.#.#
#...#E#
########

#######
#S....#
#.###.#
#...#E#
#######)";
    
    stringstream flujo(entrada);
    vector<string> mapa;
    string linea;
    int mapaNum = 1;
    
    while (true) {
        // Ignorar líneas en blanco
        do {
            if (!getline(flujo, linea)) 
                return 0;
        } while (linea.empty());
        
        // Leer mapa completo
        mapa.clear();
        while (!linea.empty()) {
            mapa.push_back(linea);
            if (!getline(flujo, linea)) break;
        }
        
        // Mostrar mapa
        cout << "\nMapa " << mapaNum++ << " (" << mapa.size() << "x" << mapa[0].size() << "):\n";
        for (const string& fila : mapa) {
            cout << fila << '\n';
        }
    }
    
    return 0;
}