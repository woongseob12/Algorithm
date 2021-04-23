#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

int treeSize;
vector<int> arr;
vector<pair<int,int>> tree;
int initMin(int s, int e, int node);
int initMax(int s, int e, int node);
int findMin(int s, int e, int node, int l, int r);
int findMax(int s, int e, int node, int l, int r);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	arr.resize(N);
	int h = (int)ceil(log2(N));
	tree.resize(1 << (h + 1));

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	initMin(0, N - 1, 1);
	initMax(0, N - 1, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int l = min(a, b) - 1;
		int r = max(a, b) - 1;
		cout << findMin(0, N - 1, 1, l, r) << " " << findMax(0, N - 1, 1, l, r) << "\n";
	}
}

int initMin(int s, int e, int node) {
	if (s == e) return tree[node].first = arr[s];
	int mid = (s + e) / 2;
	return tree[node].first = min(initMin(s, mid, node * 2), initMin(mid + 1, e, node * 2 + 1));
}

int initMax(int s, int e, int node) {
	if (s == e) return tree[node].second = arr[s];
	int mid = (s + e) / 2;
	return tree[node].second = max(initMax(s, mid, node * 2), initMax(mid + 1, e, node * 2 + 1));
}

int findMin(int s, int e, int node, int l, int r) {
	if (l <= s && e <= r) return tree[node].first;
	if (l > e || s > r) return INT_MAX;
	int mid = (s + e) / 2;
	return min(findMin(s, mid, node * 2, l, r), findMin(mid + 1, e, node * 2 + 1, l, r));
}

int findMax(int s, int e, int node, int l, int r) {
	if (l <= s && e <= r) return tree[node].second;
	if (l > e || s > r) return INT_MIN;
	int mid = (s + e) / 2;
	return max(findMax(s, mid, node * 2, l, r), findMax(mid + 1, e, node * 2 + 1, l, r));
}