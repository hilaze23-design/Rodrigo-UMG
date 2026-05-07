#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Persona.h"
#include "ConexionBD.h"

using namespace std;

class Estudiante : Persona {
private:
    string codigo;
    int id_estudiante = 0;

public:
    Estudiante() {}
    Estudiante(string nom, string ape, string dir, int tel, string fn, int id_ts, string cod, int id)
        : Persona(nom, ape, dir, tel, fn, id_ts) {
        codigo = cod;
        id_estudiante = id;
    }

    // Métodos Set para modificar atributos individualmente
    void setIdEstudiante(int id) { id_estudiante = id; }
    void setCodigo(string cod) { codigo = cod; }
    void setNombres(string nom) { nombres = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setDireccion(string dir) { direccion = dir; }
    void setTelefono(int tel) { telefono = tel; }
    void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
    void setIdTipoSangre(int id_ts) { id_tipo_sangre = id_ts; }

    // --- MÉTODOS CRUD ---

    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string t = to_string(telefono);
            string ts = to_string(id_tipo_sangre);
            string insertar = "INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "'," + ts + ");";
            const char* i = insertar.c_str();
            q_estado = mysql_query(cn.getConector(), i);
            if (!q_estado) cout << "Ingreso Exitoso..." << endl;
            else cout << "Error al ingresar: " << mysql_error(cn.getConector()) << endl;
        }
        cn.cerrar_conexion();
    }

    void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConector()) {
            string consulta = "SELECT e.id_estudiante, e.codigo, e.nombres, e.apellidos, e.direccion, e.telefono, e.fecha_nacimiento, s.sangre FROM estudiantes e INNER JOIN tipos_sangre s ON e.id_tipo_sangre = s.id_tipo_sangre;";
            const char* c = consulta.c_string();
            q_estado = mysql_query(cn.getConector(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConector());
                cout << "----------------------- ESTUDIANTES -----------------------" << endl;
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " " << fila[3] << " | " << fila[4] << " | " << fila[7] << endl;
                }
                cout << "-----------------------------------------------------------" << endl;
            }
        }
        cn.cerrar_conexion();
    }

    void actualizar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string t = to_string(telefono);
            string ts = to_string(id_tipo_sangre);
            string id = to_string(id_estudiante);
            string actualizar = "UPDATE estudiantes SET codigo = '" + codigo + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + t + ", fecha_nacimiento = '" + fecha_nacimiento + "', id_tipo_sangre = " + ts + " WHERE id_estudiante = " + id + ";";
            const char* i = actualizar.c_str();
            q_estado = mysql_query(cn.getConector(), i);
            if (!q_estado) cout << "Actualizacion Exitosa..." << endl;
            else cout << "Error al actualizar..." << endl;
        }
        cn.cerrar_conexion();
    }

    void borrar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConector()) {
            string id = to_string(id_estudiante);
            string borrar = "DELETE FROM estudiantes WHERE id_estudiante = " + id + ";";
            const char* i = borrar.c_str();
            q_estado = mysql_query(cn.getConector(), i);
            if (!q_estado) cout << "Eliminacion Exitosa..." << endl;
            else cout << "Error al eliminar..." << endl;
        }
        cn.cerrar_conexion();
    }
};