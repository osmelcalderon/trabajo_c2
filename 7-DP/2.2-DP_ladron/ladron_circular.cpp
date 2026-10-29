#include <bits/stdc++.h>
using namespace std;

// House Robber lineal (versión derecha → izquierda)
int robLinear(vector<int>& nums, int start, int end) {
    int n = end - start + 1;
    if (n == 0) return 0;
    if (n == 1) return nums[start];
    
    vector<int> dp(n + 1, 0);
    dp[n - 1] = nums[end];       // última casa del rango
    dp[n] = 0;                    // fuera de rango
    
    // Recorremos de derecha a izquierda dentro del rango
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = max(nums[start + i] + dp[i + 2], dp[i + 1]);
    }
    
    return dp[0];
}

// House Robber circular
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    
    // Escenario 1: considerar casas [0 .. n-2] (excluir última)
    int caso1 = robLinear(nums, 0, n - 2);
    
    // Escenario 2: considerar casas [1 .. n-1] (excluir primera)
    int caso2 = robLinear(nums, 1, n - 1);
    
    return max(caso1, caso2);
}

int main() {
    // Caso 1: [2,3,2] → esperado 3
    vector<int> nums1 = {2, 3, 2};
    cout << "Caso 1: [2,3,2]" << endl;
    cout << "Resultado: " << rob(nums1) << " (esperado: 3)" << endl << endl;
    
    // Caso 2: [1,2,3,1] → esperado 4
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Caso 2: [1,2,3,1]" << endl;
    cout << "Resultado: " << rob(nums2) << " (esperado: 4)" << endl << endl;
    
    // Caso 3: [1,2,3] → esperado 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Caso 3: [1,2,3]" << endl;
    cout << "Resultado: " << rob(nums3) << " (esperado: 3)" << endl << endl;
    
    // Caso 4: [5] → esperado 5
    vector<int> nums4 = {5};
    cout << "Caso 4: [5]" << endl;
    cout << "Resultado: " << rob(nums4) << " (esperado: 5)" << endl << endl;
    
    // Caso 5: [2,1] → esperado 2
    vector<int> nums5 = {2, 1};
    cout << "Caso 5: [2,1]" << endl;
    cout << "Resultado: " << rob(nums5) << " (esperado: 2)" << endl << endl;
    
    // Caso 6: [1,2,3,1,5] → esperado 8
    vector<int> nums6 = {1, 2, 3, 1, 5};
    cout << "Caso 6: [1,2,3,1,5]" << endl;
    cout << "Resultado: " << rob(nums6) << " (esperado: 8)" << endl;
    
    return 0;
}