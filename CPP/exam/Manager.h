#pragma once
#include <string>
#include <iostream>
#include "Account.h"

class Manager : public Account
{
private:
	bool m_seniorManager = false;
public:
	Manager();
	~Manager() = default;
	Manager(std::string login, std::string password, bool seniorManager);	
	bool GetSeniorManager() const;	
};
