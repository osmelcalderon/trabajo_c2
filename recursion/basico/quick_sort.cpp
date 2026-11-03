#include <bits/stdc++.h>
using namespace std;
//Donde mejor explican el merge sort
//https://www.youtube.com/watch?v=ogjf7ORKfd8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8


void quick_sort(vector<int>& nums, int baja_inicial,int alta_inicial ) {
    // Caso base:
    if (baja_inicial >= alta_inicial) return; //cuando sobrepasa el inicio del final

    int baja = baja_inicial;
    int alta = alta_inicial;
    int pivot=nums[baja_inicial];


    while (baja<alta) { 
        while (baja <= alta_inicial - 1 && nums[baja]<=pivot ) {  // Limite de desbordamiento baja <= alta - 1, los iguales al pivote terminan a la izquierda
            baja++;
        }
        
        while (alta >= baja_inicial + 1 && nums[alta]>pivot) {  
            alta--;
        }
        
        if (baja<alta) { //comparo indice, si bajo sigue siendo menor q alta
            //intercambiar
            cout << nums[baja]  << "-" << nums[alta] << "\n";
            swap(nums[baja],nums[alta]);
            cout << nums[baja]  << "-" << nums[alta] << "\n";
        }
    }

    //y una vez que termine de intercambiar todos, ubico al pivote
    swap(nums[baja_inicial], nums[alta]);   // pivote a su lugar
    
     // recursión
     quick_sort(nums, baja_inicial, alta - 1);  // izquierda (excluye pivote)
     quick_sort(nums, alta + 1, alta_inicial);  // derecha   (excluye pivote)
    
}


int main() {

    vector<int> nums = {4, 6, 2, 5, 7, 9, 1, 3};
    for (int x : nums) cout << x << " ";
    cout << "\n";

    int baja=0;
    int alta=nums.size()-1;
    
    quick_sort(nums, baja, alta);

    for (int x : nums) cout << x << " ";
    cout << "\n";
   
    return 0;
}

/*

Primero tener en cuenta que los menores van a la izquierda y que los mayores van a la derecha,
por tanto, Una vez que elija cual va a ser el pivote, voy a buscar:

- De izquierda a derecha, encontrar el primer elemento mas grande que el pivote,
   porque si es menor significa que esta bien ubicado
   * nums[baja] <= pivot, baja avanza sobre menores e iguales, y se detiene en el primero estrictamente mayor. 

- De derecha a izquierda, encontrar el primer elemento mas pequeño que el pivote,
   porque si es mayor significa que esta bien ubicado
   * nums[alta] > pivot, alta retrocede sobre estrictamente mayores, y se detiene en el primero menor o igual. 



Ahora nada de usar matrices, voy a usar bajo y alto, y mi elemento más bajo es 0 y mas alto es n   
*/