#include <iostream> // iostream 헤더파일을 불러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

#include "BinarySearchTree.h" // BinarySearchTree 헤더파일을 불러온다


int main() {
	cout << "12201937 이정연 과제 5" << endl;
	BinarySearchTree<int> test(6); // int형 원소로 이루어졌으며, root=6인 BST test를 만든다.

	// expandExternal()를 사용하여 test 트리에 원소를 삽입한다.
	test.expandExternal(test.root(), 2, 9);
	test.expandExternal(test.root()->left, 1, 4);
	test.expandExternal(test.root()->right, 8, NULL);
	cout << "삽입/삭제 연산 수행 전" << endl;
	test.print2D(test.root()); // BST 출력
	cout << "--------------------------------------------" << endl;

	cout << endl;
	
	// test BST에 100을 삽입한 뒤, 삽입 후 트리를 출력
	test.insert(100);
	cout << "100 삽입" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST에 7을 삽입한 뒤, 삽입 후 트리를 출력
	test.insert(7);
	cout << "7 삽입" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST에 3을 삽입한 뒤, 삽입 후 트리를 출력
	test.insert(3);
	cout << "3 삽입" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST에서 8을 제거한 뒤, 제거 후 트리를 출력
	test.removeElement(8);
	cout << "8 제거" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST의 원소를 preorder, inorder, postorder로 방문했을 때의 방문 순서를 출력
	cout << "preorder: ";
	test.preorder(test.root());
	cout << endl;

	cout << "inorder: ";
	test.inorder(test.root());
	cout << endl;

	cout << "postorder: ";
	test.postorder(test.root());
	cout << endl;

	return 0;
}