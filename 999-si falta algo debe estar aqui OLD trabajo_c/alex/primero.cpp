#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int main() { 
    /*
    bitset<8> a;                    //bitset<8> a("11111111");   //b.set(); // Todos en 1
    unsigned char x = 255;

    a.set(11110111); // Todos en 1
    

    auto c = a & 255;
    return 0;
    */
    
    /*
    bitset<8> c;
    bitset<8> a("11110111");
    bitset<8> b(255);

    c = a & b;

    cout << c << endl;
    */
    
    
    ///////////////////////////////////
    /*
    int a =42;
    int b=255;
    auto c = a & b;
    cout << bitset<8>(a) << endl;
    cout << bitset<8>(b) << endl;
    cout << bitset<8>(c) << endl;
    */
    
     
    /*
    00001010
    11111111
    */
    //int mascara  =  255;
     //bitset<8> valor("00000010");
    
       ///////////////////1- pregunta si el bit i está encendido./////////////////////////
        int valor = 4;  //00000100
        int posicion =  2;
        if (valor & (1<<posicion))  {
             cout << " -------si" << endl;
        }
    
    
        /////////////////////2- Comprobar si un bit en la posición n está activo o inactivo (Checking if Bit at nth Position is Set or Unset)
         int valor = 11;  //00001101
         int posicion =  2;
         cout << ((valor & (1 << posicion)) != 0);         

         /////////////////////2.1- Comprobar si el bit 1,3 y 5 estan encendido
         int valor = 106;     //0010  1000
         int mascara =  42;  //0010  1010
                            //-------------
                            // 0010  1000 
         cout << ((valor & (mascara)) == 42);        


        ///////3- Comprobar si un número es potencia de dos (Check Whether n is a Power of Two)

         int valor = 8;     //0000  1000
                              //0000  0111
                              //---------------  
                              //0000  0000

         cout << ((valor & (valor - 1)) == 0)
       
       return 0;



     //////////////////////lograr complementos a1 y a2
    int valor = 8;
    cout << "Valor:           " << bitset<8>(valor) << " = " << valor << endl;

    // Complemento a 1 (NOT)
    int comp1 = ~valor;
    cout << "Complemento a1:  " << bitset<8>(comp1) << " = " << comp1 << endl;

    // Complemento a 2   ...... Primero logra complemento a1 con "~valor" y luego hace una suma aritmetica a 1
    int comp2 = ~valor + 1;
    cout << "Complemento a2:  " << bitset<8>(comp2) << " = " << comp2 << endl;

    // XOR con 5
    int xorResult = valor ^ 5;
    cout << "8 ^ 5:           " << bitset<8>(xorResult) << " = " << xorResult << endl;

   
////////////////////////Invertir un bit de un número (Flip a Bit of Number)
         int valor = 42;     //0010  1010
         int posicion =6  ;  //0000  1000
                            //-------------
                            // 0010  1000 
         cout << ((valor ^ (1<<posicion)) );   

//////////////////////// Desactivar un bit del número:
     /*estas son 2 posibilidades
      0000 1000
     0000 0000

    
      Lo que ocurrio con: ~(1<<posicion)
       0000 0001 paso 1
       0000 1000 paso 2
       1111 0111 paso 3
     */

    //0001 1100
    
     
         int valor = 28;     
         int posicion =3;  
         cout << ((valor & ~(1<<posicion)) ); 
         return 0;

//////////////////////// Desactivar un conjunto de bit 1,3 y 5:
          
   // 2 + 8 +32

          int valor = 63;     //0011  1111 
          int mascara =   pow(2,1) + pow(2,3) + pow(2,5); //42;  //0010  1010

          cout << ((valor & ~(mascara)) );  //1101  0101
          return 0;   


///////////////////desplazamientos
 

          //<<  equivale a "multiplicar por potencias de 2"
          int valor = 8;      
          cout << (valor<<3 ) <<"\n";  //8 * 2^3
          
          //>>  equivale a "Dividir por potencias de 2"
          int resultado = 64;    
          cout << (resultado>>3 );  //64 / 2^3

          return 0;   


////////////////////Establezca un bit de número
         //int valor = 42;     //0010  1010
         int valor = 34;     //0010  0010
         int posicion =3;  
         cout << ((valor | (1<<posicion)) ); 
         return 0;

}


676- Sistema numerico
917 Bitwise