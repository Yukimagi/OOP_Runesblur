#include <stdexcept>
#include <iostream>
#include "Maingamer.h"
using namespace std;

int Maingamer::TotalEXP = 0; // ��l���R�A����

Maingamer::Maingamer(int initialExp)//��l�Ƹg���
{
	setTotalEXP(initialExp);
	updateStatus(initialExp);
}

double Maingamer::getTotalEXP()//�g���
{
	return TotalEXP;
}

void Maingamer::setTotalEXP(int experience)//�g���
{
	TotalEXP = experience;
}

int Maingamer::getLV()//����
{
	updateStatus(TotalEXP);
	return LV;
}

void Maingamer::setLV(int level)//����
{
	LV = level;
}

bool Maingamer::addEXP(int gainexp)//�g���
{
	setTotalEXP(gainexp + getTotalEXP());
	return updateStatus(TotalEXP);
}

double Maingamer::getATK()//����
{
	updateStatus(TotalEXP);
	return ATK;
}

void Maingamer::setATK(double attack)//����
{
	ATK = attack;
}

double Maingamer::getMaximumHP()//�̤j��q
{
	updateStatus(TotalEXP);
	return MaximumHP;
}

void Maingamer::setMaximumHP(double Maxhealth)//�̤j��q
{
	MaximumHP = Maxhealth;
}

bool Maingamer::updateStatus(int expAll)//���Ź��ç�s
{
	int temp = LV;
	if (0 <= expAll && expAll < 500)
	{
		LV = 1;
	}
	else if (500 <= expAll && expAll < 1200)
	{
		LV = 2;
	}
	else if (1200 <= expAll && expAll < 2000)
	{
		LV = 3;
	}
	else if (2000 <= expAll && expAll < 2800)
	{
		LV = 4;
	}
	else if (2800 <= expAll && expAll < 3600)
	{
		LV = 5;
	}
	else if (3600 <= expAll && expAll < 4300)
	{
		LV = 6;
	}
	else if (4300 <= expAll && expAll < 5200)
	{
		LV = 7;
	}
	else if (5200 <= expAll && expAll < 6200)
	{
		LV = 8;
	}
	else if (6200 <= expAll && expAll < 7000)
	{
		LV = 9;
	}
	else if (7000 <= expAll && expAll < 10000)
	{
		LV = 10;
	}
	else if (10000 <= expAll && expAll < 12000)
	{
		LV = 11;
	}
	else if (12000 <= expAll && expAll < 14000)
	{
		LV = 12;
	}
	else if (14000 <= expAll && expAll < 16000)
	{
		LV = 13;
	}
	else if (16000 <= expAll && expAll < 18000)
	{
		LV = 14;
	}
	else if (18000 <= expAll && expAll < 24000)
	{
		LV = 15;
	}
	else if (24000 <= expAll && expAll < 32000)
	{
		LV = 16;
	}
	else if (32000 <= expAll && expAll < 40000)
	{
		LV = 17;
	}
	else if (40000 <= expAll && expAll < 48000)
	{
		LV = 18;
	}
	else if (48000 <= expAll && expAll < 55000)
	{
		LV = 19;
	}
	else if (55000 <= expAll && expAll < 63000)
	{
		LV = 20;
	}
	else if (63000 <= expAll && expAll < 70000)
	{
		LV = 21;
	}
	else if (70000 <= expAll && expAll < 80000)
	{
		LV = 22;
	}
	else if (80000 <= expAll && expAll < 90000)
	{
		LV = 23;
	}
	else if (90000 <= expAll && expAll < 100000)
	{
		LV = 24;
	}
	else if (100000 <= expAll && expAll < 115000)
	{
		LV = 25;
	}
	else if (115000 <= expAll && expAll < 130000)
	{
		LV = 26;
	}
	else if (130000 <= expAll && expAll < 150000)
	{
		LV = 27;
	}
	else if (150000 <= expAll && expAll < 170000)
	{
		LV = 28;
	}
	else if (170000 <= expAll && expAll < 200000)
	{
		LV = 29;
	}
	else if (200000 <= expAll)
	{
		LV = 30;
	}
	else if (expAll < 0)
	{
		throw invalid_argument("Experience must be >= 0.0");
	}

	setATK(ATKList[LV]);
	setMaximumHP(MaximumHPList[LV]);
	setTotalEXP(expAll);

	if (temp < LV)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Maingamer::getCurrentEXP()
{
	return TotalEXP - expList[LV - 1];
}

int Maingamer::getNextEXP()
{
	return expList[LV] - expList[LV - 1];
}

void Maingamer::showEXPmessage()
{
	if (LV == 30)
	{
		cout << "EXP: MAX" << endl;
	}
	else
	{
		cout << "EXP: " << TotalEXP - expList[LV - 1] << " /" << expList[LV] << endl;
	}
}
