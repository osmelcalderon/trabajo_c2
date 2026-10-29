#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;
int main() {
    //este es un texto que esta separado por puntos
    string texto = "Juan corre rápido. Ana estudia física. El perro duerme tranquilo";
    
    // flujo_oraciones:
    // Convierte el string en un flujo (como si fuera cin o un fichero)
    stringstream flujo_oraciones(texto);
    
    string oracion;

    //dividir el texto en oraciones: 
    //getline lee hasta encontrar un punto '.'
    //Cada vuelta del ciclo obtiene UNA oración
    while (getline(flujo_oraciones, oracion, '.')) {  
        cout << "oracion = "<< oracion<< '\n';
        
        
        // Convierte la oración en otro flujo
        // para leer palabra por palabra
        stringstream convertir(oracion);  
        string palabra;                                            
        
        // Recorre el flujo palabra por palabra
        // El operador >> separa automáticamente por espacios
        while (convertir >> palabra) {  
              // También podría hacerse así:
             // while (getline(convertir, palabra, ' ')) {

            cout << "palabra = "<< palabra<< '\n';
        }
        
    }
    return 0;
}


 /*
    //cout << flujo_oraciones << '\n';
    no tiene sentido que yo mande a imprimir un flujo, 
    porque cout ya es un flujo, solo que es un flujo de pantalla, 
    y ese flujo de pantalla, espera que se mande un texto a la pantalla
    
    //flujo_oraciones<<",probando,";  //esto si es correcto se pone al inicio
    */