#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int grid[n][n];  //ejemplo 3x3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // ==================================
    // mostrar
    // ==================================
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}