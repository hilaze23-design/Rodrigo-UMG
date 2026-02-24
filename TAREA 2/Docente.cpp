#ifndef DOCENTE_CPP
#define DOCENTE_CPP

#include "Persona.cpp" 

class Docente : public Persona {
private:
    string codigo, nit, profesion;
    float salario;

public:
    Docente(string _cui, string _nom, string _ape, string _dir, int _tel, string _fec, bool _gen, 
            string _cod, string _nit, float _sal, string _prof)
        : Persona(_cui, _nom, _ape, _dir, _tel, _fec, _gen) {
        codigo = _cod; nit = _nit; salario = _sal; profesion = _prof;
    }

    void leer() {
        Persona::leer();
        cout << "--- DOCENTE ---\nCodigo: " << codigo << "\nSalario: " << salario << endl;
    }
};
#endif

