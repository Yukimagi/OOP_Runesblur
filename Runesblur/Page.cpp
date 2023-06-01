#include "Page.h"
#include <windows.h>

Page::Page(const string& music) // 建構時輸入音樂名稱
	: musicFile(music)
{
}

void Page::setMusicFile(const string& music) // 設定音樂名稱
{
	musicFile = music;
}

string Page::getMusicFile() const // 取得音樂名稱
{
	return musicFile;
}

void Page::setChange(bool changeFlag) // 設定是否換音樂
{
	changeMusic = changeFlag;
}

bool Page::getChange() const // 取得是否換音樂
{
	return changeMusic;
}

void Page::setScreenColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void Page::playMusic() // 撥放音樂
{
	setChange(false);
	string part1 = "open ";
	string quote = "\"";
	string part2 = " type mpegvideo alias mp3";
	string openline = part1 + quote + musicFile + quote + part2;  // 將打開音檔的語法串接起來
	wstring temp = wstring(openline.begin(), openline.end());  // 先將string轉成wstring
	LPCWSTR lpcwstr = temp.c_str();  // 再將wstring轉成LPCWSTR
	mciSendString(lpcwstr, NULL, 0, NULL);  // 打開音檔
	mciSendString(L"play mp3 repeat", NULL, 0, NULL);  // 撥放音檔，若音檔結束再重複播放
	while (true)
	{
		if (getChange() == true)  // 若要換音樂時
		{
			mciSendString(L"stop mp3", NULL, 0, NULL);  // 停止播放音檔
			break;
		}
	}
	mciSendString(L"close mp3", NULL, 0, NULL);  // 關閉音檔
}
