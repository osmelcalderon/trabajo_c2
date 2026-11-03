#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string entrada = 
R"(3 3
ABC
DEF
GHI

4 4
ABCD
EFGH
IJKL
MNOP

9 9
530070000
600195000
098000060
800006003
400803001
700020006
060000280
000419005
000080079)";
    
    stringstream flujo(entrada);
    int filas, columnas;
    string linea;
    
    while (flujo >> filas >> columnas) {   //1ra linea de cada bloque: 3 3
        
        // Leer el salto de línea después de filas y columnas
        getline(flujo, linea);
        
        //Cada iteración del ciclo es un ámbito NUEVO
        //Ámbito (scope) y tiempo de vida
        //Cada vez que entras al ciclo, se crea una variable NUEVA y la anterior deja de existir.
        //Es un vector de vectores = MATRIZ DINAMICA
        vector<vector<char>> matriz(filas, vector<char>(columnas));
        
        // Leer la matriz
        for (int i = 0; i < filas; i++) {
            do {
                if (!getline(flujo, linea)) 
                    return 0;
            } while (linea.empty());
            
            for (int j = 0; j < columnas && j < linea.length(); j++) {
                matriz[i][j] = linea[j];
            }
        }
        
        // Mostrar
        cout << "\nMatriz " << filas << "x" << columnas << ":\n";
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << matriz[i][j];
                if (j < columnas-1) cout << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}

/*
Procesa bloques fijos (MxN), ignorando líneas vacias 
✔ ú􀆟l para Tic Tac Toe, Sudoku, mapas, laberintos (dimensiones variables)
*/