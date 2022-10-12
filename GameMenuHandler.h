#pragma once
#include "GameMenuPrinter.h"
#include "Result.h"
#include "GameReport.h"

class GameMenuHandler
{
public:
	GameMenuHandler();
	~GameMenuHandler();
	void GameMainMenu();
	void GameIntro();
	void TryCount(const int& tryCount);
	void NotOutResult(const Result& result);
	void PrintGameReport(const GameReport& report);
private:
	GameMenuPrinter* msg;
};

