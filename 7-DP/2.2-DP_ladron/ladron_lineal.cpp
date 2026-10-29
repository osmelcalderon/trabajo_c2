#include <bits/stdc++.h>
using namespace std;


    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n + 1, 0);
        dp[n - 1] = nums[n - 1];      // última casa
        dp[n] = 0;                     // fuera de rango
        
        // Recorremos de derecha a izquierda
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        } //cout << "Caso 2: [2,7,9,3,1]" << endl;
           //dp = [12, 10, 10, 3, 1, 0] el final
        
        return dp[0];
    };


int main() {
    
    
    // Caso de prueba 1: [1,2,3,1] → esperado 4
    vector<int> nums1 = {1, 2, 3, 1};
    //vector<int> nums1 = {3, 2, 3};
    cout << "Caso 1: [1,2,3,1]" << endl;
    cout << "Resultado: " << rob(nums1) << " (esperado: 4)" << endl;
    cout << endl;
    
    // Caso de prueba 2: [2,7,9,3,1] → esperado 12
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Caso 2: [2,7,9,3,1]" << endl;
    cout << "Resultado: " << rob(nums2) << " (esperado: 12)" << endl;
    cout << endl;
    
    // Caso borde 3: [5] → esperado 5
    vector<int> nums3 = {5};
    cout << "Caso 3: [5]" << endl;
    cout << "Resultado: " << rob(nums3) << " (esperado: 5)" << endl;
    cout << endl;
    
    // Caso borde 4: [2,1] → esperado 2
    vector<int> nums4 = {2, 1};
    cout << "Caso 4: [2,1]" << endl;
    cout << "Resultado: " << rob(nums4) << " (esperado: 2)" << endl;
    cout << endl;
    
    // Caso borde 5: [1,2,3] → esperado 4 (robar 1 y 3)
    vector<int> nums5 = {1, 2, 3};
    cout << "Caso 5: [1,2,3]" << endl;
    cout << "Resultado: " << rob(nums5) << " (esperado: 4)" << endl;
    cout << endl;
    
    // Caso borde 6: [2,7,9,3,1,5,6] → esperado 22
    vector<int> nums6 = {2, 7, 9, 3, 1, 5, 6};
    cout << "Caso 6: [2,7,9,3,1,5,6]" << endl;
    cout << "Resultado: " << rob(nums6) << " (esperado: 22)" << endl;
    
    return 0;
}