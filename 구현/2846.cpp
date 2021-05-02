#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0, temp = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			temp += arr[i] - arr[i - 1];
			ans = max(ans, temp);
		}
		else {
			temp = 0;
		}
	}
	cout << ans;
}