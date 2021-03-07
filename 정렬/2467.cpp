#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int N;
bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);

	ll l, h, diff = INTMAX_MAX;
	for (int i = 0; i < N - 1; i++) {
		if (abs(diff) > abs(arr[i] + arr[i + 1])) {
			l = arr[i];
			h = arr[i + 1];
			diff = l + h;
			if (diff == 0) {
				break;
			}
		}
	}
	cout << min(l, h) << " " << max(l, h);
}
