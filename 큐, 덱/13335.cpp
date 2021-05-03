#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, w, l;
	cin >> n >> w >> l;
	vector<int> truck(n);
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}

	vector<int> len(w);
	int pos = 0, sum = 0, ans = 0;
	deque<int> dq;
	while (pos < n) {
		if (dq.size() == w) {
			sum -= dq.front();
			dq.pop_front();
		}
		if (sum + truck[pos] <= l) {
			dq.push_back(truck[pos]);
			sum += truck[pos++];
		}
		else {
			dq.push_back(0);
		}
		ans++;
	}
	ans += w;
	cout << ans;
}