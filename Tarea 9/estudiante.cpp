#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include "Persona.h"
#include "ConexionBD.h"

using namespace std;

class Estudiante : Persona {
private:
    string codigo;
    int id_estudiante = 0;

    // --- FUNCIONES DE VALIDACIÓN PRIVADAS ---

    string sanitizar(string texto) {
        // Evita inyección SQL básica escapando comillas simples
        string resultado = "";
        for (char c : texto) {
            if (c == '\'') resultado += "''";
            else resultado += c;
        }
        return resultado;
    }

    bool validarFormatoCodigo(string cod) {
        // Formato E001 a E999 (E seguido de 3 dígitos)
        return regex_match(cod, regex("^E[0-9]{3}$"));
    }

    bool validarSoloLetras(string texto) {
        // Solo letras y espacios, máximo 60 caracteres
        return texto.length() <= 60 && regex_match(texto, regex("^[a-zA-ZáéíóúÁÉÍÓÚñÑ\\s]+$"));
    }

    bool validarFecha(string fecha) {
        if (!regex_match(fecha, regex("^[0-9]{4}-[0-9]{2}-[0-9]{2}$"))) return false;

        // Comprobar que no sea una fecha futura
        time_t t = time(0);
        struct tm* now = localtime(&t);
        int anioActual = now->tm_year + 1900;
        int mesActual = now->tm_mon + 1;
        int diaActual = now->tm_mday;

        int a, m, d;
        sscanf(fecha.c_str(), "%d-%d-%d", &a, &m, &d);

        if (a > anioActual) return false;
        if (a == anioActual && m > mesActual) return false;
        if (a == anioActual && m == mesActual && d > diaActual) return false;

        // Validación básica de calendario
        if (m < 1 || m > 12 || d < 1 || d > 31) return false;
        return true;
    }

    bool existeCodigo(string cod, int id_actual = 0) {
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        bool existe = false;
        if (cn.getConector()) {
            string consulta = "SELECT count(*) FROM estudiantes WHERE codigo = '" + cod + "' AND id_estudiante <> " + to_string(id_actual) + ";";
            mysql_query(cn.getConector(), consulta.c_str());
            MYSQL_RES* res = mysql_store_result(cn.getConector());
            MYSQL_ROW fila = mysql_fetch_row(res);
            if (stoi(fila[0]) > 0) existe = true;
            mysql_free_result(res);
        }
        cn.cerrar_conexion();
        return existe;
    }

    bool existeTipoSangre(int id_ts) {
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        bool existe = false;
        if (cn.getConector()) {
            string consulta = "SELECT count(*) FROM tipos_sangre WHERE id_tipo_sangre = " + to_string(id_ts) + ";";
            mysql_query(cn.getConector(), consulta.c_str());
            MYSQL_RES* res = mysql_store_result(cn.getConector());
            MYSQL_ROW fila = mysql_fetch_row(res);
            if (stoi(fila[0]) > 0) existe = true;
            mysql_free_result(res);
        }
        cn.cerrar_conexion();
        return existe;
    }

public:
    Estudiante() {}
    Estudiante(string nom, string ape, string dir, int tel, string fn, int id_ts, string cod, int id)
        : Persona(nom, ape, dir, tel, fn, id_ts) {
        codigo = cod; id_estudiante = id;
    }

    // Setters
    void setIdEstudiante(int id) { id_estudiante = id; }
    void setCodigo(string cod) { codigo = cod; }
    void setNombres(string nom) { nombres = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setDireccion(string dir) { direccion = dir; }
    void setTelefono(int tel) { telefono = tel; }
    void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
    void setIdTipoSangre(int id_ts) { id_tipo_sangre = id_ts; }

    bool validarTodo() {
        if (!validarFormatoCodigo(codigo)) { cout << "[Error] Codigo invalido (E001-E999)." << endl; return false; }
        if (existeCodigo(codigo, id_estudiante)) { cout << "[Error] El codigo ya existe en la base de datos." << endl; return false; }
        if (!validarSoloLetras(nombres)) { cout << "[Error] Nombres invalidos (solo letras)." << endl; return false; }
        if (!validarSoloLetras(apellidos)) { cout << "[Error] Apellidos invalidos (solo letras)." << endl; return false; }
        if (direccion.empty() || direccion.length() > 100) { cout << "[Error] Direccion vacia o muy larga." << endl; return false; }
        if (!regex_match(to_string(telefono), regex("^[0-9]{8}$"))) { cout << "[Error] Telefono debe ser de 8 digitos." << endl; return false; }
        if (!validarFecha(fecha_nacimiento)) { cout << "[Error] Fecha invalida o futura (AAAA-MM-DD)." << endl; return false; }
        if (!existeTipoSangre(id_tipo_sangre)) { cout << "[Error] El Tipo de Sangre no existe." << endl; return false; }
        return true;
    }

    void crear() {
        if (!validarTodo()) return;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string consulta = "INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre) VALUES ('" + sanitizar(codigo) + "','" + sanitizar(nombres) + "','" + sanitizar(apellidos) + "','" + sanitizar(direccion) + "'," + to_string(telefono) + ",'" + fecha_nacimiento + "'," + to_string(id_tipo_sangre) + ");";
            if (!mysql_query(cn.getConector(), consulta.c_str())) cout << "Registro creado con exito." << endl;
            else cout << "Error al insertar." << endl;
        }
        cn.cerrar_conexion();
    }

    void leer() {
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string consulta = "SELECT e.id_estudiante, e.codigo, e.nombres, e.apellidos, s.sangre FROM estudiantes e JOIN tipos_sangre s ON e.id_tipo_sangre = s.id_tipo_sangre;";
            mysql_query(cn.getConector(), consulta.c_str());
            MYSQL_RES* res = mysql_store_result(cn.getConector());
            MYSQL_ROW fila;
            while (fila = mysql_fetch_row(res)) {
                cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " " << fila[3] << " | " << fila[4] << endl;
            }
            mysql_free_result(res);
        }
        cn.cerrar_conexion();
    }

    void actualizar() {
        if (id_estudiante <= 0) { cout << "ID no valido para actualizar." << endl; return; }
        if (!validarTodo()) return;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string consulta = "UPDATE estudiantes SET codigo='" + sanitizar(codigo) + "', nombres='" + sanitizar(nombres) + "', apellidos='" + sanitizar(apellidos) + "', direccion='" + sanitizar(direccion) + "', telefono=" + to_string(telefono) + ", fecha_nacimiento='" + fecha_nacimiento + "', id_tipo_sangre=" + to_string(id_tipo_sangre) + " WHERE id_estudiante=" + to_string(id_estudiante) + ";";
            if (!mysql_query(cn.getConector(), consulta.c_str())) cout << "Actualizacion exitosa." << endl;
        }
        cn.cerrar_conexion();
    }

    void borrar() {
        if (id_estudiante <= 0) return;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string consulta = "DELETE FROM estudiantes WHERE id_estudiante=" + to_string(id_estudiante) + ";";
            if (!mysql_query(cn.getConector(), consulta.c_str())) cout << "Registro eliminado." << endl;
        }
        cn.cerrar_conexion();
    }
};