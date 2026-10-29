#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pedidos, costos;
vector<int> memo;


//Calcula exactamente el "próximo pedido no cubierto".
int primerMayorQue(int limite) {
    //upper_bound a vector ordenado devuelve un iterador al 1er elemento estrictamente mayor que limite. 
    //Restando begin() obtienes el índice de ese elemento.
    //ejemplo: [1, 2, 3, 14, 15, 16, 20]
    //buscamos el primer elemento mayor q 6 y encuentra el 14 que esta en el indice 3
    auto it = upper_bound(pedidos.begin(), pedidos.end(), limite);
    return (int)(it - pedidos.begin());
    /*
    upper_bound, no devuelve numero devuelve iteradir
    it - pedidos.begin()
            pedidos = [1, 2, 3, 14, 15, 16, 20]
            begin() → apunta al 1 (posición 0)
            it      → apunta al 14 (posición 3)
            it - pedidos.begin() = 3-0 =     3
    */
}

int f(int i, vector<int> &memo) {
    if (i == n) return 0;
    if (memo[i] != -1) return memo[i];

    //aqui no hace falta buscar el proximo pedido porque va agarrar el presente y se mueve al proximo i
    int opcionBici = costos[0] + f(i+ 1, memo);

    //ejemplo: [1, 2, 3, 14, 15, 16, 20]
    //moto en i = 0, t = pedidos[0] = 1.   Por tanto -> limite = 1 + 5 = 6. 
    //por tanto buscamos el primer elemento mayor q 6 y encuentra el 14 que esta en el indice 3
    //upper_bound(pedidos, 6) → primer elemento > 6 → el 14, que está en índice 3.
    //opcionMoto = costos[1] + f(3).
    int jMoto = primerMayorQue(pedidos[i] + 5);
    int opcionMoto = costos[1] + f(jMoto, memo);

    int jAuto = primerMayorQue(pedidos[i] + 20);
    int opcionAuto = costos[2] + f(jAuto, memo);

    return memo[i] = min({opcionBici, opcionMoto, opcionAuto});
}

 


int main() {
    // Valores por defecto del Ejemplo 2
     pedidos = {1, 2, 3, 4, 5, 6, 20};  //da 11:   moto:1-6, bici:20
     pedidos = {1, 2, 3, 14, 15, 16, 20}; //da 15:   auto:1-20
     pedidos = {1, 2, 3, 24, 25, 26, 50}; //da 19:   moto:1-3, moto:24-26, bici: 50
     costos  = {3, 8, 15}; //


     pedidos = {1, 3, 5, 7,8, 9, 25}; //da 12:   bici:1, moto:3-8, bici:9,25  2+6+4=12
     costos  = {2, 6, 12}; 

    
    n = (int)pedidos.size();
    memo.assign(n + 1, -1);
    //return f(0);
    

    cout << "Costo mínimo: " << f(0, memo) << endl;  // Esperado: 11
    return 0;
}

/*

i no es un índice de pedido, es un minuto
Pero en esta versión con i + 5 + 1 estoy tratando i como minuto. Mezclándo 2 semánticas.
return memo[i] = min({ 
    costs[0] + f(i + 1),
    costs[1] + f(i + 5+1),   // ❌
    costs[2] + f(i + 20+1)   // ❌
});


**En f(i), i debería ser el índice del próximo pedido a cubrir f(i). 

No saltás al pedido correcto
Aunque i fuera un minuto, f(i + 5 + 1) asume que el próximo pedido empieza exactamente en el minuto i+6.
 Pero puede que el próximo pedido esté en i+7, o en i+3, etc. Por eso tu código correcto usa:

int jMoto = primerMayorQue(pedidos[i] + 1 + 5);
int opcionMoto = costos[1] + f(jMoto);

upper_bound te da el índice del primer pedido que la moto NO puede cubrir,
 es decir, el siguiente subproblema real. Eso es lo que hace que la recursión avance correctamente.




*/