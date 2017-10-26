#include "Account.h"

std::string Account::GetLogin() const
{
	return m_login;
}

std::string Account::GetPassword() const
{
	return m_password;
}

std::string Account::GetAccountType() const
{
	return m_accountType;
}

bool Account::CheckPassword(std::string password) const
{
	return m_password == password;
}