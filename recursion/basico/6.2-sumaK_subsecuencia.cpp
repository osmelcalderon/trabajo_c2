#include <bits/stdc++.h>
using namespace std;
int k=3;
bool subsecuencia(vector<int>& nums, int indice, vector<int>& sd, int& suma) {

//truco del caso base, para imprimir solo 1 sola respuesta min 15.26

    // Caso base:
    if (indice == (int)nums.size()) {
          //si la condicion se cumple devuelvo un true 
        if (suma==k) {  
            for (int x : sd) {            //for (int i = 0; i < sd.size(); i++) {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
    
        //si la condicion no se cumple devuelvo false
        return false;
    }
        sd.push_back(nums[indice]); 
        suma+=nums[indice]; 
        if (subsecuencia(nums, indice+1, sd,suma)==true) { //elegir
             return true;
        }
        suma-=nums[indice]; 
        sd.pop_back(); //quitar
        if (subsecuencia(nums, indice+1, sd,suma)==true) { //elegir
            return true;
        }
        return false;
    
}


int main() {

    vector<int> nums = {3, 2, 1};
    vector<int> sd;
    int suma=0;
    subsecuencia(nums, 0, sd,suma);

    return 0;
}