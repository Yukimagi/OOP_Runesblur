#ifndef MAP_H
#define MAP_H

#include <iostream>

#define Road 0 // ��
#define Wall 1 // ��
#define Exit 2 // �X�f
#define Man 3 // �D��
#define Boss 4 // �Ǫ�
#define Room 5 // practice placce
#define FinalBoss 6// �]��

#define MapRow 15 // �a�Ϫ����
#define MapColumn 15 // �a�Ϫ��C��
#define BossNum 3  //�Ǫ����ƶq

class Map
{
public:
	Map();

	void setMap(int*); // �]�w�a��
	void setExitPosition(int, int); // �]�w�a�ϥX�f
	void setManPosition(int, int); // �]�w�D����m
	int getManY() const;  //���o�D����m
	int getManX() const;  //���o�D����m
	void setBossPosition(int[][2]); // �]�w�Ǫ���m
	void setPoint(int, int, int);  //�]�w�a�ϤW�@�I����
	void setVictory(int, int, int);
	void printMap(int* = 0); // �L�X�a��

protected:
	int pointMap[MapRow][MapColumn]; // �a�ϤG���}�C

	int victory[MapRow][MapColumn] = { 0 };

	int mapRow; // �G���}�C�����
	int mapColumn; // �G���}�C���C��
	// �X�f�y��
	int exit_X;
	int exit_Y;
	// �D����l�y��
	int man_X;
	int man_Y;
	// �Ǫ��y��
	int boss_XY[3][2]; // [3 : �Ǫ��ƶq] ; [2 : x,y�b]
};

#endif
