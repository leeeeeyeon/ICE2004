// 필요한 헤더파일들을 불러온다.
#include <iostream>
#include "ArrayVector.h"

// 표준 네임스페이스 std를 사용한다.
using namespace std;

int main2(void) {
	cout << "12201937 이정연 과제 3 - ArrayVector" << endl;

	ArrayVector av; // ArrayVector 객체 av 생성

	cout << "최초 ArrayVector의 size: " << av.size() << endl; // 최초 size 출력
	cout << endl;
	cout << "Is vector empty? " << av.empty() << endl; 
	cout << "capacity: " << av.getCapacity() << endl;
	cout << endl;
	av.insert(0, 0); // capacity : 1 / av = { 0 }
	av.insert(1, 2); // capacity : 2 / av = { 0, 2 }
	av.insert(2, 4); // capacity : 4 / av = { 0, 4}
	av.insert(3, 6); // capacity : 4 / av = { 0, 6 }
	av.insert(4, 8); // capacity : 8 / av = { 0, 8 }
	av.insert(5, 10); // capacity : 8 / av = { 0, 10 }

	cout << "원소 삽입 후 배열: ";
	for (int i = 0; i < av.size(); i++)
		cout << av[i] << " ";
	cout << endl;
	cout << "capacity: " << av.getCapacity() << endl;
	cout << endl;
	cout << "size: " << av.size() << endl;
	cout << "operator[] 테스트: av[3] = " << av[3] << endl;
	cout << "at() 테스트: at(3) = " << av.at(3) << endl;

	av.erase(4);
	cout << "erase() 테스트" << endl;
	cout << "erase(4) 후의 배열: ";
	for (int i = 0; i < av.size(); i++)
		cout << av[i] << " ";
	cout << endl;

	return 0;
}