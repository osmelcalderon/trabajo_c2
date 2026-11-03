#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //simple sin puntero, 
    //&variable:  toda variable tiene una direcion de memoria 
    int arreglo[]={1,2,3,4,5,6,7,8,9,10,11}; 
    int *puntero;
    
    /*como los arreglos se almacenan en posiciones contiguas de memoria
    puedo usar:

    primer elemento, guardo posicion de memoria 
        puntero = &arreglo[0]; 
            o
        puntero = arreglo;     

     Operadores de aritmética de punteros
        Sirven para mover el puntero en memoria
       •	p++     → avanza al siguiente elemento.
       •	p--       → retrocede al elemento anterior.
       •	p + n   → se mueve n posiciones adelante.
       •	 p - n    → se mueve n posiciones atrás.

       y para ver contenidos
        *puntero  -- elemento activo 
        *(puntero+1)  -- elemento contiguo
        puntero[2]  -- elemento como si fuera arreglo

    */
    puntero = &arreglo[0]; //primer elemento, guardo posicion de memoria 
                            
    cout <<"Primer elemento (CON PUNTERO): "<< *puntero << '\n';
    cout <<"Segundo elemento (CON PUNTERO): "<< *(puntero+1) << '\n';
    cout <<"tercer elemento (CON PUNTERO): "<< puntero[2] << '\n';
    
    //no solo muestra elementos contiguos, tambien mueve el puntero
    for (int i=0; i<5; i++) {
      cout <<"Elemento "<<i <<": "<<*(puntero++) << '\n';
    }; 


    cout <<'\n';
    for(int i = 0; i < 10; i++) {
        if(*puntero % 2 == 0) {
            cout << "El numero " << *puntero << " es par" << endl;
            cout << "Posicion: " << puntero << endl;
        }
        puntero++; //mueve el puntero
    }

    

    cout << '\n';

    return 0;
}