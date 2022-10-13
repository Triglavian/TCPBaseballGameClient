#include "InputManager.h"

InputManager& InputManager::Instance()	//singleton instance
{
	static InputManager* instance = new InputManager();
	return *instance;
}

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

std::string InputManager::GetInputAsString()	//set input to buffer and get bufferas string
{
	GetInput();
	return inputBuffer;
}

char InputManager::GetInputAsChar()	//set input to buffer and get buffer's first element as char
{
	return inputBuffer[0];
}

const char* InputManager::GetInputAsCStr()	//set input to buffer and get bufferas const char*
{
	GetInput();
	return inputBuffer.c_str();
}

int InputManager::GetInputAsInt()	//set input to buffer and get buffer's first element as int
{
	GetInput();
	return inputBuffer[0] - '0';
}

std::string InputManager::GetBufferAsString()	//get buffer as string
{
	return inputBuffer;
}

char InputManager::GetBufferAsChar()	//get buffer's first element as char
{
	return inputBuffer[0];
}

const char* InputManager::GetBufferAsCStr()	//get buffer as const char*
{
	return inputBuffer.c_str();
}

int InputManager::GetBufferAsInt()	//get buffer's first element as int
{
	return inputBuffer[0] - '0';
}

void InputManager::GetInput()	//get line string and set to buffer
{
	std::getline(std::cin, inputBuffer);
}
