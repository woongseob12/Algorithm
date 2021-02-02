#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int K, idx = 1;
vector<int> inorder, tree;
void subtree(int s, int e, int rootIdx, int idx);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> K;
	K = (int)pow(2, K) - 1;
	inorder.resize(K + 1);
	for (int i = 1; i <= K; i++) {
		cin >> inorder[i];
	}

	tree.resize(K + 1);
	subtree(1, K, (1 + K)/2, 1);
	int space = 2;
	for (int i = 1; i < (int)tree.size(); i++) {
		if (i % space == 0) {
			cout << '\n';
			space *= 2;
		}
		cout << tree[i] << " ";
	}
}

void subtree(int s, int e, int rootIdx ,int idx) {
	if ( idx  > K || idx < 1) {
		return;
	}
	tree[idx] = inorder[rootIdx];
	subtree(s, rootIdx - 1, (s + rootIdx - 1) / 2, idx * 2);
	subtree(rootIdx + 1, e , (rootIdx + 1 + e) / 2, idx * 2 + 1);
}
