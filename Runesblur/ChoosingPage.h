#ifndef CHOOSING_H
#define CHOOSING_H
#include "Page.h"
#include "Poker.h"
#include "Monster.h"
#include "GameLibrary.h"
#include <windows.h>

class ChoosingPage : public Page
{
public:
	ChoosingPage(string, Monster);
	virtual ~ChoosingPage() { }

	void setArrow(COORD);  //�]�w�b�Y��m
	COORD getArrow() const;  //���o�b�Y��m

	void addChoicePos(vector<COORD>&, COORD);  //�[�J�ﶵ�_�l��m
	COORD getChoicePos(int);  //���o�ﶵ�_�l��m

	vector<Poker>& getAllPoker();

	void moveArrow(HANDLE, COORD, COORD);  //���ʽb�Y��m
	string getElementString(int);
	int reChoose();
	int print(int*);

private:
	vector<Poker> allPokers = { redElementCharacter, yellowElementCharacter, purpleElementCharacter, greenElementCharacter,blueElementCharacter };
	Monster enemy = monster[1];
	COORD arrow;  //�b�Y��m
	vector<COORD> choicePos;  //�ﶵ��m
};

#endif
