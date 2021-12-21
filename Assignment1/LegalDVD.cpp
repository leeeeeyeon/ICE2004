#include "LegalDVD.h" // LegalDVD.h ��������� �ҷ��´�

#include <iostream> // iostream ��������� �ҷ��´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

// ������ ����
LegalDVD::LegalDVD(string title, int length, string license, string copyright)
	:DVD(title, length, license) { // �θ� Ŭ������ ������ ����� �ʱ�ȭ�⸦ �̿��Ͽ� �ʱ�ȭ
	setCopyright(copyright);
}

// ������ ����� ���� set, get �Լ�
void LegalDVD::setCopyright(string c) {
	copyright = c;
}

string LegalDVD::getCopyright() {
	return copyright;
}

void LegalDVD::play() {
	cout << getPlay() << endl;
}

string LegalDVD::getPlay() {
	return "LegalDVD�� play�ǰ� �ֽ��ϴ�.";
}

// �Ҹ��� ����, ��ü�� �Ҹ��� Ȯ���ϱ� ���� ��¹� �߰�
LegalDVD::~LegalDVD() {
	cout << "LegalDVD �Ҹ��� ȣ���" << endl;
}