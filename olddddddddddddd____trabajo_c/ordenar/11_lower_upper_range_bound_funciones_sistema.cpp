#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Arreglo ordenado de calificaciones
    int calificaciones[] = {60, 65, 70, 70, 70, 75, 80, 80, 85, 85, 85, 85, 90, 90, 95};
    int n = 15;
    
    cout << "=== CALIFICACIONES DE ESTUDIANTES ===" << endl;
    cout << "Arreglo: ";
    for (int i = 0; i < n; i++) {
        cout << calificaciones[i];
        if (i < n-1) cout << ", ";
    }
    cout << "\n\n";
    
    // ========== TAREA 1: lower_bound ==========
    cout << "--- TAREA 1: Primer estudiante con 70 o más ---" << endl;
    int x1 = 70;
    int* ptr1 = lower_bound(calificaciones, calificaciones + n, x1);
    int idx1 = ptr1 - calificaciones;
    
    if (idx1 < n) {
        cout << "✅ Primer estudiante con >= " << x1 << " está en posición " << idx1 << endl;
        cout << "   Calificación: " << calificaciones[idx1] << endl;
    } else {
        cout << "❌ No hay estudiantes con >= " << x1 << endl;
    }
    cout << endl;
    
    // ========== TAREA 2: upper_bound ==========
    cout << "--- TAREA 2: Primer estudiante con más de 85 ---" << endl;
    int x2 = 85;
    int* ptr2 = upper_bound(calificaciones, calificaciones + n, x2);
    int idx2 = ptr2 - calificaciones;
    
    if (idx2 < n) {
        cout << "✅ Primer estudiante con > " << x2 << " está en posición " << idx2 << endl;
        cout << "   Calificación: " << calificaciones[idx2] << endl;
    } else {
        cout << "❌ No hay estudiantes con > " << x2 << endl;
    }
    cout << endl;
    
    // ========== TAREA 3: Contar con lower/upper ==========
    cout << "--- TAREA 3: ¿Cuántos estudiantes sacaron 85? ---" << endl;
    int x3 = 85;
    int* low = lower_bound(calificaciones, calificaciones + n, x3);
    int* up = upper_bound(calificaciones, calificaciones + n, x3);
    int cantidad = up - low;
    
    cout << "Calificación " << x3 << " aparece " << cantidad << " veces" << endl;
    if (cantidad > 0) {
        cout << "   Posiciones: desde " << (low - calificaciones) 
             << " hasta " << (up - calificaciones - 1) << endl;
    }
    cout << endl;
    
    // ========== TAREA 4: Verificar existencia ==========
    cout << "--- TAREA 4: ¿Alguien sacó 100? ---" << endl;
    int x4 = 100;
    int* ptr4 = lower_bound(calificaciones, calificaciones + n, x4);
    int idx4 = ptr4 - calificaciones;
    
    if (idx4 < n && calificaciones[idx4] == x4) {
        cout << "✅ SÍ, hay un estudiante con " << x4 << endl;
    } else {
        cout << "❌ NO, nadie sacó " << x4 << endl;
        if (idx4 < n) {
            cout << "   La calificación más cercana es " << calificaciones[idx4] << endl;
        } else {
            cout << "   Todas las calificaciones son menores que " << x4 << endl;
        }
    }
    cout << endl;
    
    // ========== TAREA 5: equal_range ==========
    cout << "--- TAREA 5: Rango de estudiantes con 80 (usando equal_range) ---" << endl;
    int x5 = 80;
    auto rango = equal_range(calificaciones, calificaciones + n, x5);
    int primerIndice = rango.first - calificaciones;
    int ultimoIndice = rango.second - calificaciones - 1;
    int total = rango.second - rango.first;
    
    if (total > 0) {
        cout << "✅ Calificación " << x5 << " encontrada:" << endl;
        cout << "   Primer estudiante: posición " << primerIndice << endl;
        cout << "   Último estudiante: posición " << ultimoIndice << endl;
        cout << "   Total de estudiantes: " << total << endl;
    } else {
        cout << "❌ No hay estudiantes con calificación " << x5 << endl;
    }
    cout << endl;
    
    // ========== TAREA 6: Posición para insertar ==========
    cout << "--- TAREA 6: ¿Dónde insertar a un estudiante con 78? ---" << endl;
    int nuevo = 78;
    int* posInsercion = lower_bound(calificaciones, calificaciones + n, nuevo);
    int idxInsercion = posInsercion - calificaciones;
    
    cout << "Para mantener el orden, un estudiante con " << nuevo << " debe ir en la posición " << idxInsercion << endl;
    cout << "   (antes del " << calificaciones[idxInsercion] << ")" << endl;
    
    // Mostrar cómo quedaría
    cout << "\n   Arreglo actual: ";
    for (int i = 0; i < n; i++) cout << calificaciones[i] << " ";
    cout << "\n   Con inserción:  ";
    for (int i = 0; i < n; i++) {
        if (i == idxInsercion) cout << nuevo << " ";
        cout << calificaciones[i] << " ";
    }
    cout << endl;
    
    return 0;
}