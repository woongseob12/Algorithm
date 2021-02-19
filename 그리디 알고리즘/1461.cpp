#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	vector<int> plus, minus;
	for (int i = 0; i < N; i++) {
		int pos;
		cin >> pos;
		if (pos < 0) {
			minus.push_back(pos);
		}
		else {
			plus.push_back(pos);
		}
	}
	if (!plus.empty()) {
		sort(plus.begin(), plus.end(), greater<>());
	}
	if (!minus.empty()) {
		sort(minus.begin(), minus.end());
	}
	int idx = 0, ans = 0;
	// 양수
	for (int i = 0; i < plus.size(); i += M) {
		ans += 2 * plus[i];
		idx = i;
	}
	//cout << "양수 처리 후 : " << ans << endl;
	// 음수
	idx = 0;
	for (int i = 0; i < minus.size(); i += M) {
		ans += -2 * minus[i];
		idx = i;
	}

	//cout << "음수 처리 후 : " << ans << endl;
	int back;
	if (!minus.empty() && !plus.empty()) {
		back = max(-1 * minus[0], plus[0]);
	}
	else if (minus.empty()) {
		back = plus[0];
	}
	else {
		back = minus[0] * -1;
	}

	ans -= back;
	cout << ans << '\n';
}