#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //simple sin puntero, 
    //&variable:  toda variable tiene una direcion de memoria 
    int numero=5; 
    cout <<"Valor de variable numero: "<< numero << '\n';
    cout <<"Dirección de variable numero: "<< &numero << '\n';
    cout << '\n';

    //Con punteros, haciendo referencia a la variable numero
    int *puntero;
    
    puntero =&numero; //guardo posicion de memoria
                       //son las variables punteros unicas q pueden guardar direccion de memoria
                      // y ademas se quedan apuntando a la variable

    cout <<"Valor de variable numero(CON PUNTERO): "<< *puntero << '\n';
    cout <<"Dirección de variable numero(CON PUNTERO): "<< puntero << '\n';

    cout << '\n';

    return 0;
}