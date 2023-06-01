#include "MapPage.h"
#include "Human.h"
#include <thread>

MapPage::MapPage(const string& music, int theMap[][MapColumn], int exitX, int exitY, int manX, int manY, int bossPos[][2])
	: Page(music)
{
	setMap(*theMap); // �ǤJ�a��
	setExitPosition(exitY, exitX); // �]�w�X�f��m(y, x)[�`�N:���W(0, 0)]
	setManPosition(manY, manX); // �]�w�D���_�l��m(y, x)[�`�N:���W(0, 0)]
	setBossPosition(bossPos); // �]�w�Ǫ���m
}

int MapPage::print(int* mC)
{
	thread musicThread(&Page::playMusic, this); //���񭵼�
	printMap(mC); //�L�X�_�l�a��

	condition = start(mC); // �}�l�C���A�������G
	setChange(true); // �N�󴫭��ֳ]��true
	musicThread.join(); // ����musicThread���槹��
	return condition; // �^�ǵ��G
}