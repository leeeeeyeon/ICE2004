// ��������� �ҷ��´�
#include <iostream>
#include <string>
#include "ArrayVectorStack.h"

// ǥ�� ���ӽ����̽� std�� �ҷ��´�
using namespace std;

// stock span �˰���
void span(int rates[], int days, int stockspan[]) {
	ArrayVectorStack stack; // �ε����� ���� ����

	// stockspan�� ��¥�� ���� �ش��ϴ� ���� ��� �迭�̴�
	stockspan[0] = 1; // �ʱⰪ���� 1�� �����Ѵ�
	stack.push(0); // �ʱⰪ���� 0�� push�Ѵ�

	for (int i = 1; i < days; i++) {
		while (rates[i] > rates[stack.top()]) { // ���� ���� �ְ��� top�� �ش��ϴ� �ְ����� ũ��
			stack.pop(); // ���ÿ��� pop�Ѵ�

			if (stack.empty()) { // ������ ���������
				break; // ���� ���� �ִ��̹Ƿ� �ݺ������� ���´�.
			}
		}

		if (!stack.empty()) { // ������ ������� ������
			stockspan[i] = i - stack.top(); // ��¥�� ���̸� �迭�� ����ִ´�
		}
		else { // ������ ��������� ���� ���� �ִ��̹Ƿ�
			stockspan[i] = i + 1; // ���� ���� �����Ѵ� (index�� 1 �����Ƿ� +1�� ���־�� �Ѵ�)
		}

		stack.push(i); // ���� index�� stack�� ������ �ѹ����� �������־�� �Ѵ�
	}
}

// ����ǥ����� ����ǥ����� ��ȯ�ϴ� �˰���

// �����ȣ ó���� ���� ����ϴ� �Լ�, �켱���� ��
int pre(char c) {
	if (c == '/' || c == '*') return 2;
	else if (c == '+' || c == '-') return 1;
	else return -1;
}
void infixToPostfix(string infix) {
	ArrayVectorStack stack; // ���� ��ȣ�� ���� ����
	string result; // ��� ���� ���� ���ڿ�

	// ���ڿ��� ���̸�ŭ �ݺ��� ����
	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		// ���ڰ� ���ĺ� �Ǵ� �����̸� result�� �߰�
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		// ���ڰ� '('�̸� ���ÿ� push
		else if (c == '(')
			stack.push('(');

		// ���ڰ� ')'�̸�
		else if (c == ')') {
			while (stack.top() != '(') { // ������ top�� '('�� ������
				result += stack.top(); // ������ top�� result�� �߰��ϰ�
				stack.pop(); // ���ÿ��� top�� pop�Ѵ�
			}
			stack.pop(); // '('�� pop�Ѵ�
		}

		// �׷��� �ʴٸ�(���� ��ȣ�� ���´ٸ�)
		else {
			while (!stack.empty() && pre(infix[i]) <= pre(stack.top())) { // top�� ���� ��ȣ�� �켱 ������ ���ٸ� 
				result += stack.top(); // ���ڿ��� top�� �߰��ϰ�
				stack.pop(); // ���ÿ��� pop�Ѵ�
			}
			stack.push(c); // ���ÿ� ���ڸ� push�Ѵ�
		}
	}

	// ������ �� ������ ���ÿ� ����ִ� ���ҵ��� ���ڿ��� �߰��Ѵ�
	while (!stack.empty()) {
		result += stack.top();
		stack.pop();
	}

	cout << result << endl;
}

int main(void) {
	cout << "12201937 ������ ���� 3 - ArrayVectorStack" << endl;

	// 16 �������� ���� ���������� �������� ���δ�
	int rates[7] = { 6,4,1,2,1,3,5 };
	int stockspan[7];

	span(rates, 7, stockspan);

	cout << "{ 6,4,1,2,1,3,5 }" << endl;
	for (int i = 0; i < 7; i++) {
		cout << stockspan[i] << " ";
	}
	cout << endl;
	cout << endl;

	// �߰��� �� 1
	int rates2[6] = { 10, 4, 5, 90, 120, 80 };
	int stockspan2[6];

	span(rates2, 6, stockspan2);

	cout << "{ 10, 4, 5, 90, 120, 80 }" << endl;
	for (int i = 0; i < 6; i++) {
		cout << stockspan2[i] << " ";
	}
	cout << endl;
	cout << endl;

	// �߰��� �� 2
	int rates3[6] = { 31, 27, 14, 21, 30, 22 };
	int stockspan3[6];

	span(rates3, 6, stockspan3);

	cout << "{ 31, 27, 14, 21, 30, 22 }" << endl;
	for (int i = 0; i < 6; i++) {
		cout << stockspan3[i] << " ";
	}
	cout << endl;
	cout << endl;

	// 27 �������� ���� ���������� �������� ���δ�
	string one = "a*(b+c)/d";
	cout << "a*(b+c)/d" << endl;
	infixToPostfix(one);
	cout << endl;

	// �߰��� �� 1
	string two = "(a+b)+(c-d)";
	cout << "(a+b)+(c-d)" << endl;
	infixToPostfix(two);
	cout << endl;

	// �߰��� �� 2
	string three = "((a*(b+d)/e)-f*(g+h/k))";
	cout << "((a*(b+d)/e)-f*(g+h/k))" << endl;
	infixToPostfix(three);
	cout << endl;

	return 0;
}