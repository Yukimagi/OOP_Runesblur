#pragma once
#ifndef GAMELIBRARY_H
#define GAMELIBRARY_H

#include <string>
#include <vector>
#include "Map.h"
#include "Poker.h"
#include "Monster.h"
using namespace std;

extern vector<string> systemMessage; // 設定系統訊息(主介面)
extern vector<string> pokemon2; //主畫面logo1
extern vector<string> congrats;  //贏的logo
extern vector<string> gameover;  //輸的logo
extern vector<string> chooselogo;  //選擇頁面logo
extern vector<string> homeChoice;  //主畫面選項
extern vector<string> endChoice;  //結束畫面選項
extern vector<string> mainLeft;  //封面左邊
extern vector<string> mainRight;  //封面右邊
extern vector<string> mainLeft_bad;  //Gameover
extern vector<string> mainRight_bad;  //Gameover右邊
extern vector<string> Left;  //Win左邊
extern vector<string>Right;  //Win右邊
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

extern int map1[MapRow][MapColumn]; // 地圖一
extern int boss1[BossNum][2]; // 地圖一 怪物座標
extern int map2[MapRow][MapColumn]; // 地圖二
extern int boss2[BossNum][2]; // 地圖二 怪物座標
extern int map3[MapRow][MapColumn]; // 地圖三
extern int boss3[BossNum][2]; // 地圖三 怪物座標
extern int map4[MapRow][MapColumn]; // 地圖四
extern int boss4[BossNum][2]; // 地圖四 怪物座標
extern int map5[MapRow][MapColumn]; // 地圖五
extern int boss5[BossNum][2]; // 地圖五 怪物座標
extern int map6[MapRow][MapColumn]; // 地圖六
extern int boss6[BossNum][2]; // 地圖六 怪物座標

//角色卡牌
extern Card RedPokerCard[5];
extern Card YellowPokerCard[5];
extern Card PurplePokerCard[5];
extern Card BluePokerCard[5];
extern Card GreenPokerCard[5];

//怪物卡牌
extern Card monsterCard[15][5];

extern Poker allPokers[5];

//角色物件
extern Poker redElementCharacter;
extern Poker yellowElementCharacter;
extern Poker greenElementCharacter;
extern Poker purpleElementCharacter;
extern Poker blueElementCharacter;

//怪物物件
extern Monster monster[15];

#endif