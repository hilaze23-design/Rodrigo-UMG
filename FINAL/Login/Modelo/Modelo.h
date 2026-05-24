#pragma once

using namespace System;
using namespace Controlador;

namespace Modelo {
	// Puesto en UserModel (M mayúscula) para que coincida con tu .cpp
	public ref class UserModel
	{
	public:
		// Puesto en UserDao (D mayúscula) y el objeto como userDao (D mayúscula)
		UserDao^ userDao = gcnew UserDao();
		bool LoginUser(String^, String^);
	}; // Se eliminó la llave duplicada que rompía el namespace
}