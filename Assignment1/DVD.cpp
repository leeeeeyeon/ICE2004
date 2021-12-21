#include "DVD.h" // DVD.h 헤더파일을 불러온다

#include <iostream> // iostream 헤더파일을 불러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

// 생성자 구현
DVD::DVD(string title, int length, string license)
	:Media(title, length) { // 초기화기를 사용하여 부모 클래스의 데이터 멤버 초기화
	setLicense(license);
}

// 데이터 멤버에 대한 set, get 함수 구현
void DVD::setLicense(string l) {
	license = l;
}

string DVD::getLicense() {
	return license;
}

string DVD::getPlay() {
	return "DVD가 play되고 있습니다.";
}

void DVD::play() {
	cout << getPlay() << endl;
}

// 소멸자 구현, 객체의 소멸을 확인하기 위해 출력문 추가
DVD::~DVD() {
	cout << "DVD 소멸자 호출됨" << endl;
}