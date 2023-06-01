
#include "Card.h"
#include <string>
using namespace std;

Card::Card(string n, double p, double s, int t, int l)
	:name(n), power(p), speed(s), type(t), limit(l)//進行初始化，並為了建立相對應的建構子!
{

};
