#include <iostream>
#include "ArrayStack.h"
// iostream 헤더파일과 ArrayStack.h 헤더파일을 불러옴

using namespace std; // 표준네임스페이스 std를 사용

int main(void) {
	cout << "12201937 이정연 과제 2" << endl;

	ArrayStack<int> mystack(2); // capacity가 2이고, 원소들의 data type이 int형인 스택 생성

	cout << mystack.size() << endl; // 스택의 사이즈 출력, 스택 안에 아무 것도 없으므로 0이 출력됨

	mystack.push(1); // 스택에 1을 push, 스택 상황: 1
	mystack.push(2); // 스택에 2를 push, 스택 상황: 2 1

	cout << mystack.top() << endl; // 스택의 top을 출력, 2가 출력됨
	mystack.pop(); // top인 2가 pop되어 1만 스택에 남음

	cout << mystack.top() << endl; // 스택의 top인 1이 출력됨
	cout << mystack.size() << endl; // 스택의 크기 출력, 1이 출력됨
	 
	try { // 스택이 full인 상황에서 push를 하는 상황을 만듦
		mystack.push(3);
		mystack.push(4);

	}
	catch (StackFull& full) { // StackFullException 발생
		try {
			cout << full << endl; // 에러메세지 출력
			// 스택이 empty인 상황에서 pop을 하는 상황을 만듦
			mystack.pop();
			mystack.pop();
			mystack.pop();
		}
		catch (StackEmpty& empty) { // StackEmptyException 발생
			cout << empty << endl; // 에러메세지 출력
		}
	}

	return 0;
}