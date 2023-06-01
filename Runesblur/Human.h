#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include "Map.h"

class Human : public Map
{
public:
	Human();
	void move(char); // 根據傳入的方向使主角移動 

	bool Up(); // 向上移
	bool Down(); // 向下移
	bool Left(); // 向左移
	bool Right(); // 向右移
	int start(int*); // 遊戲開始

private:
	char direction;
};

#endif
