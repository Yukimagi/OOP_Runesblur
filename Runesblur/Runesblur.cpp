#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <thread>
#include <time.h>
#include "Page.h"
#include "MainPage.h"
#include "Map.h"
#include "Human.h"
#include "MapPage.h"
#include "BattlePage.h"
#include "GameLibrary.h"
#include "gamer.h"
#include "Poker.h"
#include "Monster.h"
#include "ChoosingPage.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

// 建構主畫面(音樂、物件等等...)
MainPage home("opening.mp3", pokemon2, homeChoice, mainLeft, mainRight);
MainPage winGame("ending.mp3", congrats, endChoice, Left, Right);
MainPage loseGame("gameover.mp3", gameover, endChoice, mainLeft_bad, mainRight_bad);

// 建構地圖(音樂、物件等等...)
MapPage maps[6] =
{
	MapPage("walking.mp3", map1, 14, 4, 0, 11, boss1), // mp3檔, 地圖, 出口座標(x, y), 主角起始座標(x, y), 怪物位置
	MapPage("walking.mp3", map2, 13, 14, 0, 4, boss2),
	MapPage("walking.mp3", map3, 0, 13, 13, 0, boss3),
	MapPage("walking.mp3", map4, 13, 14, 0, 13, boss4),
	MapPage("walking.mp3", map5, 14, 7, 13, 14, boss5),
	MapPage("walking.mp3", map6, 16, 16, 14, 7, boss6)
};

// 建構角色指標
Maingamer* MCP1 = &redElementCharacter;//國王
Maingamer* MCP2 = &yellowElementCharacter;//皇后
Maingamer* MCP3 = &purpleElementCharacter;//小丑
Maingamer* MCP4 = &greenElementCharacter;//騎士1
Maingamer* MCP5 = &blueElementCharacter;//騎士2

int GameStart(int*); // 定義game start function
void MainCharacterStatus(int*); // 更新主角狀態
void CharacterStatus(int*); // 更新角色狀態
void recoverCharacterStatus(); // 回滿角色狀態

int main()
{
	system("mode con: cols=240 lines=80");//設定環境
	srand(time(NULL));

	int allCharacter[14] = { 0 }; // 關卡  //主角[等級 當前經驗值 / 下一等經驗值]  //角色[當前血量 / 最大血量] * 5

	while (GameStart(allCharacter) == 1) // 遊戲start!!!
	{
	}

	return 0;
}

int GameStart(int* mC)
{
	int decision = home.print(mC); // 印出主畫面，紀錄選項編號
	if (decision == 1) // 若選擇第一項
	{
		mC[1] = MCP1->getLV();
		for (int i = 0; i < 6; i++)
		{
			mC[0] = i + 1;

			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			//cout.setf(ios::left);

			//誤事敘述，過場畫面
			cout << setw(102) << "某日，橋牌國的國王，皇后，士兵，皇室小丑，" << endl;
			cout << setw(108) << "被隨機的傳送到迷離符文大地上，國王，皇后，士兵，" << endl;
			cout << setw(120) << "皇室小丑為了回到他們的王國，他們必須拿起手中的橋牌進行對抗，" << endl;
			cout << setw(80) << "並逃出迷離符文大地～" << endl;
			Sleep(4000);
			
			
			while (true)
			{
				CharacterStatus(mC);
				int meet = maps[i].print(mC); // 進入主地圖
				if (meet == 1) // mob(小怪)
				{
					ChoosingPage choose("choosing.mp3", monster[1]);

					if (choose.print(mC) == 1) // win
					{
						maps[i].setVictory(maps[i].getManY(), maps[i].getManX(), 1);

						/*if (MCP1->addEXP(monster1.getEXP())) // 更新角色狀態 並判斷是否升級
						{
							recoverCharacterStatus();
						}*/

						CharacterStatus(mC);
						MainCharacterStatus(mC);
						cout << "\n\n" << setw(90) << systemMessage[2];
						Sleep(2000);
					}
					else // lose
					{
						return loseGame.print(mC);
					}
				}
				else if (meet == 2) // practice space
				{
					ChoosingPage choose("choosing.mp3", monster[1]);
					if (choose.print(mC) == 1) // win
					{
						maps[i].setVictory(maps[i].getManY(), maps[i].getManX(), 1);

						/*if (MCP1->addEXP(monster1.getEXP())) // 更新角色狀態 並判斷是否升級
						{
							recoverCharacterStatus();
						}*/

						/*CharacterStatus(mC);
						MainCharacterStatus(mC);*/
					}
					else // lose
					{
						return loseGame.print(mC);
					}
				}
				else if (meet == 3) // 過關
				{
					cout << "\n\n\n\n\n";
					cout << setw(60) << systemMessage[0];
					Sleep(2500);
					return winGame.print(mC);
				}
				else if (meet == 4) // boss(魔王)
				{
					ChoosingPage choose("choosing.mp3", monster[1]);

					if (choose.print(mC) == 1) // win
					{
						maps[i].setVictory(maps[i].getManY(), maps[i].getManX(), 1);

						/*if (MCP1->addEXP(monster1.getEXP())) // 更新角色狀態 並判斷是否升級
						{
							recoverCharacterStatus();
						}*/

						/*CharacterStatus(mC);
						MainCharacterStatus(mC);*/

						cout << "\n\n" << setw(94) << systemMessage[1];
						Sleep(2000);
					}
					else // lose
					{
						return loseGame.print(mC);
					}
				}
			}
			system("cls");
		}
	}
	return 2;
}

void MainCharacterStatus(int* mC) // 更新主角狀態
{
	mC[1] = MCP1->getLV();
	mC[2] = MCP1->getCurrentEXP();
	mC[3] = MCP1->getNextEXP();
}

void CharacterStatus(int* mC) // 更新角色狀態
{
	mC[4] = MCP1->getCurrentHP();
	mC[5] = MCP1->getMaximumHP();
	mC[6] = MCP2->getCurrentHP();
	mC[7] = MCP2->getMaximumHP();
	mC[8] = MCP3->getCurrentHP();
	mC[9] = MCP3->getMaximumHP();
	mC[10] = MCP4->getCurrentHP();
	mC[11] = MCP4->getMaximumHP();
	mC[12] = MCP5->getCurrentHP();
	mC[13] = MCP5->getMaximumHP();
}

void recoverCharacterStatus()
{
	redElementCharacter.setCurrentHP(redElementCharacter.getMaximumHP()); // 把當前血量設定為最大血量
	yellowElementCharacter.setCurrentHP(yellowElementCharacter.getMaximumHP());
	purpleElementCharacter.setCurrentHP(purpleElementCharacter.getMaximumHP());
	greenElementCharacter.setCurrentHP(greenElementCharacter.getMaximumHP());
	blueElementCharacter.setCurrentHP(blueElementCharacter.getMaximumHP());
}