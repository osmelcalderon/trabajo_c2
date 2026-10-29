#include <bits/stdc++.h>
using namespace std;

int N_escalones, objetivo;
vector<int> costos;
vector<int>  memo;  
const int INF = 1e9;

int subirEscalera(int i) { //inicio i=0
 
    // Caso base: estamos en el escalón 0, costo 0
    if (i == 0) return 0;
    
    // Memoización
     if (memo[i] != -1) return memo[i];
 
    
    // costos[i-1] es el costo del escalón i (por el desfase 1-indexado)
    int x = costos[i - 1];

    int mejor = INF;   //INT_MAX / 2; 
        
    
    /*
    Recorre las 3 posiciones anteriores a i, pero si no existen 
     (porque i es muy pequeño), empieza desde la posición 0.
    
    Mira hacia atrás, a las 3 personas anteriores a ti, y ve una por una.
    Digamos que estás en la posición i = 5:
    Posición:  0   1   2   3   4  [5]  6   7
                       ↑   ↑   ↑   ↑
                       j   j   j  tú (i=5)
   
    Entonces:  j empieza en i - 3 = 2 y avanza: 2, 3, 4. 
               Son las 3 personas justo antes de ti (sin contarte a ti).

    ¿Y el max(0, ...)?
       Es solo un seguro para cuando estás al principio de la fila
        y no hay 3 personas atrás.     
       Ejemplo: Si estás en i = 1, atrás solo hay 1 persona (la posición 0).
                No puedes ir a la posición -2. Entonces max(0, 1-3) = max(0, -2) = 0.
                Empiezas en 0 y avanzas hasta i-1.     i=1:  [0] [1]    
    */

    // Probamos los 3 posibles orígenes: i-1, i-2, i-3
    //for (int j = i + 1; j <= min(objetivo, i + 3); j++) {  de numero hasta objetivo sin pasarse de objetivo
    for (int j = max(0, i - 3); j < i; j++) {  //i=5
        int salto = i - j;                 // cuántos escalones saltaste
        int costo = subirEscalera(j) + x + salto * salto;
        cout << "j : " <<  j << "salto : " << salto << endl;
        mejor = min(mejor, costo);
        
    }
    return memo[i] = mejor;

}

int main() {

    objetivo=4;
    costos = {1,2,3,4}; //15 costos de cada paso de escalera
    //costos = {1,100,1,1,1,100,1,1,100,1}; //6 costos de cada paso de escalera
    N_escalones= (int)(costos.size());

    memo.assign(N_escalones + 1, -1);

    int res =subirEscalera(objetivo); //min(subirEscalera(0), subirEscalera(1), subirEscalera(2));//  
    cout << "Minimo Costo subir Escalera: " <<  res << endl;  
   return 0; 
    
}

  
  
