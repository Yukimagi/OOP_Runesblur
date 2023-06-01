#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Map.h"
using namespace std;

Map::Map() // �غc�l
{
}

void Map::setExitPosition(int y, int x) // �]�w�X�f��m
{
    exit_X = x;
    exit_Y = y;
    pointMap[exit_Y][exit_X] = 2;
}

void Map::setManPosition(int y, int x) // �]�w�D���_�l��m
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

void Map::setBossPosition(int bossPos[][2]) // �]�w�Ǫ���m
{
    for (int i = 0; i < BossNum; i++)
    {
        boss_XY[i][0] = bossPos[i][0];
        boss_XY[i][1] = bossPos[i][1];
        pointMap[boss_XY[i][1]][boss_XY[i][0]] = 4;
    }
}

void Map::setMap(int* map) // �]�w�a��
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

void Map::printMap(int* mC) // �L�X�a��
{
   
    system("cls");
    //cout << "\n\n\n\n\n\n" << setw(24) << "�� " << mC[0] << " ��:" << "\n\n\n\n";

    for (int i = 0; i < MapRow; i++)
    {
        cout << setw(34);
        for (int j = 0; j < MapColumn; j++)
        {
            if (pointMap[i][j] == Road) // �}�C������ 0�A�C�L��
            {
                cout << "  ";
            }
            else if (pointMap[i][j] == Wall) // �}�C������ 1�A�C�L��
            {
                cout << "��";
            }
            else if (pointMap[i][j] == Exit) // �}�C������ 2�A�C�L�X�f
            {
                cout << "�f";
            }
            else if (pointMap[i][j] == Man) // �}�C������ 3�A�C�L�D��
            {
                cout << "��";
            }
            else if (pointMap[i][j] == Boss) // �}�C������ 4�A�C�L�Ǫ�
            {
                cout << "��";
            }
            else if (pointMap[i][j] == Room) // �}�C������ 5�A�C�Lpratice place
            {
                cout << "��";
            }
            else if (pointMap[i][j] == FinalBoss) // �}�C������ 6�A�C�L�]��
            {
                cout << "��";
            }
        }
        if (i == 0)
            cout << setw(22) << "< �D�� >";
        else if (i == 2)
            cout << setw(32) << "�D������: " << mC[1] << " ( " << mC[2] << "/" << mC[3] << " )";
        else if (i == 4)
            cout << setw(22) << "< ���� >"; // ����
        else if (i == 6)
            cout << setw(30) << "����@: king " << setw(16) << "�ݩ�: RED" << setw(14) << "���A: " << mC[4] << " / " << mC[5];
        else if (i == 8)
            cout << setw(30) << "����G: queen " << setw(16) << "�ݩ�: TEL" << setw(14) << "���A: " << mC[6] << " / " << mC[7];
        else if (i == 10)
            cout << setw(30) << "����T: joker " << setw(16) << "�ݩ�: PUR" << setw(14) << "���A: " << mC[8] << " / " << mC[9];
        else if (i == 12)
            cout << setw(30) << "����|: soldier1 " << setw(16) << "�ݩ�: GRN" << setw(14) << "���A: " << mC[10] << " / " << mC[11];
        else if (i == 14)
            cout << setw(30) << "���⤭: soldier2" << setw(16) << "�ݩ�: BLU" << setw(14) << "���A: " << mC[12] << " / " << mC[13];
        cout << endl;
    }
}