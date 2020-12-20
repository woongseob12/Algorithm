#include <iostream>
using namespace std;

const int num = 15;

// 하나의 노드 정보를 선언
typedef struct node *treePtr;
typedef struct node {
	int data;
	treePtr leftChild, rightChild;
}node;

// 전위 순회
void preorder(treePtr ptr) {
	if (ptr) {	// NULL값이 아닌 data가 있을 경우
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회
void inorder(treePtr ptr) {
	if (ptr) {	// NULL값이 아닌 data가 있을 경우
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// 후위 순회
void postorder(treePtr ptr) {
	if (ptr) {	// NULL값이 아닌 data가 있을 경우
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[num + 1];
	// 데이터 값 할당
	for (int i = 1; i <= num; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	// 자식 노드 할당
	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	// 전위 순회
	preorder(&nodes[1]);
}