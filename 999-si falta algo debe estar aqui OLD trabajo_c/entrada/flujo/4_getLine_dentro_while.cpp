#include <bits/stdc++.h>
using namespace std;

int main() {

    string linea = "10;20;30"; // Una botella con agua e􀆟quetada "10;20;30"
    stringstream flujo(linea); // Abres la botella, el agua está lista para fluir
    string numero;
    while (getline(flujo, numero, ';')) { // Vas sirviendo en vasos hasta ';'
       cout << numero << '\n'; // Te tomas cada vaso: "10", luego "20", luego "30"
    }
}    