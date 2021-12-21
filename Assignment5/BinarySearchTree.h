#pragma once // 중복 선언 방지
#include <iostream> // iostream 헤더파일을 불러온다
using namespace std; // 표준 네임스페이스 std를 사용한다

#define COUNT 10 // 상수 COUNT를 10으로 지정

template <typename Object>
class BinarySearchTree {
protected:
	// 노드 구조체
	struct Node {
		// 원소, 부모 노드, 왼쪽 자식 노드, 오른쪽 자식 노드로 구성
		Object element;
		Node* parent;
		Node* left;
		Node* right;

		// elem을 원소로 가지는 노드 생성자
		// 자식 노드들은 NULL로 지정해준다
		Node(const Object& elem) : element(elem)
		{
			parent = left = right = NULL;
		}

		// 노드의 형제 노드를 반환하는 함수
		Node* sibling() const {
			return (this == parent->left ? parent->right : parent->left);
		}
	};
	typedef Node* NodePtr; // Node*의 별명을 NodePtr로 지정해준다
	// NodePtr은 Node*과 같은 의미임

private:
	NodePtr ROOT; // 루트를 가리키는 포인터
	int sz; // 노드의 개수를 나타냄

	// elem을 원소로 하는 노드를 찾아 반환하는 함수
	NodePtr finder(NodePtr cursor, const Object& elem) {
		if (isExternal(cursor)) { // cursor 노드가 외부 노드이면
			return cursor; // cursor을 반환
		}
		// cursor 노드의 원소가 elem보다 크면, cursor의 왼쪽 자식 노드에서 finder 함수 재귀 호출
		if (cursor->element > elem) {
			return finder(leftChild(cursor), elem);
		}

		// cursor 노드의 원소가 elem보다 작으면, cursor의 오른쪽 자식 노드에서 finder 함수 재귀 호출
		else if (elem > cursor->element) {
			return finder(rightChild(cursor), elem);
		}
		else return cursor;
	}

	// elem을 원소로 하는 노드를 삽입하는 함수
	void inserter(const Object& elem) {
		NodePtr v = finder(root(), elem); // elem을 원소로 하는 노드를 찾아 v로 지정
		while (isInternal(v)) { // v가 외부 노드가 될 때까지 반복
			v = finder(rightChild(v), elem); // v의 오른쪽 자식 노드에서 finder 함수 호출
		}
		// 제일 아래 층에 있는 노드들의 자식 노드의 원소(NULL)를 우리가 삽입하려는 원소(elem)으로 바꿔준다.
		if (v->element == NULL) {
			v->element = elem;
		}
		else {
			expandExternal(v, NULL, NULL); // 가장 아래 층 아래에 새로운 층을 만들어준다.
			if (v->element > elem) { // BST의 원리를 적용하여 삽입하려는 원소가 부모 노드보다 작으면
				v->left->element = elem; // 왼쪽 자식 노드 자리에 삽입한다
				expandExternal(v->left, NULL, NULL); // 다음 insert를 위하여 가장 아래 층의 노드의 자식 노드를 NULL로 만들어준다.
			}
			else { // BST의 원리를 적용하여 삽입하려는 원소가 부모 노드보다 크면
				v->right->element = elem; // 오른쪽 자식 노드 자리에 삽입한다
				expandExternal(v->right, NULL, NULL); // 다음 insert를 위하여 가장 아래 층의 노드의 자식 노드를 NULL로 만들어준다.
			}
		}
	}

	// 노드 r을 제거하는 함수
	NodePtr remover(const NodePtr& r) {
		NodePtr p;
		// r의 자식 노드가 외부 노드일 때
		if (isExternal(leftChild(r))) p = leftChild(r);
		else if (isExternal(rightChild(r))) p = rightChild(r);
		
		// r의 자식 노드가 모두 내부 노드이면
		else {
			p = rightChild(r); // r의 자식 노드를 노드 p에 저장
			do
				p = leftChild(p);
			while (isInternal(p)); // p 노드가 외부 노드가 될 때까지 가장 왼쪽 자리를 찾는다
			r->element = p->parent->element; // r 노드에 p의 부모 노드를 복사
		}

		return removeAboveExternal(p); // 노드 p와 p의 부모 노드를 제거한다

	}
public:
	// 트리에서 elem을 원소로 하는 노드를 찾는 함수
	NodePtr find(const Object& elem) {
		NodePtr v = finder(root(), elem); // elem을 원소로 하는 노드를 찾는다
		if (v.isInternal()) return v; // 노드 v가 내부 노드이면 v를 반환한다
		else return nullptr; // 그렇지 않으면 nullptr을 반환한다

	}

	// 트리에서 elem을 원소로 하는 노드를 추가하는 함수
	void insert(const Object& elem) {
		if (!this->ROOT) { // 루트 노드가 없으면
			this->ROOT = new Node(elem); // elem을 원소로 하는 루트 노드를 생성
			return;
		}
		inserter(elem); // inserter 함수를 사용하여 내부적으로 추가 과정을 진행
	}

	// 트리에서 elem을 원소로 하는 노드를 제거하는 함수
	void removeElement(const Object& elem) {
		NodePtr p = finder(root(), elem); // elem을 원소로 하는 노드를 찾아 p에 저장
		remover(p); // remover 함수를 사용하여 내부적으로 추가 과정을 진행
	}
	

	NodePtr root() { return ROOT; } // 루트를 반환하는 함수
	
	// 노드 v의 왼쪽 자식 노드를 반환하는 함수
	NodePtr leftChild(NodePtr v) const {
		return v->left;
	}

	// 노드 v의 오른쪽 자식 노드를 반환하는 함수
	NodePtr rightChild(NodePtr v) const {
		return v->right;
	}

	// 노드 n이 외부 노드인지 판별하는 함수
	bool isExternal(NodePtr n) const {
		return(n->left == nullptr && n->right == nullptr); // 자식 노드가 둘 다 nullptr이면 외부 노드라고 판단
	}

	// 노드 n이 내부 노드인지 판별하는 함수
	bool isInternal(NodePtr n) const {
		return !isExternal(n);
	}

	// 노드 n이 루트인지 판별하는 함수
	bool isRoot(NodePtr n) const {
		return (n == ROOT);
	}

	// 노드 r을 루트로 지정하는 함수
	void setRoot(NodePtr r) {
		ROOT = r;
		r->parent = NULL;
	}

	// 노드 n의 원소를 o로 바꾸는 함수
	void replaceElement(NodePtr n, const Object& o) {
		n->element = o;
	}

	// 두 노드의 원소를 swap하는 함수
	void swapElements(NodePtr n, NodePtr w) {
		Object temp = w->element;
		w->element = n->element;
		n->element = temp;
	}

	// 외부 노드 n을 추가하는 함수
	void expandExternal(NodePtr n, Object l, Object r) {

		// 노드 n의 왼쪽 자식 노드에 원소를 l로 갖는 노드를 생성
		n->left = new Node(l);
		n->left->parent = n; // 부모를 n으로 지정해줌

		// 오른쪽 자식 노드에서도 같은 과정을 반복
		n->right = new Node(r);
		n->right->parent = n;

		sz += 2; // 노드의 개수를 2 증가
	}

	NodePtr removeAboveExternal(NodePtr n) { // 노드 n과 그 부모를 제거하는 함수
		NodePtr p = n->parent; // n의 부모 노드 p
		NodePtr s = n->sibling(); // n의 형제 노드 s
		if (isRoot(p)) setRoot(s); // p가 루트였다면, 루트를 s로 바꿔준다.
		else {
			NodePtr g = p->parent; // n의 조부모 노드 g
			if (p == g->left) g->left = s; // n의 부모노드가 g의 왼쪽 자식 노드였다면, 그 자리를 노드 s로 변경 
			else g->right = s; // n의 부모노드가 g의 오른쪽 자식 노드였다면, 그 자리를 노드 s로 변경 
			s->parent = g; // s의 부모 노드를 g로 변경 
		}

		// 노드 n, p 삭제
		delete n;
		delete p;
		sz -= 2; // 노드의 개수-2
		return s; // 노드 s 반환
	}

	// 루트의 원소가 elem인 이진 탐색 트리 생성자
	BinarySearchTree(Object elem) {
		ROOT = new Node(elem);
		sz = 1;
	}

	int size() const { return sz; } // 노드의 개수를 반환
	bool isEmpty() const { return (sz == 0); } // 트리가 비었으면 true를 반환

	// BST의 원소를 preorder로 방문했을 때의 방문 순서를 출력
	void preorder(NodePtr v) {
		if (v->element == 0) return; // nullptr일 때 원소가 0인데, 이 경우도 포함되어 출력되므로 0은 제외해주도록 한다
		cout << v->element << " ";
		if (isInternal(v)) {
			preorder(leftChild(v));
			preorder(rightChild(v));
		}
	}

	// BST의 원소를 postorder로 방문했을 때의 방문 순서를 출력
	void postorder(NodePtr v) {
		if (isInternal(v)) {
			postorder(leftChild(v));
			postorder(rightChild(v));
		}

		if (v->element == 0) return; // nullptr일 때 원소가 0인데, 이 경우도 포함되어 출력되므로 0은 제외해주도록 한다
		cout << v->element << " ";
	}

	// BST의 원소를 inorder로 방문했을 때의 방문 순서를 출력
	void inorder(NodePtr v) {
		if (isInternal(v)) inorder(leftChild(v));

		if (v->element == 0) return; // nullptr일 때 원소가 0인데, 이 경우도 포함되어 출력되므로 0은 제외해주도록 한다
		cout << v->element << " ";

		if (isInternal(v)) inorder(rightChild(v));
	}

	// 트리 구조를 2D로 출력하는 함수
	void print2DUtil(NodePtr root, int space)
	{
		if (root == NULL)
			return;

		// 층 사이의 간격을 생성
		space += COUNT;

		// 오른쪽 자식 노드들을 출력
		print2DUtil(root->right, space);

		// 노드의 원소들을 출력하는 부분
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << root->element << "\n";

		// 오른쪽 자식 노드들을 출력
		print2DUtil(root->left, space);
	}

	void print2D(NodePtr root)
	{
		// 최초 노드는 root, space는 0임을 지정해주는 함수
		print2DUtil(root, 0);
	}

};