#include "Manager.h"

Manager::Manager()
{
	m_accountType = "Manager";
}

Manager::Manager(std::string login, std::string password, bool seniorManager)
{	
	m_login = login;
	m_password = password;
	m_accountType = "Manager";
	m_seniorManager = seniorManager;
}

bool Manager::GetSeniorManager() const
{
	return m_seniorManager;
}
