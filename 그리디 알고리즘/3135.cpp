#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int A, B, N, ans;
vector<int> hz;
void input();
void solve();
void output();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	output();
}

void input() {
	cin >> A >> B >> N;
	hz.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> hz[i];
	}
}

void solve() {
	ans = abs(A - B);
	for (int i = 0; i < N; i++) {
		ans = min(ans, abs(B - hz[i]) + 1);
	}
}

void output() {
	cout << ans;
}