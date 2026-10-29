#include <bits/stdc++.h>
using namespace std;

int main() {

    //4. Diferentes separadores según contexto

     //CSV
    string linea = "10,20,30"; //separadores por comas, CSV
    stringstream ss(linea);
    string campo;
    while (getline(ss, campo, ',')) {
        cout << campo << " ";
    }
    
    //TSV
    string linea2 = "10\t20\t30"; //separadores de tabulación TSV
    stringstream ss2(linea2);
    while (getline(ss2, campo, '\t')) {
        cout << campo << " ";
    }

    //Pipe
    string linea3 = "10|20|30"; // separadores Pipe
    stringstream ss3(linea3);
    while (getline(ss3, campo, '|')) {
        cout << campo << " ";
    }
    return 0;
}