#include "Page.h"
#include <windows.h>

Page::Page(const string& music) // �غc�ɿ�J���֦W��
	: musicFile(music)
{
}

void Page::setMusicFile(const string& music) // �]�w���֦W��
{
	musicFile = music;
}

string Page::getMusicFile() const // ���o���֦W��
{
	return musicFile;
}

void Page::setChange(bool changeFlag) // �]�w�O�_������
{
	changeMusic = changeFlag;
}

bool Page::getChange() const // ���o�O�_������
{
	return changeMusic;
}

void Page::setScreenColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void Page::playMusic() // ���񭵼�
{
	setChange(false);
	string part1 = "open ";
	string quote = "\"";
	string part2 = " type mpegvideo alias mp3";
	string openline = part1 + quote + musicFile + quote + part2;  // �N���}���ɪ��y�k�걵�_��
	wstring temp = wstring(openline.begin(), openline.end());  // ���Nstring�নwstring
	LPCWSTR lpcwstr = temp.c_str();  // �A�Nwstring�নLPCWSTR
	mciSendString(lpcwstr, NULL, 0, NULL);  // ���}����
	mciSendString(L"play mp3 repeat", NULL, 0, NULL);  // �����ɡA�Y���ɵ����A���Ƽ���
	while (true)
	{
		if (getChange() == true)  // �Y�n�����֮�
		{
			mciSendString(L"stop mp3", NULL, 0, NULL);  // �������
			break;
		}
	}
	mciSendString(L"close mp3", NULL, 0, NULL);  // ��������
}
