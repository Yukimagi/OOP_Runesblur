#include "Poker.h"//�i�̩ҨϥΪ��d�P
#ifndef CARD_H
#define CARD_H
#include<string>
using namespace std;

class Card
{
	friend class Poker;//���F�ѨM���e�Hswitch�b�éI�s���L�{���L�k�����ϥ�private�Mprotected�����D!
	friend class Monster;//���F�ѨM���e�Hswitch�b�éI�s���L�{���L�k�����ϥ�private�Mprotected�����D!

public:
	Card(string, double, double, int, int); // ��l�Ʃۦ��W�� �¤O �t�� �ĴX�� �ۦ����ŭ���

private:
	string name; // �ۦ��W
	double power; // �ۦ��¤O
	double speed; // �ۦ��t��cost
	int type; // �ĴX��
	int limit; // �ۦ����ŭ���
};
#endif