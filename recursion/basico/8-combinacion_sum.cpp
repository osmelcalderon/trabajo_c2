#include <bits/stdc++.h>
using namespace std;
//combinacion sum
//https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10

int combinacion_sum(vector<int>& nums, int objetivo, int indice) {
    
    // Caso base: se acabaron los elementos
    if (indice == (int)nums.size()) return 0;

    // Caso base: encontramos una combinación
    if (objetivo == 0) return 1;

    // Caso base: nos pasamos restando
    if (objetivo < 0) return 0;

     // recursión
        int suma=0;
     
        // Elegir nums[indice] (reusar → mismo indice)
        suma+=combinacion_sum(nums, objetivo-nums[indice],indice);  //elegir - izquierda

        // No elegir nums[indice] (avanzar → indice + 1)
        suma+=combinacion_sum(nums, objetivo,indice+1);  // no elegir - derecha
     
     return suma;
     
    
}


int main() {

    vector<int> nums = {2, 3, 6, 7};
    int objetivo=7;
    
    cout << combinacion_sum(nums, objetivo, 0) << "\n";  // 2

    for (int x : nums) cout << x << " ";
    cout << "\n";
   
    return 0;
}

/*
siempre que yo pueda utilizar un elemento 2 veces, pues lo invoco 2 veces, en este caso dentro de un for
*/