#include<iostream>

using namespace std;

int main(){
    // Definimos una variable normal
    int edad = 25;
    
    // Declaramos un puntero (se usa el asterisco *)
    // El puntero debe ser del mismo tipo que la variable a la que apunta
    int *ptr_edad; 

    // Asignamos la dirección de memoria de 'edad' al puntero
    // El símbolo '&' es el operador de dirección
    ptr_edad = &edad;

    cout << "--- Primeros valores ---" << endl;
    cout << "Valor de edad: " << edad << endl; // Muestra 25
    cout << "Direccion de memoria de edad: " << &edad << endl;
    cout << "Contenido del puntero (valor al que apunta): " << *ptr_edad << endl; // El '*' aquí obtiene el valor
    cout << "Direccion almacenada en el puntero: " << ptr_edad << endl;

    // --- Cambiando el valor a través de la variable ---
    edad = 40;
    cout << "\n--- Tras cambiar edad a 40 ---" << endl;
    cout << "Variable edad: " << edad << endl;
    cout << "Puntero (*ptr_edad): " << *ptr_edad << endl; // Cambia automáticamente porque apunta a la misma memoria

    // --- Cambiando el valor a través del puntero ---
    *ptr_edad = 80; // Modificamos el contenido de la dirección de memoria
    cout << "\n--- Tras cambiar el valor usando el puntero (*ptr_edad = 80) ---" << endl;
    cout << "Variable edad: " << edad << endl; // La variable original ahora vale 80
    cout << "Puntero (*ptr_edad): " << *ptr_edad << endl;

    // --- Apuntando a una nueva variable ---
    int edad2 = 100;
    ptr_edad = &edad2; // El puntero ahora apunta a una dirección física distinta
    
    cout << "\n--- Tras apuntar a edad2 ---" << endl;
    cout << "Puntero (*ptr_edad): " << *ptr_edad << endl; // Ahora muestra 100
    cout << "Variable edad original: " << edad << endl;   // Sigue valiendo 80 (ya no están ligados)

    return 0;
}