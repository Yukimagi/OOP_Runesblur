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
	void setMyCharacter(Poker*);  //�]�w����
	string getElementString(int);
	void renew();     //��s
	void setScreenColor(int);   //�]�w�C��
	int print(int*);
private:
	Poker* myCharacter;
	Monster enemy;

};

#endif