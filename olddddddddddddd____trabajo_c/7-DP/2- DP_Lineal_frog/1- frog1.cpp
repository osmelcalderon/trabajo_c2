#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> cost(n+1, 0);  // cost[0] = 0 por defecto

    for (int i = 1; i < n; i++) {
        if (i >= 2)
            cost[i] = min(cost[i-1] + abs(h[i]-h[i-1]),
                          cost[i-2] + abs(h[i]-h[i-2]));
        else
            cost[i] = cost[i-1] + abs(h[i]-h[i-1]);
    }

    cout << cost[n-1] << '\n';
    return 0;
}
