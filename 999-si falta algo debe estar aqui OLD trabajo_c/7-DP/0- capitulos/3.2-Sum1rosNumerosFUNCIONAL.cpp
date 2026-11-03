/*
B) Usando el Enfoque Funcional
•	La función recibe n y retorna el resultado. No hay parámetros extra.
•	La función retorna un valor en cada paso. Es como decir "No imprimas, devuélveme el valor".

*/
#include <bits/stdc++.h>
using namespace std;

// La función retorna un entero (el resultado de la suma)
int sumFunctional(int n) {
    // Caso base
    if (n == 0) {
        return 0; //no imprime aqui nada, solo retorna valor
    }
    
    // Retorna n + el resultado de la suma del número anterior
    return n + sumFunctional(n - 1);
}

int main() {
    int n = 3;
    // Imprimimos lo que la función nos retorna
    cout << sumFunctional(n) << endl; 
    return 0;
}
