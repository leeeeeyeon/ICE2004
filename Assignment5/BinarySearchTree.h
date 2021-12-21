#pragma once // �ߺ� ���� ����
#include <iostream> // iostream ��������� �ҷ��´�
using namespace std; // ǥ�� ���ӽ����̽� std�� ����Ѵ�

#define COUNT 10 // ��� COUNT�� 10���� ����

template <typename Object>
class BinarySearchTree {
protected:
	// ��� ����ü
	struct Node {
		// ����, �θ� ���, ���� �ڽ� ���, ������ �ڽ� ���� ����
		Object element;
		Node* parent;
		Node* left;
		Node* right;

		// elem�� ���ҷ� ������ ��� ������
		// �ڽ� ������ NULL�� �������ش�
		Node(const Object& elem) : element(elem)
		{
			parent = left = right = NULL;
		}

		// ����� ���� ��带 ��ȯ�ϴ� �Լ�
		Node* sibling() const {
			return (this == parent->left ? parent->right : parent->left);
		}
	};
	typedef Node* NodePtr; // Node*�� ������ NodePtr�� �������ش�
	// NodePtr�� Node*�� ���� �ǹ���

private:
	NodePtr ROOT; // ��Ʈ�� ����Ű�� ������
	int sz; // ����� ������ ��Ÿ��

	// elem�� ���ҷ� �ϴ� ��带 ã�� ��ȯ�ϴ� �Լ�
	NodePtr finder(NodePtr cursor, const Object& elem) {
		if (isExternal(cursor)) { // cursor ��尡 �ܺ� ����̸�
			return cursor; // cursor�� ��ȯ
		}
		// cursor ����� ���Ұ� elem���� ũ��, cursor�� ���� �ڽ� ��忡�� finder �Լ� ��� ȣ��
		if (cursor->element > elem) {
			return finder(leftChild(cursor), elem);
		}

		// cursor ����� ���Ұ� elem���� ������, cursor�� ������ �ڽ� ��忡�� finder �Լ� ��� ȣ��
		else if (elem > cursor->element) {
			return finder(rightChild(cursor), elem);
		}
		else return cursor;
	}

	// elem�� ���ҷ� �ϴ� ��带 �����ϴ� �Լ�
	void inserter(const Object& elem) {
		NodePtr v = finder(root(), elem); // elem�� ���ҷ� �ϴ� ��带 ã�� v�� ����
		while (isInternal(v)) { // v�� �ܺ� ��尡 �� ������ �ݺ�
			v = finder(rightChild(v), elem); // v�� ������ �ڽ� ��忡�� finder �Լ� ȣ��
		}
		// ���� �Ʒ� ���� �ִ� ������ �ڽ� ����� ����(NULL)�� �츮�� �����Ϸ��� ����(elem)���� �ٲ��ش�.
		if (v->element == NULL) {
			v->element = elem;
		}
		else {
			expandExternal(v, NULL, NULL); // ���� �Ʒ� �� �Ʒ��� ���ο� ���� ������ش�.
			if (v->element > elem) { // BST�� ������ �����Ͽ� �����Ϸ��� ���Ұ� �θ� ��庸�� ������
				v->left->element = elem; // ���� �ڽ� ��� �ڸ��� �����Ѵ�
				expandExternal(v->left, NULL, NULL); // ���� insert�� ���Ͽ� ���� �Ʒ� ���� ����� �ڽ� ��带 NULL�� ������ش�.
			}
			else { // BST�� ������ �����Ͽ� �����Ϸ��� ���Ұ� �θ� ��庸�� ũ��
				v->right->element = elem; // ������ �ڽ� ��� �ڸ��� �����Ѵ�
				expandExternal(v->right, NULL, NULL); // ���� insert�� ���Ͽ� ���� �Ʒ� ���� ����� �ڽ� ��带 NULL�� ������ش�.
			}
		}
	}

	// ��� r�� �����ϴ� �Լ�
	NodePtr remover(const NodePtr& r) {
		NodePtr p;
		// r�� �ڽ� ��尡 �ܺ� ����� ��
		if (isExternal(leftChild(r))) p = leftChild(r);
		else if (isExternal(rightChild(r))) p = rightChild(r);
		
		// r�� �ڽ� ��尡 ��� ���� ����̸�
		else {
			p = rightChild(r); // r�� �ڽ� ��带 ��� p�� ����
			do
				p = leftChild(p);
			while (isInternal(p)); // p ��尡 �ܺ� ��尡 �� ������ ���� ���� �ڸ��� ã�´�
			r->element = p->parent->element; // r ��忡 p�� �θ� ��带 ����
		}

		return removeAboveExternal(p); // ��� p�� p�� �θ� ��带 �����Ѵ�

	}
public:
	// Ʈ������ elem�� ���ҷ� �ϴ� ��带 ã�� �Լ�
	NodePtr find(const Object& elem) {
		NodePtr v = finder(root(), elem); // elem�� ���ҷ� �ϴ� ��带 ã�´�
		if (v.isInternal()) return v; // ��� v�� ���� ����̸� v�� ��ȯ�Ѵ�
		else return nullptr; // �׷��� ������ nullptr�� ��ȯ�Ѵ�

	}

	// Ʈ������ elem�� ���ҷ� �ϴ� ��带 �߰��ϴ� �Լ�
	void insert(const Object& elem) {
		if (!this->ROOT) { // ��Ʈ ��尡 ������
			this->ROOT = new Node(elem); // elem�� ���ҷ� �ϴ� ��Ʈ ��带 ����
			return;
		}
		inserter(elem); // inserter �Լ��� ����Ͽ� ���������� �߰� ������ ����
	}

	// Ʈ������ elem�� ���ҷ� �ϴ� ��带 �����ϴ� �Լ�
	void removeElement(const Object& elem) {
		NodePtr p = finder(root(), elem); // elem�� ���ҷ� �ϴ� ��带 ã�� p�� ����
		remover(p); // remover �Լ��� ����Ͽ� ���������� �߰� ������ ����
	}
	

	NodePtr root() { return ROOT; } // ��Ʈ�� ��ȯ�ϴ� �Լ�
	
	// ��� v�� ���� �ڽ� ��带 ��ȯ�ϴ� �Լ�
	NodePtr leftChild(NodePtr v) const {
		return v->left;
	}

	// ��� v�� ������ �ڽ� ��带 ��ȯ�ϴ� �Լ�
	NodePtr rightChild(NodePtr v) const {
		return v->right;
	}

	// ��� n�� �ܺ� ������� �Ǻ��ϴ� �Լ�
	bool isExternal(NodePtr n) const {
		return(n->left == nullptr && n->right == nullptr); // �ڽ� ��尡 �� �� nullptr�̸� �ܺ� ����� �Ǵ�
	}

	// ��� n�� ���� ������� �Ǻ��ϴ� �Լ�
	bool isInternal(NodePtr n) const {
		return !isExternal(n);
	}

	// ��� n�� ��Ʈ���� �Ǻ��ϴ� �Լ�
	bool isRoot(NodePtr n) const {
		return (n == ROOT);
	}

	// ��� r�� ��Ʈ�� �����ϴ� �Լ�
	void setRoot(NodePtr r) {
		ROOT = r;
		r->parent = NULL;
	}

	// ��� n�� ���Ҹ� o�� �ٲٴ� �Լ�
	void replaceElement(NodePtr n, const Object& o) {
		n->element = o;
	}

	// �� ����� ���Ҹ� swap�ϴ� �Լ�
	void swapElements(NodePtr n, NodePtr w) {
		Object temp = w->element;
		w->element = n->element;
		n->element = temp;
	}

	// �ܺ� ��� n�� �߰��ϴ� �Լ�
	void expandExternal(NodePtr n, Object l, Object r) {

		// ��� n�� ���� �ڽ� ��忡 ���Ҹ� l�� ���� ��带 ����
		n->left = new Node(l);
		n->left->parent = n; // �θ� n���� ��������

		// ������ �ڽ� ��忡���� ���� ������ �ݺ�
		n->right = new Node(r);
		n->right->parent = n;

		sz += 2; // ����� ������ 2 ����
	}

	NodePtr removeAboveExternal(NodePtr n) { // ��� n�� �� �θ� �����ϴ� �Լ�
		NodePtr p = n->parent; // n�� �θ� ��� p
		NodePtr s = n->sibling(); // n�� ���� ��� s
		if (isRoot(p)) setRoot(s); // p�� ��Ʈ���ٸ�, ��Ʈ�� s�� �ٲ��ش�.
		else {
			NodePtr g = p->parent; // n�� ���θ� ��� g
			if (p == g->left) g->left = s; // n�� �θ��尡 g�� ���� �ڽ� ��忴�ٸ�, �� �ڸ��� ��� s�� ���� 
			else g->right = s; // n�� �θ��尡 g�� ������ �ڽ� ��忴�ٸ�, �� �ڸ��� ��� s�� ���� 
			s->parent = g; // s�� �θ� ��带 g�� ���� 
		}

		// ��� n, p ����
		delete n;
		delete p;
		sz -= 2; // ����� ����-2
		return s; // ��� s ��ȯ
	}

	// ��Ʈ�� ���Ұ� elem�� ���� Ž�� Ʈ�� ������
	BinarySearchTree(Object elem) {
		ROOT = new Node(elem);
		sz = 1;
	}

	int size() const { return sz; } // ����� ������ ��ȯ
	bool isEmpty() const { return (sz == 0); } // Ʈ���� ������� true�� ��ȯ

	// BST�� ���Ҹ� preorder�� �湮���� ���� �湮 ������ ���
	void preorder(NodePtr v) {
		if (v->element == 0) return; // nullptr�� �� ���Ұ� 0�ε�, �� ��쵵 ���ԵǾ� ��µǹǷ� 0�� �������ֵ��� �Ѵ�
		cout << v->element << " ";
		if (isInternal(v)) {
			preorder(leftChild(v));
			preorder(rightChild(v));
		}
	}

	// BST�� ���Ҹ� postorder�� �湮���� ���� �湮 ������ ���
	void postorder(NodePtr v) {
		if (isInternal(v)) {
			postorder(leftChild(v));
			postorder(rightChild(v));
		}

		if (v->element == 0) return; // nullptr�� �� ���Ұ� 0�ε�, �� ��쵵 ���ԵǾ� ��µǹǷ� 0�� �������ֵ��� �Ѵ�
		cout << v->element << " ";
	}

	// BST�� ���Ҹ� inorder�� �湮���� ���� �湮 ������ ���
	void inorder(NodePtr v) {
		if (isInternal(v)) inorder(leftChild(v));

		if (v->element == 0) return; // nullptr�� �� ���Ұ� 0�ε�, �� ��쵵 ���ԵǾ� ��µǹǷ� 0�� �������ֵ��� �Ѵ�
		cout << v->element << " ";

		if (isInternal(v)) inorder(rightChild(v));
	}

	// Ʈ�� ������ 2D�� ����ϴ� �Լ�
	void print2DUtil(NodePtr root, int space)
	{
		if (root == NULL)
			return;

		// �� ������ ������ ����
		space += COUNT;

		// ������ �ڽ� ������ ���
		print2DUtil(root->right, space);

		// ����� ���ҵ��� ����ϴ� �κ�
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << root->element << "\n";

		// ������ �ڽ� ������ ���
		print2DUtil(root->left, space);
	}

	void print2D(NodePtr root)
	{
		// ���� ���� root, space�� 0���� �������ִ� �Լ�
		print2DUtil(root, 0);
	}

};