#include <bits/stdc++.h>
using namespace std;
/*Con Memoizacion:*/
int min_cost(vector<int>& h, int i, unordered_map<int, int>& memo) {
    if (i == 0)
        return 0;

    if (memo.count(i))
        return memo[i];

    int opcion1 = min_cost(h, i - 1, memo) + abs(h[i] - h[i - 1]);

    int opcion2 = INT_MAX;

    if (i >= 2)
        opcion2 = min_cost(h, i - 2, memo) + abs(h[i] - h[i - 2]);

    memo[i] = min(opcion1, opcion2);

    return memo[i];
}

int main() {
    vector<int> h = {10, 30, 40, 20};

    unordered_map<int, int> memo;

    cout << min_cost(h, h.size() - 1, memo) << '\n';

    return 0;
}