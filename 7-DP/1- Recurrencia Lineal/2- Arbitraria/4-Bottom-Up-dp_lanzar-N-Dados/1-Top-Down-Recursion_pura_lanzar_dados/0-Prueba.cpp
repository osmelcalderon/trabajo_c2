#include <bits/stdc++.h>
using namespace std;

int n = 2;       // dados
int k = 6;       // caras
int target = 7;  // suma objetivo
int total = 0;

void lanzar_dado(int dado, int restante, vector<int>& elegidos) {

    /*Si el target restante es distinto de 0, no es una forma válida
       entonces encontre forma NO valida 0. 
      Por ejemplo cuando lanzo 2 dados y mi objetivo es 7, imaginate que el primer dado caiga 2, el segundo caiga 1, pues no es valido porque 7-2-1=4 entonces no se completo*/
    if (restante < 0) return; //0

    if (dado == n) {
        /*
         Si ya usaste todos los dados y el target restante es 0, 
         encontraste 1 forma válida.
         Por ejemplo cuando lanzo 2 dados y mi objetivo es 7, imaginate que el primer dado caiga 5, el segundo caiga 2, pues  es valido porque 7-5-2=0 entonces se completo
        */
        if (restante == 0) {
            for (int i = 0; i < n; i++) {
                if (i) cout << " + ";
                cout << elegidos[i];
            }
            cout << " = " << target << " ✅\n";
            total++;
        }
        /* Si el target restante es distinto de 0,
            no es una forma válida entonces encontre forma NO valida 0. 
           Por ejemplo cuando lanzo 2 dados y mi objetivo es 7, imaginate que el primer dado caiga 2, el segundo caiga 1, pues no es valido porque 7-2-1=4 entonces no se completo*/
        return; //0
    }

    //las caras de cada dado, que son las mismas para cada dado
    for (int cara = 1; cara <= k; cara++) {
        elegidos.push_back(cara);
        lanzar_dado(dado + 1, restante - cara, elegidos);
        elegidos.pop_back();
    }
}

int main() {
    vector<int> elegidos;
    //lanzar_dado(totalDados, Quedandorestante, vector<int>& elegidos) {
    lanzar_dado(0, target, elegidos);
    cout << "\nTotal de formas = " << total << "\n";
    return 0;
}