#include <bits/stdc++.h>
using namespace std;

int main() {
    // Entrada simulada
    string entrada =
    R"(2
    3
    Juan
    Maria
    Carlos
    2
    Matema􀆟ca
    Fisica
    2
    Ana
    Luis
    1
    Historia)";
    // En programa real sería: cin >> ...
    // Aquí simulamos con stringstream
    #include <sstream>
    stringstream cin(entrada);
    int T; cin >> T;
    int caso = 1;
    while (T--) {
        cout << "Caso " << caso++ << ":\n";
        
        // Bloque 1: Estudiantes
        int N; cin >> N;
        vector<string> estudiantes(N);
        cout << " Estudiantes (" << N << "):\n";
        for (int i = 0; i < N; i++) {
            cin >> estudiantes[i];
            cout << " - " << estudiantes[i] << '\n';
        }
        
        // Bloque 2: Materias
        int M; cin >> M;
        vector<string> materias(M);
        cout << " Materias (" << M << "):\n";
        for (int i = 0; i < M; i++) {
            cin >> materias[i];
            cout << " - " << materias[i] << '\n';
        }
        cout << '\n';
    }
    return 0;
}

/*
🧠🧠 10) método de entrada por bloques o casos
¿Qué significa?
Es un formato de entrada donde cada caso de prueba está compuesto por bloques de datos de tamaño conocido, 􀆡picamente:
    1. Primero lees un número T = can􀆟dad de casos
    2. Para cada caso, lees:
        o N = tamaño del primer bloque
        o N líneas/datos del primer bloque
        o M = tamaño del segundo bloque
        o M líneas/datos del segundo bloque
Es como leer "paquetes" de datos donde primero te dicen cuántos vienen, luego los datos, luego otro paquete, etc. Muy común en problemas de programación compe􀆟􀆟va.
*/