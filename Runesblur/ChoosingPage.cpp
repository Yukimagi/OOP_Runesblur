#include "ChoosingPage.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <windows.h>
#include "GameLibrary.h"
#include "BattlePage.h"

ChoosingPage::ChoosingPage(string music, Monster theMonster)
	: Page(music), enemy(theMonster)
{
}

void ChoosingPage::setArrow(COORD pos)  //�]�w�b�Y��m
{
	arrow = pos;
}

COORD ChoosingPage::getArrow() const  //���o�b�Y��m
{
	return arrow;
}

void ChoosingPage::addChoicePos(vector<COORD>& pos, COORD thePos)  //�[�J�ﶵ��m
{
	pos.push_back(thePos);
}

COORD ChoosingPage::getChoicePos(int n)  //���o�ﶵ��m
{
	return choicePos[n];
}

vector<Poker>& ChoosingPage::getAllPoker()
{
	return allPokers;
}

void ChoosingPage::moveArrow(HANDLE hConsole, COORD pos, COORD fPos)  //���ʽb�Y
{
	setScreenColor(RED);  //�N�r��]�w������

	SetConsoleCursorPosition(hConsole, arrow);  //�N��J�I����b�Y�{�b��m
	cout << "�@";  //�M���쥻���b�Y
	SetConsoleCursorPosition(hConsole, pos);  //�N��J�I����ؼЦ�m
	cout << "��";  //�L�X�b�Y
	SetConsoleCursorPosition(hConsole, fPos);  //�N��J�I���^�̫᭱
	arrow = pos;  //��s�b�Y��m

	setScreenColor(WHITE);  //�N�r���C���^�զ�
}

string ChoosingPage::getElementString(int element)
{
	switch (element)
	{
	case 1:
		return "RED";
	case 2:
		return "YELLOW";
	case 3:
		return "PURPLE";
	case 4:
		return "GREEN";
	case 5:
		return "BLUE";
	}
}

int ChoosingPage::reChoose()
{
	choicePos.clear();
	cout << fixed << setprecision(2);
	system("cls");
	thread musicThread(&Page::playMusic, this);  //���񭵼�

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "\n\n\n\n";
	setScreenColor(YELLOW);  //�r��]�w������

	for (int i = 0; i < (int)chooselogo.size(); i++)  //�C�Llogo
	{
		cout << setw(76 + chooselogo[i].length() / 2) << chooselogo[i] << "\n";
	}

	setScreenColor(WHITE); //�r��]�w�^�զ�

	cout << "\n\n";

	cout << setw(68 + enemy.getName().length() / 2) << "�Y�N���... " << enemy.getName() << " (�ݩ�:";
	cout << getElementString(enemy.getElement()) << ")\n";
	string instruction = "�п�ܤ@�Ө�������!!";
	cout << setw(78 + instruction.length() / 2) << instruction << "\n\n\n";

	COORD firstPos = { 51, 28 };
	arrow = { 45, 28 };
	COORD lastPos = { 51, 25 };

	cout << "\n\n\n\n\n";
	int cntchoice = 0;

	for (int i = 0; i < 5; i++)
	{
		if (allPokers[i].getCurrentHP() > 0)
		{
			cntchoice++;
			lastPos.Y += 3;
			addChoicePos(choicePos, lastPos);
			SetConsoleCursorPosition(hConsole, lastPos);
			cout << allPokers[i].getName() << "      �ݩ�:" << getElementString(allPokers[i].getElement()) << "      HP: " << allPokers[i].getCurrentHP() << "/" << allPokers[i].getMaximumHP();
			cout << "\n\n\n";
		}
		else
			addChoicePos(choicePos, { 0, 0 });
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);  //���o�D���x�ù���T
	COORD finalPos = csbi.dwCursorPosition;  //�����̫��J�I��m

	moveArrow(hConsole, arrow, finalPos);  //�L�X�@�}�l�b�Y��m

	while (true)
	{
		if ((GetKeyState(VK_DOWN) & 0x8000) && arrow.Y < lastPos.Y)  //�Y��������L�V�U��B�ثe�b�Y���b�̫�@�ӿﶵ
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y + 3) }, finalPos);  //�N�b�Y���ܤU�@�ӿﶵ
			Sleep(200);
		}
		if ((GetKeyState(VK_UP) & 0x8000) && arrow.Y > firstPos.Y)  //�Y��������L�V�W��B�ثe�b�Y���b�Ĥ@�ӿﶵ
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y - 3) }, finalPos);  //�N�b�Y���ܤW�@�ӿﶵ
			Sleep(200);
		}
		if (GetKeyState(VK_RETURN) & 0x8000)  //�Y��������LEnter��
		{
			static int CharacterChoosed;
			for (int i = 0; i < (int)choicePos.size(); i++)  //��X�b�Y�Ҧb�ﶵ�s��
			{
				if (choicePos[i].Y == arrow.Y)
				{
					CharacterChoosed = i + 1;
					break;
				}
			}
			setChange(true);  //�N�󴫭��ֳ]��true
			musicThread.join();  //����musicThread���槹��
			return CharacterChoosed;
		}
	}
}

int ChoosingPage::print(int* mC)
{
	Poker* battling = &getAllPoker()[reChoose() - 1];
	BattlePage battle("battle.mp3", battling, enemy);
	while (true)
	{
		if (battle.print(mC) == 1)
		{
			return 1;
		}
		else
		{
			if (getAllPoker()[0].getCurrentHP() == 0 && getAllPoker()[1].getCurrentHP() == 0 && getAllPoker()[2].getCurrentHP() == 0 && getAllPoker()[3].getCurrentHP() == 0 && getAllPoker()[4].getCurrentHP() == 0)
				return 2;
			battle.setMyCharacter(&getAllPoker()[reChoose() - 1]);
		}
	}
}