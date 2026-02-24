#ifndef PERSONA_CPP
#define PERSONA_CPP

#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string cui, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    bool genero;

public:
    Persona() {}
    Persona(string _cui, string _nombres, string _apellidos, string _dir, int _tel, string _fecha, bool _gen) {
        cui = _cui; nombres = _nombres; apellidos = _apellidos;
        direccion = _dir; telefono = _tel; fecha_nacimiento = _fecha; genero = _gen;
    }

    void crear() { cout << "Registro de " << nombres << " creado.\n"; }
    void leer() {
        cout << "\n--- DATOS PERSONALES ---\nCUI: " << cui << "\nNombre: " << nombres << " " << apellidos << endl;
    }
};
#endif