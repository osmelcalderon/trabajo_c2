#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string parrafo = 
R"(ABC

DEF

GHI

XO
OX
XO

123
456
789)";
    
    stringstream flujo(parrafo);
    char tablero[3][3];
    string linea;
    
    while (true) {
        // Leer las 3 filas del tablero, ignorando líneas en blanco
        for (int i = 0; i < 3; i++) {
            do {
                if (!getline(flujo, linea)) 
                    return 0;  // Fin de archivo
            } while (linea.empty());  // Ignorar líneas en blanco
            
            for (int j = 0; j < 3; j++) {
                tablero[i][j] = linea[j];
            }
        }
        
        // Mostrar tablero
        cout << "\nTablero:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << tablero[i][j] << ' ';
            }
            cout << '\n';
        }
        
    }
    
    return 0;
}

/*

Procesa bloques fijos (3x3), ignorando líneas vacias Funciona para:
• Tic-Tac-Toe (3x3 fijo)
• Cualquier matriz 3x3
*/