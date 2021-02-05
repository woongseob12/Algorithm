#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> w;
vector<bool> valid;
void recursive(int cnt, int weight);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	w.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> w[i];
		S += w[i];
	}
	
	valid.resize(S + 1);
	recursive(0, 0);
	int ans = 0;
	for (int i = 1; i <= S; i++) {
		if (!valid[i]) {
			ans++;
		}
	}
	cout << ans;
}

void recursive(int cnt, int weight) {
	if (weight > 0) {
		valid[weight] = true;
	}
	if (cnt == N) {
		return;
	}
	recursive(cnt + 1, weight + w[cnt]);
	recursive(cnt + 1, weight);
	recursive(cnt + 1, weight - w[cnt]);
}