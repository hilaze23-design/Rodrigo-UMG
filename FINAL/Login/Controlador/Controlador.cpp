#include "pch.h"
#include "Controlador.h"

Controlador::ConnectionToSql::ConnectionToSql()
{
    // Tu cadena de conexión que ya funciona perfecto
    connectionString = "server=localhost;port=3306;user=root;password=12345;database=facturas";
}

MySqlConnection^ Controlador::ConnectionToSql::GetConnection()
{
    return gcnew MySqlConnection(connectionString);
}

bool Controlador::UserDao::Login(String^ user, String^ password)
{
    MySqlConnection^ connection = GetConnection();
    connection->Open();
    MySqlCommand^ cursor = gcnew MySqlCommand();
    cursor->Connection = connection;
    
    // 1. Buscamos solo por usuario en la tabla 'usuarios' para no arriesgar el Query
    cursor->CommandText = "select * from usuarios where usuario='" + user + "'";
    
    MySqlDataReader^ reader = cursor->ExecuteReader();
    if (reader->Read()) { 
        // 2. EXTRAEMOS usando el nombre real que tiene tu columna en Workbench: "contrasena"
        String^ contraBD = reader["contrasenia"]->ToString();
        
        // 3. Comparamos los textos a mano dentro de C++
        if (contraBD == password) {
            connection->Close();
            return true;
        }
    }
    
    connection->Close();
    return false;
}