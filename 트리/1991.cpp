#define ALPHA 26
#include <iostream>
#include <string>
using namespace std;

int N;
typedef struct node *nodePtr;
typedef struct node {
	char data;
	nodePtr leftChild;
	nodePtr rightChild;
}node;
node tree[ALPHA];

void preorder(nodePtr p);
void inorder(nodePtr p);
void postorder(nodePtr p);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char parent, leftData, rightData;
		cin >> parent >> leftData >> rightData;
		int idx = parent - 'A';
		tree[idx].data = parent;

		if (leftData == '.') {
			tree[idx].leftChild = NULL;
		}
		else {
			int next = leftData - 'A';
			tree[idx].leftChild = &tree[next];
		}

		if (rightData == '.') {
			tree[idx].rightChild = NULL;
		}
		else {
			int next = rightData - 'A';
			tree[idx].rightChild = &tree[next];
		}
	}
	preorder(&tree[0]);
	cout << '\n';
	inorder(&tree[0]);
	cout << '\n';
	postorder(&tree[0]);
	cout << '\n';
}

void preorder(nodePtr p) {
	if (p) {
		cout << p->data;
		preorder(p->leftChild);
		preorder(p->rightChild);
	}
}

void inorder(nodePtr p) {
	if (p) {
		inorder(p->leftChild);
		cout << p->data;
		inorder(p->rightChild);
	}
}

void postorder(nodePtr p) {
	if (p) {
		postorder(p->leftChild);
		postorder(p->rightChild);
		cout << p->data;
	}
}

