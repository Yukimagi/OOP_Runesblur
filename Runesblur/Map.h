#ifndef MAP_H
#define MAP_H

#include <iostream>

#define Road 0 // 路
#define Wall 1 // 牆
#define Exit 2 // 出口
#define Man 3 // 主角
#define Boss 4 // 怪物
#define Room 5 // practice placce
#define FinalBoss 6// 魔王

#define MapRow 15 // 地圖的行數
#define MapColumn 15 // 地圖的列數
#define BossNum 3  //怪物的數量

class Map
{
public:
	Map();

	void setMap(int*); // 設定地圖
	void setExitPosition(int, int); // 設定地圖出口
	void setManPosition(int, int); // 設定主角位置
	int getManY() const;  //取得主角位置
	int getManX() const;  //取得主角位置
	void setBossPosition(int[][2]); // 設定怪物位置
	void setPoint(int, int, int);  //設定地圖上一點的值
	void setVictory(int, int, int);
	void printMap(int* = 0); // 印出地圖

protected:
	int pointMap[MapRow][MapColumn]; // 地圖二維陣列

	int victory[MapRow][MapColumn] = { 0 };

	int mapRow; // 二維陣列的行數
	int mapColumn; // 二維陣列的列數
	// 出口座標
	int exit_X;
	int exit_Y;
	// 主角初始座標
	int man_X;
	int man_Y;
	// 怪物座標
	int boss_XY[3][2]; // [3 : 怪物數量] ; [2 : x,y軸]
};

#endif
