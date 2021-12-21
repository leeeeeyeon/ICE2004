#pragma once // ���� ��������� ���� �� ���ǵǴ� �� ����

#include "DVD.h" // DVD.h ��������� �ҷ��´�

// DVD Ŭ������ public���� ��ӹ޴� �Ļ� Ŭ���� LegalDVD ����
class LegalDVD : public DVD {
private: // �����͸�� ����
	string copyright;

public:
	LegalDVD(string, int, string, string); // title, length, license, copyright�� �Ű������� �ϴ� ������
	// ������ ����� ���� set, get �Լ�
	void setCopyright(string);
	string getCopyright();
	virtual void play(); // �������� ���� virtual ����
	virtual string getPlay(); // �������� ���� virtual ����
	~LegalDVD(); // �Ҹ���
};