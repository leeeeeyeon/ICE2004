#include "LegalDVD.h" // LegalDVD.h 헤더파일을 불러온다

#include <iostream> // iostream 헤더파일을 불러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

// 생성자 구현
LegalDVD::LegalDVD(string title, int length, string license, string copyright)
	:DVD(title, length, license) { // 부모 클래스의 데이터 멤버는 초기화기를 이용하여 초기화
	setCopyright(copyright);
}

// 데이터 멤버에 대한 set, get 함수
void LegalDVD::setCopyright(string c) {
	copyright = c;
}

string LegalDVD::getCopyright() {
	return copyright;
}

void LegalDVD::play() {
	cout << getPlay() << endl;
}

string LegalDVD::getPlay() {
	return "LegalDVD가 play되고 있습니다.";
}

// 소멸자 구현, 객체의 소멸을 확인하기 위해 출력문 추가
LegalDVD::~LegalDVD() {
	cout << "LegalDVD 소멸자 호출됨" << endl;
}