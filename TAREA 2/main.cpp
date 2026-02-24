#include <iostream>
#include "Docente.cpp"
#include "Estudiante.cpp"

using namespace std;

int main() {
    Docente d1("123", "Carlos", "Lopez", "Zona 1", 555, "1980", true, "D01", "123-7", 5000.50, "Ingeniero");
    Estudiante e1("987", "Maria", "Perez", "Zona 5", 777, "2005", false, "202401");

    d1.crear();
    d1.leer();
    cout << "\n--------------------\n";
    e1.crear();
    e1.leer();

    return 0;
}

