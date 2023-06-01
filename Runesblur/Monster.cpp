#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Monster.h"

Monster::Monster(string n, double atk, double mhp, int e, Card s1, Card s2, Card s3, Card s4, Card s5, int ex, const vector<string> theImage)
	: name(n), element(e), exp(ex), image(theImage) // 怪物姓名 攻擊 最大血量 屬性 招式
{
	MonsterCard[0] = s1;//分別對應五張怪物(卡)
	MonsterCard[1] = s2;
	MonsterCard[2] = s3;
	MonsterCard[3] = s4;
	MonsterCard[4] = s5;
	setATK(atk);
	setMaximumHP(mhp);
	currentHP = mhp;
}

string Monster::getName()//取得名稱
{
	return name;
}

void Monster::setATK(double atk)//攻擊
{
	ATK = atk;
}

int Monster::getElement()//屬性
{
	return element;
}

double Monster::getATK()//攻擊
{
	return ATK;
}

void Monster::setMaximumHP(double Mhp)//最大血量
{
	MaximumHP = Mhp;
}

double Monster::getMaximumHP()//最大血量
{
	return MaximumHP;
}

double Monster::getCurrentHP()//當前血量
{
	return currentHP;
}

void Monster::setCurrentHP(double cHP)//最大血量
{
	currentHP = cHP;
}

double Monster::calculateDamage(int e, int n) // 對手屬性 使用招式
{
	switch (element)
	{
		//#傷害公式:攻擊力*(屬性加成)*威力加成/10 
	/*RED克制YEL，YEL克制PUR，PUR克制GRN，GRN克制BLU，BLU克制RED。
	克制時屬性加成是1.5倍，被克制是0.75倍，平屬1倍。效果加成正常情況下也是1倍。 */
	case 1:
		if (e == 2)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // 紅克黃*1.5再乘上招式威力
		}
		else if (e == 5)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // 藍克紅*0.75再乘上招式威力
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 2:
		if (e == 3)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // 黃克紫*1.5再乘上招式威力
		}
		else if (e == 1)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // 紅克黃*0.75再乘上招式威力
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 3:
		if (e == 4)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // 紫克綠*1.5再乘上招式威力
		}
		else if (e == 2)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // 黃克紫*0.75再乘上招式威力
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 4:
		if (e == 5)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // 綠克藍*1.5再乘上招式威力
		}
		else if (e == 3)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // 紫克綠*0.75再乘上招式威力
		}
		else
		{
			return getATK() * MonsterCard[n].power / 10;
		}
		break;
	case 5:
		if (e == 1)
		{
			return getATK() * 1.5 * MonsterCard[n].power / 10; // 藍克紅*1.5再乘上招式威力
		}
		else if (e == 4)
		{
			return getATK() * 0.75 * MonsterCard[n].power / 10; // 綠克藍*0.75再乘上招式威力
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

void Monster::setImage(vector<string> theImage)//會對應到怪物，並進而將那排指定到的屬性
                                              //施加於怪物身上，並發揮作用!
{
	image = theImage;
}

vector<string> Monster::getImage() const
{
	return image;
}