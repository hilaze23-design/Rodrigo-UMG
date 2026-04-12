#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;

// Nombre del archivo constante
const char *nombre_archivo = "archivo.dat";

struct Estudiante {
    int codigo;
    char nombres[50];
    char apellidos[50];
    int telefono;
};

// Prototipos de funciones
void crear();
void leer();

int main() {
    leer();   // Primero lee lo que ya existe
    crear();  // Luego permite ingresar nuevos datos
    
    return 0;
}

void leer() {
    system("cls"); // Limpia la pantalla
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        archivo = fopen(nombre_archivo, "w+b");
    }

    Estudiante estudiante;
    int id = 0; // Índice o posición del registro

    // Encabezados de la tabla
    cout << "____________________________________________________________________" << endl;
    cout << "ID" << " | " << "CODIGO" << " | " << "NOMBRES" << " | " << "APELLIDOS" << " | " << "TELEFONO" << endl;

    // Leer el primer registro
    fread(&estudiante, sizeof(Estudiante), 1, archivo);

    do {
        cout << id << " | " << estudiante.codigo << " | " << estudiante.nombres << " | " << estudiante.apellidos << " | " << estudiante.telefono << endl;
        fread(&estudiante, sizeof(Estudiante), 1, archivo);
        id += 1;
    } while (feof(archivo) == 0);

    fclose(archivo);
}

void crear() {
    char respuesta;
    FILE* archivo = fopen(nombre_archivo, "ab"); // "ab" abre o crea para añadir datos
    Estudiante estudiante;

    do {
        fflush(stdin); // Limpiar el flujo de entrada
        cout << "Ingrese Codigo: ";
        cin >> estudiante.codigo;
        cin.ignore(); // Limpiar el buffer para usar getline

        cout << "Ingrese Nombres: ";
        cin.getline(estudiante.nombres, 50);

        cout << "Ingrese Apellidos: ";
        cin.getline(estudiante.apellidos, 50);

        cout << "Ingrese Telefono: ";
        cin >> estudiante.telefono;

        // Escribir en el archivo
        fwrite(&estudiante, sizeof(Estudiante), 1, archivo);

        cout << "Desea ingresar otro estudiante (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    fclose(archivo);
    leer(); // Mostrar los datos actualizados
}