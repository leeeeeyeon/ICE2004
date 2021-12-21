#pragma once // 같은 헤더파일이 여러 번 정의되는 것 방지

#include "Media.h" // Media.h 헤더파일을 불러온다

class DVD : public Media { // Media 클래스를 public으로 상속받는 파생 클래스 DVD를 정의
private: // 데이터 멤버 선언
	string license;

public:
	DVD(string, int, string); // title, length, license를 매개변수로 하는 생성자
	// 데이터 멤버에 대한 set, get 함수
	void setLicense(string);
	string getLicense();
	virtual void play(); // 다형성을 위해 virtual 선언을 한 가상함수
	virtual string getPlay();
	~DVD(); // 소멸자
};