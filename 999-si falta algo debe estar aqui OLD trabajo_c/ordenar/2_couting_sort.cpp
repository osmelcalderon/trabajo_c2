#include <bits/stdc++.h>
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
*/
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arreglo = {1, 3, 6, 9, 9, 3, 5, 9};

    int minimo = *min_element(arreglo.begin(), arreglo.end()); //1
    int maximo = *max_element(arreglo.begin(), arreglo.end()); //9

    int rango = maximo - minimo + 1;

    /*
    vector<int> frecuencia(rango,   0);
            ^        ^         ^    ^
            |        |         |    |
           tipo   nombre    tamaño  valor inicial
    */
    
    vector<int> frecuencia(rango, 0);


/*
   for(int i = 0; i < frecuencia.size(); i++) {
        cout << "frecuencia[" << i << "] = " << frecuencia[i] << endl;
    }
*/
    // Contar ocurrencias {1, 3, 6, 9, 9, 3, 5, 9};
    for (int x : arreglo) {
        frecuencia[x - minimo]++;  //1-1=0, 3-1=2, 5-1=4, 6-1=5, 9-1=8
                                   //cada frecuencia se incrementa como
                                  

/*
Contar ocurrencias {1, 3, 6, 9, 9, 3, 5, 9};
Los índices 1, 3, 6, 7 quedan en 0 porque los valores 2, 4, 7, 8 no aparecen en el arreglo.
frecuencia[1] = 0
frecuencia[3] = 0
frecuencia[6] = 0
frecuencia[7] = 0

1 se mapea a índice 0 (1 vez)    frecuencia[0] = 1
3 se mapea a índice 2 (2 veces)  frecuencia[2] = 2
5 se mapea a índice 4 (1 vez)    frecuencia[4] = 1
6 se mapea a índice 5 (1 vez)    frecuencia[5] = 1
9 se mapea a índice 8 (3 veces)  frecuencia[8] = 3

Índice:    0    1    2    3    4    5    6    7    8
Valor:     1    2    3    4    5    6    7    8    9
frecuencia:[1]  [0]  [2]  [0]  [1]  [1]  [0]  [0]  [3]
            ↑    ↑    ↑    ↑    ↑    ↑    ↑    ↑    ↑
            1    0    2    0    1    1    0    0    3
*/                                   

    }

    // Reconstruir arreglo ordenado
    vector<int> ordenado;

    for (int i = 0; i < rango; i++) {
        while (frecuencia[i] > 0) {
            ordenado.push_back(i + minimo);
            frecuencia[i]--;
        }
    }

    // Mostrar resultado
    for (int x : ordenado) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}