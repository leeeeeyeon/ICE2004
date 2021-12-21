#pragma once // 중복 선언 방지

// 필요한 헤더파일을 불러온다
#include <iostream>
#include <string>

// 표준 네임스페이스 std를 사용한다.
using namespace std;

// int 타입을 Elem으로 재정의한다.
typedef int Elem;

// DoublyLinkedList를 구성하는 각 노드
class DNode {
private:
	Elem elem; // 노드의 원소
	DNode* prev = NULL; // 이전 노드
	DNode* next = NULL; // 다음 노드
	friend class DLinkedList; // DLinkedList에서 DNode를 접근할 수 있도록 한다.
};

class DLinkedList {
public:
	DLinkedList(); // 생성자
	~DLinkedList(); // 소멸자
	bool empty() const; // 리스트가 비었는지 여부를 반환
	const Elem& front() const; // 제일 앞에 있는 노드의 원소를 반환
	const Elem& back() const; // 제일 뒤에 있는 노드의 원소를 반환
	void addFront(const Elem& e); // 리스트의 앞에 원소를 추가
	void addBack(const Elem& e); // 리스트의 뒤에 원소를 추가
	void removeFront(); // 리스트 앞에 있는 원소를 제거
	void removeBack(); // 리스트 뒤에 있는 원소를 제거

	// 전체 리스트를 출력하는 함수
	void printAll() {
		DNode* ptr = header; // 첫 노드를 header로 지정
		while (ptr != trailer) { // 노드가 trailer가 될 때까지
			cout << ptr->elem << " "; // 노드의 원소를 출력
			ptr = ptr->next; // 다음 노드로 이동
		}
	}

private:
	DNode* header; // 가장 앞에 있는 노드
	DNode* trailer; // 가장 뒤에 있는 노드

protected:
	void add(DNode* v, const Elem& e); // 새로운 노드를 v 앞에 생성하는 함수
	void remove(DNode* v); // 노드를 제거하는 함수
	void connect(DNode* a, DNode* b) { // 두 노드를 연결하는 함수
		a->next = b;
		b->prev = a;
	}
};

DLinkedList::DLinkedList() { // 생성자
	header = new DNode; // header 노드 생성
	trailer = new DNode; // trailer 노드 생성
	header->next = trailer; // header의 다음 노드를 trailer로 설정
	trailer->prev = header; // trailer의 이전 노드를 header로 설정
}

DLinkedList::~DLinkedList() { // 소멸자
	while(!empty()) removeFront(); // 리스트가 빌 때까지 원소를 제거 (앞에서부터)
	delete header; // header의 메모리 해제
	delete trailer; // trailer의 메모리 해제
}

void DLinkedList::add(DNode* v, const Elem& e) { // 새로운 노드를 v 앞에 생성하는 함수
	DNode* u = new DNode; // 새로운 노드를 생성
	u->elem = e; // 노드의 원소 값 대입
	connect(v->prev, u); // 앞 노드와 새로운 노드를 연결
	connect(u, v); // 새로운 노드와 앞 노드를 연결
}

void DLinkedList::addFront(const Elem& e) { // 리스트의 앞에 원소를 추가
	add(header->next, e);
}

void DLinkedList::addBack(const Elem& e) { // 리스트의 뒤에 원소를 추가
	add(trailer, e);
}

void DLinkedList::remove(DNode* v) { // 노드를 제거하는 함수
	DNode* u = v->prev; // 새로운 노드 u를 만들어 v의 이전 노드로 설정
	DNode* w = v->next; // 새로운 노드 w를 만들어 v의 다음 노드로 설정
	u->next = w; // u의 다음 노드는 w
	w->prev = u; // w의 이전 노드는 u -> w와 u가 연결된 리스트가 만들어짐
	delete v; // v에 할당된 메모리 해제
}

void DLinkedList::removeFront() { // 리스트 앞에 있는 원소를 제거
	remove(header->next);
}

void DLinkedList::removeBack() { // 리스트 뒤에 있는 원소를 제거
	remove(trailer->prev);
}

bool DLinkedList::empty() const { // 리스트가 비었는지 여부를 반환
	return(header->next == trailer); // header의 다음 노드가 trailer이면 리스트가 비었다고 간주
}

const Elem& DLinkedList::front() const { // 제일 앞에 있는 노드의 원소를 반환
	return header->next->elem;
}

const Elem& DLinkedList::back() const { // 제일 뒤에 있는 노드의 원소를 반환
	return trailer->prev->elem;
}

// 전체 리스트의 front와 back을 출력하는 함수
void printList(const DLinkedList& list) {
	cout << "front: " << list.front() << ", back: " << list.back() << endl;
}