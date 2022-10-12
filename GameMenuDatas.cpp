#include "GameMenuDatas.h"

GameMenuDatas::GameMenuDatas()
{
	mainMenu = "<숫자야구 게임>\n1. 게임시작\n2. 종료\n   선택:";
	gameIntro = "컴퓨터가 임의로 고른 0 ~ 9 사이의 숫자 3개를 맞추세요.\n숫자와 자리가 일치하면 스트라이크, 숫자만 일치하면 ball입니다.\n3 스트라이크를 3개 만들면 게임이 종료됩니다.\n3개의 숫자를 띄워서 입력해주세요 ex. 1 2 3";
	result.push_back("스트라이크 : ");
	result.push_back("볼 : ");
	result.push_back("3 스트라이크 아웃\n시도 횟수 : ");
	report.push_back("총 게임 횟수 : ");
	report.push_back("최저 시도 횟수 : ");
	report.push_back("최다 시도 횟수 : ");
}

GameMenuDatas::~GameMenuDatas()
{

}
