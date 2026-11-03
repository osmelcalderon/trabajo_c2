#include <bits/stdc++.h>
using namespace std;

int main() {
   
   
    string linea = "10;20;30";

    stringstream flujo(linea);   //convertir un texto en flujo
    string n1, n2, n3;
    
    // Extraer uno por uno manualmente
    getline(flujo, n1, ';');
    getline(flujo, n2, ';');
    getline(flujo, n3, ';');
    cout << n1 << '\n';
    cout << n2 << '\n';
    cout << n3 << '\n';
}