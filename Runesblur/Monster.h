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
    Monster(string, double, double, int, Card, Card, Card, Card, Card, int, const vector<string>); // �Ǫ��m�W ���� �̤j��q �ݩ� �ۦ�
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
    double calculateDamage(int, int); // �ǤJ������H�ݩ� �ΩǪ������ҭn�ϥΩۦ�
    string getSkillName(int); // �ǤJn �^�ǲ�n�۪��W��
    int getEXP();
    void setImage(vector<string>);//�]�m����Ϯ� 
    vector<string> getImage() const;//���o����Ϯ� 

private:
    string name;
    const int exp;
    double currentHP;
    const int element;

    Card MonsterCard[5] = { Card("defulat",0,0,0,0),Card("defulat",0,0,0,0),Card("defulat",0,0,0,0),Card("defulat",0,0,0,0),Card("defulat",0,0,0,0) };
    // �ۦ��W�� �¤O �t�� �ĴX�� �ۦ����ŭ���

    vector<string> image;
};

#endif
