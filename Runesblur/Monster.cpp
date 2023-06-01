#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Monster.h"

Monster::Monster(string n, double atk, double mhp, int e, Card s1, Card s2, Card s3, Card s4, Card s5, int ex, const vector<string> theImage)
	: name(n), element(e), exp(ex), image(theImage) // �Ǫ��m�W ���� �̤j��q �ݩ� �ۦ�
{
	MonsterCard[0] = s1;//���O�������i�Ǫ�(�d)
	MonsterCard[1] = s2;
	MonsterCard[2] = s3;
	MonsterCard[3] = s4;
	MonsterCard[4] = s5;
	setATK(atk);
	setMaximumHP(mhp);
	currentHP = mhp;
}

string Monster::getName()//���o�W��
{
	return name;
}

void Monster::setATK(double atk)//����
{
	ATK = atk;
}

int Monster::getElement()//�ݩ�
{
	return element;
}

double Monster::getATK()//����
{
	return ATK;
}

void Monster::setMaximumHP(double Mhp)//�̤j��q
{
	MaximumHP = Mhp;
}

double Monster::getMaximumHP()//�̤j��q
{
	return MaximumHP;
}

double Monster::getCurrentHP()//��e��q
{
	return currentHP;
}

void Monster::setCurrentHP(double cHP)//�̤j��q
{
	currentHP = cHP;
}

double Monster::calculateDamage(int e, int n) // ����ݩ� �ϥΩۦ�
{
	switch (element)
	{
		//#�ˮ`����:�����O*(�ݩʥ[��)*�¤O�[��/10 
	/*RED�J��YEL�AYEL�J��PUR�APUR�J��GRN�AGRN�J��BLU�ABLU�J��RED�C
	�J����ݩʥ[���O1.5���A�Q�J��O0.75���A����1���C�ĪG�[�����`���p�U�]�O1���C */
	case 1:
		if (e == 2)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // ���J��*1.5�A���W�ۦ��¤O
		}
		else if (e == 5)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // �ŧJ��*0.75�A���W�ۦ��¤O
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 2:
		if (e == 3)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // ���J��*1.5�A���W�ۦ��¤O
		}
		else if (e == 1)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // ���J��*0.75�A���W�ۦ��¤O
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 3:
		if (e == 4)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // ���J��*1.5�A���W�ۦ��¤O
		}
		else if (e == 2)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // ���J��*0.75�A���W�ۦ��¤O
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 4:
		if (e == 5)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // ��J��*1.5�A���W�ۦ��¤O
		}
		else if (e == 3)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // ���J��*0.75�A���W�ۦ��¤O
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 5:
		if (e == 1)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // �ŧJ��*1.5�A���W�ۦ��¤O
		}
		else if (e == 4)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // ��J��*0.75�A���W�ۦ��¤O
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	default:
		break;
	}
}

bool Monster::underAttack(double dmg)
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

int Monster::getSpeed(int type)
{
	return MonsterCard[type].speed;
};

string Monster::getSkillName(int n)
{
	return MonsterCard[n].name;
}

int Monster::getEXP()
{
	return exp;
}

void Monster::setImage(vector<string> theImage)//�|������Ǫ��A�öi�ӱN���ƫ��w�쪺�ݩ�
                                              //�I�[��Ǫ����W�A�õo���@��!
{
	image = theImage;
}

vector<string> Monster::getImage() const
{
	return image;
}