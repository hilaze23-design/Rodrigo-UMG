/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author carlos.mendez
 */
//NOMBRE: Carlos Alberto Mendez Giron
//CARNET: 4820-25-11347
public class Cliente extends Persona {

    Conexion cn;
    private int id;
    private String nit;

    public Cliente() {
    }

    public Cliente(int id, String nit, String cui, String nombres, String apellidos, String direccion, String telefono, String fecha_nacimiento) {
        super(cui, nombres, apellidos, direccion, telefono, fecha_nacimiento);
        this.id = id;
        this.nit = nit;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNit() {
        return nit;
    }

    public void setNit(String nit) {
        this.nit = nit;
    }

    /**
     * PUNTO 2: solo se muestran los clientes activos (activo = 1).
     * Los registros dados de baja logicamente (activo = 0) ya no aparecen.
     */
    @Override
    public DefaultTableModel leer() {
        DefaultTableModel tabla = new DefaultTableModel();
        try {
            cn = new Conexion();
            cn.abrir_conexion();

            // ANTES: String query = "SELECT * FROM clientes;";
            String query = "SELECT id_cliente, cui, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento "
                         + "FROM clientes WHERE activo = 1 ORDER BY id_cliente;";

            ResultSet consulta = cn.conexionBD.createStatement().executeQuery(query);

            String encabezado[] = {
                "id_cliente", "CUI", "NIT", "Nombres", "Apellidos", "Direccion", "Telefono", "Fecha Nacimiento"
            };
            tabla.setColumnIdentifiers(encabezado);

            while (consulta.next()) {
                String datos[] = new String[8];
                datos[0] = consulta.getString("id_cliente");
                datos[1] = consulta.getString("cui");
                datos[2] = consulta.getString("nit");
                datos[3] = consulta.getString("nombres");
                datos[4] = consulta.getString("apellidos");
                datos[5] = consulta.getString("direccion");
                datos[6] = consulta.getString("telefono");
                datos[7] = consulta.getString("fecha_nacimiento");
                tabla.addRow(datos);
            }

            cn.cerrar_conexion();
        } catch (SQLException ex) {
            System.out.println("Error: " + ex.getMessage());
        }
        return tabla;
    }

    /**
     * PUNTO 3: al crear un cliente se asignan automaticamente desde el INSERT:
     *   activo                 = 1
     *   fecha_ingreso_registro = NOW()
     *   fecha_eliminacion      = NULL
     * Estos valores NO se piden al usuario en el formulario.
     */
    @Override
    public void crear() {
        try {
            PreparedStatement parametro;
            cn = new Conexion();
            cn.abrir_conexion();

            // ANTES: insert into clientes(cui,nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) values (?,?,?,?,?,?,?);
            String query = "INSERT INTO clientes "
                         + "(cui, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento, activo, fecha_ingreso_registro, fecha_eliminacion) "
                         + "VALUES (?, ?, ?, ?, ?, ?, ?, 1, NOW(), NULL);";

            parametro = cn.conexionBD.prepareStatement(query);
            parametro.setString(1, this.getCui());
            parametro.setString(2, this.getNit());
            parametro.setString(3, this.getNombres());
            parametro.setString(4, this.getApellidos());
            parametro.setString(5, this.getDireccion());
            parametro.setString(6, this.getTelefono());
            parametro.setString(7, this.getFecha_nacimiento());
            parametro.executeUpdate();

            cn.cerrar_conexion();
        } catch (SQLException ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }

    /**
     * Solo se permite actualizar clientes que sigan activos.
     */
    @Override
    public void actualizar() {
        try {
            PreparedStatement parametro;
            cn = new Conexion();
            cn.abrir_conexion();

            String query = "UPDATE clientes SET cui = ?, nit = ?, nombres = ?, apellidos = ?, "
                         + "direccion = ?, telefono = ?, fecha_nacimiento = ? "
                         + "WHERE id_cliente = ? AND activo = 1;";

            parametro = cn.conexionBD.prepareStatement(query);
            parametro.setString(1, this.getCui());
            parametro.setString(2, this.getNit());
            parametro.setString(3, this.getNombres());
            parametro.setString(4, this.getApellidos());
            parametro.setString(5, this.getDireccion());
            parametro.setString(6, this.getTelefono());
            parametro.setString(7, this.getFecha_nacimiento());
            parametro.setInt(8, this.getId());
            parametro.executeUpdate();

            cn.cerrar_conexion();
        } catch (SQLException ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }

    /**
     * PUNTO 4: eliminacion LOGICA.
     * Ya no se borra fisicamente el registro con DELETE; se hace un UPDATE que
     * pone activo = 0 y guarda la fecha y hora exacta en fecha_eliminacion con NOW().
     */
    @Override
    public void borrar() {
        try {
            PreparedStatement parametro;
            cn = new Conexion();
            cn.abrir_conexion();

            // ELIMINACION FISICA - METODO ANTERIOR (ya no se usa)
            // String query = "DELETE FROM clientes WHERE id_cliente = ?;";

            // ELIMINACION LOGICA - METODO ACTUAL
            String query = "UPDATE clientes SET activo = 0, fecha_eliminacion = NOW() "
                         + "WHERE id_cliente = ? AND activo = 1;";

            parametro = cn.conexionBD.prepareStatement(query);
            parametro.setInt(1, this.getId());
            parametro.executeUpdate();

            cn.cerrar_conexion();
        } catch (SQLException ex) {
            System.out.println("Error: " + ex.getMessage());
        }
    }
}
