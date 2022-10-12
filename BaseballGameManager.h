#pragma once
#include "InputManager.h"
#include "GameMenuHandler.h"
#include "Socket.h"
#include <conio.h>

class BaseballGameManager
{
public:
	BaseballGameManager();
	BaseballGameManager(Socket* socket);
	~BaseballGameManager();
	void MainMenu();
	void EndGame();
private:
	Socket* _socket;
	InputManager& input = InputManager::Instance();
	GameMenuHandler* menuHandler;
	bool loopFlag;
	void ServeiceSwitch(const int& input);
	void StartGame();
	bool ReadyToPlayGame();
	void PlayGame();
	bool GetTryCount();
	void RecvGameReport();
	void PressAnyKeyToContinue();
	void WrongAccess();
	void ClearConsole();
};

