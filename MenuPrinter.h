#pragma once
#include <iostream>
#include "MenuDatas.h"

class MenuPrinter
{
public:
	MenuPrinter();
	~MenuPrinter();
	void PrintMainMenu();	//print main menu
	void PrintRegistrationMenu(const int& index);	//print registration menu announce message
	void PrintLoginMenu(const int& index);		//print log in menu announce message
	void PrintLoginResult(const int& index);	//print log in result
private:
	MenuDatas msg;
};

