#include "GameMenuPrinter.h"

GameMenuPrinter::GameMenuPrinter()
{
}

GameMenuPrinter::~GameMenuPrinter()
{
}

void GameMenuPrinter::PrintGameMainMenu()	//print game menu
{
	std::cout << msg.mainMenu;
}

void GameMenuPrinter::PrintGameIntroMsg()	//print game intro message
{
	std::cout << msg.gameIntro << std::endl;
}

void GameMenuPrinter::PrintGameResult(const int& index, const int& result)	//print comparation result
{
	
	std::cout << msg.result[index] << result << std::endl;
}

void GameMenuPrinter::PrintGameReport(const int& index, const int& count)	//print total game report
{
	std::cout << msg.report[index] << count << std::endl;
}
