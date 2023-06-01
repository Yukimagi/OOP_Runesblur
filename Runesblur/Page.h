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

	void setMusicFile(const string&);  // �]�w�����ɮצW��
	string getMusicFile() const;  // ���o�����ɮצW��

	void setChange(bool);  // �]�w�O�_������
	bool getChange() const;  // ���o�O�_������

	void setScreenColor(int);
	void playMusic();  // ���񭵼�
	virtual int print(int*) = 0;

private:
	string musicFile;  // �����ɮצW��
	bool changeMusic;  // �O�_�����֪�flag
};

#endif

