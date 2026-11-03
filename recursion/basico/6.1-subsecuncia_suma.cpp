#include <bits/stdc++.h>
using namespace std;

void subsecuencia(vector<int>& nums, int indice, int& suma) {

    // Caso base:
    if (indice == (int)nums.size()) {
        cout << suma << " ";
        cout << endl;
        return;
    }
        suma+=(int)nums[indice]; 
        subsecuencia(nums, indice+1, suma); //elegir
        suma-=(int)nums[indice]; 
        //suma.pop_back(); //quitar
        subsecuencia(nums, indice+1, suma); //NO elegir
    
}

int main() {

    vector<int> nums = {3, 2, 1};
    int suma=0;
    subsecuencia(nums, 0, suma);

    return 0;
}