#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
#include "gamer.h"
#include "Card.h"
using namespace std;

class Monster : public gamer
{
public:
    Monster(string, double, double, int, Card, Card, Card, Card, Card, int, const vector<string>); // 怪物姓名 攻擊 最大血量 屬性 招式
    string getName();
    virtual double getATK();
    virtual void setATK(double);
    virtual double getMaximumHP();
    virtual void setMaximumHP(double);
    int getElement();
    double getCurrentHP();
    void setCurrentHP(double);
    bool underAttack(double);
    int getSpeed(int);
    double calculateDamage(int, int); // 傳入攻擊對象屬性 及怪物本身所要使用招式
    string getSkillName(int); // 傳入n 回傳第n招的名稱
    int getEXP();
    void setImage(vector<string>);//設置角色圖案 
    vector<string> getImage() const;//取得角色圖案 

private:
    string name;
    const int exp;
    double currentHP;
    const int element;

    Card MonsterCard[5] = { Card("defulat",0,0,0,0),Card("defulat",0,0,0,0),Card("defulat",0,0,0,0),Card("defulat",0,0,0,0),Card("defulat",0,0,0,0) };
    // 招式名稱 威力 速度 第幾招 招式等級限制

    vector<string> image;
};

#endif
