#pragma once // 같은 헤더파일이 여러 번 정의되는 것 방지

#include <iostream>
#include <string> // string 헤더파일을 풀러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

class Media { // Media 클래스 선언
private: // 데이터 멤버 title, string
	string title;
	int length;

public:
	static int count; // static 변수 count
	Media(string, int); // title, length를 매개변수로 하는 생성자
	// 데이터 멤버에 대한 set, get 함수
	void setLength(int);
	void setTitle(string);
	int getLength();
	string getTitle();
	// 다형성을 위해 virtual 선언
	virtual void play() {
		cout << getPlay() << endl;
	}
	// 다형성을 위해 virtual 선언
	virtual string getPlay() {
		return "Media가 play되고 있습니다.";
	}
	virtual ~Media(); // virtual을 적용한 소멸자 -> Memory leak을 막기 위함

	// << 연산자 오버로딩 - 전역함수
	friend ostream& operator<<(ostream& out, Media* media);
	// + 연산자 오버로딩
	Media* operator+(Media* media);

};
