#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int H, W;
int arr[500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 0; i < W; i++) {
		int left = 0, right = 0, side;
		for (int j = 0; j <= i; j++) {
			left = max(left, arr[j]);
		}
		for (int j = i; j < W; j++) {
			right = max(right, arr[j]);
		}
		side = min(left, right);
		ans += side - arr[i];
	}

	cout << ans << "\n";
}
