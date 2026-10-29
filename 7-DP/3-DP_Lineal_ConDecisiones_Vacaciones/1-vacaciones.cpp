#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;  cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Problema general - calcula maximo de felicidad desde el dia 1 hasta el n
    // dp que considere las 3 opciones
    // no puede hacer la misma actividad dos dias seguidos
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    // dp[i][0] = maximo de felicidad en el dia i-esimo si hace la actividad A
    // dp[i][1] = maximo de felicidad en el dia i-esimo si hace la actividad B
    // dp[i][2] = maximo de felicidad en el dia i-esimo si hace la actividad C

    for (int i = 0; i < n; ++i) {
        dp[i+1][0] = a[i] + max(dp[i][1], dp[i][2]);
        dp[i+1][1] = b[i] + max(dp[i][0], dp[i][2]);
        dp[i+1][2] = c[i] + max(dp[i][0], dp[i][1]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
    return 0;
}
