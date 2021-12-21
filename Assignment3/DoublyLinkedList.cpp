// �ʿ��� ��������� �ҷ��´�
#include <iostream>
#include "DoublyLinkedList.h"

// ǥ�� ���ӽ����̽� std�� ����Ѵ�
using namespace std;

int main(void) {
	cout << "12201937 ������ ���� 3- DoublyLinkedList" << endl;

	DLinkedList d; // ���߿��Ḯ��Ʈ d ����
	cout << "Is list empty? " << d.empty() << endl; // ����Ʈ�� ������� Ȯ��
	cout << endl;

	// ���� ����Ʈ�� ���� ���
	cout << "����" << endl;
	printList(d);
	d.printAll();
	cout << endl;
	cout << endl;

	// addFront()�� 3�� ������ ��� ���
	cout << "addFront()" << endl;
	for (int i = 1; i <= 3; i++) {
		d.addFront(i);
		printList(d);
		cout << endl;
	}
	d.printAll();
	cout << endl;
	cout << endl;
	// { 3 2 1 }

	cout << endl;

	// addBack()�� 3�� ������ ��� ���
	cout << "addBack()" << endl;
	for (int i = 4; i <= 6; i++) {
		d.addBack(i);
		printList(d);
		cout << endl;
	}
	d.printAll();
	cout << endl;
	cout << endl;
	// { 3 2 1 4 5 6 }

	cout << endl;

	// removeFront()�� 3�� ������ ��� ���
	cout << "removeFront()" << endl;
	for (int i = 0; i < 3; i++) {
		d.removeFront();
		printList(d);
		cout << endl;
	}
	d.printAll();
	cout << endl;
	cout << endl;
	
	cout << endl;

	// removeBack()�� 3�� ������ ��� ���
	cout << "removeBack()" << endl;
	for (int i = 0; i < 3; i++) {
		d.removeBack();
		printList(d);
		cout << endl;
	}
	d.printAll();
	cout << endl;
	cout << endl;

	return 0;
}