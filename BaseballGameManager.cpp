#include "BaseballGameManager.h"

BaseballGameManager::BaseballGameManager()
{
	loopFlag = true;
	menuHandler = new GameMenuHandler();
	_socket = nullptr;
}

BaseballGameManager::BaseballGameManager(Socket* socket)
{
	loopFlag = true;
	menuHandler = new GameMenuHandler();
	_socket = socket;
}

BaseballGameManager::~BaseballGameManager()
{
	if (menuHandler != nullptr) delete menuHandler;
}

void BaseballGameManager::MainMenu()
{
	ClearConsole();
	while (loopFlag)
	{
		menuHandler->GameMainMenu();
		ServeiceSwitch(input.GetInputAsInt());
	}
	loopFlag = true;
}

void BaseballGameManager::EndGame()
{
	_socket->SetFlag(true);
	_socket->SetProtocol(QUIT);
	_socket->SendBoolPacket();
	_socket->SetFlag(false);

	_socket->RecvBoolPacket();
	if (_socket->GetFlag() == false || _socket->GetProtocol() != QUITRDY) 
	{
		WrongAccess();
	}
	loopFlag = false;
}

void BaseballGameManager::ServeiceSwitch(const int& input)
{
	switch (input)
	{
		case 1:
			StartGame();
			break;
		case 2:
			EndGame();
			RecvGameReport();
			menuHandler->PrintGameReport(_socket->GetReport());
			break;
	}
}

void BaseballGameManager::StartGame()
{
	if (ReadyToPlayGame() == false) 
	{
		WrongAccess();
		return;
	}
	ClearConsole();
	menuHandler->GameIntro();
	PlayGame();
}

bool BaseballGameManager::ReadyToPlayGame()	//return is server ready to play game
{
	_socket->SetProtocol(PLAY);
	_socket->SetFlag(true);
	_socket->SendBoolPacket();
	_socket->SetFlag(false);

	_socket->RecvBoolPacket();

	if (_socket->GetFlag() == false || _socket->GetProtocol() != PLAYRDY)	//exception : invalid data or protocol
	{
		return false;
	}
	return true;
}

void BaseballGameManager::PlayGame()	//input number and get result
{
	
	while (true)
	{
		//get number string and send
		input.GetInputAsString();
		_socket->SetProtocol(INNUM);
		_socket->SetStr(input.GetBufferAsString());
		_socket->SendStrPacket();

		//receive match result
		_socket->RecvResultPacket();
		if (_socket->GetProtocol() == RETNOUT) //exception : is not out protocol
		{
			menuHandler->NotOutResult(_socket->GetResult());
			continue;
		}
		if (_socket->GetProtocol() != RETOUT) //exception : is not out protocol 
		{
			WrongAccess();
		}
		break;
	}
	if (GetTryCount() == false)
	{
		WrongAccess();
	}
	menuHandler->TryCount(_socket->GetNum());
	PressAnyKeyToContinue();
	ClearConsole();
}

bool BaseballGameManager::GetTryCount()
{
	_socket->RecvIntPacket();
	if (_socket->GetNum() < 1 || _socket->GetProtocol() != SENDCNT) 
	{
		return false;
	}
	return true;
}

void BaseballGameManager::RecvGameReport()
{	
	_socket->RecvReportPacket();
}

void BaseballGameManager::PressAnyKeyToContinue()
{
	std::cout << "계속하시려면 아무 키나 눌러주세요." << std::endl;
	_getch();
}

void BaseballGameManager::WrongAccess()
{
	std::cout << "잘못된 접근입니다." << std::endl;
	exit(0);
}

void BaseballGameManager::ClearConsole()
{
	system("cls");
}
