#include <iostream>
using namespace std;

void obtenerVocales(char *cadena, char *vocales, int *contador) {
    char *p = cadena;
    char *v = vocales;
    *contador = 0;
    
    while(*p != '\0') {
        char c = tolower(*p); //convertir a minusula
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            *v = *p;
            v++;
            (*contador)++;
        }
        p++;
    }
    *v = '\0';
}

int main() {
    char texto[] = "parafraseando";
    char vocales[100];
    int numeroVocales;
    
    obtenerVocales(texto, vocales, &numeroVocales);
    
    cout << "Texto original: " << texto << endl;
    cout << "Vocales encontradas: " << vocales << endl;
    cout << "Numero de vocales: " << numeroVocales << endl;
    
    return 0;
}