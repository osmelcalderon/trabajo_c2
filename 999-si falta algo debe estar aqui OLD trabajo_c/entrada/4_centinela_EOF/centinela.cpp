#include <iostream>
using namespace std;

int main() {
    long long N;
    int contador = 1;
    //solo puede entrar 10 numeros
    while (cin >> N && contador < 10) { // Leer hasta EOF pero limitando a 75 (por seguridad)
        // Aquí procesas cada N
        contador++;
    }
    return 0;
}


/*

Un valor cen􀆟nela es un valor especial que "indica el final de la entrada". 
Cuando se lee ese valor, el programa debe terminar la lectura.
Ejemplo: Que un programa termine cuando pongan 0 significa “termina”

while (cin >> x && x != 0) {  //termina en 0
while(cin>>n>>k && casosLeidos < 10) {   //2 entradas, menores q 10


*/