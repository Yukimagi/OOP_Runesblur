#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include "Map.h"

class Human : public Map
{
public:
	Human();
	void move(char); // �ھڶǤJ����V�ϥD������ 

	bool Up(); // �V�W��
	bool Down(); // �V�U��
	bool Left(); // �V����
	bool Right(); // �V�k��
	int start(int*); // �C���}�l

private:
	char direction;
};

#endif
