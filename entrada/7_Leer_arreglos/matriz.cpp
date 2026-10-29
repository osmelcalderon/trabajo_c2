#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n); //declarando un vector de tipo string con un tamaño "n"
 
 //entrada   
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

//salida
    for (int i = 0; i < grid.size(); i++) {
        cout << grid[i] << " ";
    }

}

/*
    
C:\Users\denisse1\Desktop\binario\trabajo_c\entrada>matriz.exe
    4 5
    uno
    dos
    tres
    cuatro

*/