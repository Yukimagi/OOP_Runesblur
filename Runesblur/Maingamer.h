#ifndef MAINGAMER_H
#define MAINGAMER_H

#include"gamer.h"

class Maingamer : public gamer
{
public:
	Maingamer(int = 0);
	double getTotalEXP();
	void setTotalEXP(int);
	int getLV();
	void setLV(int);
	virtual double getATK() override;
	virtual void setATK(double) override;
	virtual double getMaximumHP() override;
	virtual void setMaximumHP(double) override;
	bool addEXP(int); // �[�g��� �æ^��bool��ܬO�_�ɯ�
	virtual bool updateStatus(int); // �ھڥثe�g���`�M �վ�lv atk MaxHp ���ƭ� �æ^��bool��ܬO�_�ɯ�
	int getCurrentEXP();
	int getNextEXP();
	virtual double getCurrentHP() = 0; // ���o�����e��q
	void showEXPmessage();

private:
	static int TotalEXP;
	int LV;

	// �H�U���List�������¦���� �u���������O�P�̤j��q�|�ھڨ����ݩʶi��վ�(�h��)
	double MaximumHPList[31] =
	{
		1000,1500,2000,3000,4000,5000,7000,8500,10000,12000,
		20000,22000,24000,26500,28500,35000,36000,38000,40000,45000,
		50000,54000,56000,58000,60000,65000,67000,69500,72000,75000
	};
	double ATKList[31] =
	{
		300,400,500,550,600,700,900,1150,1300,1400,
		1500,1600,1700,1800,2000,2400,2600,2750,2900,3000,
		3250,3350,3500,3600,3750,4000,4200,4500,4750,5000
	};
	int expList[31] =
	{
		0,500,1200,2000,2800,3600,4300,5200,6200,7200,
		10000,12000,14000,16000,18000,24000,32000,40000,48000,55000,
		63000,70000,80000,90000,1000000,115000,130000,150000,170000,200000
	};
};

#endif
