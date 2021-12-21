#include <iostream>

// 랜덤한 데이터셋 생성을 위해 필요한 헤더파일
#include <stdlib.h>
#include <time.h>

// 알고리즘 시간 측정을 위해 필요한 헤더파일
#include <chrono>

// ArrayVector 헤더파일을 사용한다
#include "ArrayVector.h"

// namespace std와 chrono를 사용한다
using namespace std;
using namespace chrono;

// 함수 선언을 main 함수 앞에서 하고, 함수 구현은 main 함수 밑에서 하였다

// 1. 보조적인 함수들
void printVector(ArrayVector& v); // 벡터를 출력하는 함수
void swap(int &a, int &b); // 두 원소를 swap하는 함수

// 2. 정렬 알고리즘 함수들
// key, value 쌍으로 출력하기 위해 인덱스를 담는 벡터인 key가 인자로 추가된 함수들을 함께 만들어줌
void insertionSort(ArrayVector& v); // insertions sort를 구현한 함수
void insertionSort(ArrayVector& v, ArrayVector& key);

void selectionSort(ArrayVector& v); // selection sort를 구현한 함수
void selectionSort(ArrayVector& v, ArrayVector& key);


void merge(ArrayVector& v, int start, int end); // merge sort를 구현한 함수
void merge(ArrayVector& v, ArrayVector& key, int start, int end);
void mergeSort(ArrayVector& v, int start, int end);

void quickSort(ArrayVector& v, int start, int end); // quick sort를 구현한 함수
void quickSort(ArrayVector& v, ArrayVector& key, int start, int end);

void one(); // 첫 번째 문제 관련 출력 코드
void two(); // 두 번째 문제 관련 출력 코드
void three(int n); // 세 번째 문제 관련 코드, n은 데이터 셋의 크기

ArrayVector temp; // merge sort에서 사용할 추가적인 배열

int main() {
	// Insertion Sort Selection Sort Merge Sort Quick Sort
	// 각 정렬 알고리즘이 정상 동작함을 보이기
	// 중복 허용 > 10개 정도의 데이터셋 > stable한지 제시 ** 정렬 데이터를 <key, data> 쌍으로
	// 데이터셋을 random하게 생성, 크기 변화, 알고리즘의 성능 비교

	cout << "12201937 이정연 과제 4" << endl;
	cout << endl;

	cout << "1. 각 정렬 알고리즘의 정상 동작 확인" << endl;
	cout << endl;
	
	one();

	cout << endl;
	cout << "2. 각 알고리즘이 stable한지 테스트" << endl;
	
	two();

	cout << endl;
	cout << "3. 알고리즘의 성능 비교" << endl; // 10 100 1000 10000 1000000

	three(10); // n = 10
	three(100); // n = 100
	three(1000); // n = 1000
	three(10000); // n = 10000
	return 0;
}

// Vector의 원소들을 출력하는 함수
void printVector(ArrayVector& v){
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

// 두 원소를 swap하는 함수
void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// insertion sort를 구현한 함수
void insertionSort(ArrayVector& v) {
	int i, j;
	for (i = 1; i < v.size() - 1; i++) {
		j = i;
		while (v[j] > v[j + 1]) { // 뒤의 원소가 앞의 원소보다 클 때까지
			swap(v[j], v[j + 1]); // 두 원소를 swap한다
			j--;
		}
	}
}

// insertion sort를 key, value 쌍으로 구현하기 위해
// index를 담는 ArrayVector을 만들어 원소의 이동에 따라 index도 이동하는거처럼 구현함 
void insertionSort(ArrayVector& v, ArrayVector& key) {
	int i, j, temp;
	for (i = 1; i < v.size() - 1; i++) {
		j = i;
		while (v[j] > v[j + 1]) {
			swap(v[j], v[j + 1]);
			swap(key[j], key[j + 1]); // index 관련 ArrayVector도 동일하게 swap 과정을 거침
			j--;
		}
	}
}

// selection sort를 구현하는 함수
void selectionSort(ArrayVector& v) {
	for (int i = 0; i < v.size()-1; i++) {
		int min = v[i]; // 최소값을 저장할 변수
		int location = i; // 최소값의 index를 저장할 변수

		// 반복문을 통해 최소값을 찾는다.
		for (int j = i + 1; j < v.size(); j++) {
			if (min > v[j]) {
				min = v[j];
				location = j;
			}
		}

		// 현재의 최소값과 새로운 최소값을 swap한다
		swap(v[i], v[location]);
	}
}

// selection sort를 key, value 쌍으로 구현하기 위해
// index를 담는 ArrayVector을 만들어 원소의 이동에 따라 index도 이동하는거처럼 구현함 
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
		swap(key[i], key[location]); // index 관련 ArrayVector도 동일하게 swap 과정을 거침
		//cout << "key: ";
		//printVector(key);
		//cout << endl;
	}
}

// 병합을 수행해주는 함수
// 작은 값부터 차례대로 임시 배열에 채워지게 되고, 원본 배열의 값을 임시 배열 값으로 교체
void merge(ArrayVector& v, int start, int end) {
	int mid = (start + end) / 2; // 가운데 값

	int lIdx = start; // 왼쪽 부분 배열의 시작 인덱스
	int rIdx = mid + 1; // 오른쪽 부분 배열의 시작 인덱스
	int k = start;

	// k가 left부터 시작하여 right index에 도달할 때까지 while문을 수행
	while (k <= end) {
		if (lIdx > mid) { // 왼쪽 부분 배열의 원소들이 전부 병합되었을 때 그 뒤에 오른쪽 부분 배열을 그대로 연결시켜줌
			temp[k++] = v[rIdx++];
			continue;
		}
		if (rIdx > end) { // 오른쪽 부분 배열의 원소들이 전부 병합되었을 때 그 뒤에 왼쪽 부분 배열을 그대로 연결시켜줌
			temp[k++] = v[lIdx++];
			continue;
		}

		// 왼쪽, 오른쪽 부분 배열의 원소 중 더 작은 값을 대입하고 index를 1 증가
		if (v[lIdx] <= v[rIdx]) temp[k++] = v[lIdx++];
		else temp[k++] = v[rIdx++];
	}
	for (int i = start; i <= end; i++) v[i] = temp[i]; // 임시 배열 값을 다시 원본 배열에 채워줌
}

// merge sort를 구현하는 함수
void mergeSort(ArrayVector& v, int start, int end) {
	if (start >= end) return; // 배열의 크기가 1이 되는 마지막까지 분할을 완료했으면 분할 종료
	int mid = (start + end) / 2;
	mergeSort(v, start, mid); // 왼쪽 절반에 대해 merge sort
	mergeSort(v, mid + 1, end); // 오른쪽 절반에 대하 merge sort
	merge(v, start, end); // 둘을 합해줌
}

void quickSort(ArrayVector& v, int start, int end) {
	if (start >= end) return;

	int pivot = start; // pivot을 첫 원소로 선정
	int i = pivot + 1; // 왼쪽 출발 지점
	int j = end; // 오른쪽 출발 지점

	while (i <= j) {
		// 포인터가 엇갈릴 때까지 반복
		while (i <= end && v[i] <= v[pivot]) i++;
		while (j > start && v[j] >= v[pivot]) j--;

		if (i > j) {
			swap(v[j], v[pivot]);
		}
		else {
			swap(v[i], v[j]);
		}
	}

	// 재귀적으로 호출
	quickSort(v, start, j - 1);
	quickSort(v, j + 1, end);
}

// quick sort를 key, value 쌍으로 구현하기 위해
// index를 담는 ArrayVector을 만들어 원소의 이동에 따라 index도 이동하는거처럼 구현함 
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
			swap(key[j], key[pivot]); // index 관련 ArrayVector도 동일하게 swap 과정을 거침
		}
		else {
			swap(v[i], v[j]);
			swap(key[i], key[j]); // index 관련 ArrayVector도 동일하게 swap 과정을 거침
		}
	}

	quickSort(v, key, start, j - 1);
	quickSort(v, key, j + 1, end);
}

void one() {
	ArrayVector insertionTest; // insertion sort를 진행할 Array Vector
	ArrayVector selectionTest; // selection sort를 진행할 Array Vector
	ArrayVector mergeTest; // merge sort를 진행할 Array Vector
	ArrayVector quickTest; // quick sort를 진행할 Array Vector

	// insertionTest에 원소들을 담아줌
	insertionTest.insert(0, 4);
	insertionTest.insert(1, 5);
	insertionTest.insert(2, 2);
	insertionTest.insert(3, 7);
	insertionTest.insert(4, 3);
	insertionTest.insert(5, 1);
	insertionTest.insert(6, 6);

	// 다른 3개의 벡터들에도 동일한 값을 담아줌
	for (int i = 0; i < insertionTest.size(); i++) {
		selectionTest.insert(i, insertionTest[i]);
		mergeTest.insert(i, insertionTest[i]);
		quickTest.insert(i, insertionTest[i]);
	}

	// merge sort에 사용되는 temp 벡터도 크기가 동일하도록 만들어줌
	for (int i = 0; i < insertionTest.size(); i++) {
		temp.insert(i, 0);
	}

	// 정렬 전 벡터들의 값 출력
	cout << "[ 정렬 전 ]" << endl;
	cout << "insertion sort: ";
	printVector(insertionTest);
	cout << "selection sort: ";
	printVector(selectionTest);
	cout << "merge sort: ";
	printVector(mergeTest);
	cout << "quick sort: ";
	printVector(quickTest);

	// 각 정렬 알고리즘들 수행
	insertionSort(insertionTest);
	selectionSort(selectionTest);
	mergeSort(mergeTest, 0, 6);
	quickSort(quickTest, 0, 6);

	// 정렬 후 벡터들의 값 출력
	cout << endl;
	cout << "[ 정렬 후 ]" << endl;
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
	ArrayVector insertionStable; // insertion sort에 사용할 벡터
	ArrayVector selectionStable; // selection sort에 사용할 벡터
	ArrayVector mergeStable; // merge sort에 사용할 벡터
	ArrayVector quickStable; // quick sort에 사용할 벡터

	// 각 정렬 벡터들의 index를 나타낼 벡터
	ArrayVector insertionIndex;
	ArrayVector selectionIndex;
	ArrayVector mergeIndex;
	ArrayVector quickIndex;

	// insertionStable에 원소들을 담아줌
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

	// 다른 3개의 벡터들에도 동일한 값을 담아줌
	for (int i = 0; i < insertionStable.size(); i++) {
		selectionStable.insert(i, insertionStable[i]);
		mergeStable.insert(i, insertionStable[i]);
		quickStable.insert(i, insertionStable[i]);
	}

	// index를 나타내는 벡터에 index 초기 값 삽입
	for (int i = 0; i <= 10; i++) {
		insertionIndex.insert(i, i);
		selectionIndex.insert(i, i);
		mergeIndex.insert(i, i);
		quickIndex.insert(i, i);
	}

	// merge sort에 사용되는 temp 벡터도 크기가 동일하도록 만들어줌
	for (int i = 0; i < insertionIndex.size(); i++) {
		temp.insert(i, 0);
	}

	// 정렬 전 출력
	cout << "1. Insertion Sort" << endl;
	cout << "key:   ";
	printVector(insertionIndex);
	cout << "value: ";
	printVector(insertionStable);

	// 정렬
	insertionSort(insertionStable, insertionIndex);

	// 정렬 후 출력
	cout << endl;
	cout << "key: ";
	printVector(insertionIndex);
	cout << "value: ";
	printVector(insertionStable);
	cout << endl;

	// 정렬 전 출력
	cout << "2. Selection Sort" << endl;
	cout << "key:   ";
	printVector(selectionIndex);
	cout << "value: ";
	printVector(selectionStable);
	cout << endl;

	// 정렬
	selectionSort(selectionStable, selectionIndex);

	// 정렬 후 출력
	cout << "key: ";
	printVector(selectionIndex);
	cout << "value: ";
	printVector(selectionStable);
	cout << endl;

	// 정렬 전 출력
	cout << "3. Merge Sort" << endl;

	// 정렬 전 출력
	cout << "4. Quick Sort" << endl;
	cout << "key:   ";
	printVector(quickIndex);
	cout << "value: ";
	printVector(quickStable);
	cout << endl;

	// 정렬
	quickSort(quickStable, quickIndex, 0, 10);

	// 정렬 후 출력
	cout << "key: ";
	printVector(quickIndex);
	cout << "value: ";
	printVector(quickStable);
	cout << endl;

}

void three(int n) {
	cout << endl;
	cout << "n = " << n << endl;
	ArrayVector s0; // insertion sort에 사용할 벡터
	ArrayVector s1; // selection sort에 사용할 벡터
	ArrayVector s2; // merge sort에 사용할 벡터
	ArrayVector s3; // quick sort에 사용할 벡터

	// 데이터셋을 랜덤하게 생성
	srand(time(0)); // 프로그램 실행할 때마다 숫자 다르게 함
	for (int i = 0; i < n; i++) {
		int num = rand() % 100; // 랜덤 숫자 생성
		s0.insert(i, num); // s0에 그 값 대입
	}

	// s0와 동일하게 나머지 벡터들에도 값을 대입
	for (int i = 0; i < s0.size(); i++) {
		s1.insert(i, s0[i]);
		s2.insert(i, s0[i]);
		s3.insert(i, s0[i]);
	}

	// merge sort에 사용되는 temp 벡터도 크기가 동일하도록 만들어줌
	for (int i = 0; i < s0.size(); i++) {
		temp.insert(i, 0);
	}

	// insertion sort를 수행하고 걸린 시간을 측정
	system_clock::time_point start = system_clock::now();
	insertionSort(s0);
	system_clock::time_point end = system_clock::now();

	duration<double> sec = end - start;
	cout << "insertion sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;

	// selection sort를 수행하고 걸린 시간을 측정
	start = system_clock::now();
	selectionSort(s1);
	end = system_clock::now();

	sec = end - start;
	cout << "selection sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;

	// merge sort를 수행하고 걸린 시간을 측정
	start = system_clock::now();
	mergeSort(s2, 0, 9);
	end = system_clock::now();

	sec = end - start;
	cout << "merge sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;

	// quick sort를 수행하고 걸린 시간을 측정
	start = system_clock::now();
	quickSort(s3, 0, 9);
	end = system_clock::now();

	sec = end - start;
	cout << "quick sort: " << duration_cast<nanoseconds>(end - start).count() << "ns" << endl;
}