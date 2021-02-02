#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> pre, in;
void subtree(int s, int e, int root);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		pre.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> pre[i];
		}
		in.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> in[i];
		}
		// 전위 순회의 시작은 무조건 루트
		subtree(0, N - 1, 0);
		cout << '\n';
	}
}

void subtree(int s, int e, int root) {
	for (int i = s; i <= e; i++) {
		if (in[i] == pre[root]) {
			subtree(s, i  - 1, root + 1);
			subtree(i + 1, e, root + 1 + (i - s));
			cout << pre[root] << " ";
		}
	}
}