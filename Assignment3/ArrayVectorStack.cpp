// 헤더파일을 불러온다
#include <iostream>
#include <string>
#include "ArrayVectorStack.h"

// 표준 네임스페이스 std를 불러온다
using namespace std;

// stock span 알고리즘
void span(int rates[], int days, int stockspan[]) {
	ArrayVectorStack stack; // 인덱스를 담을 스택

	// stockspan은 날짜의 차에 해당하는 값을 담는 배열이다
	stockspan[0] = 1; // 초기값으로 1을 삽입한다
	stack.push(0); // 초기값으로 0을 push한다

	for (int i = 1; i < days; i++) {
		while (rates[i] > rates[stack.top()]) { // 현재 날의 주가가 top에 해당하는 주가보다 크면
			stack.pop(); // 스택에서 pop한다

			if (stack.empty()) { // 스택이 비어있으면
				break; // 현재 값이 최대이므로 반복문에서 나온다.
			}
		}

		if (!stack.empty()) { // 스택이 비어있지 않으면
			stockspan[i] = i - stack.top(); // 날짜의 차이를 배열에 집어넣는다
		}
		else { // 스택이 비어있으면 현재 값이 최대이므로
			stockspan[i] = i + 1; // 현재 값을 대입한다 (index는 1 작으므로 +1을 해주어야 한다)
		}

		stack.push(i); // 현재 index를 stack에 무조건 한번씩은 대입해주어야 한다
	}
}

// 중위표기식을 후위표기식을 변환하는 알고리즘

// 연산기호 처리를 위해 사용하는 함수, 우선순위 비교
int pre(char c) {
	if (c == '/' || c == '*') return 2;
	else if (c == '+' || c == '-') return 1;
	else return -1;
}
void infixToPostfix(string infix) {
	ArrayVectorStack stack; // 연산 기호를 담을 스택
	string result; // 결과 값을 담을 문자열

	// 문자열의 길이만큼 반복문 수행
	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		// 문자가 알파벳 또는 숫자이면 result에 추가
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		// 문자가 '('이면 스택에 push
		else if (c == '(')
			stack.push('(');

		// 문자가 ')'이면
		else if (c == ')') {
			while (stack.top() != '(') { // 스택의 top이 '('일 때까지
				result += stack.top(); // 스택의 top을 result에 추가하고
				stack.pop(); // 스택에서 top을 pop한다
			}
			stack.pop(); // '('을 pop한다
		}

		// 그렇지 않다면(연산 기호가 들어온다면)
		else {
			while (!stack.empty() && pre(infix[i]) <= pre(stack.top())) { // top의 연산 기호의 우선 순위가 높다면 
				result += stack.top(); // 문자열에 top을 추가하고
				stack.pop(); // 스택에서 pop한다
			}
			stack.push(c); // 스택에 문자를 push한다
		}
	}

	// 스택이 빌 때까지 스택에 들어있는 원소들을 문자열에 추가한다
	while (!stack.empty()) {
		result += stack.top();
		stack.pop();
	}

	cout << result << endl;
}

int main(void) {
	cout << "12201937 이정연 과제 3 - ArrayVectorStack" << endl;

	// 16 페이지의 예가 정상적으로 동작함을 보인다
	int rates[7] = { 6,4,1,2,1,3,5 };
	int stockspan[7];

	span(rates, 7, stockspan);

	cout << "{ 6,4,1,2,1,3,5 }" << endl;
	for (int i = 0; i < 7; i++) {
		cout << stockspan[i] << " ";
	}
	cout << endl;
	cout << endl;

	// 추가의 예 1
	int rates2[6] = { 10, 4, 5, 90, 120, 80 };
	int stockspan2[6];

	span(rates2, 6, stockspan2);

	cout << "{ 10, 4, 5, 90, 120, 80 }" << endl;
	for (int i = 0; i < 6; i++) {
		cout << stockspan2[i] << " ";
	}
	cout << endl;
	cout << endl;

	// 추가의 예 2
	int rates3[6] = { 31, 27, 14, 21, 30, 22 };
	int stockspan3[6];

	span(rates3, 6, stockspan3);

	cout << "{ 31, 27, 14, 21, 30, 22 }" << endl;
	for (int i = 0; i < 6; i++) {
		cout << stockspan3[i] << " ";
	}
	cout << endl;
	cout << endl;

	// 27 페이지의 예가 정상적으로 동작함을 보인다
	string one = "a*(b+c)/d";
	cout << "a*(b+c)/d" << endl;
	infixToPostfix(one);
	cout << endl;

	// 추가의 예 1
	string two = "(a+b)+(c-d)";
	cout << "(a+b)+(c-d)" << endl;
	infixToPostfix(two);
	cout << endl;

	// 추가의 예 2
	string three = "((a*(b+d)/e)-f*(g+h/k))";
	cout << "((a*(b+d)/e)-f*(g+h/k))" << endl;
	infixToPostfix(three);
	cout << endl;

	return 0;
}