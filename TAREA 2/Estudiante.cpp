#ifndef ESTUDIANTE_CPP
#define ESTUDIANTE_CPP

#include "Persona.cpp" 

class Estudiante : public Persona {
private:
    string carnet;

public:
    Estudiante(string _cui, string _nom, string _ape, string _dir, int _tel, string _fec, bool _gen, string _car)
        : Persona(_cui, _nom, _ape, _dir, _tel, _fec, _gen) {
        carnet = _car;
    }

    void leer() {
        Persona::leer();
        cout << "--- ESTUDIANTE ---\nCarnet: " << carnet << endl;
    }
};
#endif