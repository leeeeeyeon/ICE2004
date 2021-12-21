#include <iostream> // iostream ��������� �ҷ��´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

#include "BinarySearchTree.h" // BinarySearchTree ��������� �ҷ��´�


int main() {
	cout << "12201937 ������ ���� 5" << endl;
	BinarySearchTree<int> test(6); // int�� ���ҷ� �̷��������, root=6�� BST test�� �����.

	// expandExternal()�� ����Ͽ� test Ʈ���� ���Ҹ� �����Ѵ�.
	test.expandExternal(test.root(), 2, 9);
	test.expandExternal(test.root()->left, 1, 4);
	test.expandExternal(test.root()->right, 8, NULL);
	cout << "����/���� ���� ���� ��" << endl;
	test.print2D(test.root()); // BST ���
	cout << "--------------------------------------------" << endl;

	cout << endl;
	
	// test BST�� 100�� ������ ��, ���� �� Ʈ���� ���
	test.insert(100);
	cout << "100 ����" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST�� 7�� ������ ��, ���� �� Ʈ���� ���
	test.insert(7);
	cout << "7 ����" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST�� 3�� ������ ��, ���� �� Ʈ���� ���
	test.insert(3);
	cout << "3 ����" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST���� 8�� ������ ��, ���� �� Ʈ���� ���
	test.removeElement(8);
	cout << "8 ����" << endl;
	test.print2D(test.root());
	cout << "--------------------------------------------" << endl;

	// test BST�� ���Ҹ� preorder, inorder, postorder�� �湮���� ���� �湮 ������ ���
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