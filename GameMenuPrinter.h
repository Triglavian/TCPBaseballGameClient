#pragma once
#include <iostream>
#include "GameMenuDatas.h"

class GameMenuPrinter
{
public:
	GameMenuPrinter();
	~GameMenuPrinter();
	void PrintGameMainMenu();	//print game menu
	void PrintGameIntroMsg();	//print game intro message
	void PrintGameResult(const int& index, const int& result);	//print comparation result
	void PrintGameReport(const int& index, const int& count);	//print total game report
private:
	GameMenuDatas msg;
};

