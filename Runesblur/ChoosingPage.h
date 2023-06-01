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

	void setArrow(COORD);  //設定箭頭位置
	COORD getArrow() const;  //取得箭頭位置

	void addChoicePos(vector<COORD>&, COORD);  //加入選項起始位置
	COORD getChoicePos(int);  //取得選項起始位置

	vector<Poker>& getAllPoker();

	void moveArrow(HANDLE, COORD, COORD);  //移動箭頭位置
	string getElementString(int);
	int reChoose();
	int print(int*);

private:
	vector<Poker> allPokers = { redElementCharacter, yellowElementCharacter, purpleElementCharacter, greenElementCharacter,blueElementCharacter };
	Monster enemy = monster[1];
	COORD arrow;  //箭頭位置
	vector<COORD> choicePos;  //選項位置
};

#endif
