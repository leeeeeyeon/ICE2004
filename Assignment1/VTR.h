#pragma once // 같은 헤더파일이 여러 번 정의되는 것 방지

#include "Media.h" // Media.h 헤더파일을 불러온다

// Media 클래스를 public으로 상속받는 파생 클래스 VTR을 정의
class VTR : public Media {
private: // 데이터 멤버 선언
	string format;

public:
	VTR(string, int, string); // title, length, format을 매개변수로 하는 생성자
	// 데이터 멤버에 대한 set, get 함수
	void setFormat(string);
	string getFormat();
	virtual void play(); // 다형성을 위해 virtual 선언
	virtual string getPlay();
	~VTR(); // 소멸자
};
