#pragma once
#include <WS2tcpip.h>
#include "Protocol.h"
#include "Socket.h"
#include <iostream>
#include "MenuHandler.h"
#include "InputManager.h"
#include "BaseballGameManager.h"

class ClientBase
{
public:
	ClientBase();
	~ClientBase();
	void Run();
private:
	WSADATA wsaData;		//window socket api
	Socket* _socket;
	MenuHandler menuHandler;
	InputManager& input = InputManager::Instance();
	AccountForm userAccount;
	BaseballGameManager* gameManager;
	bool Initialization();	//server initialization
	bool IsWSAStartFail();	//validate initialization
	int result;				//event result	
	int selection;
	char addr[INET_ADDRSTRLEN];
	int retval;
	bool loopFlag;
	void ServiceSwitch(const int& selection);
	void Registration();
	bool ReadyForRegistration();
	void SetAccountData(AccountForm& acc);
	bool AttemptRegistration(const AccountForm& acc);
	bool LogIn();
	bool ReadyForLogIn();
	bool AttemptLogIn(const AccountForm& acc);
	bool ReadyToPlayGame();
	void Disconnection();
	void ReadyForDisconnection();
	void Disconnect();
	void WrongAccess();
	void PressAnyKeyToContinue();
	void ClearConsole();
};