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

void ChoosingPage::setArrow(COORD pos)  //設定箭頭位置
{
	arrow = pos;
}

COORD ChoosingPage::getArrow() const  //取得箭頭位置
{
	return arrow;
}

void ChoosingPage::addChoicePos(vector<COORD>& pos, COORD thePos)  //加入選項位置
{
	pos.push_back(thePos);
}

COORD ChoosingPage::getChoicePos(int n)  //取得選項位置
{
	return choicePos[n];
}

vector<Poker>& ChoosingPage::getAllPoker()
{
	return allPokers;
}

void ChoosingPage::moveArrow(HANDLE hConsole, COORD pos, COORD fPos)  //移動箭頭
{
	setScreenColor(RED);  //將字體設定為紅色

	SetConsoleCursorPosition(hConsole, arrow);  //將輸入點移到箭頭現在位置
	cout << "　";  //清掉原本的箭頭
	SetConsoleCursorPosition(hConsole, pos);  //將輸入點移到目標位置
	cout << "◢";  //印出箭頭
	SetConsoleCursorPosition(hConsole, fPos);  //將輸入點移回最後面
	arrow = pos;  //更新箭頭位置

	setScreenColor(WHITE);  //將字體顏色改回白色
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
	thread musicThread(&Page::playMusic, this);  //撥放音樂

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "\n\n\n\n";
	setScreenColor(YELLOW);  //字體設定為黃色

	for (int i = 0; i < (int)chooselogo.size(); i++)  //列印logo
	{
		cout << setw(76 + chooselogo[i].length() / 2) << chooselogo[i] << "\n";
	}

	setScreenColor(WHITE); //字體設定回白色

	cout << "\n\n";

	cout << setw(68 + enemy.getName().length() / 2) << "即將對戰... " << enemy.getName() << " (屬性:";
	cout << getElementString(enemy.getElement()) << ")\n";
	string instruction = "請選擇一個角色應戰!!";
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
			cout << allPokers[i].getName() << "      屬性:" << getElementString(allPokers[i].getElement()) << "      HP: " << allPokers[i].getCurrentHP() << "/" << allPokers[i].getMaximumHP();
			cout << "\n\n\n";
		}
		else
			addChoicePos(choicePos, { 0, 0 });
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);  //取得主控台螢幕資訊
	COORD finalPos = csbi.dwCursorPosition;  //紀錄最後輸入點位置

	moveArrow(hConsole, arrow, finalPos);  //印出一開始箭頭位置

	while (true)
	{
		if ((GetKeyState(VK_DOWN) & 0x8000) && arrow.Y < lastPos.Y)  //若偵測到鍵盤向下鍵且目前箭頭不在最後一個選項
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y + 3) }, finalPos);  //將箭頭移至下一個選項
			Sleep(200);
		}
		if ((GetKeyState(VK_UP) & 0x8000) && arrow.Y > firstPos.Y)  //若偵測到鍵盤向上鍵且目前箭頭不在第一個選項
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y - 3) }, finalPos);  //將箭頭移至上一個選項
			Sleep(200);
		}
		if (GetKeyState(VK_RETURN) & 0x8000)  //若偵測到鍵盤Enter鍵
		{
			static int CharacterChoosed;
			for (int i = 0; i < (int)choicePos.size(); i++)  //找出箭頭所在選項編號
			{
				if (choicePos[i].Y == arrow.Y)
				{
					CharacterChoosed = i + 1;
					break;
				}
			}
			setChange(true);  //將更換音樂設為true
			musicThread.join();  //等待musicThread執行完畢
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