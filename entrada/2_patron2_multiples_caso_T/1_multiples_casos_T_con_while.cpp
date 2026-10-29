#include <iostream>
using namespace std;

int main() {
    int N;
    long long a, b;
    
    cin >> N;
    
    while (N--) {
        cin >> a >> b;
        cout << (a+b) << endl;

    }
    
    return 0;
}





/*
Se usa cuando el enunciado dice algo como:
“La primera línea con􀆟ene un entero T (número de casos)”
“Se deben procesar T casos de prueba”

Es decir:
✔ Hay múl􀆟ples casos
✔ Sabes exactamente cuántos
*/