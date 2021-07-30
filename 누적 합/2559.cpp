#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ans = -10000001;
vector<int> temperature;

void input();
void solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}

void input() {
	cin >> N >> K;
	temperature.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> temperature[i];
		temperature[i] += temperature[i - 1];
	}
}

void solve() {
	for (int i = K; i <= N; i++) {
		ans = max(ans, temperature[i] - temperature[i - K]);
	}
	cout << ans;
}