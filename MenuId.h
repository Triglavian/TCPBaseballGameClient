#pragma once


enum class MenuId {
	MAIN,
	REGISTRATION,
	LOG_IN,
	LOG_OUT,
	EXIT_MENU,
	MAX
#define MREG		(int)MenuId::REGISTRATION
#define MLIN		(int)MenuId::LOG_IN
#define MEXIT		(int)MenuId::EXIT_MENU
#define MMAX		(int)MenuId::MAX
};