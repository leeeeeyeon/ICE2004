#include <iostream>
#include "ArrayStack.h"
// iostream ������ϰ� ArrayStack.h ��������� �ҷ���

using namespace std; // ǥ�س��ӽ����̽� std�� ���

int main(void) {
	cout << "12201937 ������ ���� 2" << endl;

	ArrayStack<int> mystack(2); // capacity�� 2�̰�, ���ҵ��� data type�� int���� ���� ����

	cout << mystack.size() << endl; // ������ ������ ���, ���� �ȿ� �ƹ� �͵� �����Ƿ� 0�� ��µ�

	mystack.push(1); // ���ÿ� 1�� push, ���� ��Ȳ: 1
	mystack.push(2); // ���ÿ� 2�� push, ���� ��Ȳ: 2 1

	cout << mystack.top() << endl; // ������ top�� ���, 2�� ��µ�
	mystack.pop(); // top�� 2�� pop�Ǿ� 1�� ���ÿ� ����

	cout << mystack.top() << endl; // ������ top�� 1�� ��µ�
	cout << mystack.size() << endl; // ������ ũ�� ���, 1�� ��µ�
	 
	try { // ������ full�� ��Ȳ���� push�� �ϴ� ��Ȳ�� ����
		mystack.push(3);
		mystack.push(4);

	}
	catch (StackFull& full) { // StackFullException �߻�
		try {
			cout << full << endl; // �����޼��� ���
			// ������ empty�� ��Ȳ���� pop�� �ϴ� ��Ȳ�� ����
			mystack.pop();
			mystack.pop();
			mystack.pop();
		}
		catch (StackEmpty& empty) { // StackEmptyException �߻�
			cout << empty << endl; // �����޼��� ���
		}
	}

	return 0;
}