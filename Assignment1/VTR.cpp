#include "VTR.h" // VTR.h ��������� �ҷ��´�

#include <iostream> // iostream ��������� �ҷ��´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

// ������ ����
VTR::VTR(string title, int length, string format)
	:Media(title, length) { // �θ� Ŭ������ ������ ����� �ʱ�ȭ�⸦ ����Ͽ� �ʱ�ȭ
	setFormat(format);
}

// ������ ����� ���� set, get �Լ�
void VTR::setFormat(string f) {
	format = f;
}

string VTR::getFormat() {
	return format;
}

void VTR::play() {
	cout << getPlay() << endl;
}

string VTR::getPlay() {
	return "VTR�� play�ǰ� �ֽ��ϴ�.";
}

// �Ҹ��� ����, ��ü�� �Ҹ��� Ȯ���ϱ� ���� ��¹� �߰�
VTR::~VTR() {
	cout << "VTR �Ҹ��� ȣ���" << endl;
}