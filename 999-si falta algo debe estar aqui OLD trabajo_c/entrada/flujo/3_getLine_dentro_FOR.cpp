#include <bits/stdc++.h>
using namespace std;

int main() {
    string linea = "10;20;30";
    
    stringstream flujo(linea);
    string numero;

    for (int i = 0; i < 3; i++) { // sabes que hay 3 números
        getline(flujo, numero, ';');
        cout << numero << '\n';
    }
}    