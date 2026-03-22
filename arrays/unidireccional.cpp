#include<iostream>

using namespace std;

int main(){
    // Definimos el arreglo
    int numeros[] = {1, 2, 3, 4, 5};
    int suma = 0;

    // Recorremos el arreglo
    for(int i=0; i<5; i++){
        suma += numeros[i];
    }

    cout << "La suma de los elementos del arreglo es: " << suma << endl;

    // En lugar de getch(), usamos cin.get() que es estándar
    // O simplemente omitimos la pausa si tu IDE mantiene la consola abierta
    cin.get(); 
    return 0;
}
