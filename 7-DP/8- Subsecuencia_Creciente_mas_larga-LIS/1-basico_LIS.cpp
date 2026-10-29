#include <bits/stdc++.h>

using namespace std;

int LIS(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // dp[i] = longitud de la LIS que termina en i

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { //j = cada elemento anterior a i.
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
    }



    return *max_element(dp.begin(), dp.end()); //devuelve el valor mas grande
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Longitud de la LIS: " << LIS(arr) << endl;  // 5
    return 0;
}