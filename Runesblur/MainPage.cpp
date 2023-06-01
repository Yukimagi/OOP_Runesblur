#include "MainPage.h"
#include "GameLibrary.h"
#include <iostream>
#include <thread>
#include <iomanip>

MainPage::MainPage(const string& music, const vector<string> theLogo, const vector<string> theChoices, const vector<string> left, const vector<string> right)  //�غc�l
	: Page(music), logo(theLogo), choices(theChoices), leftGraph(left), rightGraph(right)
{
}

void MainPage::setLogo(const vector<string> theLogo)  // �]�w�Dlogo
{
	logo = theLogo;
}

vector<string> MainPage::getLogo() const // ���ologo
{
	return logo;
}

void MainPage::setChoices(const vector<string> theChoices)  // �]�w�ﶵ
{
	choices = theChoices;
}

vector<string> MainPage::getChoices() const  // ���o�ﶵ
{
	return choices;
}

void MainPage::setArrow(COORD pos)  // �]�w�b�Y��m
{
	arrow = pos;
}

COORD MainPage::getArrow() const  // ���o�b�Y��m
{
	return arrow;
}

void MainPage::addChoicePos(vector<COORD>& pos, COORD thePos)  // �[�J�ﶵ��m
{
	pos.push_back(thePos);
}

COORD MainPage::getChoicePos(int n)  // ���o�ﶵ��m
{
	return choicePos[n];
}

void MainPage::moveArrow(HANDLE hConsole, COORD pos, COORD fPos)  // ���ʽb�Y
{
	setScreenColor(RED);  // �N�r��]�w������

	SetConsoleCursorPosition(hConsole, arrow);  // �N��J�I����b�Y�{�b��m
	cout << "�@";  // �M���쥻���b�Y
	SetConsoleCursorPosition(hConsole, pos);  // �N��J�I����ؼЦ�m
	cout << "��";  // �L�X�b�Y
	SetConsoleCursorPosition(hConsole, fPos);  // �N��J�I���^�̫᭱
	arrow = pos;  // ��s�b�Y��m

	setScreenColor(WHITE);  // �N�r���C���^�զ�
}

int MainPage::print(int*)  // �e���i��
{
	system("cls");
	thread musicThread(&Page::playMusic, this);  // ���񭵼�

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	setScreenColor(YELLOW);  // �r��]�w������

	cout << "\n\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i < (int)logo.size(); i++)  // �C�Llogo
	{
		cout << setw(113) << logo[i] << "\n";
		Sleep(100);
	}

	setScreenColor(WHITE); // �r��]�w�^�զ�

	cout << "\n\n\n\n\n\n\n\n";

	SHORT minX = 76;  // �����ﶵ���_�l��m�̥���̪�X�y�Э�
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	for (int i = 0; i < (int)choices.size(); i++)  // �C�L�ﶵ
	{
		cout << setw(76 + choices[i].length() / 2) << choices[i];  // �L�X�ﶵ�A�m��
		GetConsoleScreenBufferInfo(hConsole, &csbi);  // ���o�D���x�ù���T
		COORD temp = csbi.dwCursorPosition;  // ���o�ثe��J�I��m
		temp.X -= choices[i].length();  // ���o�ﶵ�}�Y��m (�N�ثe��J�I��m��X�ȴ�ӿﶵ���r�����)
		addChoicePos(choicePos, temp);  // �N�ﶵ�}�Y��m�����bchoicePos��
		if (temp.X < minX)  // �Y���ﶵ���}�Y��m����e��minX����A�N�NminX�]�����ﶵ�}�Y��m
			minX = temp.X;
		cout << "\n\n\n\n\n\n";
	}

	int minY = choicePos[0].Y;  // �����Ĥ@�ӿﶵ���y��Y��
	int maxY = choicePos[choicePos.size() - 1].Y;  // �����̫�@�ӿﶵ���y��Y��

	arrow = { static_cast<short>(minX - 5), choicePos[0].Y };  // �N�b�Y�y�г]�b�Ĥ@�ӿﶵ�e��

	SHORT tempY = arrow.Y - 2;
	SetConsoleCursorPosition(hConsole, { 0, tempY });
	setScreenColor(YELLOW);
	for (int i = 0; i < 13; i++)
	{
		cout << setw(45) << leftGraph[i] << "\n"; // �L�X(��)
	}

	for (int i = 0; i < 13; i++)
	{
		SetConsoleCursorPosition(hConsole, { 110, tempY });
		cout << rightGraph[i]; // �L�X(�k)
		tempY++;
	}
	setScreenColor(WHITE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);  // ���o�D���x�ù���T
	COORD finalPos = csbi.dwCursorPosition;  // �����̫��J�I��m

	moveArrow(hConsole, arrow, finalPos);  // �L�X�@�}�l�b�Y��m

	while (true)
	{
		if ((GetKeyState(VK_DOWN) & 0x8000) && arrow.Y < maxY)  // �Y��������L�V�U��B�ثe�b�Y���b�̫�@�ӿﶵ
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y + 3) }, finalPos);  // �N�b�Y���ܤU�@�ӿﶵ
		}
		if ((GetKeyState(VK_UP) & 0x8000) && arrow.Y > minY)  // �Y��������L�V�W��B�ثe�b�Y���b�Ĥ@�ӿﶵ
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y - 3) }, finalPos);  // �N�b�Y���ܤW�@�ӿﶵ
		}
		if (GetKeyState(VK_RETURN) & 0x8000)  // �Y��������LEnter��
		{
			static int finalChoice;
			for (int i = 0; i < (int)choicePos.size(); i++)  // ��X�b�Y�Ҧb�ﶵ�s��
			{
				if (choicePos[i].Y == arrow.Y)
				{
					finalChoice = i + 1;
					break;
				}
			}
			setChange(true);  // �N�󴫭��ֳ]��true
			musicThread.join();  // ����musicThread���槹��
			return finalChoice;  // �^�ǨϥΪ̿�����ﶵ�s��
		}
	}
}