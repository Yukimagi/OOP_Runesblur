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

void BattlePage::setScreenColor(int element)     //�]�w�C��
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

void BattlePage::renew()  //��s
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, { 0, 0 });

	for (int i = 0; i < 38; i++) // �C�L����
	{
		setScreenColor(enemy.getElement());
		cout << setw(80 - (80 - enemy.getImage()[i].length()) / 2) << enemy.getImage()[i];
		setScreenColor(myCharacter->getElement());
		cout << setw(80 - (80 - myCharacter->getImage()[i].length()) / 2) << myCharacter->getImage()[i] << "\n";
	}

	setScreenColor(0);

	cout << "\n";
	cout << setw(35) << enemy.getName() << " (�ݩ�:" << getElementString(enemy.getElement()) << ")"
		<< setw(65) << myCharacter->getName() << " (�ݩ�:" << getElementString(myCharacter->getElement()) << ")\n";
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

int BattlePage::print(int* mC)   //�԰��e���C�L
{
	system("cls");
	cout << fixed << setprecision(2);
	srand(time(NULL));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	thread musicThread(&Page::playMusic, this);  // ���񭵼�

	bool win = 0;
	bool end = 0;
	int n; // ��n��
	int a = 1;
	int mn = rand() % 4; // �Ǫ��ϥΩۦ�
	while (a == 1) {
		while (!end)
		{
			system("cls");
			for (int i = 0; i < 38; i++) {    //�L���d�P�ʵe
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
			cout << "��ܧޯ�: ";
			cin >> n;



			if (!myCharacter->checkLV(n) || n >= 5)
			{
				cout << "�|���Ƿ|�ӧޯ�!\n";
			}
			else
			{
				system("cls");
				if (myCharacter->getSpeed(n) >= enemy.getSpeed(mn)) // �D������ (�t�פj������)
				{
					int monsterAlive = enemy.underAttack(myCharacter->calculateDamage(1, n)); // ���HP
					renew();
					cout << "\n";
					cout << myCharacter->getName() + "�ϥ�" + myCharacter->getSkillName(n) + "\n��" + enemy.getName() + "�y��"
						<< myCharacter->calculateDamage(1, n) << "�I�ˮ`\n"; // �ĤH����ϥβ�n��

					if (!monsterAlive) // �Ǫ����`
					{
						cout << "***********";
						cout << "\n YOU WIN!!\n";
						cout << "***********\n";
						win = 1; // �D����� 
						end = 1; // �԰�����
						cout << "�O�_�~��C��<yes(1)/no(0)" << endl;
						cin >> a;
						break;
					}
					else // �Ǫ��S�� �D���D�����
					{
						system("pause");
						system("cls");
						int myCharacterAlive = myCharacter->underAttack(enemy.calculateDamage(1, mn));
						renew();
						cout << "\n";
						cout << "Monster's turn!\n";
						cout << enemy.getName() + "�ϥ�" + enemy.getSkillName(mn);
						cout << "\n�D��" << enemy.calculateDamage(1, mn) << "�ˮ`!!!\n";

						if (!myCharacterAlive) // r�D���D���Ǫ��ˮ`�ᦺ�`
						{
							cout << "***********";
							cout << "\n You Die!!!\n";
							cout << "***********\n";
							win = 0; // �D����
							end = 1; // �԰�����
							cout << "�O�_�~��C��<yes(1)/no(0)" << endl;
							cin >> a;
							break;
						}
						else {
							cout << "\nRound ends!";
							end = 0; // �^�X���� �԰��~��
						}
					}
				}
				else // �Ǫ�����
				{
					int myCharacterAlive = myCharacter->underAttack(enemy.calculateDamage(1, mn));
					renew();
					cout << "\n";
					cout << enemy.getName() + "�ϥ�" + enemy.getSkillName(mn);
					cout << "\n�D��" << enemy.calculateDamage(1, mn) << "�ˮ`!!!\n";
					if (!myCharacterAlive) // �D���D���Ǫ��ˮ`���`
					{
						cout << "***********";
						cout << "\n You Die!!!\n";
						cout << "***********\n";
						win = 0; // �D����
						end = 1; // �԰�����
						cout << "�O�_�~��C��<yes(1)/no(0)" << endl;
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
						cout << myCharacter->getName() + "�ϥ�" + myCharacter->getSkillName(n) + "\n��" + enemy.getName() + "�y��"
							<< myCharacter->calculateDamage(1, n) << "�I�ˮ`"; // �ĤH�ϥβ�n��
						if (!monsterAlive) // �Ǫ����`
						{
							cout << "\n***********";
							cout << "\n YOU WIN!!\n";
							cout << "***********\n";
							win = 1; // �D����� 
							end = 1; // �԰�����
							cout << "�O�_�~��C��<yes(1)/no(0)" << endl;
							cin >> a;
							break;
						}
						else // �Ǫ��S�� �^�X����
						{
							cout << "\nRound ends!\n";
							end = 0; // �^�X���� �԰��~��
						}
					}
				}
			}
		}


		if (win)
		{
			setChange(true); // �N�󴫭��ֳ]��true
			musicThread.join(); // ����musicThread���槹��
			mciSendString(L"open \"winning.mp3\" type mpegvideo alias mp3", NULL, 0, NULL); // ���}����
			mciSendString(L"play mp3", NULL, 0, NULL); // ������
			system("pause");
			mciSendString(L"close mp3", NULL, 0, NULL); // ��������
			system("cls");
			mciSendString(L"open \"upgrade.mp3\" type mpegvideo alias mp3", NULL, 0, NULL); // ���}����
			mciSendString(L"play mp3", NULL, 0, NULL); // ������

			if (myCharacter->addEXP(enemy.getEXP())) // ��s���⪬�A �çP�_�O�_�ɯ�
			{
				SetConsoleCursorPosition(hConsole, { 65, 20 });
				cout << "���ߤɯŦ�" << myCharacter->getLV() << "��";
				SetConsoleCursorPosition(hConsole, { 65, 22 });
				cout << "Pokemon���A�w��_\n";
				myCharacter->setCurrentHP(myCharacter->getMaximumHP()); // ���e��q�]�w���̤j��q
				SetConsoleCursorPosition(hConsole, { 65, 24 });
				myCharacter->showEXPmessage();
				SetConsoleCursorPosition(hConsole, { 65, 26 });
				system("pause");
			}
			mciSendString(L"close mp3", NULL, 0, NULL); // ��������
			return 1;
		}
		else
		{
			setChange(true); // �N�󴫭��ֳ]��true
			musicThread.join(); // ����musicThread���槹��
			mciSendString(L"open \"losing.mp3\" type mpegvideo alias mp3", NULL, 0, NULL); // ���}����
			mciSendString(L"play mp3", NULL, 0, NULL); // ������
			system("pause");
			mciSendString(L"close mp3", NULL, 0, NULL); // ��������
			return 2;
		}
	}
}