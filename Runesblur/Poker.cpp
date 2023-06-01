#include "Poker.h"

Poker::Poker(string n, int exp, int ele, Card s1, Card s2, Card s3, Card s4, Card s5, double aa, double ah, vector<string> theImage)
	: Maingamer(exp),
	name(n), element(ele), adjATK(aa), adjMaximumHP(ah), image(theImage)//�غc�l��l�ƻP�~�ӱo��ƪ�l��
{
	PokerCard[0] = s1;//�C�i�������d�P�ҹ������ޯ�(5��)
	PokerCard[1] = s2;
	PokerCard[2] = s3;
	PokerCard[3] = s4;
	PokerCard[4] = s5;
	currentHP = getMaximumHP();
}
double Poker::getATK()
{
	return Maingamer::getATK() * adjATK; // �����ݩʪ��}��(king)���������[��1.2
}
double Poker::getMaximumHP()
{
	return Maingamer::getMaximumHP() * adjMaximumHP; // ���o����̤j�ͩR��(�����ݩʨ���(king)�̤j�ͩR��*0.83)
}
double Poker::calculateDamage(int enemyElement, int n)
{
	switch (element)
	{
		//#�ˮ`����:�����O*(�ݩʥ[��)*�¤O�[��/10 
		/*RED�J��YEL�AYEL�J��PUR�APUR�J��GRN�AGRN�J��BLU�ABLU�J��RED�C
		�J����ݩʥ[���O1.5���A�Q�J��O0.75���A����1���C�ĪG�[�����`���p�U�]�O1���C */
	case 1:
		if (enemyElement == 2)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // ���J��*1.5�A���W�ۦ��¤O
		}
		else if (enemyElement == 5)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // �ŧJ��*0.75�A���W�ۦ��¤O
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//����
		}
		break;
	case 2:
		if (enemyElement == 3)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // ���J��*1.5 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else if (enemyElement == 1)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // ���J��*0.75 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//����
		}
		break;
	case 3:
		if (enemyElement == 4)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // ���J��*1.5 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else if (enemyElement == 2)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // ���J��*0.75 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//����
		}
		break;
	case 4:
		if (enemyElement == 5)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // ��J��*1.5 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else if (enemyElement == 3)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // ���J��*0.75 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//����
		}
		break;
	case 5:
		if (enemyElement == 1)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // �ŧJ��*1.5 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else if (enemyElement == 4)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // ��J��*0.75 ����}�⥻�������[��1.2 �A���W�ۦ��¤O
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//����
		}
		break;
	default:
		break;
	}
}
int Poker::getSpeed(int type)
{
	return PokerCard[type - 1].speed;
}

string Poker::getName()
{
	return name;
}

double Poker::getCurrentHP()
{
	return currentHP;
}

void Poker::setCurrentHP(double cHP)
{
	currentHP = cHP;
}

bool Poker::underAttack(double dmg)
{
	if (currentHP <= dmg)
	{
		currentHP = 0;
		return 0;
	}
	else
	{
		currentHP -= dmg;
		return 1;
	}
}

string Poker::getSkillName(int n)
{
	return PokerCard[n - 1].name;
}

int Poker::getPower(int n)
{
	return PokerCard[n - 1].power;
}

bool Poker::checkLV(int n)
{
	if (PokerCard[n - 1].limit > getLV())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Poker::getElement()
{
	return element;
}

void Poker::setImage(vector<string> theImage)//�|������}��A�öi�ӱN���ƫ��w�쪺�ݩ�
                                              //�I�[��}�⨭�W�A�õo���@��!
{
	image = theImage;
}

vector<string> Poker::getImage()
{
	return image;
}