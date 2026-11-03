#include <bits/stdc++.h>
#include <cstring>
using namespace std;

struct Persona {
    int edad;
    char nombre[50];  // <-- Esto es un ARREGLO fijo de caracteres
                //Los arreglos NO soportan asignación directa
    bool sexo;
};

int main() {
    // Declarar una variable y un puntero
    Persona persona1;

    //variable puntero a STRUC
    Persona *puntero; 
    // El puntero apunta a la estructura
    puntero = &persona1; 
    
    // Acceder a los campos usando el puntero (->)

// Asignar nombre usando el puntero
    
    //Los arreglos NO soportan asignación directa
    strcpy(puntero->nombre, "Carlos"); //❌ ERROR: puntero->nombre = "Carlos";  
    puntero->edad = 30;

    persona1.sexo=true; //sin usar puntero
    
    cout << "Nombre: " << puntero->nombre << endl;
    cout << "Edad: " << puntero->edad << endl;
    cout << "Sexo: " << puntero->sexo << endl;
    
    return 0;
}