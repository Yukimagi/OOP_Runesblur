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

// �غc�D�e��(���֡B���󵥵�...)
MainPage home("opening.mp3", pokemon2, homeChoice, mainLeft, mainRight);
MainPage winGame("ending.mp3", congrats, endChoice, Left, Right);
MainPage loseGame("gameover.mp3", gameover, endChoice, mainLeft_bad, mainRight_bad);

// �غc�a��(���֡B���󵥵�...)
MapPage maps[6] =
{
	MapPage("walking.mp3", map1, 14, 4, 0, 11, boss1), // mp3��, �a��, �X�f�y��(x, y), �D���_�l�y��(x, y), �Ǫ���m
	MapPage("walking.mp3", map2, 13, 14, 0, 4, boss2),
	MapPage("walking.mp3", map3, 0, 13, 13, 0, boss3),
	MapPage("walking.mp3", map4, 13, 14, 0, 13, boss4),
	MapPage("walking.mp3", map5, 14, 7, 13, 14, boss5),
	MapPage("walking.mp3", map6, 16, 16, 14, 7, boss6)
};

// �غc�������
Maingamer* MCP1 = &redElementCharacter;//���
Maingamer* MCP2 = &yellowElementCharacter;//�ӦZ
Maingamer* MCP3 = &purpleElementCharacter;//�p��
Maingamer* MCP4 = &greenElementCharacter;//�M�h1
Maingamer* MCP5 = &blueElementCharacter;//�M�h2

int GameStart(int*); // �w�qgame start function
void MainCharacterStatus(int*); // ��s�D�����A
void CharacterStatus(int*); // ��s���⪬�A
void recoverCharacterStatus(); // �^�����⪬�A

int main()
{
	system("mode con: cols=240 lines=80");//�]�w����
	srand(time(NULL));

	int allCharacter[14] = { 0 }; // ���d  //�D��[���� ��e�g��� / �U�@���g���]  //����[��e��q / �̤j��q] * 5

	while (GameStart(allCharacter) == 1) // �C��start!!!
	{
	}

	return 0;
}

int GameStart(int* mC)
{
	int decision = home.print(mC); // �L�X�D�e���A�����ﶵ�s��
	if (decision == 1) // �Y��ܲĤ@��
	{
		mC[1] = MCP1->getLV();
		for (int i = 0; i < 6; i++)
		{
			mC[0] = i + 1;

			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			//cout.setf(ios::left);

			//�~�Ʊԭz�A�L���e��
			cout << setw(102) << "�Y��A���P�ꪺ����A�ӦZ�A�h�L�A�ӫǤp���A" << endl;
			cout << setw(108) << "�Q�H�����ǰe��g���Ť�j�a�W�A����A�ӦZ�A�h�L�A" << endl;
			cout << setw(120) << "�ӫǤp�����F�^��L�̪�����A�L�̥������_�⤤�����P�i���ܡA" << endl;
			cout << setw(80) << "�ðk�X�g���Ť�j�a��" << endl;
			Sleep(4000);
			
			
			while (true)
			{
				CharacterStatus(mC);
				int meet = maps[i].print(mC); // �i�J�D�a��
				if (meet == 1) // mob(�p��)
				{
					ChoosingPage choose("choosing.mp3", monster[1]);

					if (choose.print(mC) == 1) // win
					{
						maps[i].setVictory(maps[i].getManY(), maps[i].getManX(), 1);

						/*if (MCP1->addEXP(monster1.getEXP())) // ��s���⪬�A �çP�_�O�_�ɯ�
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

						/*if (MCP1->addEXP(monster1.getEXP())) // ��s���⪬�A �çP�_�O�_�ɯ�
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
				else if (meet == 3) // �L��
				{
					cout << "\n\n\n\n\n";
					cout << setw(60) << systemMessage[0];
					Sleep(2500);
					return winGame.print(mC);
				}
				else if (meet == 4) // boss(�]��)
				{
					ChoosingPage choose("choosing.mp3", monster[1]);

					if (choose.print(mC) == 1) // win
					{
						maps[i].setVictory(maps[i].getManY(), maps[i].getManX(), 1);

						/*if (MCP1->addEXP(monster1.getEXP())) // ��s���⪬�A �çP�_�O�_�ɯ�
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

void MainCharacterStatus(int* mC) // ��s�D�����A
{
	mC[1] = MCP1->getLV();
	mC[2] = MCP1->getCurrentEXP();
	mC[3] = MCP1->getNextEXP();
}

void CharacterStatus(int* mC) // ��s���⪬�A
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
	redElementCharacter.setCurrentHP(redElementCharacter.getMaximumHP()); // ���e��q�]�w���̤j��q
	yellowElementCharacter.setCurrentHP(yellowElementCharacter.getMaximumHP());
	purpleElementCharacter.setCurrentHP(purpleElementCharacter.getMaximumHP());
	greenElementCharacter.setCurrentHP(greenElementCharacter.getMaximumHP());
	blueElementCharacter.setCurrentHP(blueElementCharacter.getMaximumHP());
}