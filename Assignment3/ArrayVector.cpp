// �ʿ��� ������ϵ��� �ҷ��´�.
#include <iostream>
#include "ArrayVector.h"

// ǥ�� ���ӽ����̽� std�� ����Ѵ�.
using namespace std;

int main2(void) {
	cout << "12201937 ������ ���� 3 - ArrayVector" << endl;

	ArrayVector av; // ArrayVector ��ü av ����

	cout << "���� ArrayVector�� size: " << av.size() << endl; // ���� size ���
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

	cout << "���� ���� �� �迭: ";
	for (int i = 0; i < av.size(); i++)
		cout << av[i] << " ";
	cout << endl;
	cout << "capacity: " << av.getCapacity() << endl;
	cout << endl;
	cout << "size: " << av.size() << endl;
	cout << "operator[] �׽�Ʈ: av[3] = " << av[3] << endl;
	cout << "at() �׽�Ʈ: at(3) = " << av.at(3) << endl;

	av.erase(4);
	cout << "erase() �׽�Ʈ" << endl;
	cout << "erase(4) ���� �迭: ";
	for (int i = 0; i < av.size(); i++)
		cout << av[i] << " ";
	cout << endl;

	return 0;
}