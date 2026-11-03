#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Leer primer arreglo
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    // Leer segundo arreglo
    int y[n];
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }
    

    //mostrar
    for(int i = 0; i < n; i++) {
        cout <<  ((i%2) ? (x[i]) : (y[i])) << "\n";
    }
    
    
    return 0;
}