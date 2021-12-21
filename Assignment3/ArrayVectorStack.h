#pragma once // �ߺ� ���� ����

// �ʿ��� ������ϵ��� �ҷ��´�
#include "ArrayVector.h"
#include <string>

// ǥ�� ���ӽ����̽� std�� ����Ѵ�
using namespace std;

// ���� Ŭ����
class RuntimeException {
private:
	string errorMsg; // ���� �޼���

public:
	RuntimeException(const string& err) { // ������
		errorMsg = err; // ������ ��� errorMsg�� err ������ �� ����
	}
	string getMessage() const { // errorMsg�� ��ȯ�ϴ� �Լ�
		return errorMsg;
	}
};

// << ������ �����ε�
inline ostream& operator<<(ostream& out, const RuntimeException& e) {
	return out << e.getMessage();
}

// ������ ������� ���� ���� ��Ȳ
class StackEmpty : public RuntimeException {
public:
	StackEmpty(const string& err) :RuntimeException(err) {
	}
};


class ArrayVectorStack {
private:
	ArrayVector av; // ArrayVector ��ü
	int av_size; // ArrayVector ��ü�� ũ��
public:
	ArrayVectorStack(); // ������
	~ArrayVectorStack(); // �Ҹ���
	int size() const; // ������ ũ�⸦ ����ϴ� �Լ�
	bool empty() const; // ������ ����ִ��� ���θ� ��Ÿ���� �Լ�
	int& top() throw(StackEmpty); // ������ top�� ��ȯ�ϴ� �Լ�
	void push(const int e); // ���ÿ� ���Ҹ� �߰��ϴ� �Լ�
	void pop() throw(StackEmpty); // ������ top�� pop�ϴ� �Լ�
};

ArrayVectorStack::ArrayVectorStack() // ������
	:av_size(0) { } // av_size�� 0���� �ʱ�ȭ

int ArrayVectorStack::size() const { // ������ ũ�⸦ ���
	return av_size;
}

bool ArrayVectorStack::empty() const { // ������ ����ִ��� ���θ� ��Ÿ���� �Լ�
	return av.empty(); // ArrayVector�� empty()�� ���
}

int& ArrayVectorStack::top() throw(StackEmpty) { // ������ top�� ��ȯ�ϴ� �Լ�
	if (empty()) throw StackEmpty("top of empty stack");
	return av.at(av.size()-1); // top�� index�� av.size()���� 1�� �۴�
}

void ArrayVectorStack::push(const int e) { // ���ÿ� ���Ҹ� �߰��ϴ� �Լ�
	av.insert(av_size, e); // insert �Լ��� �̿��Ͽ� ������ ���� ���� ���Ҹ� �߰��� �� �ִ�.
	av_size += 1;
}

void ArrayVectorStack::pop() throw(StackEmpty){ // ������ top�� pop�ϴ� �Լ�
	if (empty()) throw StackEmpty("pop of empty stack");
	av.erase(top()); // ArrayVector�� erase()�� ���
	av_size -= 1;
}