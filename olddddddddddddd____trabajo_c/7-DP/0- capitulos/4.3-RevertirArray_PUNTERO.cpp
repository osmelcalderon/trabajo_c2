#include <bits/stdc++.h>
using namespace std;
//aqui usa un puntero con una funcion bool

// Función booleana (retorna true o false)
bool isPalindrome(int i, string &s) {
    // Caso base: si llegamos a la mitad, es palíndromo
    if (i >= s.length() / 2) return true;
    
    // Si los caracteres no coinciden, no es palíndromo
    if (s[i] != s[s.length() - i - 1]) return false;
    
    // Si coinciden, revisar el siguiente par
    return isPalindrome(i + 1, s);
}

int main() {
    string s = "MADAM";
    // Se pasa i=0 y el string por referencia
    cout << isPalindrome(0, s) << endl; // Imprime 1 (true)
    
    return 0;
}