#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    int *codigo;       // Puntero para arreglo de códigos
    string *nombre;    // Puntero para arreglo de nombres
    int **notas;       // Puntero doble para matriz de notas (filas x columnas)
} estudiante;

int main() {
    int fila = 0, columna = 0;

    cout << "Cuantos estudiantes desea agregar: ";
    cin >> fila;
    cout << "Cuantas notas por estudiante desea agregar: ";
    cin >> columna;

    // Asignación de memoria dinámica [00:12:30]
    estudiante.codigo = new int[fila];
    estudiante.nombre = new string[fila];
    estudiante.notas = new int*[fila]; // Arreglo de punteros para la matriz

    for (int i = 0; i < fila; i++) {
        estudiante.notas[i] = new int[columna]; // Asignación de columnas por cada fila [00:14:27]
    }

    // Ingreso de datos (Recorrido de filas y columnas) [00:15:43]
    for (int i = 0; i < fila; i++) {
        cout << "\n--- Estudiante " << i << " ---" << endl;
        cout << "Codigo: ";
        cin >> estudiante.codigo[i];
        
        cin.ignore();
        cout << "Nombre completo: ";
        getline(cin, estudiante.nombre[i]);

        for (int j = 0; j < columna; j++) {
            cout << "Ingrese nota " << j + 1 << ": ";
            cin >> estudiante.notas[i][j];
        }
    }

    // Mostrar resultados [00:22:02]
    cout << "\n\n--- REPORTE DE NOTAS ---" << endl;
    for (int i = 0; i < fila; i++) {
        cout << "Codigo: " << estudiante.codigo[i] << " | Nombre: " << estudiante.nombre[i] << endl;
        for (int j = 0; j < columna; j++) {
            cout << "  Nota [" << j + 1 << "]: " << estudiante.notas[i][j] << endl;
        }
    }

    // Liberar memoria (Importante en punteros) [00:24:25]
    for (int i = 0; i < fila; i++) {
        delete[] estudiante.notas[i];
    }
    delete[] estudiante.notas;
    delete[] estudiante.codigo;
    delete[] estudiante.nombre;

    return 0;
}