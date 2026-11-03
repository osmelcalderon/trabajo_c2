#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool descendente(int a, int b) {
    return a > b;  // Mayor va primero
}

int main() {
    vector<int> numeros = {5, 2, 8, 1, 9, 3};
    
    //el ultimo argumento es la funcion para q compare
    sort(numeros.begin(), numeros.end(), descendente);
    
    cout << "Orden descendente: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;
    
    return 0;
}
