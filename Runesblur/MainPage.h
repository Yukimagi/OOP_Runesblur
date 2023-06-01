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

	void setLogo(const vector<string>);  // �]�w�����Dlogo
	vector<string> getLogo() const;  // ���o�����Dlogo

	void setChoices(const vector<string>);  // �]�w�U��ﶵ
	vector<string> getChoices() const;  // ���o�U��ﶵ

	void setArrow(COORD);  // �]�w�b�Y��m
	COORD getArrow() const;  // ���o�b�Y��m

	void addChoicePos(vector<COORD>&, COORD);  // �[�J�ﶵ�_�l��m
	COORD getChoicePos(int);  // ���o�ﶵ�_�l��m
	void moveArrow(HANDLE, COORD, COORD);  // ���ʽb�Y��m
	int print(int*);  // �C�L�e��

private:
	vector<string> logo;  // �Dlogo
	vector<string> choices;  // �ﶵ
	vector<string> leftGraph;  //����Ϯ�
	vector<string> rightGraph;  //�k��Ϯ�
	vector<COORD> choicePos;  // �ﶵ��m
	COORD arrow;  // �b�Y��m
};

#endif
