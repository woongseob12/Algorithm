#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> arr, int target, int idx);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, ans = 0;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		if (binarySearch(arr, arr[i], i)) {
			ans++;
		}
	}
	cout << ans << endl;
}

bool binarySearch(vector<int> arr, int target, int idx) {
	int l = 0, r = arr.size() - 1;
	while (l < r) {
		int sum = arr[l] + arr[r];
		if (sum == target) {
			if (l != idx && r != idx) {
				return true;
			}
			else if (l == idx) {
				l++;
			}
			else if (r == idx) {
				r--;
			}
		}
		else {
			if (sum < target) {
				l++;
			}
			else {
				r--;
			}
		}
	}
	return false;
}