#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> arr, tree;
int init(int s, int e, int node);
int find(int s, int e, int node, int l, int r);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int h = (int)ceil(log2(N));
	tree.resize(1 << (h + 1));
	init(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << find(0, N - 1, 1, --a, --b)<< '\n';
	}
}

int init(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = min(init(s, mid, node * 2), init(mid + 1, e, node * 2 + 1));
}

int find(int s, int e, int node, int l, int r) {
	if (r < s || l > e) return INT_MAX;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return min(find(s, mid, node * 2, l, r), find(mid + 1, e, node * 2 + 1, l, r));
}
