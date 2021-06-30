#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;
	vector<int> cookie(n);

	for (int i = 0; i < n; i++) {
		cin >> cookie[i];
	}

	int l = 0, r = 987654321, ans = 0;
	while (l <= r) {
		int temp = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			temp += cookie[i] / mid;
		}
		if (temp >= m) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}
