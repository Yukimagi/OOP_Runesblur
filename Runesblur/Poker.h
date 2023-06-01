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
	Poker(string, int, int, Card, Card, Card, Card, Card, double, double, vector<string>); // 初始化角色姓名 經驗及屬性
	double calculateDamage(int, int); // 傳入敵人屬性及攻擊招式 計算傷害量後 並且回傳damage
	string getName(); // 取得角色名稱
	virtual double getCurrentHP() override; // 取得角色當前血量
	void setCurrentHP(double); // 設置角色當前血量
	bool underAttack(double); // 傳入角色受到攻擊量 修改當前血量後 回傳bool 1表還活著 0表死亡 
	virtual double getATK() override; // 取得角色攻擊力(紅色角色攻擊力*1.2)
	virtual double getMaximumHP() override; // 取得角色最大生命值(紅色角色最大生命值*0.83)
	string getSkillName(int); // 傳入n 回傳第n招的名稱
	int getPower(int); // 傳入n 回傳第n招的威力
	int getSpeed(int); // 傳入n 回傳第n招的速度
	bool checkLV(int); // 傳入第n招 檢查是否已達使用該招式的LV 回傳bool
	int getElement(); // 回傳角色屬性
	void setImage(vector<string>); // 設置角色圖案 
	vector<string> getImage(); // 取得角色圖案 

private:
	string name;
	double damage;
	double currentHP;
	const int element; // ex:紅屬=1
	const double adjATK;
	const double adjMaximumHP;
	Card PokerCard[5] = { Card("default",0,0,0,0),Card("default",0,0,0,0),Card("default",0,0,0,0),Card("default",0,0,0,0),Card("default",0,0,0,0) }; // 招式名稱 威力 速度 第幾招 招式等級限制
	vector<string> image; // 角色圖案 
};

#endif
