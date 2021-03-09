#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int arr[100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	vector<int> tap(N + 1, 0);
	int ans = 0;
	for (int i = 0; i < K; i++) {
		bool put = false;
		int emptySpace = 0;
		for (int j = 1; j <= N; j++) {
			if (tap[j] == arr[i]) {
				put = true;
			}
			if (tap[j] == 0) {
				emptySpace = j;
			}
		}
		// 이미 있음
		if (put) { continue; }
		// 빈공간 있음
		if (emptySpace) {
			tap[emptySpace] = arr[i];
			continue;
		}
		// 뺴야 함
		ans++;
		int lastIdx = -1, tapIdx = 0;
		for (int j = 1; j <= N; j++) {
			int out = 0;
			for (int k = i + 1; k < K; k++) {
				if (tap[j] == arr[k]) {	break;}
				out++;
			}
			if (lastIdx < out) {
				lastIdx = out;
				tapIdx = j;
			}
		}
		tap[tapIdx] = arr[i];
	}
	cout << ans;
}
