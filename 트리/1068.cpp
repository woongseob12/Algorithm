#include <iostream>
#include <vector>
using namespace std;

typedef struct node *nodePtr;
typedef struct node {
	int data;
	vector<nodePtr> Child;
}node;

int N, delData, leaf;
node tree[51];
void preorder(nodePtr p);
void calLeaf(nodePtr p);
void removeNode(nodePtr p);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		tree[i].data = i;
	}

	int root;
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;
			continue;
		}
		tree[parent].Child.push_back(&tree[i]);
	}

	cin >> delData;
	//cout << "제거 전: ";
	//preorder(&tree[root]);
	removeNode(&tree[root]);
	//cout << "\n제거 후: ";
	//preorder(&tree[root]);
	//cout << endl;
	calLeaf(&tree[root]);
	//cout << "\n리프노드의 개수 : " << leaf << '\n';
	cout << leaf << endl;
}

void preorder(nodePtr p) {
	if (p) {
		cout << p->data << " ";
		for (int i = 0; i < (int)p->Child.size(); i++) {
			preorder(p->Child[i]);
		}
	}
}

void calLeaf(nodePtr p) {
	if (p) {
		if (p->data == delData) { return; }
		if (p->Child.empty()) {
			//cout << "추가된 리프노드 : " << p->data << "\n";
			leaf++;
		}
		for (int i = 0; i < (int)p->Child.size(); i++) {
			calLeaf(p->Child[i]);
		}
	}
}

void removeNode(nodePtr p) {
	if (p) {
		for (auto it = p->Child.begin(); it != p->Child.end(); it++) {
			if ((*it)->data == delData) {
				p->Child.erase(it);
				return;
			}
		}
		for (int i = 0; i < (int)p->Child.size(); i++) {
			removeNode(p->Child[i]);
		}
	}
}