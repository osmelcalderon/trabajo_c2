#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
vector<int> costs;
vector<bool> esDiaDeViaje;
int lastDay;

int f(int d) {
    // Caso base: si ya pasamos el último día, no necesitamos comprar más
    if (d > lastDay) return 0;

     // **Si no es día de viaje, lo saltamos sin costo
    if (!esDiaDeViaje[d]) return f(d + 1);
    
    // Si ya calculamos este subproblema, lo devolvemos
    if (memo[d] != -1) return memo[d];
    
    // Tomamos el mínimo de las tres opciones
    return memo[d] = min({
                costs[0] + f(d + 1),  // Opción 1: comprar pase de 1 día
                costs[1] + f(d + 7),  // Opción 2: comprar pase de 7 días
                costs[2] + f(d + 30) // Opción 3: comprar pase de 30 días
            });
            
    
}

int mincostTickets(vector<int>& days, vector<int>& c) {
    costs = c;
    lastDay = days.back();
    
    memo.assign(lastDay + 31, -1);
    
    esDiaDeViaje.assign(lastDay + 31, false);
    for (int d : days) esDiaDeViaje[d] = true;
    
    return f(1);
}

int main() {
    // Ejemplo: días de viaje = [1, 8, 20], costos = [2, 7, 15]
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    
    cout << "Costo mínimo: " << mincostTickets(days, costs) << endl;
    
    return 0;
}