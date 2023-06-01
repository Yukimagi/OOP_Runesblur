#include "Maingamer.h"

#ifndef	POKER_H
#define POKER_H

#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Poker : public Maingamer
{
public:
	Poker(string, int, int, Card, Card, Card, Card, Card, double, double, vector<string>); // ��l�ƨ���m�W �g����ݩ�
	double calculateDamage(int, int); // �ǤJ�ĤH�ݩʤΧ����ۦ� �p��ˮ`�q�� �åB�^��damage
	string getName(); // ���o����W��
	virtual double getCurrentHP() override; // ���o�����e��q
	void setCurrentHP(double); // �]�m�����e��q
	bool underAttack(double); // �ǤJ�����������q �ק��e��q�� �^��bool 1���٬��� 0���` 
	virtual double getATK() override; // ���o��������O(���⨤������O*1.2)
	virtual double getMaximumHP() override; // ���o����̤j�ͩR��(���⨤��̤j�ͩR��*0.83)
	string getSkillName(int); // �ǤJn �^�ǲ�n�۪��W��
	int getPower(int); // �ǤJn �^�ǲ�n�۪��¤O
	int getSpeed(int); // �ǤJn �^�ǲ�n�۪��t��
	bool checkLV(int); // �ǤJ��n�� �ˬd�O�_�w�F�ϥθөۦ���LV �^��bool
	int getElement(); // �^�Ǩ����ݩ�
	void setImage(vector<string>); // �]�m����Ϯ� 
	vector<string> getImage(); // ���o����Ϯ� 

private:
	string name;
	double damage;
	double currentHP;
	const int element; // ex:����=1
	const double adjATK;
	const double adjMaximumHP;
	Card PokerCard[5] = { Card("default",0,0,0,0),Card("default",0,0,0,0),Card("default",0,0,0,0),Card("default",0,0,0,0),Card("default",0,0,0,0) }; // �ۦ��W�� �¤O �t�� �ĴX�� �ۦ����ŭ���
	vector<string> image; // ����Ϯ� 
};

#endif
