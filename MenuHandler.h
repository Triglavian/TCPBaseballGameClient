#pragma once
#include <string>
#include <functional>
#include "MenuId.h"
#include "MenuPrinter.h"

class MenuHandler
{
public:
	MenuHandler();
	~MenuHandler();
	void MainMenu();
	void RegistrationMenu(const int& index);
	void LogIn(const int& index);
private:
	MenuPrinter menuPrinter;
};