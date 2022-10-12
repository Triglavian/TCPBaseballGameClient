#include "GameReport.h"

GameReport::GameReport()
{
	gameCount = tryCount = minTryCount = maxTryCount = 0;
}

GameReport::~GameReport()
{

}

void GameReport::Clear()
{
	gameCount = tryCount = minTryCount = maxTryCount = 0;
}

void GameReport::ResetTryCount()
{
	tryCount = 0;
}
