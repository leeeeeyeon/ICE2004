#pragma once // ���� ��������� ���� �� ���ǵǴ� �� ����

#include "Media.h" // Media.h ��������� �ҷ��´�

// Media Ŭ������ public���� ��ӹ޴� �Ļ� Ŭ���� VTR�� ����
class VTR : public Media {
private: // ������ ��� ����
	string format;

public:
	VTR(string, int, string); // title, length, format�� �Ű������� �ϴ� ������
	// ������ ����� ���� set, get �Լ�
	void setFormat(string);
	string getFormat();
	virtual void play(); // �������� ���� virtual ����
	virtual string getPlay();
	~VTR(); // �Ҹ���
};
