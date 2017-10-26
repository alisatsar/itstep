#pragma once
#include <string>
#include <iostream>

class Account
{
protected:
	std::string m_login;
	std::string m_password;
	std::string m_accountType;

public:
	~Account() = default;
	std::string GetLogin() const;
	std::string GetPassword() const;
	std::string GetAccountType() const;
	bool CheckPassword(std::string password) const;
};
