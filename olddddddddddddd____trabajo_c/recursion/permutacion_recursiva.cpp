#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int>& nums, vector<bool>& states, int take) {

    // Caso base:
    // Ya tomamos todos los elementos
    if (take == nums.size()) {
        cout << endl;
        return;
    }

    // Probar cada elemento
    for (int i = 0; i < nums.size(); i++) {

        // Si ya fue utilizado, lo saltamos
        if (states[i] == true) {
            continue;
        }

        // Tomamos nums[i]
        cout << nums[i] << " ";

        // Marcamos que ya fue utilizado
        states[i] = true;

        // Llamada recursiva
        permutation(nums, states, take + 1);

        // Desmarcamos para poder utilizarlo
        // en otra permutación
        states[i] = false;
    }
}

int main() {

    vector<int> nums = {1, 2, 3};
    vector<bool> states(nums.size(), false);

    permutation(nums, states, 0);

    return 0;
}