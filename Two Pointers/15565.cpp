#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int cnt = 0, e = 0, ans = INF;
	for (int s = 0; s < N; s++) {
		if (cnt == K) {
			ans = min(ans, e - s);
		}
		while (cnt < K && e < N) {
			if (arr[e] == 1) {
				cnt++;
			}
			if (cnt == K) {
				ans = min(ans, e - s + 1);
			}
			e++;
		}
		if (arr[s] == 1) {
			cnt--;
		}
	}
	if (ans == INF) {
		ans = -1;
	}
	cout << ans;
}
