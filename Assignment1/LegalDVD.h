#pragma once // 같은 헤더파일이 여러 번 정의되는 것 방지

#include "DVD.h" // DVD.h 헤더파일을 불러온다

// DVD 클래스를 public으로 상속받는 파생 클래스 LegalDVD 정의
class LegalDVD : public DVD {
private: // 데이터멤버 선언
	string copyright;

public:
	LegalDVD(string, int, string, string); // title, length, license, copyright을 매개변수로 하는 생성자
	// 데이터 멤버에 대한 set, get 함수
	void setCopyright(string);
	string getCopyright();
	virtual void play(); // 다형성을 위해 virtual 선언
	virtual string getPlay(); // 다형성을 위해 virtual 선언
	~LegalDVD(); // 소멸자
};