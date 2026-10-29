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
     //Si el día d NO es un día en el que vas a viajar, entonces no necesitas comprar ningún ticket 
     //ese día. Simplemente avanzas al día siguiente (d + 1) sin pagar nada.
     //No hay costo asociado, no hay decisión que tomar. Solo avanzas.
    if (!esDiaDeViaje[d]) return f(d + 1);
    
    // Si ya calculamos este subproblema, lo devolvemos
    if (memo[d] != -1) return memo[d];
    
    // Tomamos el mínimo de las tres opciones
    //El [costo de cada Día] + [Siguiente día a resolver]
   // ¿Cada decisión a dónde me lleva? Me lleva a un nuevo día
     // Día d+1, d+7, d+30

    return memo[d] = min({
                costs[0] + f(d + 1),  // Opción 1: comprar pase de 1 día
                costs[1] + f(d + 7),  // Opción 2: comprar pase de 7 días
                costs[2] + f(d + 30) // Opción 3: comprar pase de 30 días
            }); //d es un número de día del año (1 a 365).
            
    
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

/*

Ejemplo: 
Supón days = [1, 4, 6] y costs = [2, 7, 15].

f(1) → día 1 sí viaja → decides.

Si eliges ticket de 1 día → 2 + f(2).
    f(2) → día 2 no viaja → return f(3).
    f(3) → día 3 no viaja → return f(4).
    f(4) → día 4 sí viaja → decides.
Entonces f(2) y f(3) son atajos que te llevan directo a f(4) sin costo.

¿Y de dónde salen d+1, d+7, d+30?
Del enunciado:
"Un pase de 1 día te permite viajar durante 1 día"
"Un pase de 7 días te permite viajar durante 7 días"
"Un pase de 30 días te permite viajar durante 30 días"
Si compras un pase de 7 días el día d, cubres los días d, d+1, ..., d+6. Por lo tanto, el siguiente día sin cubrir es d+7.
Por eso f(d + 7), no f(d + 6).


*/