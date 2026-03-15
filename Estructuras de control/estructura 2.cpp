#include <iostream>
using namespace std;

int main() {
    int inicio = 0, fin = 0, resultado = 0;

    cout << "Ingrese tabla inicial: ";
    cin >> inicio;
    cout << "Ingrese tabla final: ";
    cin >> fin;

    // FOR PRINCIPAL (Externo): Controla qué tabla estamos viendo actualmente
    // La variable 'rango' empieza en el número de inicio y termina en el número final.
    for(int rango = inicio; rango <= fin; rango++) {
        
        cout << "\nTabla del " << rango << endl;
        cout << "------------" << endl;

        // FOR SECUNDARIO (Interno): Genera las multiplicaciones del 1 al 10
        // Por cada vuelta que da el for principal, este for interno da 10 vueltas completas.
        for(int i = 1; i <= 10; i++) {
            resultado = rango * i;
            // Imprime en formato: 5 X 1 = 5
            cout << rango << " X " << i << " = " << resultado << endl;
        }
        
    } 

    return 0;
}