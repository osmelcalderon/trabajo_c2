#include <bits/stdc++.h>
using namespace std;
/*
 uso de sort 


   // Ordenar ascendentemente
    sort(arr, arr + n); // ordena desde arr[0] hasta arr[n-1].

  // Ordenar descendentemente (sin usar comparador comparador) 
   sort(arr.rbegin(), arr.rend()); 
     
 // Ordenar descendentemente (usando comparador)
     sort(arr, arr + n, greater<int>());
 

*/
int main() {
    
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]); // calcular automáticamente el número de elementos que tiene un arreglo

    // Ordenar ascendentemente
    sort(arr, arr + n); // ordena desde arr[0] hasta arr[n-1].

    cout << "Ascendente: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    // Ordenar descendentemente (usando comparador)
    sort(arr, arr + n, greater<int>());

    cout << "Descendente: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";



    vector<int> v = {4,2,5,3,5,8,3}; 
    // Ordenar descendentemente con vectores (sin usar comparador comparador) 
    sort(v.rbegin(), v.rend()); 
     
    cout << "Ordenar Descendente usando vectores: ";
    for (int x : v) cout << x << " ";
    cout << "\n";


    //Ordenar Cadena 
    string s = "monkey"; 
    sort(s.begin(), s.end());  // ekmnoy.
    
    cout << "Ordenar Descendente uso cadena : ";
    for (int x : s) cout << x  << " -> " << (char)x   << " ";
    cout << "\n";

    return 0;
}
