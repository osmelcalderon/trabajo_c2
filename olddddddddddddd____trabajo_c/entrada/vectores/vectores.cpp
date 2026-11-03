#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matriz;  //(3, vector<int>(4));

    matriz[0][1] = 7;

    for (int i = 0; i < matriz.size(); i++) {

        for (int j = 0; j < matriz[i].size(); j++) {

            cout << matriz[i][j] << " ";
        }

        cout << '\n';
    }
}