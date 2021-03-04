#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, k;
int parent[10001];
int money[10001];
bool check[10001];
int getParent(int node);
void unionParent(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		cin >> money[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int temp = getParent(i);
		if (!check[temp]) {
			ans += money[temp];
			check[temp] = true;
		}
	}

	if (ans > k) {
		cout << "Oh no\n";
	}
	else {
		cout << ans;
	}
}

int getParent(int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = getParent(parent[node]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (money[a] <= money[b]) parent[b] = a;
	else parent[a] = b;
}
