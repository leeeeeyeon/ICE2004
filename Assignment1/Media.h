#pragma once // ���� ��������� ���� �� ���ǵǴ� �� ����

#include <iostream>
#include <string> // string ��������� Ǯ���´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

class Media { // Media Ŭ���� ����
private: // ������ ��� title, string
	string title;
	int length;

public:
	static int count; // static ���� count
	Media(string, int); // title, length�� �Ű������� �ϴ� ������
	// ������ ����� ���� set, get �Լ�
	void setLength(int);
	void setTitle(string);
	int getLength();
	string getTitle();
	// �������� ���� virtual ����
	virtual void play() {
		cout << getPlay() << endl;
	}
	// �������� ���� virtual ����
	virtual string getPlay() {
		return "Media�� play�ǰ� �ֽ��ϴ�.";
	}
	virtual ~Media(); // virtual�� ������ �Ҹ��� -> Memory leak�� ���� ����

	// << ������ �����ε� - �����Լ�
	friend ostream& operator<<(ostream& out, Media* media);
	// + ������ �����ε�
	Media* operator+(Media* media);

};
