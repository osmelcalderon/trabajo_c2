#include <bits/stdc++.h>
using namespace std;


int n = 2;       // dados
int caras = 6;       // caras
int objetivo = 7;  // suma objetivo


const int MOD = 1e9 + 7; //Con n=10⁴

long long lanzar_dados(int objetivo, int n, vector<vector<long long>>& memo) {

    /*
        // 1) Si el objetivo se volvió negativo, no hay forma de recuperarlo
       Si en algún momento el target restante se vuelve negativo, no hay forma de recuperarlo, así que se devuelve 0. 
       Por ejemplo cuando lanzo 4 dados y mi objetivo es 7, imaginate que el primer dado caiga 6, el segundo caiga 4, para que voy a continuar si ya 7-6-4=negativo
    */
    if (objetivo < 0 ) return 0;

    /* Si ya no quedan dados, decides según el objetivo
    caso 1: Si ya usaste todos los dados y el target restante es 0, 
     encontraste 1 forma válida.
     Por ejemplo cuando lanzo 2 dados y mi objetivo es 7, imaginate que el primer dado caiga 5, el segundo caiga 2, pues  es valido porque 7-5-2=0 entonces se completo
    
    caso 2: Si el target restante es distinto de 0, no es una forma válida
    entonces encontre forma NO valida 0. 
     Por ejemplo cuando lanzo 2 dados y mi objetivo es 7, imaginate que el primer dado caiga 2, el segundo caiga 1, pues no es valido porque 7-2-1=4 entonces no se completo*/
     
    
    if (n == 0) return (objetivo == 0) ? 1 : 0;

     //cache, memoizacion
    //if (memo[objetivo]!=-1) return memo[objetivo];
    if (memo[objetivo][n] != -1) return memo[objetivo][n];

 
       long long total = 0; //aqui voy guardando el acumulado
    
        for (int i = 1; i <= caras; i++) { // las caras de cada dado
            total = (total + lanzar_dados(objetivo - i, n - 1,memo)) % MOD;
        }

        
     return memo[objetivo][n] = total;
    //return memo[objetivo]=total % MOD;
    
}

int main() {

    //vector<int> memo(objetivo+ 1, -1); //relleno en -1 el vector memo
    vector<vector<long long>> memo(objetivo + 1, vector<long long>(n + 1, -1));

    cout << "Resultado: " << lanzar_dados(objetivo,n,memo)  << endl;

return 0;


}


/*

La memoización es bidimensional: porque el estado de la recursión depende de dos variables independientes:
 - objetivo (la suma que falta)
 - n (los dados que faltan)

Si dos llamadas tienen esos dos valores iguales, 
 el resultado es exactamente el mismo sin importar cómo llegaste ahí.

¿Qué significa "estado"?
El estado es toda la información que necesitas para calcular el resultado de una llamada. Si dos llamadas tienen el mismo estado, devuelven lo mismo.

  Mira esta función:  long long lanzar_dados(int objetivo, int n, ...)
    Solo hay dos parámetros que cambian entre llamadas: objetivo y n. 
        caras es fijo. No hay más nada variable.

Entonces el estado es la pareja: (objetivo,n) Y por eso la tabla necesita dos índices:
  memo[objetivo][n]
¿Por qué no basta con una dimensión?
   Porque objetivo solo, o n solo, no identifican unívocamente el estado. 
     Mira estos dos casos:

        lanzar_dados(5, 1)   // me falta sumar 5, me queda 1 dado
        lanzar_dados(5, 2)   // me falta sumar 5, me quedan 2 dados
        Mismo objetivo = 5, pero diferente n. Y dan resultados distintos:

            lanzar_dados(5, 1) = 1 forma → solo la cara 5.
            lanzar_dados(5, 2) = 4 formas → (1,4), (2,3), (3,2), (4,1).

    Si guardas solo por objetivo:

        memo[5] = 1;   // calculaste lanzar_dados(5, 1)
        Luego llega lanzar_dados(5, 2), ves memo[5] != -1, devuelves 1. Mal, debería ser 4.

Por eso necesitas el segundo índice n:
    memo[5][1] = 1;   // lanzar_dados(5, 1)
    memo[5][2] = 4;   // lanzar_dados(5, 2)
Cada celda (objetivo, n) guarda un resultado único.

¿Por qué el estado es solo (objetivo, n) y no más?
Porque no importa cómo llegaste a ese estado. Solo importa lo que falta.

Compara dos caminos distintos que llegan al mismo estado:

    Camino A:
    dado1=1 → dado2=2 → objetivo restante = 7-1-2 = 4, dados restantes = 0

    Camino B:
    dado1=3 → dado2=0? no, no existe cara 0...



    Mejor ejemplo con 3 dados:
Camino A: dado1=1, dado2=2 → restante=7-1-2=4, faltan 1 dado
Camino B: dado1=2, dado2=1 → restante=7-2-1=4, faltan 1 dado
Ambos llegan a (objetivo=4, n=1). Y desde ahí, el futuro es idéntico: te queda 1 dado y debes sumar 4. Las formas posibles son las mismas en ambos caminos.

Por eso la memoización no guarda los valores ya lanzados. No le importa el pasado. Solo guarda:

"Desde el estado (objetivo=4, n=1), ¿cuántas formas hay de terminar?"

Y esa respuesta es siempre la misma, sin importar qué dados ya lanzaste.

Lo que guardas vs lo que NO guardas
Guardas	No guardas
Cuánto falta sumar (objetivo)	Qué valores salieron antes
Cuántos dados faltan (n)	En qué orden salieron
Cuántas formas hay desde aquí	El camino recorrido
Eso es lo bonito de DP: el pasado se olvida. Solo el futuro importa.

Analogía
Imagina que vas en un auto y te falta llegar a la meta. El estado es:

Cuánta distancia falta (objetivo).

Cuánta gasolina te queda (n).

No importa por qué calles llegaste. Si dos autos están en el mismo punto con la misma gasolina, tienen exactamente las mismas rutas posibles hacia la meta. Eso es el estado.

Resumen
La memoización es 2D porque el estado depende de dos variables: objetivo y n.

No guarda los valores de cada dado. Guarda el resultado desde cada estado (objetivo, n).

Dos llamadas con el mismo objetivo y el mismo n devuelven siempre lo mismo, sin importar cómo llegaron.

Por eso memo[objetivo][n] es la celda correcta, y memo[objetivo] (1D) colisiona estados distintos.
*/

   