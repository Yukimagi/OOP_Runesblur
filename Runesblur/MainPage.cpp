#include "MainPage.h"
#include "GameLibrary.h"
#include <iostream>
#include <thread>
#include <iomanip>

MainPage::MainPage(const string& music, const vector<string> theLogo, const vector<string> theChoices, const vector<string> left, const vector<string> right)  //建構子
	: Page(music), logo(theLogo), choices(theChoices), leftGraph(left), rightGraph(right)
{
}

void MainPage::setLogo(const vector<string> theLogo)  // 設定主logo
{
	logo = theLogo;
}

vector<string> MainPage::getLogo() const // 取得logo
{
	return logo;
}

void MainPage::setChoices(const vector<string> theChoices)  // 設定選項
{
	choices = theChoices;
}

vector<string> MainPage::getChoices() const  // 取得選項
{
	return choices;
}

void MainPage::setArrow(COORD pos)  // 設定箭頭位置
{
	arrow = pos;
}

COORD MainPage::getArrow() const  // 取得箭頭位置
{
	return arrow;
}

void MainPage::addChoicePos(vector<COORD>& pos, COORD thePos)  // 加入選項位置
{
	pos.push_back(thePos);
}

COORD MainPage::getChoicePos(int n)  // 取得選項位置
{
	return choicePos[n];
}

void MainPage::moveArrow(HANDLE hConsole, COORD pos, COORD fPos)  // 移動箭頭
{
	setScreenColor(RED);  // 將字體設定為紅色

	SetConsoleCursorPosition(hConsole, arrow);  // 將輸入點移到箭頭現在位置
	cout << "　";  // 清掉原本的箭頭
	SetConsoleCursorPosition(hConsole, pos);  // 將輸入點移到目標位置
	cout << "◢";  // 印出箭頭
	SetConsoleCursorPosition(hConsole, fPos);  // 將輸入點移回最後面
	arrow = pos;  // 更新箭頭位置

	setScreenColor(WHITE);  // 將字體顏色改回白色
}

int MainPage::print(int*)  // 畫面進行
{
	system("cls");
	thread musicThread(&Page::playMusic, this);  // 撥放音樂

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	setScreenColor(YELLOW);  // 字體設定為黃色

	cout << "\n\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i < (int)logo.size(); i++)  // 列印logo
	{
		cout << setw(113) << logo[i] << "\n";
		Sleep(100);
	}

	setScreenColor(WHITE); // 字體設定回白色

	cout << "\n\n\n\n\n\n\n\n";

	SHORT minX = 76;  // 紀錄選項中起始位置最左邊者的X座標值
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	for (int i = 0; i < (int)choices.size(); i++)  // 列印選項
	{
		cout << setw(76 + choices[i].length() / 2) << choices[i];  // 印出選項，置中
		GetConsoleScreenBufferInfo(hConsole, &csbi);  // 取得主控台螢幕資訊
		COORD temp = csbi.dwCursorPosition;  // 取得目前輸入點位置
		temp.X -= choices[i].length();  // 取得選項開頭位置 (將目前輸入點位置的X值減掉該選項的字串長度)
		addChoicePos(choicePos, temp);  // 將選項開頭位置紀錄在choicePos中
		if (temp.X < minX)  // 若此選項之開頭位置比先前的minX更左邊，就將minX設為此選項開頭位置
			minX = temp.X;
		cout << "\n\n\n\n\n\n";
	}

	int minY = choicePos[0].Y;  // 紀錄第一個選項的座標Y值
	int maxY = choicePos[choicePos.size() - 1].Y;  // 紀錄最後一個選項的座標Y值

	arrow = { static_cast<short>(minX - 5), choicePos[0].Y };  // 將箭頭座標設在第一個選項前面

	SHORT tempY = arrow.Y - 2;
	SetConsoleCursorPosition(hConsole, { 0, tempY });
	setScreenColor(YELLOW);
	for (int i = 0; i < 13; i++)
	{
		cout << setw(45) << leftGraph[i] << "\n"; // 印出(左)
	}

	for (int i = 0; i < 13; i++)
	{
		SetConsoleCursorPosition(hConsole, { 110, tempY });
		cout << rightGraph[i]; // 印出(右)
		tempY++;
	}
	setScreenColor(WHITE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);  // 取得主控台螢幕資訊
	COORD finalPos = csbi.dwCursorPosition;  // 紀錄最後輸入點位置

	moveArrow(hConsole, arrow, finalPos);  // 印出一開始箭頭位置

	while (true)
	{
		if ((GetKeyState(VK_DOWN) & 0x8000) && arrow.Y < maxY)  // 若偵測到鍵盤向下鍵且目前箭頭不在最後一個選項
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y + 3) }, finalPos);  // 將箭頭移至下一個選項
		}
		if ((GetKeyState(VK_UP) & 0x8000) && arrow.Y > minY)  // 若偵測到鍵盤向上鍵且目前箭頭不在第一個選項
		{
			moveArrow(hConsole, { arrow.X, static_cast<short>(arrow.Y - 3) }, finalPos);  // 將箭頭移至上一個選項
		}
		if (GetKeyState(VK_RETURN) & 0x8000)  // 若偵測到鍵盤Enter鍵
		{
			static int finalChoice;
			for (int i = 0; i < (int)choicePos.size(); i++)  // 找出箭頭所在選項編號
			{
				if (choicePos[i].Y == arrow.Y)
				{
					finalChoice = i + 1;
					break;
				}
			}
			setChange(true);  // 將更換音樂設為true
			musicThread.join();  // 等待musicThread執行完畢
			return finalChoice;  // 回傳使用者選取的選項編號
		}
	}
}