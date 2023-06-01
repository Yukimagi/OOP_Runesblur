#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Human.h"
using namespace std;

Human::Human()
{
}

void Human::move(char dir) // �ھڶǤJ����V�ϥD������
{
    switch (dir)
    {
    case 'U': // �W��
        man_Y -= 1;
        break;
    case 'D': // �U��
        man_Y += 1;
        break;
    case 'L': // ����
        man_X -= 1;
        break;
    case 'R': // �k��
        man_X += 1;
        break;
    default:
        break;
    }
}

bool Human::Up() // �V�W���@�B�C���\�A�^��ture�F���ѡA�^��false
{
    if (pointMap[man_Y - 1][man_X] == 1)
        return false;
    else
        pointMap[man_Y][man_X] = 0;
    move('U');
    pointMap[man_Y][man_X] = 3;
    return true;
}

bool Human::Down() // �V�U���@�B�C���\�A�^��ture�F���ѡA�^��false
{
    if (pointMap[man_Y + 1][man_X] == 1)
        return false;
    else
        pointMap[man_Y][man_X] = 0;
    move('D');
    pointMap[man_Y][man_X] = 3;
    return true;
}

bool Human::Left() // �V�����@�B�C���\�A�^��ture�F���ѡA�^��false
{
    if (pointMap[man_Y][man_X - 1] == 1)
        return false;
    else
        pointMap[man_Y][man_X] = 0;
    move('L');
    pointMap[man_Y][man_X] = 3;
    return true;
}

bool Human::Right() // �V�k���@�B�C���\�A�^��ture�F���ѡA�^��false
{
    if (pointMap[man_Y][man_X + 1] == 1)
        return false;
    else
        pointMap[man_Y][man_X] = 0;
    move('R');
    pointMap[man_Y][man_X] = 3;
    return true;
}

int Human::start(int* mC) // �C���}�l
{
    while (true)
    {
        if ((GetKeyState(VK_DOWN) & 0x8000))
        {
            Down();
            printMap(mC);
            Sleep(150);
        }
        if ((GetKeyState(VK_UP) & 0x8000))
        {
            Up();
            printMap(mC);
            Sleep(150);
        }
        if ((GetKeyState(VK_LEFT) & 0x8000))
        {
            Left();
            printMap(mC);
            Sleep(150);
        }
        if ((GetKeyState(VK_RIGHT) & 0x8000))
        {
            Right();
            printMap(mC);
            Sleep(150);
        }

        for (int i = 0; i < BossNum; i++)  // �P�_�O�_�J��Ǫ�
        {
            if (man_X == boss_XY[i][0] && man_Y == boss_XY[i][1] && victory[man_Y][man_X] == 0)
            {
                return 1;
            }
        }

        if (man_X == 1 && man_Y == 1)
        {
            pointMap[man_Y][man_X] = Room;
            if (pointMap[man_Y + 1][man_X])
            {
                man_X++;
                pointMap[man_Y][man_X] = Man;
            }
            else
            {
                man_Y++;
                pointMap[man_Y][man_X] = Man;
            }
            return 2;
        }

        if (man_X == exit_X && man_Y == exit_Y) // ��F�X�f
        {
            return 3;
        }

        if (man_X == 7 && man_Y == 7 && mC[0] == 6) // ��F�X�f
        {
            return 4;
        }
    }
}