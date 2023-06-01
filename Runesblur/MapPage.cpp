#include "MapPage.h"
#include "Human.h"
#include <thread>

MapPage::MapPage(const string& music, int theMap[][MapColumn], int exitX, int exitY, int manX, int manY, int bossPos[][2])
	: Page(music)
{
	setMap(*theMap); // 傳入地圖
	setExitPosition(exitY, exitX); // 設定出口位置(y, x)[注意:左上(0, 0)]
	setManPosition(manY, manX); // 設定主角起始位置(y, x)[注意:左上(0, 0)]
	setBossPosition(bossPos); // 設定怪物位置
}

int MapPage::print(int* mC)
{
	thread musicThread(&Page::playMusic, this); //撥放音樂
	printMap(mC); //印出起始地圖

	condition = start(mC); // 開始遊戲，紀錄結果
	setChange(true); // 將更換音樂設為true
	musicThread.join(); // 等待musicThread執行完畢
	return condition; // 回傳結果
}