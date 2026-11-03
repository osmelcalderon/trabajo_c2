#include <bits/stdc++.h>
using namespace std;

void subsecuencia(vector<int>& nums, int indice, vector<int>& sd) {

    // Caso base:
    if (indice == (int)nums.size()) {
        for (int x : sd) {            //for (int i = 0; i < sd.size(); i++) {
            cout << x << " ";
        }
        if (sd.size()==0) { 
            cout << "{} ";
        }
    
        cout << endl;
        return;
    }
        sd.push_back(nums[indice]); 
        subsecuencia(nums, indice+1, sd); //elegir
        sd.pop_back(); //quitar
        subsecuencia(nums, indice+1, sd); //NO elegir
    
}

int main() {

    vector<int> nums = {3, 2, 1};
    vector<int> sd;
    subsecuencia(nums, 0, sd);

    return 0;
}