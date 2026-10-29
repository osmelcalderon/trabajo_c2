#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> regilla(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> regilla[i][j];
        }
    }
    
    // Imprimir la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << regilla[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}