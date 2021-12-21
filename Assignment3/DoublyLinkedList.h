#pragma once // �ߺ� ���� ����

// �ʿ��� ��������� �ҷ��´�
#include <iostream>
#include <string>

// ǥ�� ���ӽ����̽� std�� ����Ѵ�.
using namespace std;

// int Ÿ���� Elem���� �������Ѵ�.
typedef int Elem;

// DoublyLinkedList�� �����ϴ� �� ���
class DNode {
private:
	Elem elem; // ����� ����
	DNode* prev = NULL; // ���� ���
	DNode* next = NULL; // ���� ���
	friend class DLinkedList; // DLinkedList���� DNode�� ������ �� �ֵ��� �Ѵ�.
};

class DLinkedList {
public:
	DLinkedList(); // ������
	~DLinkedList(); // �Ҹ���
	bool empty() const; // ����Ʈ�� ������� ���θ� ��ȯ
	const Elem& front() const; // ���� �տ� �ִ� ����� ���Ҹ� ��ȯ
	const Elem& back() const; // ���� �ڿ� �ִ� ����� ���Ҹ� ��ȯ
	void addFront(const Elem& e); // ����Ʈ�� �տ� ���Ҹ� �߰�
	void addBack(const Elem& e); // ����Ʈ�� �ڿ� ���Ҹ� �߰�
	void removeFront(); // ����Ʈ �տ� �ִ� ���Ҹ� ����
	void removeBack(); // ����Ʈ �ڿ� �ִ� ���Ҹ� ����

	// ��ü ����Ʈ�� ����ϴ� �Լ�
	void printAll() {
		DNode* ptr = header; // ù ��带 header�� ����
		while (ptr != trailer) { // ��尡 trailer�� �� ������
			cout << ptr->elem << " "; // ����� ���Ҹ� ���
			ptr = ptr->next; // ���� ���� �̵�
		}
	}

private:
	DNode* header; // ���� �տ� �ִ� ���
	DNode* trailer; // ���� �ڿ� �ִ� ���

protected:
	void add(DNode* v, const Elem& e); // ���ο� ��带 v �տ� �����ϴ� �Լ�
	void remove(DNode* v); // ��带 �����ϴ� �Լ�
	void connect(DNode* a, DNode* b) { // �� ��带 �����ϴ� �Լ�
		a->next = b;
		b->prev = a;
	}
};

DLinkedList::DLinkedList() { // ������
	header = new DNode; // header ��� ����
	trailer = new DNode; // trailer ��� ����
	header->next = trailer; // header�� ���� ��带 trailer�� ����
	trailer->prev = header; // trailer�� ���� ��带 header�� ����
}

DLinkedList::~DLinkedList() { // �Ҹ���
	while(!empty()) removeFront(); // ����Ʈ�� �� ������ ���Ҹ� ���� (�տ�������)
	delete header; // header�� �޸� ����
	delete trailer; // trailer�� �޸� ����
}

void DLinkedList::add(DNode* v, const Elem& e) { // ���ο� ��带 v �տ� �����ϴ� �Լ�
	DNode* u = new DNode; // ���ο� ��带 ����
	u->elem = e; // ����� ���� �� ����
	connect(v->prev, u); // �� ���� ���ο� ��带 ����
	connect(u, v); // ���ο� ���� �� ��带 ����
}

void DLinkedList::addFront(const Elem& e) { // ����Ʈ�� �տ� ���Ҹ� �߰�
	add(header->next, e);
}

void DLinkedList::addBack(const Elem& e) { // ����Ʈ�� �ڿ� ���Ҹ� �߰�
	add(trailer, e);
}

void DLinkedList::remove(DNode* v) { // ��带 �����ϴ� �Լ�
	DNode* u = v->prev; // ���ο� ��� u�� ����� v�� ���� ���� ����
	DNode* w = v->next; // ���ο� ��� w�� ����� v�� ���� ���� ����
	u->next = w; // u�� ���� ���� w
	w->prev = u; // w�� ���� ���� u -> w�� u�� ����� ����Ʈ�� �������
	delete v; // v�� �Ҵ�� �޸� ����
}

void DLinkedList::removeFront() { // ����Ʈ �տ� �ִ� ���Ҹ� ����
	remove(header->next);
}

void DLinkedList::removeBack() { // ����Ʈ �ڿ� �ִ� ���Ҹ� ����
	remove(trailer->prev);
}

bool DLinkedList::empty() const { // ����Ʈ�� ������� ���θ� ��ȯ
	return(header->next == trailer); // header�� ���� ��尡 trailer�̸� ����Ʈ�� ����ٰ� ����
}

const Elem& DLinkedList::front() const { // ���� �տ� �ִ� ����� ���Ҹ� ��ȯ
	return header->next->elem;
}

const Elem& DLinkedList::back() const { // ���� �ڿ� �ִ� ����� ���Ҹ� ��ȯ
	return trailer->prev->elem;
}

// ��ü ����Ʈ�� front�� back�� ����ϴ� �Լ�
void printList(const DLinkedList& list) {
	cout << "front: " << list.front() << ", back: " << list.back() << endl;
}