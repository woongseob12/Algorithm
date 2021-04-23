#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

vector<ll> arr, tree;
ll init(int s, int e, int node);
void update(int s, int e, int node, int idx, ll diff);
ll query(int s, int e, int node, int l, int r);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, K;
	cin >> N >> M >> K;
	arr.resize(N);
	int h = (int)ceil(log2(N));
	tree.resize(1 << (h + 1));
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(0, N - 1, 1);
	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - arr[--b];
			arr[b] = c;
			update(0, N - 1, 1, b, diff);
		}
		else {
			--b, --c;
			cout << query(0, N - 1, 1, b, c) << "\n";
		}
	}
}

ll init(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

void update(int s, int e, int node, int idx, ll diff) {
	if (idx < s || e < idx) return;
	tree[node] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		update(s, mid, node * 2, idx, diff);
		update(mid + 1, e, node * 2 + 1, idx, diff);
	}
}

ll query(int s, int e, int node, int l, int r) {
	if (l > e || r < s) return 0;
	if (s >= l && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return query(s, mid, node * 2, l, r) + query(mid + 1, e, node * 2 + 1, l, r);
}