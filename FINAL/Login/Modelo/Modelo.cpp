#include "pch.h"
#include "Modelo.h"

// Este código ya está bien, solo necesitaba que el .h tuviera las mismas mayúsculas
bool Modelo::UserModel::LoginUser(String^ user, String^ password)
{
    return this->userDao->Login(user, password);
}