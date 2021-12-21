#pragma once // 헤더파일의 중복 선언 방지

#include <string> // string 헤더파일을 불러옴
using namespace std; // 표준 네임스페이스 std 사용

class RuntimeException { // RuntimeException 예외 클래스
private: // 데이터 멤버
	string errorMsg; // 에러 메세지

public:
	RuntimeException(const string& err) { // RuntimeException 생성자
		errorMsg = err; // 데이터 멤버 errorMsg에 err 변수의 값 대입
	}
	string getMessage() const { // errorMsg를 반환하는 함수
		return errorMsg;
	}
};
inline ostream& operator<<(ostream& out, const RuntimeException& e) { // errorMsg를 출력하도록 << 연산자 오버로딩
	return out << e.getMessage();
}

class StackEmpty : public RuntimeException { // RuntimeException 클래스에서 파생된 클래스, 스택이 비어있을 때의 예외 상황을 나타냄
public:
	StackEmpty(const string& err) : RuntimeException(err) { // StackEmpty 생성자
	}
};

class StackFull : public RuntimeException { // RuntimeException 클래스에서 파생된 클래스, 스택이 다 찼을 때의 예외 상황을 나타냄
public:
	StackFull(const string& err) :RuntimeException(err) { // StackFull 생성자
	}
};

template <typename E>
class ArrayStack {
	enum { DEF_CAPACITY = 100 }; //상수 DEF_CAPACITY 선언

public:
	ArrayStack(int cap = DEF_CAPACITY); // 인자가 없을 때 DEF_CAPACITY를 capacity로 하는 생성자
	int size() const; // 스택의 크기를 출력하는 함수
	bool empty() const; // 스택이 비어있는지 여부를 나타내는 함수
	const E& top() const throw(StackEmpty); // 스택의 top을 반환하는 함수, 예외 발생 시(스택이 비어 top이 없음) StackEmpty를 throw
	void push(const E& e) throw(StackFull); // 스택에 원소를 추가하는 함수, 예외 발생 시(스택이 가득 참) StackFull을 throw
	void pop() throw(StackEmpty); // 스택의 top을 pop하는 함수

private: // 데이터 멤버
	E* S; // 스택 원소의 배열
	int capacity; // 스택의 크기
	int t; // 스택의 top의 index
};

template <typename E> ArrayStack<E>::ArrayStack(int cap) // ArrayStack을 만드는 생성자
	:S(new E[cap]), capacity(cap), t(-1) { }

template <typename E> int ArrayStack<E>::size() const { // 스택의 크기를 출력
	return (t + 1); // top의 인덱스 + 1이 스택의 크기
}

template <typename E> bool ArrayStack<E>::empty() const { // 스택이 비어있는지 여부를 나타내는 함수
	return (t < 0); // top의 index가 가장 작을 때가 0, 즉 top이 0보다 작으면 스택은 비어있음
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) { // 스택의 top을 반환하는 함수, 예외 발생 시(스택이 비어 top이 없음) StackEmpty를 throw
	if (empty()) throw StackEmpty("Top of empty stack"); // 스택이 비어있을 시 StackEmpty를 throw함
	return S[t]; // 그렇지 않으면 top인 S[t]를 반환
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) { // 스택에 원소를 추가하는 함수, 예외 발생 시(스택이 가득 참) StackFull을 throw
	if (size() == capacity) throw StackFull("Push to full stack"); // 스택의 크기가 capacity와 같을 때 push를 시도하면 StackFull을 throw함
	S[++t] = e; // 그렇지 않으면 이전 top보다 index가 1 큰 자리에 새로운 원소를 대입
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) { // 스택의 top을 pop하는 함수
	if (empty()) throw StackEmpty("Pop from empty stack"); // 스택이 비어있을 때 pop을 시도하면 StackEmpty를 throw함
	--t; // top의 index를 하나 내림
}