#include <bits/stdc++.h>
using namespace std;

int main() {
        //pares
        vector<pair<int,int>> v; 
        v.push_back({1,5}); 
        v.push_back({2,3}); 
        v.push_back({1,2}); 
        sort(v.begin(), v.end()); 
        //Después de esto, el orden de los pares es (1, 2), (1, 5) y (2, 3).
        cout << "Ordenar pares:\n";
        for(auto p : v) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << "\n";


        //tuplas
        vector<tuple<int,int,int>> t; 
        t.push_back({2,1,4}); 
        t.push_back({1,5,3}); 
        t.push_back({2,1,3}); 
        sort(t.begin(), t.end()); 
        //Después de esto, el orden de las tuplas es (1, 5, 3), (2, 1, 3) y (2, 1, 4).

        cout << "Ordenar tuplas:\n";
        for(const auto &x : t) {
            cout << "("
                << get<0>(x) << ", "
                << get<1>(x) << ", "
                << get<2>(x) << ") ";
        }


}

/*
Los pares (pair):
   se ordenan principalmente según su primer elemento (first).
   Sin embargo, si los primeros elementos de dos pares son iguales, 
   se ordenan según su segundo elemento (second): 

Las tuplas (tuple):
  se ordenan principalmente por el primer elemento, 
  secundariamente por el segundo elemento, etc.:    
*/
