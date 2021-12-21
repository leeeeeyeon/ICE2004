#include "Media.h" // Media.h 헤더파일을 불러온다

#include <iostream> // iostream 헤더파일을 불러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

int Media::count = 0; // static 변수 count를 0으로 초기화

// 생성자 구현
Media::Media(string title, int length) {
	// set 함수를 이용한 데이터 멤버에 값 할당
	setLength(length);
	setTitle(title);
	count++; // Media 클래스를 생성, 즉 new를 할 때마다 count 증가하도록 함
}

// 데이터 멤버에 대한 set, get 함수 구현
void Media::setLength(int l) {
	length = l;
}

void Media::setTitle(string t) {
	title = t;
}

int Media::getLength() {
	return length;
}

string Media::getTitle() {
	return title;
}

// 소멸자 구현, 객체의 소멸을 확인하기 위해 출력문 추가
Media::~Media() {
	cout << "Media 소멸자 호출됨" << endl;
}

// << 연산자 오버로딩 - 전역함수
ostream& operator<<(ostream& out, Media* media) {
	out << media->getPlay() << endl;
	return out;
}

// + 연산자 오버로딩
Media* Media::operator+(Media* media) {
	return new Media(title, length + media->length); // length끼리 합친 값을 데이터 멤버로 가지는 새로운 객체를 생성
}