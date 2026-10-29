#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string parrafo = 
R"(Este es un párrafo.
Tiene varias líneas.
Y conserva los saltos de línea.)";

  
    string oracion;
    stringstream flujo(parrafo);  //convierte el string en un flujo de entrada como si fuera cin.
    

    while (true) {
         //ignorar las líneas en blanco, y si se tropieza con el fin de archivo sale de todo 
        do {
            
            //toma una línea del párrafo, 
            //sino logra tomar una linea es porq no existe entonces falla, por EOF
            //verifica si falla  entonces sale de la app
            if (!getline(flujo, oracion)) 
                            return 0;   //Fin de archivo
           // aqui quiero preguntar \n cout << "--vacio--" << '\n';                
        } while (oracion.empty()); //línea vacía continua ciclo 

         cout << "Linea leida: " << oracion << '\n';
        
       
        
    }
}

/*
5. Saltar líneas vacías
✔ lee múl􀆟ples casos hasta EOF ✔ salta líneas vacías
XOX 
.O.
XXO 

OOX
XXO 
OX.
*/