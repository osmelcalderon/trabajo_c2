#include <bits/stdc++.h>
using namespace std;
//Donde mejor explican el merge sort
//https://www.youtube.com/watch?v=ogjf7ORKfd8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8

void fusionar(vector<int>&nums, int baja, int mitad, int alta){
  //en vez de usar muchas matrices lo que uso es apuntadores y una matriz temporal
  vector<int> temp;
   temp.reserve(alta - baja + 1); //para q solo me reserve el tamaño del array original

  int inicio=baja;  //aqui inicio se guarda y no se cambia nunca mas, porq recordar no es recursivida
               //  Lo que cambia es baja, porque se usa como puntero que avanza en los while.

  int bajaDer=mitad+1;
  while ( (baja<=mitad) && (bajaDer<=alta) )  { //mientras haya dados tanto en izquierda y derecha
        if (nums[baja]<=nums[bajaDer] ) {
             temp.push_back(nums[baja]);
             baja++; //y corro puntero parte baja
        } else {        //} if (nums[bajaDer]<=nums[alta] ) {
            temp.push_back(nums[bajaDer]);
            bajaDer++; //y corro puntero parte baja
       } 
  }

  while  (baja<=mitad)   { //copiar todos los elementos de izq, porq en der no queda nada
    temp.push_back(nums[baja]);
    baja++; //y corro puntero parte baja
  } 
  while  (bajaDer<=alta)   { //copiar todos los elementos de der, porq en izq no queda nada
    temp.push_back(nums[bajaDer]);
    bajaDer++; //y corro puntero parte baja
  } 

  
  /*

  - fusionar se llama con segmentos que no empiezan en 0.
     temp: siempre empieza en 0 (es un vector auxiliar limpio). Que se usa aqui en esta funcion
     nums: no siempre empieza en 0 (el segmento que estamos analizando puede estar en medio del array).

    Por eso se necesita, inicio como offset "posición dentro de temp" → "posición dentro de nums".
    Por eso inicio es indispensable: es el puente entre el índice local de temp y el índice global de nums.

    Ejemplo: si estamos analizando por ejemplo en nums desde la posicion 8-14   inicio va a ser 8, pero temp va a ser 0, 
    porque en temp es un array auxiliar para analizar pedazos
    Ejemplo:
    nums usa índices globales (8, 9, ..., 14).
    temp usa índices locales (0, 1, ..., 6).
    inicio es el offset que traduce de uno al otro.
  */
  for (int i = 0; i < (int)temp.size(); i++)  { //baja
      nums[inicio+i]=temp[i];
  }
  
  

}


void merge_sort(vector<int>& nums, int baja,int alta ) {
    // Caso base:
    if (baja >= alta) {
        return;  //regresa porq ya llegastes a un array de tamaño 1
    }

    int mitad = baja + (alta - baja) / 2; //para evitar desbordamiento
    merge_sort(nums, baja, mitad);
    merge_sort(nums, mitad+1, alta);
    fusionar(nums, baja, mitad, alta);

    
}


int main() {

    vector<int> nums = {8,4,3,4, 2, 2, 12, 1};
    int baja=0;
    int alta=nums.size()-1;
    
    merge_sort(nums, baja, alta);

    for (int x : nums) cout << x << " ";
    cout << "\n";
    return 0;

    //cout <<" cantidad " << merge_sort(nums, baja, alta) << endl;

    return 0;
}