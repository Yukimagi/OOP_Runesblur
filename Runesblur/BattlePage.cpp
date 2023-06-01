#include "BattlePage.h"
#include <iostream>
#include <thread>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include"GameLibrary.h"
BattlePage::BattlePage(const string& music, Poker* mine, Monster others)
	: Page(music), myCharacter(mine), enemy(others)
{
}

void BattlePage::setScreenColor(int element)     //設定顏色
{
	switch (element)
	{
	case 0:
		Page::setScreenColor(WHITE);
		break;
	case 1:
		Page::setScreenColor(RED);
		break;
	case 2:
		Page::setScreenColor(YELLOW);
		break;
	case 3:
		Page::setScreenColor(PURPLE);
		break;
	case 4:
		Page::setScreenColor(GREEN);
		break;
	case 5:
		Page::setScreenColor(BLUE);
		break;
	}
}

void BattlePage::setMyCharacter(Poker* theCharacter)
{
	myCharacter = theCharacter;
}

string BattlePage::getElementString(int element)
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

void BattlePage::renew()  //更新
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, { 0, 0 });

	for (int i = 0; i < 38; i++) // 列印角色
	{
		setScreenColor(enemy.getElement());
		cout << setw(80 - (80 - enemy.getImage()[i].length()) / 2) << enemy.getImage()[i];
		setScreenColor(myCharacter->getElement());
		cout << setw(80 - (80 - myCharacter->getImage()[i].length()) / 2) << myCharacter->getImage()[i] << "\n";
	}

	setScreenColor(0);

	cout << "\n";
	cout << setw(35) << enemy.getName() << " (屬性:" << getElementString(enemy.getElement()) << ")"
		<< setw(65) << myCharacter->getName() << " (屬性:" << getElementString(myCharacter->getElement()) << ")\n";
	cout << setw(30) << "HP: ";

	if (enemy.getCurrentHP() == 0)
		setScreenColor(1);

	cout << enemy.getCurrentHP();
	setScreenColor(0);
	cout << "/" << enemy.getMaximumHP() << setw(60) << "HP: ";

	if (myCharacter->getCurrentHP() == 0)
		setScreenColor(1);

	cout << myCharacter->getCurrentHP();
	setScreenColor(0);
	cout << "/" << myCharacter->getMaximumHP() << "\n\n";
}

int BattlePage::print(int* mC)   //戰鬥畫面列印
{
	system("cls");
	cout << fixed << setprecision(2);
	srand(time(NULL));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	thread musicThread(&Page::playMusic, this);  // 撥放音樂

	bool win = 0;
	bool end = 0;
	int n; // 第n招
	int a = 1;
	int mn = rand() % 4; // 怪物使用招式
	while (a == 1) {
		while (!end)
		{
			system("cls");
			for (int i = 0; i < 38; i++) {    //過場卡牌動畫
				setScreenColor(1);
				cout << setw(40) << heart[i];
				setScreenColor(4);
				cout << setw(60) << square[i] << "\n";
				Sleep(50);
			}
			system("cls");
			for (int i = 0; i < 38; i++) {
				setScreenColor(3);
				cout << setw(20) << circle[i];
				setScreenColor(5);
				cout << setw(40) << pum[i];
				setScreenColor(2);
				cout << setw(60) << flower[i] << "\n";
				Sleep(50);
			}
			system("cls");
			renew();

			cin.clear();
			cout << "選擇技能: ";
			cin >> n;



			if (!myCharacter->checkLV(n) || n >= 5)
			{
				cout << "尚未學會該技能!\n";
			}
			else
			{
				system("cls");
				if (myCharacter->getSpeed(n) >= enemy.getSpeed(mn)) // 主角先攻 (速度大的先攻)
				{
					int monsterAlive = enemy.underAttack(myCharacter->calculateDamage(1, n)); // 改到HP
					renew();
					cout << "\n";
					cout << myCharacter->getName() + "使用" + myCharacter->getSkillName(n) + "\n對" + enemy.getName() + "造成"
						<< myCharacter->calculateDamage(1, n) << "點傷害\n"; // 敵人角色使用第n招

					if (!monsterAlive) // 怪物死亡
					{
						cout << "***********";
						cout << "\n YOU WIN!!\n";
						cout << "***********\n";
						win = 1; // 主角獲勝 
						end = 1; // 戰鬥結束
						cout << "是否繼續遊戲<yes(1)/no(0)" << endl;
						cin >> a;
						break;
					}
					else // 怪物沒死 主角遭到攻擊
					{
						system("pause");
						system("cls");
						int myCharacterAlive = myCharacter->underAttack(enemy.calculateDamage(1, mn));
						renew();
						cout << "\n";
						cout << "Monster's turn!\n";
						cout << enemy.getName() + "使用" + enemy.getSkillName(mn);
						cout << "\n遭受" << enemy.calculateDamage(1, mn) << "傷害!!!\n";

						if (!myCharacterAlive) // r主角遭受怪物傷害後死亡
						{
							cout << "***********";
							cout << "\n You Die!!!\n";
							cout << "***********\n";
							win = 0; // 主角輸
							end = 1; // 戰鬥結束
							cout << "是否繼續遊戲<yes(1)/no(0)" << endl;
							cin >> a;
							break;
						}
						else {
							cout << "\nRound ends!";
							end = 0; // 回合結束 戰鬥繼續
						}
					}
				}
				else // 怪物先攻
				{
					int myCharacterAlive = myCharacter->underAttack(enemy.calculateDamage(1, mn));
					renew();
					cout << "\n";
					cout << enemy.getName() + "使用" + enemy.getSkillName(mn);
					cout << "\n遭受" << enemy.calculateDamage(1, mn) << "傷害!!!\n";
					if (!myCharacterAlive) // 主角遭受怪物傷害死亡
					{
						cout << "***********";
						cout << "\n You Die!!!\n";
						cout << "***********\n";
						win = 0; // 主角輸
						end = 1; // 戰鬥結束
						cout << "是否繼續遊戲<yes(1)/no(0)" << endl;
						cin >> a;
						break;
					}
					else
					{
						system("pause");
						system("cls");
						int monsterAlive = enemy.underAttack(myCharacter->calculateDamage(1, n));
						renew();
						cout << "\n";
						cout << "Your turn!\n";
						cout << myCharacter->getName() + "使用" + myCharacter->getSkillName(n) + "\n對" + enemy.getName() + "造成"
							<< myCharacter->calculateDamage(1, n) << "點傷害"; // 敵人使用第n招
						if (!monsterAlive) // 怪物死亡
						{
							cout << "\n***********";
							cout << "\n YOU WIN!!\n";
							cout << "***********\n";
							win = 1; // 主角獲勝 
							end = 1; // 戰鬥結束
							cout << "是否繼續遊戲<yes(1)/no(0)" << endl;
							cin >> a;
							break;
						}
						else // 怪物沒死 回合結束
						{
							cout << "\nRound ends!\n";
							end = 0; // 回合結束 戰鬥繼續
						}
					}
				}
			}
		}


		if (win)
		{
			setChange(true); // 將更換音樂設為true
			musicThread.join(); // 等待musicThread執行完畢
			mciSendString(L"open \"winning.mp3\" type mpegvideo alias mp3", NULL, 0, NULL); // 打開音檔
			mciSendString(L"play mp3", NULL, 0, NULL); // 撥放音檔
			system("pause");
			mciSendString(L"close mp3", NULL, 0, NULL); // 關閉音檔
			system("cls");
			mciSendString(L"open \"upgrade.mp3\" type mpegvideo alias mp3", NULL, 0, NULL); // 打開音檔
			mciSendString(L"play mp3", NULL, 0, NULL); // 撥放音檔

			if (myCharacter->addEXP(enemy.getEXP())) // 更新角色狀態 並判斷是否升級
			{
				SetConsoleCursorPosition(hConsole, { 65, 20 });
				cout << "恭喜升級至" << myCharacter->getLV() << "級";
				SetConsoleCursorPosition(hConsole, { 65, 22 });
				cout << "Pokemon狀態已恢復\n";
				myCharacter->setCurrentHP(myCharacter->getMaximumHP()); // 把當前血量設定為最大血量
				SetConsoleCursorPosition(hConsole, { 65, 24 });
				myCharacter->showEXPmessage();
				SetConsoleCursorPosition(hConsole, { 65, 26 });
				system("pause");
			}
			mciSendString(L"close mp3", NULL, 0, NULL); // 關閉音檔
			return 1;
		}
		else
		{
			setChange(true); // 將更換音樂設為true
			musicThread.join(); // 等待musicThread執行完畢
			mciSendString(L"open \"losing.mp3\" type mpegvideo alias mp3", NULL, 0, NULL); // 打開音檔
			mciSendString(L"play mp3", NULL, 0, NULL); // 撥放音檔
			system("pause");
			mciSendString(L"close mp3", NULL, 0, NULL); // 關閉音檔
			return 2;
		}
	}
}