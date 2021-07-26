#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int> h;
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
	cin >> N >> L;
	h.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
}

void solve() {
	sort(h.begin(), h.end());
	for (int i = 0; i < N; i++) {
		if (L >= h[i]) {
			L++;
		}
		else {
			break;
		}
	}
	cout << L;
}