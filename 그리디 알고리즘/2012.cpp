#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int N;
ll ans;
vector<int> rankArr;
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
	cin >> N;
	rankArr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> rankArr[i];
	}
}

void solve() {
	sort(rankArr.begin(), rankArr.end());
	for (int i = 0; i < N; i++) {
		ans += abs(rankArr[i] - (i + 1));
	}
}

void output() {
	cout << ans;
}
