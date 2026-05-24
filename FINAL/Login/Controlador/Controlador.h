#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient; // 'M' mayúscula corregida

namespace Controlador {
	public ref class ConnectionToSql
	{
	public:
		static String^ connectionString;
		ConnectionToSql();
		MySqlConnection^ GetConnection();
	};

	// Cambiado a UserDao con D mayúscula para que coincida con el .cpp
	public ref class UserDao : public ConnectionToSql {
	public:
		bool Login(String^, String^);
	};
}