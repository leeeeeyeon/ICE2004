#pragma once // �ߺ� ���� ����

// �ʿ��� ������ϵ��� �ҷ��´�.
#include <algorithm>
#include <string>

// ǥ�� ���ӽ����̽� std�� ����Ѵ�.
using namespace std;

// int�� Elem���� �������Ѵ�.
typedef int Elem;

// ���� Ŭ����
class IndexOutOfBounds {
public:
	IndexOutOfBounds(const string& err) { // ������
		errorMsg = err; // �����͸�� errorMsg�� err ������ �� ����
	}
private: // ������ ���
	string errorMsg; // �����޽���
};

class ArrayVector {
public:
	ArrayVector(); // ������
	~ArrayVector(); // �Ҹ���
	int size() const; // ArrayVector�� ũ�� ��ȯ
	bool empty() const; // ArrayVector�� ������� ���θ� ��ȯ
	Elem& operator[] (int i); // [] �����ε�, �ε����� �̿��Ͽ� ������ ���� ����
	Elem& at(int i) throw(IndexOutOfBounds); // �ε����� �̿��Ͽ� ������ ���� ����
	// ���� �߻� ��(�������� ��� �ε����� ����) IndexOutOfBounds�� throw
	void erase(int i); // �ε����� �̿��Ͽ� ���Ҹ� ����
	void insert(int i, const Elem& e); // �ε����� �̿��Ͽ� ���� ����
	void reserve(int N); // ArrayVector�� capacity�� �ø���
	int getCapacity() { return capacity; } // capacity ���� ��ȯ
	int getN() { return n; }

private:
	int capacity; // Arrayvector�� size
	int n; // ArrayVector�� ����ִ� ������ ����
	Elem* A; // ���Ҹ� �����ϰ� �ִ� �迭
};

ArrayVector::ArrayVector() // ������
	:capacity(0), n(0), A(NULL) { } // �ʱ�ȭ�⸦ �̿��Ͽ� �ʱ� �� ����

ArrayVector::~ArrayVector() {
	delete[] A; // ����� ���� A�� �޸� ����
}
int ArrayVector::size() const { // ArrayVector�� ũ�� ��ȯ
	return n;
}

bool ArrayVector::empty() const { // ArrayVector�� ������� ���θ� ��ȯ
	return size() == 0; // size()�� 0�̸� true(1), �ƴϸ� false(0)
}

Elem& ArrayVector::operator[] (int i) { // [] �����ε�, �ε����� �̿��Ͽ� ������ ���� ����
	return A[i];
}

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) { // �ε����� �̿��Ͽ� ������ ���� ����
	// ���� �߻� ��(�������� ��� �ε����� ����) IndexOutOfBounds�� throw

	if (i < 0 || i >= n) { // �ε����� 0���� �۰ų�, ���� ������ ������ Ŭ ��
		throw IndexOutOfBounds("illegal index in function at()"); // ���� �߻�
	}

	return A[i];
}

void ArrayVector::reserve(int N) { // ArrayVector�� capacity�� �ø���
	// ArrayVector�� ũ�Ⱑ ArrayVector�� ������ �������� Ŭ �� ���� �Լ����� ����������
	if (capacity >= N) return;
	Elem* B = new Elem[N]; // ũ�Ⱑ N��, ���Ҹ� ������ ���ο� �迭 ����

	for (int j = 0; j < n; j++) // �迭 B�� �迭 A�� ������ ���� ( A ���� )
		B[j] = A[j];

	if (A != NULL) delete[] A; // A�� �޸� ����
	A = B; // �迭 B�� A�� ���� > B�� ���ο� A�� ��
	capacity = N; // ArrayVector�� ũ�⸦ N���� �Ѵ�
}

void ArrayVector::insert(int i, const Elem& e) { // �ε����� �̿��Ͽ� ���� ����
	if (n >= capacity) { // ArrayVector�� ������ ������ ArrayVector�� ũ�⺸�� Ŭ �� 
		reserve(max(1, 2 * capacity)); // reserve �Լ��� �̿��Ͽ� ArrayVector�� ũ�⸦ �ø���
		// ���� capacity�� 0�̹Ƿ�, �� ��츦 ����Ͽ� ó�� capacity�� �ø� ���� 1��,
		// �� ���Ŀ��� 2 * capacity�� �ǵ��� ����
	}
	// cout << getCapacity() << endl;
	// cout << getN() << endl;
	// cout << sizeof(A) / sizeof(int) << endl;
	n++; // ������ ������ ���� + 1

	for (int j = n - 1; j > i; j--) // �ݺ����� �̿��Ͽ� ���������� �� ĭ�� shift
		A[j + 1] = A[j];
	A[i] = e; // �ε����� �ش��ϴ� ��ġ�� ���� ����
}

void ArrayVector::erase(int i) { // �ε����� �̿��Ͽ� ���� ����
	for (int j = i + 1; j < n; j++) // �ݺ����� �̿��Ͽ� �������� �� ĭ�� shift
		A[j - 1] = A[j];
	n--; // ArrayVector�� ������ ���� - 1
}