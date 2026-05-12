#include <iostream>
#include <string>
#include "Estudiante.h"

using namespace std;

int main() {
    int opcion;
    Estudiante e = Estudiante();

    do {
        cout << "\n--- SISTEMA DE CONTROL ESCOLAR (CRUD) ---" << endl;
        cout << "1. Listar Estudiantes\n2. Ingresar Nuevo\n3. Actualizar\n4. Eliminar\n5. Salir\nOpcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 2 || opcion == 3) {
            string cod, nom, ape, dir, fn;
            int tel, ts, id = 0;

            if (opcion == 3) {
                cout << "ID Estudiante a modificar: "; cin >> id; cin.ignore();
            }

            cout << "Codigo (Ej: E001): "; cin >> cod; cin.ignore();
            cout << "Nombres: "; getline(cin, nom);
            cout << "Apellidos: "; getline(cin, ape);
            cout << "Direccion: "; getline(cin, dir);
            cout << "Telefono (8 digitos): "; cin >> tel;
            cout << "Fecha Nac. (AAAA-MM-DD): "; cin >> fn;
            cout << "ID Tipo Sangre: "; cin >> ts;

            e.setIdEstudiante(id);
            e.setCodigo(cod);
            e.setNombres(nom);
            e.setApellidos(ape);
            e.setDireccion(dir);
            e.setTelefono(tel);
            e.setFechaNacimiento(fn);
            e.setIdTipoSangre(ts);

            if (opcion == 2) e.crear();
            else e.actualizar();

        } else if (opcion == 1) {
            e.leer();
        } else if (opcion == 4) {
            int id;
            cout << "ID Estudiante a eliminar: "; cin >> id;
            e.setIdEstudiante(id);
            e.borrar();
        }

    } while (opcion != 5);

    return 0;
}