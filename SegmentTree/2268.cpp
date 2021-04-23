#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> arr, tree;
ll Init(int s, int e, int node);
ll Sum(int s, int e, int node, int l, int r);
void Modify(int s, int e, int node, int idx, int diff);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	arr.resize(N);
	int h = (int)ceil(log2(N));
	tree.resize(1 << (h + 1));
	Init(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			int l = min(b, c) - 1;
			int r = max(b, c) - 1;
			cout << Sum(0, N - 1, 1, l, r) << "\n";
		}
		else {
			int diff = c - arr[--b];
			arr[b] = c;
			Modify(0, N - 1, 1, b, diff);
		}
	}
}

ll Init(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = Init(s, mid, node * 2) + Init(mid + 1, e, node * 2 + 1);
}

ll Sum(int s, int e, int node, int l, int r) {
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return Sum(s, mid, node * 2, l, r) + Sum(mid + 1, e, node * 2 + 1, l, r);
}

void Modify(int s, int e, int node, int idx, int diff) {
	if (idx < s || idx > e) return;
	tree[node] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		Modify(s, mid, node * 2, idx, diff);
		Modify(mid + 1, e, node * 2 + 1, idx, diff);
	}
}