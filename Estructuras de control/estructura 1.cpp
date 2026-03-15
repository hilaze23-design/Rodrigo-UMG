#include <iostream>
using namespace std;

int main() {
    char respuesta;

    // El DO-WHILE ejecuta el bloque primero, y evalúa la condición al final.
    do {
        cout << "Desea ingresar otro valor (s/n): ";
        cin >> respuesta;
        
    } while(respuesta == 's' || respuesta == 'S'); // || significa OR (O lógico)

    return 0;
}