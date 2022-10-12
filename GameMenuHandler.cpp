#include "GameMenuHandler.h"

GameMenuHandler::GameMenuHandler()
{
	msg = new GameMenuPrinter();
}

GameMenuHandler::~GameMenuHandler()
{
	if (msg != nullptr) delete msg;
}

void GameMenuHandler::GameMainMenu()
{
	msg->PrintGameMainMenu();
}

void GameMenuHandler::GameIntro()
{
	msg->PrintGameIntroMsg();
}

void GameMenuHandler::TryCount(const int& tryCount)
{
	msg->PrintGameResult(2, tryCount);
}

void GameMenuHandler::NotOutResult(const Result& result)
{
	msg->PrintGameResult(0, result.strikes);
	msg->PrintGameResult(1, result.balls);
}

void GameMenuHandler::PrintGameReport(const GameReport& report)
{
	msg->PrintGameReport(0, report.gameCount);
	msg->PrintGameReport(1, report.minTryCount);
	msg->PrintGameReport(2, report.maxTryCount);
}
