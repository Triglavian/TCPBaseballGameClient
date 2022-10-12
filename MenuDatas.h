#pragma once
#include <string>
#include <Vector>
#include "MenuId.h"

class MenuDatas
{
public:
	MenuDatas();
	~MenuDatas();
	std::string mainMenu;
	std::vector<std::string> registrationMenu;
	std::vector<std::string> loginMenu;
	std::vector<std::string> login;	
private:
};

