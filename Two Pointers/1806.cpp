#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, S, ans = INF;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int e = 0, sum = 0;
	for (int s = 0; s < N; s++) {
		if (sum >= S) {
			ans = min(ans, e - s);
		}
		while (sum < S && e < N) {
			sum += arr[e++];
			if (sum >= S) {
				ans = min(ans, e - s);
			}
		}
		sum -= arr[s];
	}

	if (ans == INF) {
		ans = 0;
	}
	cout << ans;
}
