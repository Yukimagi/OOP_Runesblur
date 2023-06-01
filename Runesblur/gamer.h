#ifndef GAMER_H
#define GAMER_H

class gamer //pure virtual based class
{
public:
	virtual double getATK() = 0;
	virtual void setATK(double) = 0;
	virtual double getMaximumHP() = 0;
	virtual void setMaximumHP(double) = 0;

protected:
	double ATK;
	double MaximumHP;
};

#endif
