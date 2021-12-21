#include "DVD.h" // DVD.h ��������� �ҷ��´�

#include <iostream> // iostream ��������� �ҷ��´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

// ������ ����
DVD::DVD(string title, int length, string license)
	:Media(title, length) { // �ʱ�ȭ�⸦ ����Ͽ� �θ� Ŭ������ ������ ��� �ʱ�ȭ
	setLicense(license);
}

// ������ ����� ���� set, get �Լ� ����
void DVD::setLicense(string l) {
	license = l;
}

string DVD::getLicense() {
	return license;
}

string DVD::getPlay() {
	return "DVD�� play�ǰ� �ֽ��ϴ�.";
}

void DVD::play() {
	cout << getPlay() << endl;
}

// �Ҹ��� ����, ��ü�� �Ҹ��� Ȯ���ϱ� ���� ��¹� �߰�
DVD::~DVD() {
	cout << "DVD �Ҹ��� ȣ���" << endl;
}