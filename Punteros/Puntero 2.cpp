#include<iostream>

using namespace std;

int main(){
    int filas, col;
    // Puntero doble para una matriz dinámica (Fila x Columna)
    int **pm_notas; 

    cout << "--- Gestion de Estudiantes y Notas (Matriz Dinamica) ---" << endl;
    cout << "Ingrese la cantidad de estudiantes (filas): ";
    cin >> filas;
    cout << "Ingrese la cantidad de notas por estudiante (columnas): ";
    cin >> col;

    // 1. Asignar memoria dinámica para las FILAS
    // Creamos un arreglo de punteros a enteros
    pm_notas = new int*[filas];

    // 2. Asignar memoria dinámica para las COLUMNAS de cada fila
    for(int i=0; i<filas; i++){
        pm_notas[i] = new int[col];
    }

    // 3. Rellenar la matriz dinámica
    cout << "\n--- Ingreso de Datos ---" << endl;
    for(int i=0; i<filas; i++){
        for(int j=0; j<col; j++){
            cout << "Estudiante [" << i << "], Nota [" << j << "]: ";
            // Acceso al contenido usando la aritmética de punteros
            cin >> *(*(pm_notas + i) + j); 
        }
        cout << "-----------------------" << endl;
    }

    // 4. Mostrar los datos almacenados
    cout << "\n--- Notas Almacenadas ---" << endl;
    for(int i=0; i<filas; i++){
        cout << "Estudiante " << i << ": ";
        for(int j=0; j<col; j++){
            cout << *(*(pm_notas + i) + j) << " ";
        }
        cout << endl;
    }

    // 5. LIBERAR MEMORIA (Crucial en C++ para evitar Memory Leaks)
    // Primero liberamos cada columna (el arreglo interno)
    for(int i=0; i<filas; i++){
        delete[] pm_notas[i];
    }
    // Luego liberamos el puntero de las filas
    delete[] pm_notas;

    cout << "\nMemoria liberada correctamente." << endl;

    return 0;
}