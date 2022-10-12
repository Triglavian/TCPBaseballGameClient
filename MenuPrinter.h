#pragma once
#include <iostream>
#include "MenuDatas.h"

class MenuPrinter
{
public:
	MenuPrinter();
	~MenuPrinter();
	void PrintMainMenu();
	void PrintRegistrationMenu(const int& index);
	void PrintLoginMenu(const int& index);
	void PrintLoginResult(const int& index);
private:
	MenuDatas msg;
};

