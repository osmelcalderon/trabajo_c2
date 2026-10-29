#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    
    bool operator<(const Persona &otra) const {
        return edad < otra.edad;  // Ordena por edad (menor a mayor)
    }
};
int main() {
    vector<Persona> personas = {
        {"Ana", 30},
        {"Luis", 25},
        {"Carlos", 35},
        {"Maria", 28}
    };
    
//este va a respetar lo que dice el operador
    sort(personas.begin(), personas.end());
    
    cout << "Personas ordenadas por edad:" << endl;
    for (auto p : personas) {
        cout << p.nombre << ": " << p.edad << " años" << endl;
    }
    
    return 0;
} 
