#pragma once
#include <iostream>
#include "GameMenuDatas.h"

class GameMenuPrinter
{
public:
	GameMenuPrinter();
	~GameMenuPrinter();
	void PrintGameMainMenu();
	void PrintGameIntroMsg();
	void PrintGameResult(const int& index, const int& result);
	void PrintGameReport(const int& index, const int& count);
private:
	GameMenuDatas msg;
};

