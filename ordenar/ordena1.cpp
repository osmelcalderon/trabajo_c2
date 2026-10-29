#include <iostream>
using namespace std;

int temp[8];
//fusiona dos mitades ordenadas de un arreglo en una sola parte ordenada.
void combinar(int arreglo[], int izquierda, int medio, int derecha) { 

//    int i = izquierda, j = medio + 1, k = izquierda;

int i = izquierda;     // i = 0 (apunta al inicio de 1ª mitad)
int j = medio + 1;     // j = 3 (apunta al inicio de 2ª mitad)
int k = izquierda;     // k = 0 (apunta a dónde poner en temp)



//Mientras queden elementos en AMBAS listas(izquierda y derecha), haz esto.
    while (i <= medio && j <= derecha) {
        //cout << arreglo[i] << " --- " << arreglo[j] << "\n";
        
        if (arreglo[i] <= arreglo[j]) { 
            temp[k] = arreglo[i]; // Toma de la izquierda
            i++;
        } else {
            
            temp[k] = arreglo[j];  // Toma de la derecha
             j++;
        }
        k++; 
    }
    
                                    int tamano = sizeof(temp) / sizeof(temp[0]);

                                    cout << "📊 temp: [";
                                    for(int h = 0; h < tamano; h++) {
                                        cout << temp[h];
                                        cout << (h < tamano-1 ? " , " : "");
                                    }
                                    cout << "]\n";
       
  // Copiar elementos restantes de la primera mitad
    while (i <= medio) {
            temp[k] = arreglo[i];  // Toma de la izquierda
            i++;
            k++;
        }
        
    
    // Copiar elementos restantes de la segunda mitad
    while (j <= derecha) {
            temp[k] = arreglo[j];  // Toma de la derecha
            j++;
            k++;
        }
        
    
    // Copiar de temp de vuelta al arreglo original
    for (int i = izquierda; i <= derecha; i++)
        arreglo[i] = temp[i];        
    
      

        
} 

void dividir(int arreglo[], int izquierda, int derecha) { //divide y venceras
	
    	//imprimir 
    cout << " [";
    for (int i = izquierda; i <= derecha; i++) {
        cout << arreglo[i];
        if (i < derecha) cout << " ";
    }
    cout << "]" << endl;


    // interrumpe recursion, con 1 solo elemento.
    if (izquierda >= derecha) { 
        return;
    }
    
    // Calcular la mitad y dividir
    int medio =  (derecha + izquierda) / 2;
    
    
    dividir(arreglo, izquierda, medio);   //izquierda - medio
    dividir(arreglo, medio + 1, derecha); // medio+1 - derecha 
     //combinar
    combinar(arreglo, izquierda, medio,  derecha);



}

int main() {
    //int arreglo[] = {38, 27, 43, 3, 9, 82, 10};
    //int arreglo[] = {3, 4, 2, 1};
    int arreglo[] = {38, 27, 4};
    int n  = sizeof(arreglo) / sizeof(arreglo[0]);
    
    cout << "=== SOLO DIVISIONES (sin mezclar) ===" << endl;
    
    dividir(arreglo, 0, n - 1);

    //arreglo completo ordenado
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    
    return 0;
}


/*
La recursividad divide.
mergear reconstruye.

 // combinar
    mergear(izq, medio, der);

    ORDENA cada mitad.

Luego:

mergear(izq, medio, der);

UNE ambas mitades ya ordenadas.
*/

/*
    //arreglo, izquierda, derecha, nivel
    //merge sort 
    //https://www.youtube.com/watch?v=tl74Gvi71s8
    https://www.youtube.com/watch?v=vUSoMDEz8Mw

https://es.cppreference.com/
https://learn.microsoft.com/es-es/cpp/cpp/type-conversions-and-type-safety-modern-cpp?view=msvc-170 
1- 0.5
2- 0.25
3- 0.125
4- 0.625
5- 0.0625
6- 0.03125
7- 0.015625
8- 0.0078125
9- 0.00390625
10- 0.001953125
11- 0.0009765625
12- 0.00048828125
13 0.000244140625


0.3  = 0.0100110011001100


void mergeSort(int izq, int der) {
    if (izq >= der) return;

    int medio = (izq + der) / 2;

    mergeSort(izq, medio);
    mergeSort(medio + 1, der);

    mergear(izq, medio, der);
}


main{  //[38 27 43 3 9 82 10]
   mergeSort(0, 6)
}
*/