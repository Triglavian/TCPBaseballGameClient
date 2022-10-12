#pragma once
#include <string>
#include <vector>

class GameMenuDatas
{
public:
	GameMenuDatas();
	~GameMenuDatas();
	std::string mainMenu;
	std::string gameIntro;
	std::vector<std::string> result;
	std::vector<std::string> report;
private:
};

