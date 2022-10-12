#pragma once
#include <iostream>
#include <string>

class InputManager
{
public:
	static InputManager& Instance();
	~InputManager();
	std::string GetInputAsString();
	char GetInputAsChar();
	const char* GetInputAsCStr();
	int GetInputAsInt();
	std::string GetBufferAsString();
	char GetBufferAsChar();
	const char* GetBufferAsCStr();
	int GetBufferAsInt();
	InputManager();
	void GetInput();
	std::string inputBuffer;
};

