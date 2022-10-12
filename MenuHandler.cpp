#include "MenuHandler.h"

MenuHandler::MenuHandler()
{	

}

MenuHandler::~MenuHandler()
{

}

void MenuHandler::MainMenu()
{
	menuPrinter.PrintMainMenu();
}

/// <summary>
/// index 0 = input id msg
/// index 1 = input pw msg
/// </summary>
/// <param name="index"></param>
void MenuHandler::RegistrationMenu(const int& index)
{
	menuPrinter.PrintRegistrationMenu(index);
}

/// <summary>
/// index 0 = login success
/// index 1 = login fail
/// </summary>
/// <param name="index"></param>
void MenuHandler::LogIn(const int& index)
{
	menuPrinter.PrintLoginResult(index);
}