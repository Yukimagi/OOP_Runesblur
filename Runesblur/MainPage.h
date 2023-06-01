#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "Page.h"
#include <vector>
#include <windows.h>

class MainPage : public Page
{
public:
	MainPage(const string&, const vector<string>, const vector<string>, const vector<string>, const vector<string>);
	virtual ~MainPage() { }

	void setLogo(const vector<string>);  // 設定頁面主logo
	vector<string> getLogo() const;  // 取得頁面主logo

	void setChoices(const vector<string>);  // 設定下方選項
	vector<string> getChoices() const;  // 取得下方選項

	void setArrow(COORD);  // 設定箭頭位置
	COORD getArrow() const;  // 取得箭頭位置

	void addChoicePos(vector<COORD>&, COORD);  // 加入選項起始位置
	COORD getChoicePos(int);  // 取得選項起始位置
	void moveArrow(HANDLE, COORD, COORD);  // 移動箭頭位置
	int print(int*);  // 列印畫面

private:
	vector<string> logo;  // 主logo
	vector<string> choices;  // 選項
	vector<string> leftGraph;  //左邊圖案
	vector<string> rightGraph;  //右邊圖案
	vector<COORD> choicePos;  // 選項位置
	COORD arrow;  // 箭頭位置
};

#endif
