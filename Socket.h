#pragma once
#include <WS2tcpip.h>
#include "PacketHandler.h"
#include "Result.h"

class Socket
{
public:
	Socket();
	~Socket();
	void CreateSocket();
	bool IsInvalidSock();
	void ConnectToServer();
	bool IsWrongConnection();

	//set data
	void SetNum(const int& num);
	void SetFlag(const bool& flag);
	void SetProtocol(const Protocol& protocol);
	void SetAccountData(const AccountForm& acc);
	void SetStr(const std::string& str);

	//get data
	const int& GetNum();
	const bool& GetFlag();
	const Protocol& GetProtocol();
	const std::string GetStr();
	const Result GetResult();
	const GameReport GetReport();

	//send packet
	int SendBoolPacket();
	int SendIntPacket();
	int SendAccPacket();
	int SendStrPacket();
	int SendResultPacket();
	int SendReportPacket(const GameReport& report);

	//receive packet
	int RecvBoolPacket();
	int RecvIntPacket();
	int RecvAccPacket();
	int RecvStrPacket();
	int RecvResultPacket();
	int RecvReportPacket();
	PacketHandler packetHandler;
private:
	SOCKET* _socket;
	SOCKADDR_IN* serverAddr;
	int result;
	Result _result;
	AccountForm acc;
	Protocol protocol;
	std::string str;
	int num;
	bool flag;
	GameReport report;
};