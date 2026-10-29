#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int *puntero;
    int numero =3;
    
    
    puntero= new int[numero]; //NEW- arreglo dinamico con 
    
    puntero[0] =10;
    puntero[1] =20;
    puntero[2] =30;


    //no solo muestra elementos contiguos, tambien mueve el puntero
    for (int i=0; i<numero; i++) {
      cout <<"Elemento "<<i <<": "<<*(puntero++) << '\n';
    }; 

    //delete[] puntero;


    

    cout << '\n';

    return 0;
}