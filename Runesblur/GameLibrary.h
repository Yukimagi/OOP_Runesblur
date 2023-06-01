#pragma once
#ifndef GAMELIBRARY_H
#define GAMELIBRARY_H

#include <string>
#include <vector>
#include "Map.h"
#include "Poker.h"
#include "Monster.h"
using namespace std;

extern vector<string> systemMessage; // �]�w�t�ΰT��(�D����)
extern vector<string> pokemon2; //�D�e��logo1
extern vector<string> congrats;  //Ĺ��logo
extern vector<string> gameover;  //�骺logo
extern vector<string> chooselogo;  //��ܭ���logo
extern vector<string> homeChoice;  //�D�e���ﶵ
extern vector<string> endChoice;  //�����e���ﶵ
extern vector<string> mainLeft;  //�ʭ�����
extern vector<string> mainRight;  //�ʭ��k��
extern vector<string> mainLeft_bad;  //Gameover
extern vector<string> mainRight_bad;  //Gameover�k��
extern vector<string> Left;  //Win����
extern vector<string>Right;  //Win�k��
extern vector<string> king;
extern vector<string> queen;
extern vector<string> joker;
extern vector<string> soldier;
extern vector<string> heart;
extern vector<string> square;
extern vector<string> circle;
extern vector<string> pum;
extern vector<string> flower;
extern vector<string> ghost;
extern vector<string> cat;
extern vector<string> pumkin;
extern vector<string> witch;

extern int map1[MapRow][MapColumn]; // �a�Ϥ@
extern int boss1[BossNum][2]; // �a�Ϥ@ �Ǫ��y��
extern int map2[MapRow][MapColumn]; // �a�ϤG
extern int boss2[BossNum][2]; // �a�ϤG �Ǫ��y��
extern int map3[MapRow][MapColumn]; // �a�ϤT
extern int boss3[BossNum][2]; // �a�ϤT �Ǫ��y��
extern int map4[MapRow][MapColumn]; // �a�ϥ|
extern int boss4[BossNum][2]; // �a�ϥ| �Ǫ��y��
extern int map5[MapRow][MapColumn]; // �a�Ϥ�
extern int boss5[BossNum][2]; // �a�Ϥ� �Ǫ��y��
extern int map6[MapRow][MapColumn]; // �a�Ϥ�
extern int boss6[BossNum][2]; // �a�Ϥ� �Ǫ��y��

//����d�P
extern Card RedPokerCard[5];
extern Card YellowPokerCard[5];
extern Card PurplePokerCard[5];
extern Card BluePokerCard[5];
extern Card GreenPokerCard[5];

//�Ǫ��d�P
extern Card monsterCard[15][5];

extern Poker allPokers[5];

//���⪫��
extern Poker redElementCharacter;
extern Poker yellowElementCharacter;
extern Poker greenElementCharacter;
extern Poker purpleElementCharacter;
extern Poker blueElementCharacter;

//�Ǫ�����
extern Monster monster[15];

#endif