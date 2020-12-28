#include <iostream>
using namespace std;

typedef struct node *nodePtr;
typedef struct node {
	int data;
	nodePtr leftchild = NULL;
	nodePtr rightchild = NULL;
}node;

node tree[10000];
void postorder(nodePtr p);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int root, val, idx = 0;
	cin >> root;
	tree[idx].data = root;
	nodePtr p = &tree[idx];

	while (cin >> val) {
		idx++;
		p = &tree[0];
		while (1) {
			if (val < p->data) {
				if (!p->leftchild) {
					tree[idx].data = val;
					p->leftchild = &tree[idx];
					break;
				}
				else {
					p = p->leftchild;
				}
			}
			else {
				if (!p->rightchild) {
					tree[idx].data = val;
					p->rightchild = &tree[idx];
					break;
				}
				else {
					p = p->rightchild;
				}
			}
		}
	}
	postorder(&tree[0]);
}

void postorder(nodePtr p) {
	if (p) {
		postorder(p->leftchild);
		postorder(p->rightchild);
		cout << p->data << '\n';
	}
}