#include "MenuDatas.h"

MenuDatas::MenuDatas()
{
	mainMenu = "<�޴�>\n1. ȸ������\n2. �α���\n3. ����\n   ����:";
	registrationMenu.push_back("Id�� �Է����ּ���.");
	registrationMenu.push_back("Pw�� �Է����ּ���.");
	registrationMenu.push_back("ȸ�������� �Ϸ�Ǿ����ϴ�.");
	registrationMenu.push_back("ȸ�������� �����Ͽ����ϴ�.");
	loginMenu.push_back("Id�� �Է����ּ���.");
	loginMenu.push_back("Pw�� �Է����ּ���.");
	login.push_back("�α��ο� �����Ͽ����ϴ�.");
	login.push_back("�α��ο� �����Ͽ����ϴ�.");
}

MenuDatas::~MenuDatas()
{

}