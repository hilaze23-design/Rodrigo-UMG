#include <iostream>
using namespace std;

// --- PROTOTIPOS DE FUNCIONES ---
// Se declaran aquí para que el compilador las reconozca antes del main [00:16:42]
int suma(int num1, int num2);
int suma(int num1, int num2, int num3); // Sobrecarga de métodos [00:07:34]
void sumaMetodo(int &num1, int &num2);  // Método con paso por referencia [00:14:15]

int main() {
    int a = 10;
    int b = 20;

    // 1. Llamada a función simple (Retorna valor) [00:04:12]
    cout << "Suma simple (2 parametros): " << suma(a, b) << endl;

    // 2. Llamada a función sobrecargada (3 parametros) [00:07:46]
    cout << "Suma sobrecargada (3 parametros): " << suma(10, 20, 30) << endl;

    // 3. Llamada a método (Uso de referencia &) [00:14:28]
    // Al pasar por referencia, los valores originales de 'a' y 'b' cambiarán.
    cout << "\nValores originales: a = " << a << ", b = " << b << endl;
    sumaMetodo(a, b);
    cout << "Valores despues del metodo (referencia): a = " << a << ", b = " << b << endl;

    return 0;
}

// --- DEFINICIÓN DE LAS FUNCIONES ---

// Función que retorna un entero [00:03:56]
int suma(int num1, int num2) {
    int resultado = num1 + num2;
    return resultado;
}

// Sobrecarga: misma función pero con 3 parámetros [00:06:38]
int suma(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

// Método (void): no retorna valor y modifica los originales por referencia [00:09:23]
void sumaMetodo(int &num1, int &num2) {
    num1 += 1; // Incrementa el valor original [00:12:06]
    num2 += 1;
    int resultado = num1 + num2;
    cout << "Resultado calculado dentro del metodo: " << resultado << endl;
}