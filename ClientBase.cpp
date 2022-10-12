#include "ClientBase.h"

ClientBase::ClientBase()
{
	memset(&wsaData, 0, sizeof(wsaData));
	memset(addr, 0, sizeof(addr));
	_socket = new Socket();
	result = 0;
	retval = 0;
	selection = 0;
	loopFlag = true;
	gameManager = new BaseballGameManager(_socket);
}

ClientBase::~ClientBase()
{
	if (gameManager != nullptr) delete gameManager;
	if (_socket != nullptr) delete _socket;
}

void ClientBase::Run()	//service base 
{
	if (Initialization() == false) //exception : initialization or connection failed
	{
		std::cout << "Server Initialization Failed" << std::endl;
		exit(0);
	}
	while (loopFlag) {
		menuHandler.MainMenu();	
		ServiceSwitch(input.GetInputAsInt());
	}
}

bool ClientBase::Initialization()	//server initialization
{
	result = WSAStartup(MAKEWORD(2, 2), &wsaData);	//linker error

	//WSA startup validation
	if (IsWSAStartFail())
	{
		std::cout << "WSAStartup() Error" << std::endl;
		return false;
	}
	_socket->CreateSocket();
	//listen socket validation
	if (_socket->IsInvalidSock())
	{
		std::cout << "socket() error" << std::endl;
		return false;
	}
	_socket->ConnectToServer();
	if (_socket->IsWrongConnection()) 
	{
		std::cout << "Wrong Connection" << std::endl;
		exit(0);
	}
	return true;
}

bool ClientBase::IsWSAStartFail()	//validate initialization
{
	return result != 0;
}

void ClientBase::ServiceSwitch(const int& selection)
{
	switch (selection)
	{
		case 1:
			Registration();
			break;
		case 2:
			if (LogIn() == false) //exception : failed to login
			{
				PressAnyKeyToContinue();
				ClearConsole();
				return;	
			}
			if (ReadyToPlayGame() == false)	//exception : failed to start game
			{
				PressAnyKeyToContinue();
				ClearConsole();
				return;
			}
			PressAnyKeyToContinue();
			gameManager->MainMenu();
			break;
		case 3:
			Disconnection();
			break;
	}
	PressAnyKeyToContinue();
	ClearConsole();
}

void ClientBase::Registration()
{
	if (ReadyForRegistration() == false) 
	{
		WrongAccess();
		return;
	}

	//set account data
	AccountForm acc;
	SetAccountData(acc);

	//attempt registration
	if (AttemptRegistration(acc) == false) 
	{
		menuHandler.RegistrationMenu(3);
		return;
	}
	menuHandler.RegistrationMenu(2);
}

bool ClientBase::ReadyForRegistration()	//send registraion ready protocol and receive result
{
	//send registration packet
	_socket->SetProtocol(REG);
	_socket->SetFlag(true);
	_socket->SendBoolPacket();
	_socket->SetFlag(false);	//reset flag

	_socket->RecvBoolPacket();	//receive result

	if (_socket->GetFlag() == false || _socket->GetProtocol() != REGRDY) {	//exception : wrong protocol or invalid data
		return false;
	}
	return true;
}

void ClientBase::SetAccountData(AccountForm& acc)
{
	menuHandler.RegistrationMenu(0);
	acc.id = input.GetInputAsString();
	menuHandler.RegistrationMenu(1);
	acc.pw = input.GetInputAsString();
}

bool ClientBase::AttemptRegistration(const AccountForm& acc)
{
	//send account data packet
	_socket->SetProtocol(REG);
	_socket->SetAccountData(acc);
	_socket->SendAccPacket();

	//recv registraion result packet
	_socket->RecvBoolPacket();
	if (_socket->GetFlag() == false || _socket->GetProtocol() == REGFAIL)	//exception : wrong protocol or invalid data
	{
		return false;
	}
	return true;
}

bool ClientBase::LogIn()
{
	if (ReadyForLogIn() == false) {
		WrongAccess();
		return false;
	}

	//set account data
	SetAccountData(userAccount);	

	//attempt login
	if (AttemptLogIn(userAccount) == false)
	{
		menuHandler.LogIn(1);	//login failed
		userAccount.Clear();
		return false;
	}
	menuHandler.LogIn(0);	//login success
	return true;
}

bool ClientBase::ReadyForLogIn()	//send login ready protocol and receive result
{
	//send login ready protocol
	_socket->SetProtocol(LIN);
	_socket->SetFlag(true);
	_socket->SendBoolPacket();
	_socket->SetFlag(false);	//reset flag

	_socket->RecvBoolPacket();	//receive result
	if (_socket->GetFlag() == false || _socket->GetProtocol() != LINRDY)	//exception : wrong protocol or invalid data
	{
		return false;
	}
	return true;
}

bool ClientBase::AttemptLogIn(const AccountForm& acc)
{
	//send account data packet
	_socket->SetProtocol(LIN);
	_socket->SetAccountData(acc);
	_socket->SendAccPacket();

	//receive login result packet
	_socket->RecvBoolPacket();
	if (_socket->GetFlag() == false || _socket->GetProtocol() != LINSUC) {	//exception : wrong protocol or invalid data
		return false;
	}
	return true;
}

bool ClientBase::ReadyToPlayGame()
{
	_socket->SetProtocol(EXEGAME);
	_socket->SetFlag(true);
	_socket->SendBoolPacket();
	_socket->SetFlag(false);

	_socket->RecvBoolPacket();
	if (_socket->GetFlag() == false || _socket->GetProtocol() != GAMERDY) 
	{
		WrongAccess();
		return false;
	}
	return true;
}

void ClientBase::Disconnection()
{
	ReadyForDisconnection();
	Disconnect();
}

void ClientBase::ReadyForDisconnection()	//send disconnection packet
{
	_socket->SetProtocol(EXIT);
	_socket->SetFlag(true);
	_socket->SendBoolPacket();
	_socket->RecvBoolPacket();
}

void ClientBase::Disconnect()
{
	loopFlag = false;
	delete _socket;
}

void ClientBase::WrongAccess()
{
	std::cout << "잘못된 접근입니다." << std::endl;
	exit(0);
}

void ClientBase::PressAnyKeyToContinue()
{
	std::cout << "계속하시려면 아무 키나 눌러주세요." << std::endl;
	_getch();
}

void ClientBase::ClearConsole()
{
	system("cls");
}
