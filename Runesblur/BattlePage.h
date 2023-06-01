#ifndef BATTLEPAGE_H
#define BATTLEPAGE_H

#include "Page.h"
#include "Poker.h"
#include "Monster.h"
#include"GameLibrary.h"

class BattlePage : public Page
{
public:
	BattlePage(const string&, Poker*, Monster);
	virtual ~BattlePage() { }
	void setMyCharacter(Poker*);  //設定角色
	string getElementString(int);
	void renew();     //更新
	void setScreenColor(int);   //設定顏色
	int print(int*);
private:
	Poker* myCharacter;
	Monster enemy;

};

#endif