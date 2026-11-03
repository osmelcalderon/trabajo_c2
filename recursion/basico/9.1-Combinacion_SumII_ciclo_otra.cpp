#include <bits/stdc++.h>
using namespace std;
//combinacion sum
//https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11

int combinacion_sum(vector<int>& nums, int objetivo, int indice, vector<int>& camino_actual, vector<vector<int>>& todos_losCaminos) {
    


    // Caso base: encontramos una combinación
    if (objetivo == 0) {
         todos_losCaminos.push_back(camino_actual);
         return 1;
    }

    // Caso base: nos pasamos restando
    if (objetivo < 0) return 0;

    // Caso base: se acabaron los elementos
    //este lo puedo eliminar, porq ya esta implicito en el for
    //if (indice == (int)nums.size()) return 0;
    
    // recursión
        int suma=0;
     
        for (int i = indice; i < (int)nums.size(); i++) {
            
                //esto funciona si el array esta ordenado
                // ✅ saltar duplicados en el mismo nivel(cada ciclo for),
                // el continue obliga a que solo tomes la primera aparición de cada número distinto. 
                //Si el número se repite, las siguientes apariciones en ese mismo nivel las saltas.
                //"En cada nivel del árbol (en cada ciclo for), solo exploras el primer 1, el primer 2, el primer 3, etc. 
                //Las copias repetidas de ese mismo número en ese mismo nivel, las saltas."
                //Si no soy el primero de este nivel, y soy igual al anterior, entonces soy una copia inútil, me salto
                if (i > indice && nums[i] == nums[i-1]) continue;
                // ✅ poda: si el valor excede el objetivo, los siguientes también (ordenado)
                if (nums[i] > objetivo) break;

            camino_actual.push_back(nums[i]); 
            // Elegir nums[indice] (reusar → mismo indice)
            suma+=combinacion_sum(nums, objetivo-nums[i],i+1,camino_actual,todos_losCaminos);  //elegir - izquierda
            camino_actual.pop_back(); //backtraking

        }
     return suma;
    
}


int main() {

    vector<int> nums = {1, 2, 1, 2, 2};
    int objetivo=6;
    vector<int> camino;
    vector<vector<int>> resultados;
    //cout << combinacion_sum(nums, objetivo, 0,{},{}) << "\n";  // 2
    //ordenar el array
    sort(nums.begin(), nums.end());
    cout << combinacion_sum(nums, objetivo, 0,camino,resultados) << "\n";  // 2

    for (const auto& comb : resultados) {      // comb es vector<int>
        cout << "[";
        for (int i = 0; i < (int)comb.size(); i++) {
            cout << comb[i];
            if (i + 1 < (int)comb.size()) cout << ",";
        }
        cout << "]\n";
    }
    cout << "\n";
   
    return 0;
}

/*
siempre que yo pueda utilizar un elemento 2 veces, pues lo invoco 2 veces, en este caso dentro de un for
*/