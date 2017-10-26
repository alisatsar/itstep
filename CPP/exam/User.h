#pragma once
#include <string>
#include <iostream>
#include "Account.h"

class User : public Account
{
public:
	User();
	~User() = default;	
	User(std::string login, std::string password);
};

