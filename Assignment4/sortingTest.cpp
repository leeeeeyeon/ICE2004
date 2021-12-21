#include <iostream>

// ������ �����ͼ� ������ ���� �ʿ��� �������
#include <stdlib.h>
#include <time.h>

// �˰��� �ð� ������ ���� �ʿ��� �������
#include <chrono>

// ArrayVector ��������� ����Ѵ�
#include "ArrayVector.h"

// namespace std�� chrono�� ����Ѵ�
using namespace std;
using namespace chrono;

// �Լ� ������ main �Լ� �տ��� �ϰ�, �Լ� ������ main �Լ� �ؿ��� �Ͽ���

// 1. �������� �Լ���
void printVector(ArrayVector& v); // ���͸� ����ϴ� �Լ�
void swap(int &a, int &b); // �� ���Ҹ� swap�ϴ� �Լ�

// 2. ���� �˰��� �Լ���
// key, value ������ ����ϱ� ���� �ε����� ��� ������ key�� ���ڷ� �߰��� �Լ����� �Բ� �������
void insertionSort(ArrayVector& v); // insertions sort�� ������ �Լ�
void insertionSort(ArrayVector& v, ArrayVector& key);

void selectionSort(ArrayVector& v); // selection sort�� ������ �Լ�
void selectionSort(ArrayVector& v, ArrayVector& key);


void merge(ArrayVector& v, int start, int end); // merge sort�� ������ �Լ�
void merge(ArrayVector& v, ArrayVector& key, int start, int end);
void mergeSort(ArrayVector& v, int start, int end);

void quickSort(ArrayVector& v, int start, int end); // quick sort�� ������ �Լ�
void quickSort(ArrayVector& v, ArrayVector& key, int start, int end);

void one(); // ù ��° ���� ���� ��� �ڵ�
void two(); // �� ��° ���� ���� ��� �ڵ�
void three(int n); // �� ��° ���� ���� �ڵ�, n�� ������ ���� ũ��

ArrayVector temp; // merge sort���� ����� �߰����� �迭

int main() {
	// Insertion Sort Selection Sort Merge Sort Quick Sort
	// �� ���� �˰����� ���� �������� ���̱�
	// �ߺ� ��� > 10�� ������ �����ͼ� > stable���� ���� ** ���� �����͸� <key, data> ������
	// �����ͼ��� random�ϰ� ����, ũ�� ��ȭ, �˰����� ���� ��

	cout << "12201937 ������ ���� 4" << endl;
	cout << endl;

	cout << "1. �� ���� �˰����� ���� ���� Ȯ��" << endl;
	cout << endl;
	
	one();

	cout << endl;
	cout << "2. �� �˰����� stable���� �׽�Ʈ" << endl;
	
	two();

	cout << endl;
	cout << "3. �˰����� ���� ��" << endl; // 10 100 1000 10000 1000000

	three(10); // n = 10
	three(100); // n = 100
	three(1000); // n = 1000
	three(10000); // n = 10000
	return 0;
}

// Vector�� ���ҵ��� ����ϴ� �Լ�
void printVector(ArrayVector& v){
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

// �� ���Ҹ� swap�ϴ� �Լ�
void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// insertion sort�� ������ �Լ�
void insertionSort(ArrayVector& v) {
	int i, j;
	for (i = 1; i < v.size() - 1; i++) {
		j = i;
		while (v[j] > v[j + 1]) { // ���� ���Ұ� ���� ���Һ��� Ŭ ������
			swap(v[j], v[j + 1]); // �� ���Ҹ� swap�Ѵ�
			j--;
		}
	}
}

// insertion sort�� key, value ������ �����ϱ� ����
// index�� ��� ArrayVector�� ����� ������ �̵��� ���� index�� �̵��ϴ°�ó�� ������ 
void insertionSort(ArrayVector& v, ArrayVector& key) {
	int i, j, temp;
	for (i = 1; i < v.size() - 1; i++) {
		j = i;
		while (v[j] > v[j + 1]) {
			swap(v[j], v[j + 1]);
			swap(key[j], key[j + 1]); // index ���� ArrayVector�� �����ϰ� swap ������ ��ħ
			j--;
		}
	}
}

// selection sort�� �����ϴ� �Լ�
void selectionSort(ArrayVector& v) {
	for (int i = 0; i < v.size()-1; i++) {
		int min = v[i]; // �ּҰ��� ������ ����
		int location = i; // �ּҰ��� index�� ������ ����

		// �ݺ����� ���� �ּҰ��� ã�´�.
		for (int j = i + 1; j < v.size(); j++) {
			if (min > v[j]) {
				min = v[j];
				location = j;
			}
		}

		// ������ �ּҰ��� ���ο� �ּҰ��� swap�Ѵ�
		swap(v[i], v[location]);
	}
}

// selection sort�� key, value ������ �����ϱ� ����
// index�� ��� ArrayVector�� ����� ������ �̵��� ���� index�� �̵��ϴ°�ó�� ������ 
void selectionSort(ArrayVector& v, ArrayVector& key) {
	for (int i = 0; i < v.size() - 1; i++) {
		int min = v[i];
		int location = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (min > v[j]) {
				min = v[j];
				location = j;
			}
		}
		swap(v[i], v[location]);
		//cout << "v: ";
		//printVector(v);
		swap(key[i], key[location]); // index ���� ArrayVector�� �����ϰ� swap ������ ��ħ
		//cout << "key: ";
		//printVector(key);
		//cout << endl;
	}
}

// ������ �������ִ� �Լ�
// ���� ������ ���ʴ�� �ӽ� �迭�� ä������ �ǰ�, ���� �迭�� ���� �ӽ� �迭 ������ ��ü
void merge(ArrayVector& v, int start, int end) {
	int mid = (start + end) / 2; // ��� ��

	int lIdx = start; // ���� �κ� �迭�� ���� �ε���
	int rIdx = mid + 1; // ������ �κ� �迭�� ���� �ε���
	int k = start;

	// k�� left���� �����Ͽ� right index�� ������ ������ while���� ����
	while (k <= end) {
		if (lIdx > mid) { // ���� �κ� �迭�� ���ҵ��� ���� ���յǾ��� �� �� �ڿ� ������ �κ� �迭�� �״�� ���������
			temp[k++] = v[rIdx++];
			continue;
		}
		if (rIdx > end) { // ������ �κ� �迭�� ���ҵ��� ���� ���յǾ��� �� �� �ڿ� ���� �κ� �迭�� �״�� ���������
			temp[k++] = v[lIdx++];
			continue;
		}

		// ����, ������ �κ� �迭�� ���� �� �� ���� ���� �����ϰ� index�� 1 ����
		if (v[lIdx] <= v[rIdx]) temp[k++] = v[lIdx++];
		else temp[k++] = v[rIdx++];
	}
	for (int i = start; i <= end; i++) v[i] = temp[i]; // �ӽ� �迭 ���� �ٽ� ���� �迭�� ä����
}

// merge sort�� �����ϴ� �Լ�
void mergeSort(ArrayVector& v, int start, int end) {
	if (start >= end) return; // �迭�� ũ�Ⱑ 1�� �Ǵ� ���������� ������ �Ϸ������� ���� ����
	int mid = (start + end) / 2;
	mergeSort(v, start, mid); // ���� ���ݿ� ���� merge sort
	mergeSort(v, mid + 1, end); // ������ ���ݿ� ���� merge sort
	merge(v, start, end); // ���� ������
}

void quickSort(ArrayVector& v, int start, int end) {
	if (start >= end) return;

	int pivot = start; // pivot�� ù ���ҷ� ����
	int i = pivot + 1; // ���� ��� ����
	int j = end; // ������ ��� ����

	while (i <= j) {
		// �����Ͱ� ������ ������ �ݺ�
		while (i <= end && v[i] <= v[pivot]) i++;
		while (j > start && v[j] >= v[pivot]) j--;

		if (i > j) {
			swap(v[j], v[pivot]);
		}
		else {
			swap(v[i], v[j]);
		}
	}

	// ��������� ȣ��
	quickSort(v, start, j - 1);
	quickSort(v, j + 1, end);
}

// quick sort�� key, value ������ �����ϱ� ����
// index�� ��� ArrayVector�� ����� ������ �̵��� ���� index�� �̵��ϴ°�ó�� ������ 
void quickSort(ArrayVector& v, ArrayVector& key, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;

	while (i <= j) {
		while (i <= end && v[i] <= v[pivot]) i++;
		while (j > start && v[j] >= v[pivot]) j--;

		if (i > j) {
			swap(v[j], v[pivot]);
			swap(key[j], key[pivot]); // index ���� ArrayVector�� �����ϰ� swap ������ ��ħ
		}
		else {
			swap(v[i], v[j]);
			swap(key[i], key[j]); // index ���� ArrayVector�� �����ϰ� swap ������ ��ħ
		}
	}

	quickSort(v, key, start, j - 1);
	quickSort(v, key, j + 1, end);
}

void one() {
	ArrayVector insertionTest; // insertion sort�� ������ Array Vector
	ArrayVector selectionTest; // selection sort�� ������ Array Vector
	ArrayVector mergeTest; // merge sort�� ������ Array Vector
	ArrayVector quickTest; // quick sort�� ������ Array Vector

	// insertionTest�� ���ҵ��� �����
	insertionTest.insert(0, 4);
	insertionTest.insert(1, 5);
	insertionTest.insert(2, 2);
	insertionTest.insert(3, 7);
	insertionTest.insert(4, 3);
	insertionTest.insert(5, 1);
	insertionTest.insert(6, 6);

	// �ٸ� 3���� ���͵鿡�� ������ ���� �����
	for (int i = 0; i < insertionTest.size(); i++) {
		selectionTest.insert(i, insertionTest[i]);
		mergeTest.insert(i, insertionTest[i]);
		quickTest.insert(i, insertionTest[i]);
	}

	// merge sort�� ���Ǵ� temp ���͵� ũ�Ⱑ �����ϵ��� �������
	for (int i = 0; i < insertionTest.size(); i++) {
		temp.insert(i, 0);
	}

	// ���� �� ���͵��� �� ���
	cout << "[ ���� �� ]" << endl;
	cout << "insertion sort: ";
	printVector(insertionTest);
	cout << "selection sort: ";
	printVector(selectionTest);
	cout << "merge sort: ";
	printVector(mergeTest);
	cout << "quick sort: ";
	printVector(quickTest);

	// �� ���� �˰���� ����
	insertionSort(insertionTest);
	selectionSort(selectionTest);
	mergeSort(mergeTest, 0, 6);
	quickSort(quickTest, 0, 6);

	// ���� �� ���͵��� �� ���
	cout << endl;
	cout << "[ ���� �� ]" << endl;
	cout << "insertion sort: ";
	printVector(insertionTest);
	cout << "selection sort: ";
	printVector(selectionTest);
	cout << "merge sort: ";
	printVector(mergeTest);
	cout << "quick sort: ";
	printVector(quickTest);
}

void two() {
	ArrayVector insertionStable; // insertion sort�� ����� ����
	ArrayVector selectionStable; // selection sort�� ����� ����
	ArrayVector mergeStable; // merge sort�� ����� ����
	ArrayVector quickStable; // quick sort�� ����� ����

	// �� ���� ���͵��� index�� ��Ÿ�� ����
	ArrayVector insertionIndex;
	ArrayVector selectionIndex;
	ArrayVector mergeIndex;
	ArrayVector quickIndex;

	// insertionStable�� ���ҵ��� �����
	insertionStable.insert(0, 3);
	insertionStable.insert(1, 5);
	insertionStable.insert(2, 7);
	insertionStable.insert(3, 6);
	insertionStable.insert(4, 9);
	insertionStable.insert(5, 10);
	insertionStable.insert(6, 9);
	insertionStable.insert(7, 2);
	insertionStable.insert(8, 1);
	insertionStable.insert(9, 4);
	insertionStable.insert(10, 8);

	// �ٸ� 3���� ���͵鿡�� ������ ���� �����
	for (int i = 0; i < insertionStable.size(); i++) {
		selectionStable.insert(i, insertionStable[i]);
		mergeStable.insert(i, insertionStable[i]);
		quickStable.insert(i, insertionStable[i]);
	}

	// index�� ��Ÿ���� ���Ϳ� index �ʱ� �� ����
	for (int i = 0; i <= 10; i++) {
		insertionIndex.insert(i, i);
		selectionIndex.insert(i, i);
		mergeIndex.insert(i, i);
		quickIndex.insert(i, i);
	}

	// merge sort�� ���Ǵ� temp ���͵� ũ�Ⱑ �����ϵ��� �������
	for (int i = 0; i < insertionIndex.size(); i++) {
		temp.insert(i, 0);
	}

	// ���� �� ���
	cout << "1. Insertion Sort" << endl;
	cout << "key:   ";
	printVector(insertionIndex);
	cout << "value: ";
	printVector(insertionStable);

	// ����
	insertionSort(insertionStable, insertionIndex);

	// ���� �� ���
	cout << endl;
	cout << "key: ";
	printVector(insertionIndex);
	cout << "value: ";
	printVector(insertionStable);
	cout << endl;

	// ���� �� ���
	cout << "2. Selection Sort" << endl;
	cout << "key:   ";
	printVector(selectionIndex);
	cout << "value: ";
	printVector(selectionStable);
	cout << endl;

	// ����
	selectionSort(selectionStable, selectionIndex);

	// ���� �� ���
	cout << "key: ";
	printVector(selectionIndex);
	cout << "value: ";
	printVector(selectionStable);
	cout << endl;

	// ���� �� ���
	cout << "3. Merge Sort" << endl;

	// ���� �� ���
	cout << "4. Quick Sort" << endl;
	cout << "key:   ";
	printVector(quickIndex);
	cout << "value: ";
	printVector(quickStable);
	cout << endl;

	// ����
	quickSort(quickStable, quickIndex, 0, 10);

	// ���� �� ���
	cout << "key: ";
	printVector(quickIndex);
	cout << "value: ";
	printVector(quickStable);
	cout << endl;

}

void three(int n) {
	cout << endl;
	cout << "n = " << n << endl;
	ArrayVector s0; // insertion sort�� ����� ����
	ArrayVector s1; // selection sort�� ����� ����
	ArrayVector s2; // merge sort�� ����� ����
	ArrayVector s3; // quick sort�� ����� ����

	// �����ͼ��� �����ϰ� ����
	srand(time(0)); // ���α׷� ������ ������ ���� �ٸ��� ��
	for (int i = 0; i < n; i++) {
		int num = rand() % 100; // ���� ���� ����
		s0.insert(i, num); // s0�� �� �� ����
	}

	// s0�� �����ϰ� ������ ���͵鿡�� ���� ����
	for (int i = 0; i < s0.size(); i++) {
		s1.insert(i, s0[i]);
		s2.insert(i, s0[i]);
		s3.insert(i, s0[i]);
	}

	// merge sort�� ���Ǵ� temp ���͵� ũ�Ⱑ �����ϵ��� �������
	for (int i = 0; i < s0.size(); i++) {
		temp.insert(i, 0);
	}

	// insertion sort�� �����ϰ� �ɸ� �ð��� ����
	system_clock::time_point start = system_clock::now();
	insertionSort(s0);
	system_clock::time_point end = system_clock::now();

	duration<double> sec = end - start;
	cout << "insertion sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;

	// selection sort�� �����ϰ� �ɸ� �ð��� ����
	start = system_clock::now();
	selectionSort(s1);
	end = system_clock::now();

	sec = end - start;
	cout << "selection sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;

	// merge sort�� �����ϰ� �ɸ� �ð��� ����
	start = system_clock::now();
	mergeSort(s2, 0, 9);
	end = system_clock::now();

	sec = end - start;
	cout << "merge sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;

	// quick sort�� �����ϰ� �ɸ� �ð��� ����
	start = system_clock::now();
	quickSort(s3, 0, 9);
	end = system_clock::now();

	sec = end - start;
	cout << "quick sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;
}