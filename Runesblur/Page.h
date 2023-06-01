#ifndef PAGE_H
#define PAGE_H
#define GREEN 2
#define BLUE 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7

#include <string>
using namespace std;

class Page
{
public:
	Page(const string&);
	virtual ~Page() { }

	void setMusicFile(const string&);  // 設定音樂檔案名稱
	string getMusicFile() const;  // 取得音樂檔案名稱

	void setChange(bool);  // 設定是否換音樂
	bool getChange() const;  // 取得是否換音樂

	void setScreenColor(int);
	void playMusic();  // 撥放音樂
	virtual int print(int*) = 0;

private:
	string musicFile;  // 音樂檔案名稱
	bool changeMusic;  // 是否換音樂的flag
};

#endif

