#pragma once // 중복 선언 방지

// 필요한 헤더파일들을 불러온다
#include "ArrayVector.h"
#include <string>

// 표준 네임스페이스 std를 사용한다
using namespace std;

// 예외 클래스
class RuntimeException {
private:
	string errorMsg; // 에러 메세지

public:
	RuntimeException(const string& err) { // 생성자
		errorMsg = err; // 데이터 멤버 errorMsg에 err 변수의 값 대입
	}
	string getMessage() const { // errorMsg를 반환하는 함수
		return errorMsg;
	}
};

// << 연산자 오버로딩
inline ostream& operator<<(ostream& out, const RuntimeException& e) {
	return out << e.getMessage();
}

// 스택이 비어있을 때의 예외 상황
class StackEmpty : public RuntimeException {
public:
	StackEmpty(const string& err) :RuntimeException(err) {
	}
};


class ArrayVectorStack {
private:
	ArrayVector av; // ArrayVector 객체
	int av_size; // ArrayVector 객체의 크기
public:
	ArrayVectorStack(); // 생성자
	~ArrayVectorStack(); // 소멸자
	int size() const; // 스택의 크기를 출력하는 함수
	bool empty() const; // 스택이 비어있는지 여부를 나타내는 함수
	int& top() throw(StackEmpty); // 스택의 top을 반환하는 함수
	void push(const int e); // 스택에 원소를 추가하는 함수
	void pop() throw(StackEmpty); // 스택의 top을 pop하는 함수
};

ArrayVectorStack::ArrayVectorStack() // 생성자
	:av_size(0) { } // av_size를 0으로 초기화

int ArrayVectorStack::size() const { // 스택의 크기를 출력
	return av_size;
}

bool ArrayVectorStack::empty() const { // 스택이 비어있는지 여부를 나타내는 함수
	return av.empty(); // ArrayVector의 empty()를 사용
}

int& ArrayVectorStack::top() throw(StackEmpty) { // 스택의 top을 반환하는 함수
	if (empty()) throw StackEmpty("top of empty stack");
	return av.at(av.size()-1); // top의 index는 av.size()보다 1이 작다
}

void ArrayVectorStack::push(const int e) { // 스택에 원소를 추가하는 함수
	av.insert(av_size, e); // insert 함수를 이용하여 스택이 가득 차도 원소를 추가할 수 있다.
	av_size += 1;
}

void ArrayVectorStack::pop() throw(StackEmpty){ // 스택의 top을 pop하는 함수
	if (empty()) throw StackEmpty("pop of empty stack");
	av.erase(top()); // ArrayVector의 erase()를 사용
	av_size -= 1;
}