#include "Media.h" // Media.h 헤더파일을 불러온다
#include "DVD.h" // DVD.h 헤더파일을 불러온다
#include "VTR.h" // VTR.h 헤더파일을 불러온다
#include "LegalDVD.h" // LegalDVD.h 헤더파일을 불러온다

#include <iostream> // iostream 헤더파일을 불러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

int main(void) {
	cout << "12201937 이정연 과제 1 출력화면" << endl;
	cout << endl;

	Media* mp[4]; // 포인터 배열 생성

	// new 키워드를 이용하여 각 포인터마다 객체를 할당해준다
	mp[0] = new VTR("Hello", 15, "avi");
	mp[1] = new DVD("Superman", 3, "123-9899");
	mp[2] = new LegalDVD("Marvel", 10, "456-9899", "GG entertainment");
	mp[3] = new VTR("Disney", 23, "mkv");

	// 다형성의 개념을 사용해 각 원소의 클래스에 맞는 play()를 호출한다.
	for (int i = 0; i < Media::count; i++)
		mp[i]->play();

	cout << endl;
	cout << "연산자 오버로딩 실습" << endl;

	cout << mp[0];
	cout << endl;

	mp[3] = *mp[1] + mp[2];
	cout << mp[3]->getLength() << endl;
	cout << endl;

	// Memory leak을 막기 위해 new로 할당해준 객체들을 delete해준다.
	for (int i = 0; i < Media::count; i++)
		delete mp[i];

	return 0;
}