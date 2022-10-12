#include "MenuDatas.h"

MenuDatas::MenuDatas()
{
	mainMenu = "<메뉴>\n1. 회원가입\n2. 로그인\n3. 종료\n   선택:";
	registrationMenu.push_back("Id를 입력해주세요.");
	registrationMenu.push_back("Pw를 입력해주세요.");
	registrationMenu.push_back("회원가입이 완료되었습니다.");
	registrationMenu.push_back("회원가입이 실패하였습니다.");
	loginMenu.push_back("Id를 입력해주세요.");
	loginMenu.push_back("Pw를 입력해주세요.");
	login.push_back("로그인에 성공하였습니다.");
	login.push_back("로그인에 실패하였습니다.");
}

MenuDatas::~MenuDatas()
{

}