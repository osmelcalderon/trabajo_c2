#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, K; cin >> n >> K; //
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i]; //alturas

     vector<int> cost(n, INT_MAX);
     cost[0] = 0;

    for (int i = 1; i < n; i++) {
       for (int j = 1; j <= K; j++) {
            if (i - j >= 0) {
                 cost[i] = min(cost[i],
                              cost[i-j] + abs(h[i]-h[i-j]));

            }    
        }     
    }

    cout << cost[n-1] << '\n';
    return 0;
}
