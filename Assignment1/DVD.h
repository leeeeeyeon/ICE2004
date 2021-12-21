#pragma once // ���� ��������� ���� �� ���ǵǴ� �� ����

#include "Media.h" // Media.h ��������� �ҷ��´�

class DVD : public Media { // Media Ŭ������ public���� ��ӹ޴� �Ļ� Ŭ���� DVD�� ����
private: // ������ ��� ����
	string license;

public:
	DVD(string, int, string); // title, length, license�� �Ű������� �ϴ� ������
	// ������ ����� ���� set, get �Լ�
	void setLicense(string);
	string getLicense();
	virtual void play(); // �������� ���� virtual ������ �� �����Լ�
	virtual string getPlay();
	~DVD(); // �Ҹ���
};