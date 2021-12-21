// 필요한 헤더파일을 불러온다
#include <iostream>
#include "DoublyLinkedList.h"

// 표준 네임스페이스 std를 사용한다
using namespace std;

int main(void) {
	cout << "12201937 이정연 과제 3- DoublyLinkedList" << endl;

	DLinkedList d; // 이중연결리스트 d 생성
	cout << "Is list empty? " << d.empty() << endl; // 리스트가 비었는지 확인
	cout << endl;

	// 최초 리스트의 상태 출력
	cout << "최초" << endl;
	printList(d);
	d.printAll();
	cout << endl;
	cout << endl;

	// addFront()를 3번 수행한 결과 출력
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

	// addBack()을 3번 수행한 결과 출력
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

	// removeFront()를 3번 수행한 결과 출력
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

	// removeBack()을 3번 수행한 결과 출력
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