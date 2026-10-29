#include <iostream>
using namespace std;

//es el principio de la busqueda binaria con saltos

// FUNCIÓN ok
bool ok(int valor, int x) {
    cout << "   ok(" << valor << "," << x << ") = ";
    if (valor <= x) {
        cout << "true\n";
        return true;
    }
    else {
        cout << "false\n";
        return false;
    }
}

// FUNCIÓN DE BÚSQUEDA POR SALTOS
int busquedaPorSaltos(int array[], int n, int x) {
    int k = -1;
    for (int b = n/2; b >= 1; b /= 2) {
        cout << "\nSALTO b = " << b << '\n';
        while (k + b < n && ok(array[k + b], x)) {
            
            cout << "   SALTA a indice "
                 << k+b
                 << " valor = "
                 << array[k+b]
                 << '\n';
                 
            k += b;
        }
    }

    if (k != -1 && array[k] == x) {
        return k;
    }

    return -1;
}

int main() {
    int array[] = {2,3,4,5,8,12,16,23,38,45};
    int n = 10;
    int x = 16;
    int resultado = busquedaPorSaltos(array, n, x);
    if (resultado != -1) {
        cout << "\nENCONTRADO\n";
        cout << "indice = "
             << resultado
             << " valor = "
             << array[resultado]
             << '\n';
    }
    else {
       cout << "\nNO ENCONTRADO\n";
    }
}