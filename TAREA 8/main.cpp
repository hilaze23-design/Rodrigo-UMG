#include <iostream>
#include <string>
#include "Estudiante.h"

using namespace std;

void menu() {
    cout << "\n--- MENU CRUD ESTUDIANTES ---" << endl;
    cout << "1. Leer Estudiantes" << endl;
    cout << "2. Crear Estudiante" << endl;
    cout << "3. Actualizar Estudiante" << endl;
    cout << "4. Eliminar Estudiante" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    int opcion;
    string codigo, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono, id_tipo_sangre, id_estudiante;
    Estudiante e = Estudiante();

    do {
        menu();
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer

        switch (opcion) {
        case 1:
            e.leer();
            break;
        case 2:
            cout << "Codigo: "; cin >> codigo; cin.ignore();
            cout << "Nombres: "; getline(cin, nombres);
            cout << "Apellidos: "; getline(cin, apellidos);
            cout << "Direccion: "; getline(cin, direccion);
            cout << "Telefono: "; cin >> telefono;
            cout << "Fecha Nacimiento (YYYY-MM-DD): "; cin >> fecha_nacimiento;
            cout << "ID Tipo Sangre: "; cin >> id_tipo_sangre;
            e = Estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, codigo, 0);
            e.crear();
            break;
        case 3:
            e.leer();
            cout << "Ingrese ID a modificar: "; cin >> id_estudiante; cin.ignore();
            cout << "Nuevo Codigo: "; cin >> codigo; cin.ignore();
            cout << "Nuevos Nombres: "; getline(cin, nombres);
            cout << "Nuevos Apellidos: "; getline(cin, apellidos);
            cout << "Nueva Direccion: "; getline(cin, direccion);
            cout << "Nuevo Telefono: "; cin >> telefono;
            cout << "Nueva Fecha Nac. (YYYY-MM-DD): "; cin >> fecha_nacimiento;
            cout << "Nuevo ID Tipo Sangre: "; cin >> id_tipo_sangre;
            e.setIdEstudiante(id_estudiante);
            e.setCodigo(codigo);
            e.setNombres(nombres);
            e.setApellidos(apellidos);
            e.setDireccion(direccion);
            e.setTelefono(telefono);
            e.setFechaNacimiento(fecha_nacimiento);
            e.setIdTipoSangre(id_tipo_sangre);
            e.actualizar();
            break;
        case 4:
            e.leer();
            cout << "Ingrese ID a eliminar: "; cin >> id_estudiante;
            e.setIdEstudiante(id_estudiante);
            e.borrar();
            break;
        }
    } while (opcion != 5);

    return 0;
}