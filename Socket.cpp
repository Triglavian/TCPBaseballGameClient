#include "Socket.h"

Socket::Socket()
{
	_socket = new SOCKET();
	serverAddr = new SOCKADDR_IN();
	result = 0;
	protocol = Protocol::MAX;
	num = 0;
	flag = false;
}

Socket::~Socket()
{
	closesocket(*_socket);
	if (_socket != nullptr) delete _socket;
	if (serverAddr != nullptr) delete serverAddr;
}

void Socket::CreateSocket()
{
	*_socket = socket(AF_INET, SOCK_STREAM, 0);	
	serverAddr->sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &serverAddr->sin_addr);
	serverAddr->sin_port = htons(9000);	
}

bool Socket::IsInvalidSock() {
	return *_socket == INVALID_SOCKET;
}

void Socket::ConnectToServer()
{
	result = connect(*_socket, (sockaddr*)serverAddr, sizeof(*serverAddr));
}

bool Socket::IsWrongConnection()
{
	return result == SOCKET_ERROR;
}

void Socket::SetNum(const int& num)
{
	this->num = num;
}

void Socket::SetFlag(const bool& flag)
{
	this->flag = flag;	
}

void Socket::SetProtocol(const Protocol& protocol)
{
	this->protocol = protocol;
}

void Socket::SetAccountData(const AccountForm& acc)
{
	this->acc = acc;
}

void Socket::SetStr(const std::string& str)
{
	this->str = str;
}

const int& Socket::GetNum()
{
	return num;
}

const bool& Socket::GetFlag()
{
	return flag;
}

const Protocol& Socket::GetProtocol()
{
	return protocol;
}

const std::string Socket::GetStr()
{
	return str;
}

const Result Socket::GetResult()
{
	return _result;
}

const GameReport Socket::GetReport()
{
	return report;
}

int Socket::SendBoolPacket()
{
	return packetHandler.SendBoolPacket(*_socket, protocol, flag);
}

int Socket::SendIntPacket()
{
	return packetHandler.SendIntPacket(*_socket, protocol, num);
}

int Socket::SendAccPacket()
{
	return packetHandler.SendAccPacket(*_socket, protocol, acc);
}

int Socket::SendStrPacket()
{
	return packetHandler.SendStrPacket(*_socket, protocol, str);
}

int Socket::SendResultPacket()
{
	return packetHandler.SendResultPacket(*_socket, protocol, _result);
}

int Socket::SendReportPacket(const GameReport& report)
{
	return packetHandler.SendReportPacket(*_socket, protocol, report);
}

int Socket::RecvBoolPacket()
{
	return packetHandler.RecvBoolPacket(*_socket, protocol, &flag);
}

int Socket::RecvIntPacket()
{
	return packetHandler.RecvIntPacket(*_socket, protocol, &num);
}

int Socket::RecvAccPacket()
{
	return packetHandler.RecvAccPacket(*_socket, protocol, &acc);
}

int Socket::RecvStrPacket()
{
	return packetHandler.RecvStrPacket(*_socket, protocol, &str);
}

int Socket::RecvResultPacket()
{
	return packetHandler.RecvResultPacket(*_socket, protocol, &_result);
}

int Socket::RecvReportPacket()
{
	return packetHandler.RecvReportPacket(*_socket, protocol, &report);
}
