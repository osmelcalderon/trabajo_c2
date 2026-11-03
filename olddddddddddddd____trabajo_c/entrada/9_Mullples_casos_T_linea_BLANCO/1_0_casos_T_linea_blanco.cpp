#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (t--) {
        string line;

        // obligatorio para saltar líneas en blanco
        //es decir que si t=5, aunque escriba 1000 lineas en blanco, 
        //estoy obligado a escribir al menos 5 lineas con textos
        do {
            getline(cin, line); //entra de datos
        } while (line.empty());
 
        // procesamos la línea
        stringstream flujo(line);
        string palabra;

        while (flujo >> palabra) {
            cout << palabra << endl;
        }
    }

    return 0;
}



/*
🎯 Problema propuesto
    👉 Se te da un número T de casos.
    👉 Cada caso es una línea con palabras separadas por espacios.
    👉 Entre casos puede haber líneas en blanco (una o varias).

    Nivel concurso(Este tipo de entrada aparece cuando:)        
        hay separación visual entre casos
        hay inputs “sucios”
        el juez mete líneas en blanco


Múltiples casos, con líneas en blanco
Se ignorar líneas vacías
Línea en blanco como separador de casos
Datos:
10 20 30

40 50 60
70 80 90


*/



/*  Quizas NO sirva

tipos de separadores complejos:
    líneas vacías
    bloques
    separadores personalizados

//if (line.empty()) continue;
    
✅ Mejor práctica (más limpia)
while (t--) {
    string line;

    do {
        getline(cin, line);
    } while (line.empty());

    // aquí ya tienes línea válida
}




*/