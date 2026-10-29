#include <bits/stdc++.h>
using namespace std;

int D, A, m_lit,destino;
vector<int> pos;              // pos[0]=0, pos[1..m]=estaciones, pos[m+1]=D
vector<int> litros, costos;
vector<vector<int>> memo;     // memo[num_estacion][gas]
const int INF = 1e9;

//gasolina_actual = gasolina actual en el tanque en el momento en que estás en una estación determinada.
//comienzo num_estacion 0, tanque lleno
int f(int num_estacion, int gasolina_actual) {
    
    //caso base
    if (num_estacion == destino) return 0;   // llegamos al num_estacion de destino final 100
    
    //memoizacion
    if (memo[num_estacion][gasolina_actual] != -1) return memo[num_estacion][gasolina_actual];

    //0,20,50,80,100  es la distancia_Prox_Estacionancia a la siguiente estación (o al destino).
    int distancia_Prox_Estacion = pos[num_estacion + 1] - pos[num_estacion];  //20-0, 50-20, 80-50, 100-80
    int mejor = INF;
    
    //1-avanzá sin Costo: "si me alcanza sin cargar". (sin comprar gasolina)
    if (gasolina_actual >= distancia_Prox_Estacion)  
        mejor = min(mejor, f(num_estacion + 1, gasolina_actual - distancia_Prox_Estacion)); 

    //2-avanzá CON Costo: Sino alcanza tengo que cargar una de las tres opciones
    for (int k = 0; k < m_lit; k++) {
        int gasolina_tras_carga = min(A, gasolina_actual + litros[k]);     // capacidad máxima A, "cargo, pero sin pasarme del tanque".
        if (gasolina_tras_carga >= distancia_Prox_Estacion)                     // ¿alcanza para el tramo?
            //con cuánto llego a la próxima estación después de cargar y consumir el tramo
            mejor = min(mejor, costos[k] + f(num_estacion + 1, gasolina_tras_carga - distancia_Prox_Estacion)); 
    }

    return memo[num_estacion][gasolina_actual] = mejor;
}

int main() {
    //D = 100; A = 50;
    //vector<int> estaciones = {20, 50, 80}; //están las gasolineras reales, sin inicio ni destino
                //    litros = {10, 25, 40};
                    //costos = {5, 12, 18};  //23

    D = 150; A = 60;
    vector<int> estaciones = {30, 70, 110}; 
    litros = {15, 30, 50};
    costos = {6, 11, 17};  //11+11+11=33

    m_lit = litros.size();

     //estructura de la DP: todas las posiciones donde hay un estado: 
     //**inicio, estaciones, destino**.
    //pos= {0,20, 50, 80,100}
    pos.clear();
    pos.push_back(0); //inicio
    for (int e : estaciones) pos.push_back(e); //estaciones
    pos.push_back(D);                          // destino final
    destino = (int)pos.size() - 1;

    memo.assign(pos.size(), vector<int>(A + 1, -1));

    int res = f(0, A);  // comienzo num_estacion 0, tanque lleno
    cout << "Costo mínimo: " << (res == INF ? -1 : res) << endl;  // 23
}


/*
pos= {0,20, 50, 80,100}
 memo.assign(pos.size(), vector<int>(A + 1, -1));
estaciones/capacidad   0 1 2 3... 50 51
 0    
20
50
80
100

g >= distancia_Prox_Estacion se lee directo: "¿la gasolina actual alcanza para el tramo?"
g - distancia_Prox_Estacion es "con cuánto llego a la próxima estación si no cargo".
min(A, g + litros[k]) es "cargo, pero sin pasarme del tanque".
nuevo - distancia_Prox_Estacion es "con cuánto llego a la próxima estación después de cargar y consumir el tramo".
costos[k] + f(...) es "pago esta carga + lo que cueste el resto del viaje".

La clave es que las dos ramas hacen lo mismo: calcular con cuánta gasolina llegás a num_estacion+1 y sumarle el costo óptimo desde ahí. La única diferencia es si pagás o no. Eso es exactamente lo que tus comentarios resaltan.
Y el min final elige entre no cargar y cargar cada una de las tres opciones, que es la decisión completa en esa estación.
Bien ahí. Esa es la forma más clara de escribirlo.








int f(int num_estacion, int gasolina_actual) 
num_estacion: En la estación que estoy parado actualmente, que incluso puede ser en el inicio que vale 0, porq no estoy en una gasolinera apenas voy a empezar a tanque lleno
gasolina_actual: La cantidad de gasolina que tengo actualmente, cuando comienza el tanque esta lleno.
Caso base
if (num_estacion == destino) return 0;  //Llegamos al num_estacion de destino (al final 100)
Memorización 
if (memo[num_estacion][gasolina_actual] != -1) return memo[num_estacion][gasolina_actual];


Solo avanza si la gasolina actual alcanza para el tramo, y no suma ningún costo (costos[k]). Es una decisión de "puedo permitirme no cargar". Recursión sin sumar costo.
if (gasolina_actual >= distancia_Prox_Estacion)  //"si me alcanza sin cargar, avanzá sin pagar".
    mejor = min(mejor, f(num_estacion + 1, gasolina_actual – distancia_Prox_Estacion));

    • No hay costos[k] + ... → no pagás nada → no cargaste.
    • gasolina_actual >= distancia_Prox_Estacion es solo un filtro de factibilidad: "si no cargo, ¿llego?".
    • gasolina_actual - distancia_Prox_Estacion es la gasolina con la que llegás a la próxima estación(num_estacion + 1) habiendo gastado el tramo.
Nota: 
    • gasolina_actual >= distancia_Prox_Estacion se lee: "¿la gasolina actual alcanza para el tramo?"
    • gasolina_actual – distancia_Prox_Estacion) se lee: "con cuánto llego a la próxima estación si no cargo".








Desglose

Este for representa la decisión de cargar combustible en la estación actual, probando cada una de las opciones de carga disponibles (k = 0, 1, 2). Es decir, en vez de un único "cargar sí/no", hay tres formas distintas de cargar (cada una con su litraje y su costo), y el algoritmo prueba las tres.
Cada k es una alternativa de carga con:
    • litros[k] → cuántos litros agregás
    • costos[k] → cuánto pagás por esa carga
El for es para evaluar las tres y quedarte con la mejor. Cada iteración es un "mundo hipotético" distinto.

// Opciones 2..4: cargar una de las tres opciones
for (int k = 0; k < m_lit; k++) {  //Opciones de (k = 0, 1, 2)
     int gasolina_tras_carga = min(A, gasolina_actual + litros[k]); // capacidad máxima A

   if (gasolina_tras_carga  >= distancia_Prox_Estacion) // ¿alcanza para el tramo?
      mejor = min(mejor, costos[k] + f(num_estacion + 1, gasolina_tras_carga  - distancia_Prox_Estacion));
}

int nuevo = min(A, gasolina_actual + litros[k]); 
Acá simulás la carga:
    • gasolina_actual + litros[k]→ lo que tendrías si agregás litros[k] sin límite.
    • min(A, ...) → pero el tanque tiene capacidad máxima A, así que no podés pasarte. Se lee: "cargo, pero sin pasarme del tanque".
    • Que significa A Pagás el costo completo igual (pagás por la carga aunque se derrame). Lo único que hace es recortar la gasolina que queda en el tanque para no superar la capacidad A, es decir, si la opción no entra entera, solo "agarrás" la parte que cabe (el excedente se pierde) pero igual pagás todo; pero no pagás menos por eso. 

if (gasolina_tras_carga  >= distancia_Prox_Estacion) : Filtro de factibilidad: después de cargar, ¿tienés suficiente para llegar a la próxima estación?
    • Si gasolina_tras_carga  < distancia_Prox_Estacion → esta carga no sirve, no podés avanzar. Se descarta (no se ejecuta el cuerpo del if).
    • Si gasolina_tras_carga  >= distancia_Prox_Estacion → esta carga es viable, se evalúa el costo.

Ojo: este if no decide cargar; decide si esta carga particular te permite avanzar. La decisión de cargar ya está implícita en que estás dentro del for y vas a sumar costos[k].







mejor = min(mejor, costos[k] + f(num_estacion + 1, gasolina_tras_carga  - distancia_Prox_Estacion));
Acá está el corazón. Se lee:
    • gasolina_tras_carga - distancia_Prox_Estacion se lee: "con cuánto llego a la próxima estación después de cargar y consumir el tramo".
    • costos[k] + f(...) : se lee "pago esta carga + lo que cueste el resto del viaje".





f(0, 50)   [km 0 → km 20, tramo=20]
│
├── NO CARGAR (50 >= 20) → f(1, 30)          [km 20, llego con 30]
│   │
│   ├── NO CARGAR (30 >= 30) → f(2, 0)       [km 50, llego con 0]
│   │   │
│   │   ├── NO CARGAR (0 >= 30) ? NO → descarta
│   │   ├── k=0 pequeña: tras_carga=min(50,0+10)=10 <30 → descarta
│   │   ├── k=1 media:   tras_carga=min(50,0+25)=25 <30 → descarta
│   │   └── k=2 grande:  tras_carga=min(50,0+40)=40 >=30 → 18 + f(3, 10)
│   │       │
│   │       └── f(3, 10)  [km 80, llego con 10, tramo=20]
│   │           │
│   │           ├── NO CARGAR (10 >= 20)? NO → descarta
│   │           ├── k=0: tras_carga=min(50,10+10)=20 >=20 → 5 + f(4, 0) = 5+0 = 5
│   │           ├── k=1: tras_carga=min(50,10+25)=35 >=20 → 12 + f(4,15) = 12
│   │           └── k=2: tras_carga=min(50,10+40)=50 >=20 → 18 + f(4,30) = 18
│   │           → f(3,10) = min(5,12,18) = 5
│   │       → costo = 18 + 5 = 23
│   │
│   ├── k=0 pequeña: tras_carga=min(50,30+10)=40 >=30 → 5 + f(2,10)
│   │   └── f(2,10): tramo=30, 10<30 → no cargar descarta;
│   │       k=0: 20<30 ✗; k=1: 35>=30 → 12+f(3,5); k=2: 50>=30 → 18+f(3,20)
│   │       f(3,5): tramo=20, 5<20; k=0:15<20✗; k=1:30→12+f(4,10); k=2:45→18+...
│   │       ... (caro)
│   ├── k=1 media: tras_carga=min(50,30+25)=50 >=30 → 12 + f(2,20)
│   │   └── f(2,20): 20<30; k=0:30>=30 → 5+f(3,0); k=1:45→12+f(3,15); k=2:50→18+...
│   │       f(3,0): 0<20; k=0:10<20✗; k=1:25>=20→12+f(4,5); k=2:40→18+...
│   │       → f(3,0)=12+0=12; f(2,20)=min(5+12=17, ...) ≥17
│   │       → costo = 12 + 17 = 29
│   └── k=2 grande: tras_carga=min(50,30+40)=50 >=30 → 18 + f(2,20) = 18+17 = 35
│   → f(1,30) = min(23, 29, 35) = 23   ← (acá ya se ve que NO cargar en km 20 es lo mejor)
│
├── k=0 pequeña: tras_carga=min(50,50+10)=50 >=20 → 5 + f(1,30)
│   └── f(1,30) ya calculado = 23 → costo = 5 + 23 = 28
├── k=1 media: tras_carga=min(50,50+25)=50 >=20 → 12 + f(1,30) = 12+23 = 35
└── k=2 grande: tras_carga=min(50,50+40)=50 >=20 → 18 + f(1,30) = 18+23 = 41
│
→ f(0,50) = min(23, 28, 35, 41) = 23  ✅    

*/