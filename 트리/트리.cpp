#include <iostream>
using namespace std;

const int num = 15;

// �ϳ��� ��� ������ ����
typedef struct node *treePtr;
typedef struct node {
	int data;
	treePtr leftChild, rightChild;
}node;

// ���� ��ȸ
void preorder(treePtr ptr) {
	if (ptr) {	// NULL���� �ƴ� data�� ���� ���
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ���� ��ȸ
void inorder(treePtr ptr) {
	if (ptr) {	// NULL���� �ƴ� data�� ���� ���
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// ���� ��ȸ
void postorder(treePtr ptr) {
	if (ptr) {	// NULL���� �ƴ� data�� ���� ���
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[num + 1];
	// ������ �� �Ҵ�
	for (int i = 1; i <= num; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	// �ڽ� ��� �Ҵ�
	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	// ���� ��ȸ
	preorder(&nodes[1]);
}