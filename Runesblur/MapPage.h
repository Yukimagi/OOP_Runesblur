#ifndef MAPPAGE_H
#define MAPPAGE_H

#include "Page.h"
#include "Human.h"
#include <vector>

class MapPage : public Page, public Human//建立runesblur迷宮畫面
{
public:
	MapPage(const string&, int[][MapColumn], int, int, int, int, int[][2]);
	virtual ~MapPage() { }

	void setCondition(int);
	int getCondition() const;

	int print(int*);

private:
	int condition;
};

#endif
