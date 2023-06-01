#include "Poker.h"//勇者所使用的卡牌
#ifndef CARD_H
#define CARD_H
#include<string>
using namespace std;

class Card
{
	friend class Poker;//為了解決之前以switch在並呼叫的過程中無法直接使用private和protected的問題!
	friend class Monster;//為了解決之前以switch在並呼叫的過程中無法直接使用private和protected的問題!

public:
	Card(string, double, double, int, int); // 初始化招式名稱 威力 速度 第幾招 招式等級限制

private:
	string name; // 招式名
	double power; // 招式威力
	double speed; // 招式速度cost
	int type; // 第幾招
	int limit; // 招式等級限制
};
#endif