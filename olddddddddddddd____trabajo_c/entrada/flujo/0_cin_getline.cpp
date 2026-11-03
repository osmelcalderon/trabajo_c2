#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string a, b;
    cin >> a;  // Hola\tMundo\n
    cout <<  a << '\n';
    cin >> b;   
    cout <<  b << '\n';

    /*
    string a, b;

    getline(cin, a, '|');

    cout << "a = " << a << '\n';

     //NO espera nueva entrada porque todavía quedan caracteres pendientes dentro del buffer de cin.
    getline(cin, b);

    cout << "b = " << b << '\n';*/

    //return 0;
    
    /*
    string campo;

    cout << "Ingrese datos separados por | :\n";

    getline(cin, campo, '|');
    cout << "Campo leido: [" << campo << "]\n";*/

    // Lee hasta encontrar |
    /*while (getline(cin, campo, '|')) {

        cout << "Campo leido: [" << campo << "]\n";

        // Si el usuario presiona ENTER termina
        if (cin.peek() == '\n')            break;
    }*/

    return 0;


}

/*

solo recoges UN campo, hasta el primer |.

#include <bits/stdc++.h>
using namespace std;

int main() {

    string campo;

    cout << "Ingrese datos separados por | :\n";

    while (getline(cin, campo, '|')) {

        cout << "Campo leido: [" << campo << "]\n";

        // Si lo siguiente es ENTER termina
        if (cin.peek() == '\n') {
            cin.get(); // consumir '\n'
            break;
        }
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {

    string linea =
    "parte una|otro 2|ninguna 3|mio 4\n"
    "esta es mi segunda linea\n"
    "esta es mi tercera linea";

    stringstream flujo(linea);

    string campo;

    cout << "CAMPOS:\n";

    // Leer primera línea completa
    string primeraLinea;
    getline(flujo, primeraLinea);

    // Convertir esa línea en otro flujo
    stringstream separar(primeraLinea);

    int contador = 1;

    // Separar usando |
    while (getline(separar, campo, '|')) {
        cout << "Campo " << contador++ << ": ";
        cout << campo << '\n';
    }

    cout << "\nLINEAS RESTANTES:\n";

    string bloque;

    while (getline(flujo, bloque)) {
        cout << bloque << '\n';
    }

    return 0;
}


////////////////






string linea = "parte una| otro 2|ninguna 3|mio 4 \n esta es mi segunda linea \n esta es mi teercera linea";
    stringstream flujo(linea);
    string a, campo, bloque;

    flujo >> a;  //parte
    cout << a << "\n"; 
    getline(flujo, campo, '|'); //una
    cout << campo << "\n"; 
    getline(flujo, bloque, '|'); // otro 2
    cout << bloque << "\n"; 
    getline(flujo, bloque, ' '); //ninguna
    cout << bloque << "\n"; 
    
    getline(flujo, bloque); //3|mio 4
    cout << bloque << "\n"; 

    getline(flujo, bloque); //esta es mi segunda linea
    cout << bloque << "\n"; 

    getline(flujo, bloque); //esta es mi teercera linea
    cout << bloque << "\n"; 


    return 0;
*/