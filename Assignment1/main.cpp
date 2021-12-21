#include "Media.h" // Media.h ��������� �ҷ��´�
#include "DVD.h" // DVD.h ��������� �ҷ��´�
#include "VTR.h" // VTR.h ��������� �ҷ��´�
#include "LegalDVD.h" // LegalDVD.h ��������� �ҷ��´�

#include <iostream> // iostream ��������� �ҷ��´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

int main(void) {
	cout << "12201937 ������ ���� 1 ���ȭ��" << endl;
	cout << endl;

	Media* mp[4]; // ������ �迭 ����

	// new Ű���带 �̿��Ͽ� �� �����͸��� ��ü�� �Ҵ����ش�
	mp[0] = new VTR("Hello", 15, "avi");
	mp[1] = new DVD("Superman", 3, "123-9899");
	mp[2] = new LegalDVD("Marvel", 10, "456-9899", "GG entertainment");
	mp[3] = new VTR("Disney", 23, "mkv");

	// �������� ������ ����� �� ������ Ŭ������ �´� play()�� ȣ���Ѵ�.
	for (int i = 0; i < Media::count; i++)
		mp[i]->play();

	cout << endl;
	cout << "������ �����ε� �ǽ�" << endl;

	cout << mp[0];
	cout << endl;

	mp[3] = *mp[1] + mp[2];
	cout << mp[3]->getLength() << endl;
	cout << endl;

	// Memory leak�� ���� ���� new�� �Ҵ����� ��ü���� delete���ش�.
	for (int i = 0; i < Media::count; i++)
		delete mp[i];

	return 0;
}