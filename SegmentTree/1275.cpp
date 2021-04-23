#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int N, Q;
vector<ll> arr, tree;
ll init(int s, int e, int node);
ll query(int s, int e, int node, int l, int r);
void update(int s, int e, int node, int idx, ll diff);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	tree.resize(N * 4);
	init(0, N - 1, 1);

	for (int i = 0; i < Q; i++) {
		int l, r, idx, val;
		ll diff;
		cin >> l >> r >> idx >> val;
		--l, --r, --idx;
		l < r? cout << query(0, N - 1, 1, l, r) << "\n": cout << query(0, N - 1, 1, r, l) << "\n";
		diff = val - arr[idx];
		arr[idx] = val;
		update(0, N - 1, 1, idx, diff);
	}
}

ll init(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

ll query(int s, int e, int node, int l, int r) {
	if (r < s || e < l) return 0;
	if (s >= l && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return query(s, mid, node * 2, l, r) + query(mid + 1, e, node * 2 + 1, l, r);
}

void update(int s, int e, int node, int idx, ll diff) {
	if (idx < s || e < idx) return;
	tree[node] += diff;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, node * 2, idx, diff);
	update(mid + 1, e, node * 2 + 1, idx, diff);
}