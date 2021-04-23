#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int N, K;
vector<int> arr, tree;
int init(int s, int e, int node);
void update(int s, int e, int node, int idx, int diff);
int mul(int s, int e, int node, int l, int r);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin >> N >> K) {
		arr.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (arr[i] > 0) arr[i] = 1;
			else if (arr[i] < 0) arr[i] = -1;
		}
		int h = (int)ceil(log2(N));
		tree.resize(1 << (h + 1));
		init(0, N - 1, 1);
		string ans = "";
		for (int i = 0; i < K; i++) {
			char op;
			int a, b;
			cin >> op >> a >> b;
			if (op == 'C') {
				--a;
				if (b > 0) b = 1;
				else if (b < 0) b = -1;
				arr[a] = b;
				update(0, N - 1, 1, a, b);
			}
			else {
				--a, --b;
				int val = mul(0, N - 1, 1, a, b);
				if (val == 0) {
					ans += "0";
				}
				else if (val == 1) {
					ans += "+";
				}
				else {
					ans += "-";
				}
			}
		}
		cout << ans << "\n";
	}
}

int init(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = init(s, mid, node * 2) * init(mid + 1, e, node * 2 + 1);
}

void update(int s, int e, int node, int idx, int diff) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node] = diff;
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, node * 2, idx, diff);
	update(mid + 1, e, node * 2 + 1, idx, diff);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int mul(int s, int e, int node, int l, int r) {
	if (r < s || l > e) return 1;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return mul(s, mid, node * 2, l, r) * mul(mid + 1, e, node * 2 + 1, l, r);
}