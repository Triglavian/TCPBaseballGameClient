#include "InputManager.h"

InputManager& InputManager::Instance()
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

std::string InputManager::GetInputAsString()
{
	GetInput();
	return inputBuffer;
}

char InputManager::GetInputAsChar()
{
	return inputBuffer[0];
}

const char* InputManager::GetInputAsCStr()
{
	GetInput();
	return inputBuffer.c_str();
}

int InputManager::GetInputAsInt()
{
	GetInput();
	return inputBuffer[0] - '0';
}

std::string InputManager::GetBufferAsString()
{
	return inputBuffer;
}

char InputManager::GetBufferAsChar()
{
	return inputBuffer[0];
}

const char* InputManager::GetBufferAsCStr()
{
	return inputBuffer.c_str();
}

int InputManager::GetBufferAsInt()
{
	return inputBuffer[0] - '0';
}

void InputManager::GetInput()
{
	std::getline(std::cin, inputBuffer);
}
