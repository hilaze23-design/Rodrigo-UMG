#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;

const char *nombre_archivo = "archivo.dat";

struct Estudiante {
    int codigo;
    char nombres[50];
    char apellidos[50];
    int telefono;
};

// Prototipos de funciones
void leer();
void crear();
void actualizar();
void borrar();

int main() {
    leer();
    // crear(); // Descomentar para agregar registros
    // actualizar(); // Descomentar para modificar un registro por su ID
    borrar(); // Descomentar para eliminar un registro
    return 0;
}

void leer() {
    system("cls");
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        archivo = fopen(nombre_archivo, "w+b");
    }

    Estudiante estudiante;
    int id = 0;
    cout << "____________________________________________________________________" << endl;
    cout << "ID" << " | " << "CODIGO" << " | " << "NOMBRES" << " | " << "APELLIDOS" << " | " << "TELEFONO" << endl;

    fread(&estudiante, sizeof(Estudiante), 1, archivo);
    while (feof(archivo) == 0) {
        cout << id << " | " << estudiante.codigo << " | " << estudiante.nombres << " | " << estudiante.apellidos << " | " << estudiante.telefono << endl;
        fread(&estudiante, sizeof(Estudiante), 1, archivo);
        id += 1;
    };
    fclose(archivo);
}

void crear() {
    char respuesta;
    FILE* archivo = fopen(nombre_archivo, "ab");
    Estudiante estudiante;
    do {
        fflush(stdin);
        cout << "Ingrese Codigo: ";
        cin >> estudiante.codigo;
        cin.ignore();
        cout << "Ingrese Nombres: ";
        cin.getline(estudiante.nombres, 50);
        cout << "Ingrese Apellidos: ";
        cin.getline(estudiante.apellidos, 50);
        cout << "Ingrese Telefono: ";
        cin >> estudiante.telefono;

        fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
        cout << "Desea ingresar otro estudiante (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');
    fclose(archivo);
    leer();
}

void actualizar() {
    FILE* archivo = fopen(nombre_archivo, "r+b"); // r+b para lectura y escritura
    int id;
    Estudiante estudiante;
    cout << "Ingrese el ID que desea modificar: ";
    cin >> id;

    // FSEEK posiciona el puntero en el registro exacto usando el tamaño de la estructura
    fseek(archivo, id * sizeof(Estudiante), SEEK_SET);

    cout << "Ingrese Codigo: ";
    cin >> estudiante.codigo;
    cin.ignore();
    cout << "Ingrese Nombres: ";
    cin.getline(estudiante.nombres, 50);
    cout << "Ingrese Apellidos: ";
    cin.getline(estudiante.apellidos, 50);
    cout << "Ingrese Telefono: ";
    cin >> estudiante.telefono;

    fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
    fclose(archivo);
    leer();
}

void borrar() {
    const char *nombre_archivo_temp = "archivo_temp.dat";
    FILE* archivo_temp = fopen(nombre_archivo_temp, "w+b");
    FILE* archivo = fopen(nombre_archivo, "rb");
    Estudiante estudiante;
    int id_eliminar, id_actual = 0;

    cout << "Ingrese el ID a eliminar: ";
    cin >> id_eliminar;

    while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
        if (id_actual != id_eliminar) {
            fwrite(&estudiante, sizeof(Estudiante), 1, archivo_temp);
        }
        id_actual++;
    }

    fclose(archivo);
    fclose(archivo_temp);

    // Ahora pasamos los datos del temporal de vuelta al original (sobrescribiendo)
    archivo_temp = fopen(nombre_archivo_temp, "rb");
    archivo = fopen(nombre_archivo, "wb");

    while (fread(&estudiante, sizeof(Estudiante), 1, archivo_temp)) {
        fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
    }

    fclose(archivo);
    fclose(archivo_temp);
    leer();
}
