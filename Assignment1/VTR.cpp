#include "VTR.h" // VTR.h 헤더파일을 불러온다

#include <iostream> // iostream 헤더파일을 불러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

// 생성자 구현
VTR::VTR(string title, int length, string format)
	:Media(title, length) { // 부모 클래스의 데이터 멤버는 초기화기를 사용하여 초기화
	setFormat(format);
}

// 데이터 멤버에 대한 set, get 함수
void VTR::setFormat(string f) {
	format = f;
}

string VTR::getFormat() {
	return format;
}

void VTR::play() {
	cout << getPlay() << endl;
}

string VTR::getPlay() {
	return "VTR이 play되고 있습니다.";
}

// 소멸자 구현, 객체의 소멸을 확인하기 위해 출력문 추가
VTR::~VTR() {
	cout << "VTR 소멸자 호출됨" << endl;
}