#include "Poker.h"

Poker::Poker(string n, int exp, int ele, Card s1, Card s2, Card s3, Card s4, Card s5, double aa, double ah, vector<string> theImage)
	: Maingamer(exp),
	name(n), element(ele), adjATK(aa), adjMaximumHP(ah), image(theImage)//建構子初始化與繼承得函數初始化
{
	PokerCard[0] = s1;//每張對應的卡牌所對應的技能(5種)
	PokerCard[1] = s2;
	PokerCard[2] = s3;
	PokerCard[3] = s4;
	PokerCard[4] = s5;
	currentHP = getMaximumHP();
}
double Poker::getATK()
{
	return Maingamer::getATK() * adjATK; // 紅色屬性的腳色(king)本身攻擊加乘1.2
}
double Poker::getMaximumHP()
{
	return Maingamer::getMaximumHP() * adjMaximumHP; // 取得角色最大生命值(紅色屬性角色(king)最大生命值*0.83)
}
double Poker::calculateDamage(int enemyElement, int n)
{
	switch (element)
	{
		//#傷害公式:攻擊力*(屬性加成)*威力加成/10 
		/*RED克制YEL，YEL克制PUR，PUR克制GRN，GRN克制BLU，BLU克制RED。
		克制時屬性加成是1.5倍，被克制是0.75倍，平屬1倍。效果加成正常情況下也是1倍。 */
	case 1:
		if (enemyElement == 2)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // 紅克黃*1.5再乘上招式威力
		}
		else if (enemyElement == 5)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // 藍克紅*0.75再乘上招式威力
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//平屬
		}
		break;
	case 2:
		if (enemyElement == 3)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // 黃克紫*1.5 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else if (enemyElement == 1)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // 紅克黃*0.75 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//平屬
		}
		break;
	case 3:
		if (enemyElement == 4)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // 紫克綠*1.5 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else if (enemyElement == 2)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // 黃克紫*0.75 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//平屬
		}
		break;
	case 4:
		if (enemyElement == 5)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // 綠克藍*1.5 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else if (enemyElement == 3)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // 紫克綠*0.75 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//平屬
		}
		break;
	case 5:
		if (enemyElement == 1)
		{
			return damage = getATK() * 1.5 * PokerCard[n - 1].power / 10; // 藍克紅*1.5 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else if (enemyElement == 4)
		{
			return damage = getATK() * 0.75 * PokerCard[n - 1].power / 10; // 綠克藍*0.75 紅色腳色本身攻擊加乘1.2 再乘上招式威力
		}
		else
		{
			return damage = getATK() * PokerCard[n - 1].power / 10;//平屬
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

void Poker::setImage(vector<string> theImage)//會對應到腳色，並進而將那排指定到的屬性
                                              //施加於腳色身上，並發揮作用!
{
	image = theImage;
}

vector<string> Poker::getImage()
{
	return image;
}