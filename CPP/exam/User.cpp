#include "User.h"

User::User()
{	
}

User::User(std::string login, std::string password)	
{	
	m_login = login;
	m_password = password;
	m_accountType = "User";
}