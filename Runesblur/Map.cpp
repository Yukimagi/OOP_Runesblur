#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Map.h"
using namespace std;

Map::Map() // 建構子
{
}

void Map::setExitPosition(int y, int x) // 設定出口位置
{
    exit_X = x;
    exit_Y = y;
    pointMap[exit_Y][exit_X] = 2;
}

void Map::setManPosition(int y, int x) // 設定主角起始位置
{
    man_X = x;
    man_Y = y;
    pointMap[man_Y][man_X] = 3;
}

int Map::getManY() const
{
    return man_Y;
}

int Map::getManX() const
{
    return man_X;
}

void Map::setBossPosition(int bossPos[][2]) // 設定怪物位置
{
    for (int i = 0; i < BossNum; i++)
    {
        boss_XY[i][0] = bossPos[i][0];
        boss_XY[i][1] = bossPos[i][1];
        pointMap[boss_XY[i][1]][boss_XY[i][0]] = 4;
    }
}

void Map::setMap(int* map) // 設定地圖
{
    for (int i = 0; i < MapRow; i++)
    {
        for (int j = 0; j < MapColumn; j++)
        {
            pointMap[i][j] = *map;
            map++;
        }
    }
}

void Map::setPoint(int Y, int X, int value)
{
    pointMap[Y][X] = value;
}

void Map::setVictory(int Y, int X, int value)
{
    victory[Y][X] = value;
}

void Map::printMap(int* mC) // 印出地圖
{
   
    system("cls");
    //cout << "\n\n\n\n\n\n" << setw(24) << "第 " << mC[0] << " 關:" << "\n\n\n\n";

    for (int i = 0; i < MapRow; i++)
    {
        cout << setw(34);
        for (int j = 0; j < MapColumn; j++)
        {
            if (pointMap[i][j] == Road) // 陣列元素為 0，列印路
            {
                cout << "  ";
            }
            else if (pointMap[i][j] == Wall) // 陣列元素為 1，列印牆
            {
                cout << "■";
            }
            else if (pointMap[i][j] == Exit) // 陣列元素為 2，列印出口
            {
                cout << "口";
            }
            else if (pointMap[i][j] == Man) // 陣列元素為 3，列印主角
            {
                cout << "Ａ";
            }
            else if (pointMap[i][j] == Boss) // 陣列元素為 4，列印怪物
            {
                cout << "※";
            }
            else if (pointMap[i][j] == Room) // 陣列元素為 5，列印pratice place
            {
                cout << "㊣";
            }
            else if (pointMap[i][j] == FinalBoss) // 陣列元素為 6，列印魔王
            {
                cout << "⊙";
            }
        }
        if (i == 0)
            cout << setw(22) << "< 主角 >";
        else if (i == 2)
            cout << setw(32) << "主角等級: " << mC[1] << " ( " << mC[2] << "/" << mC[3] << " )";
        else if (i == 4)
            cout << setw(22) << "< 角色 >"; // 角色
        else if (i == 6)
            cout << setw(30) << "角色一: king " << setw(16) << "屬性: RED" << setw(14) << "狀態: " << mC[4] << " / " << mC[5];
        else if (i == 8)
            cout << setw(30) << "角色二: queen " << setw(16) << "屬性: TEL" << setw(14) << "狀態: " << mC[6] << " / " << mC[7];
        else if (i == 10)
            cout << setw(30) << "角色三: joker " << setw(16) << "屬性: PUR" << setw(14) << "狀態: " << mC[8] << " / " << mC[9];
        else if (i == 12)
            cout << setw(30) << "角色四: soldier1 " << setw(16) << "屬性: GRN" << setw(14) << "狀態: " << mC[10] << " / " << mC[11];
        else if (i == 14)
            cout << setw(30) << "角色五: soldier2" << setw(16) << "屬性: BLU" << setw(14) << "狀態: " << mC[12] << " / " << mC[13];
        cout << endl;
    }
}