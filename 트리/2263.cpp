#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> inorder, postorder, idx;
void preorder(int inStart, int inEnd, int postStart, int postEnd);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	idx.resize(n + 1);
	inorder.resize(n);
	postorder.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i < n; i++) {
		idx[inorder[i]] = i;
	}
	preorder(0, n - 1, 0, n - 1);
}

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) {
		return;
	}
	int root = postorder[postEnd];
	int rootIdx = idx[root];
	// Ãâ·Â
	cout << root << " ";
	// ÁÂ
	preorder(inStart, rootIdx - 1, postStart, postStart + (rootIdx - 1 - inStart));
	// ¿ì
	preorder(rootIdx + 1, inEnd, (postEnd - 1) - (inEnd - (rootIdx + 1)), postEnd - 1);
}