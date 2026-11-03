#include <bits/stdc++.h>
using namespace std;
int k=3; 
int subsecuencia(vector<int>& nums, int indice, vector<int>& sd, int& suma) {

//En recursión de conteo: devuelve el conteo desde cada llamada, 
//suma los hijos en una variable LOCAL y no uses globales
  
    // Caso base:
    if (indice == (int)nums.size()) {
          //si la condicion se cumple devuelvo un 1
        if (suma==k) return 1;
         //si la condicion no se cumple devuelvo 0
        return 0;
    }
        sd.push_back(nums[indice]); 
        suma+=nums[indice]; 
        int elegir=subsecuencia(nums, indice+1, sd,suma);
        
        suma-=nums[indice]; 
        sd.pop_back(); //quitar
        int NoElegir= subsecuencia(nums, indice+1, sd,suma);
        return elegir+NoElegir; //para lograr la cantidad las variables tienen q ser locales, cada vez q termine una pila hace calculo
    
}


int main() {

    vector<int> nums = {3, 2, 1};
    vector<int> sd;
    int suma=0;
    cout <<" cantidad " << subsecuencia(nums, 0, sd,suma) << endl;

    return 0;
}