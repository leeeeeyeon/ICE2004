#pragma once // 중복 선언 방지

// 필요한 헤더파일들을 불러온다.
#include <algorithm>
#include <string>

// 표준 네임스페이스 std를 사용한다.
using namespace std;

// int를 Elem으로 재정의한다.
typedef int Elem;

// 예외 클래스
class IndexOutOfBounds {
public:
	IndexOutOfBounds(const string& err) { // 생성자
		errorMsg = err; // 데이터멤버 errorMsg에 err 변수의 값 대입
	}
private: // 데이터 멤버
	string errorMsg; // 에러메시지
};

class ArrayVector {
public:
	ArrayVector(); // 생성자
	~ArrayVector(); // 소멸자
	int size() const; // ArrayVector의 크기 반환
	bool empty() const; // ArrayVector가 비었는지 여부를 반환
	Elem& operator[] (int i); // [] 오버로딩, 인덱스를 이용하여 원소의 값에 접근
	Elem& at(int i) throw(IndexOutOfBounds); // 인덱스를 이용하여 원소의 값에 접근
	// 예외 발생 시(범위에서 벗어난 인덱스에 접근) IndexOutOfBounds를 throw
	void erase(int i); // 인덱스를 이용하여 원소를 삭제
	void insert(int i, const Elem& e); // 인덱스를 이용하여 원소 삽입
	void reserve(int N); // ArrayVector의 capacity를 늘린다
	int getCapacity() { return capacity; } // capacity 값을 반환
	int getN() { return n; }

private:
	int capacity; // Arrayvector의 size
	int n; // ArrayVector에 들어있는 원소의 개수
	Elem* A; // 원소를 저장하고 있는 배열
};

ArrayVector::ArrayVector() // 생성자
	:capacity(0), n(0), A(NULL) { } // 초기화기를 이용하여 초기 값 설정

ArrayVector::~ArrayVector() {
	delete[] A; // 사용이 끝난 A의 메모리 해제
}
int ArrayVector::size() const { // ArrayVector의 크기 반환
	return n;
}

bool ArrayVector::empty() const { // ArrayVector가 비었는지 여부를 반환
	return size() == 0; // size()가 0이면 true(1), 아니면 false(0)
}

Elem& ArrayVector::operator[] (int i) { // [] 오버로딩, 인덱스를 이용하여 원소의 값에 접근
	return A[i];
}

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) { // 인덱스를 이용하여 원소의 값에 접근
	// 예외 발생 시(범위에서 벗어난 인덱스에 접근) IndexOutOfBounds를 throw

	if (i < 0 || i >= n) { // 인덱스가 0보다 작거나, 현재 원소의 수보다 클 때
		throw IndexOutOfBounds("illegal index in function at()"); // 예외 발생
	}

	return A[i];
}

void ArrayVector::reserve(int N) { // ArrayVector의 capacity를 늘린다
	// ArrayVector의 크기가 ArrayVector의 원소의 개수보다 클 때 현재 함수에서 빠져나간다
	if (capacity >= N) return;
	Elem* B = new Elem[N]; // 크기가 N인, 원소를 저장할 새로운 배열 생성

	for (int j = 0; j < n; j++) // 배열 B에 배열 A의 값들을 대입 ( A 복사 )
		B[j] = A[j];

	if (A != NULL) delete[] A; // A의 메모리 해제
	A = B; // 배열 B를 A에 대입 > B가 새로운 A가 됨
	capacity = N; // ArrayVector의 크기를 N으로 한다
}

void ArrayVector::insert(int i, const Elem& e) { // 인덱스를 이용하여 원소 삽입
	if (n >= capacity) { // ArrayVector의 원소의 개수가 ArrayVector의 크기보다 클 때 
		reserve(max(1, 2 * capacity)); // reserve 함수를 이용하여 ArrayVector의 크기를 늘린다
		// 최초 capacity는 0이므로, 이 경우를 고려하여 처음 capacity를 늘릴 때는 1로,
		// 그 이후에는 2 * capacity가 되도록 구현
	}
	// cout << getCapacity() << endl;
	// cout << getN() << endl;
	// cout << sizeof(A) / sizeof(int) << endl;
	n++; // 벡터의 원소의 개수 + 1

	for (int j = n - 1; j > i; j--) // 반복문을 이용하여 오른쪽으로 한 칸씩 shift
		A[j + 1] = A[j];
	A[i] = e; // 인덱스에 해당하는 위치에 원소 삽입
}

void ArrayVector::erase(int i) { // 인덱스를 이용하여 원소 삭제
	for (int j = i + 1; j < n; j++) // 반복문을 이용하여 왼쪽으로 한 칸씩 shift
		A[j - 1] = A[j];
	n--; // ArrayVector의 원소의 개수 - 1
}