#include "MenuPrinter.h"

MenuPrinter::MenuPrinter()
{

}

MenuPrinter::~MenuPrinter()
{
	
}

void MenuPrinter::PrintMainMenu()	//print main menu
{
	std::cout << msg.mainMenu;	
}

void MenuPrinter::PrintRegistrationMenu(const int& index)	//print registration menu announce message
{
	if (index > msg.registrationMenu.size() - 1 || index < 0) 
	{
		std::cout << "registration menu index error, index = " << index << std::endl;
		return;
	}
	std::cout << msg.registrationMenu[index] << std::endl;
}

void MenuPrinter::PrintLoginMenu(const int& index)	//print log in menu announce message
{
	if (index > msg.registrationMenu.size() - 1 || index < 0)
	{
		std::cout << "login menu index error, index = " << index << std::endl;
		return;
	}
	std::cout << msg.loginMenu[index] << std::endl;
}

void MenuPrinter::PrintLoginResult(const int& index)	//print log in result
{
	std::cout << msg.login[index] << std::endl;
}