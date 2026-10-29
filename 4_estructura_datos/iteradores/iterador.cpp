#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> s = {8,2,5,1};

    // primer elemento
    auto it = s.begin();

    cout << "Primer elemento: " << *it << "\n";

    // recorrer
    cout << "Elementos:\n";

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    cout << "\n";

    // ultimo elemento
    auto ultimo = s.end();
    ultimo--;

    cout << "Ultimo: " << *ultimo << "\n";

    // buscar
    auto buscar = s.find(5);

    if (buscar != s.end()) {
        cout << "Encontrado: " << *buscar << "\n";
    }

    return 0;
}

/*
Salida:
Primer elemento: 1
Elementos:
1 2 5 8
Ultimo: 8
Encontrado: 5
*/