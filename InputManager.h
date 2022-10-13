#pragma once
#include <iostream>
#include <string>

class InputManager
{
public:
	static InputManager& Instance();	//singleton instance
	~InputManager();
	std::string GetInputAsString();		//set input to buffer and get bufferas string
	char GetInputAsChar();				//set input to buffer and get buffer's first element as char
	const char* GetInputAsCStr();		//set input to buffer and get bufferas const char*
	int GetInputAsInt();				//set input to buffer and get buffer's first element as int
	std::string GetBufferAsString();	//get buffer as string
	char GetBufferAsChar();				//get buffer's first element as char
	const char* GetBufferAsCStr();		//get buffer as const char*
	int GetBufferAsInt();				//get buffer's first element as int
	InputManager();	
	void GetInput();					//get line string and set to buffer
	std::string inputBuffer;
};

