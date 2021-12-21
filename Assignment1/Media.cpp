#include "Media.h" // Media.h ��������� �ҷ��´�

#include <iostream> // iostream ��������� �ҷ��´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

int Media::count = 0; // static ���� count�� 0���� �ʱ�ȭ

// ������ ����
Media::Media(string title, int length) {
	// set �Լ��� �̿��� ������ ����� �� �Ҵ�
	setLength(length);
	setTitle(title);
	count++; // Media Ŭ������ ����, �� new�� �� ������ count �����ϵ��� ��
}

// ������ ����� ���� set, get �Լ� ����
void Media::setLength(int l) {
	length = l;
}

void Media::setTitle(string t) {
	title = t;
}

int Media::getLength() {
	return length;
}

string Media::getTitle() {
	return title;
}

// �Ҹ��� ����, ��ü�� �Ҹ��� Ȯ���ϱ� ���� ��¹� �߰�
Media::~Media() {
	cout << "Media �Ҹ��� ȣ���" << endl;
}

// << ������ �����ε� - �����Լ�
ostream& operator<<(ostream& out, Media* media) {
	out << media->getPlay() << endl;
	return out;
}

// + ������ �����ε�
Media* Media::operator+(Media* media) {
	return new Media(title, length + media->length); // length���� ��ģ ���� ������ ����� ������ ���ο� ��ü�� ����
}