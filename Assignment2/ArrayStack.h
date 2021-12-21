#pragma once // ��������� �ߺ� ���� ����

#include <string> // string ��������� �ҷ���
using namespace std; // ǥ�� ���ӽ����̽� std ���

class RuntimeException { // RuntimeException ���� Ŭ����
private: // ������ ���
	string errorMsg; // ���� �޼���

public:
	RuntimeException(const string& err) { // RuntimeException ������
		errorMsg = err; // ������ ��� errorMsg�� err ������ �� ����
	}
	string getMessage() const { // errorMsg�� ��ȯ�ϴ� �Լ�
		return errorMsg;
	}
};
inline ostream& operator<<(ostream& out, const RuntimeException& e) { // errorMsg�� ����ϵ��� << ������ �����ε�
	return out << e.getMessage();
}

class StackEmpty : public RuntimeException { // RuntimeException Ŭ�������� �Ļ��� Ŭ����, ������ ������� ���� ���� ��Ȳ�� ��Ÿ��
public:
	StackEmpty(const string& err) : RuntimeException(err) { // StackEmpty ������
	}
};

class StackFull : public RuntimeException { // RuntimeException Ŭ�������� �Ļ��� Ŭ����, ������ �� á�� ���� ���� ��Ȳ�� ��Ÿ��
public:
	StackFull(const string& err) :RuntimeException(err) { // StackFull ������
	}
};

template <typename E>
class ArrayStack {
	enum { DEF_CAPACITY = 100 }; //��� DEF_CAPACITY ����

public:
	ArrayStack(int cap = DEF_CAPACITY); // ���ڰ� ���� �� DEF_CAPACITY�� capacity�� �ϴ� ������
	int size() const; // ������ ũ�⸦ ����ϴ� �Լ�
	bool empty() const; // ������ ����ִ��� ���θ� ��Ÿ���� �Լ�
	const E& top() const throw(StackEmpty); // ������ top�� ��ȯ�ϴ� �Լ�, ���� �߻� ��(������ ��� top�� ����) StackEmpty�� throw
	void push(const E& e) throw(StackFull); // ���ÿ� ���Ҹ� �߰��ϴ� �Լ�, ���� �߻� ��(������ ���� ��) StackFull�� throw
	void pop() throw(StackEmpty); // ������ top�� pop�ϴ� �Լ�

private: // ������ ���
	E* S; // ���� ������ �迭
	int capacity; // ������ ũ��
	int t; // ������ top�� index
};

template <typename E> ArrayStack<E>::ArrayStack(int cap) // ArrayStack�� ����� ������
	:S(new E[cap]), capacity(cap), t(-1) { }

template <typename E> int ArrayStack<E>::size() const { // ������ ũ�⸦ ���
	return (t + 1); // top�� �ε��� + 1�� ������ ũ��
}

template <typename E> bool ArrayStack<E>::empty() const { // ������ ����ִ��� ���θ� ��Ÿ���� �Լ�
	return (t < 0); // top�� index�� ���� ���� ���� 0, �� top�� 0���� ������ ������ �������
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) { // ������ top�� ��ȯ�ϴ� �Լ�, ���� �߻� ��(������ ��� top�� ����) StackEmpty�� throw
	if (empty()) throw StackEmpty("Top of empty stack"); // ������ ������� �� StackEmpty�� throw��
	return S[t]; // �׷��� ������ top�� S[t]�� ��ȯ
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) { // ���ÿ� ���Ҹ� �߰��ϴ� �Լ�, ���� �߻� ��(������ ���� ��) StackFull�� throw
	if (size() == capacity) throw StackFull("Push to full stack"); // ������ ũ�Ⱑ capacity�� ���� �� push�� �õ��ϸ� StackFull�� throw��
	S[++t] = e; // �׷��� ������ ���� top���� index�� 1 ū �ڸ��� ���ο� ���Ҹ� ����
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) { // ������ top�� pop�ϴ� �Լ�
	if (empty()) throw StackEmpty("Pop from empty stack"); // ������ ������� �� pop�� �õ��ϸ� StackEmpty�� throw��
	--t; // top�� index�� �ϳ� ����
}