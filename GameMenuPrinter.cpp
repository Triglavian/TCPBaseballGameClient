#include "GameMenuPrinter.h"

GameMenuPrinter::GameMenuPrinter()
{
}

GameMenuPrinter::~GameMenuPrinter()
{
}

void GameMenuPrinter::PrintGameMainMenu()
{
	std::cout << msg.mainMenu;
}

void GameMenuPrinter::PrintGameIntroMsg()
{
	std::cout << msg.gameIntro << std::endl;
}

void GameMenuPrinter::PrintGameResult(const int& index, const int& result)
{
	
	std::cout << msg.result[index] << result << std::endl;
}

void GameMenuPrinter::PrintGameReport(const int& index, const int& count)
{
	std::cout << msg.report[index] << count << std::endl;
}
