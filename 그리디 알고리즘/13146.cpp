#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll cnt = 0;
	int maxVal = arr[0];
	for (int i = 1; i < n; i++) {
		// 다음 값이 크면 해당 차이만큼 더해줌
		if (arr[i] > arr[i - 1]) {
			cnt += (arr[i] - arr[i - 1]);
		}
		maxVal = max(maxVal, arr[i]);
	}
	// 오름차순의 크기는 모두 더한 값이지만, 내림차순은 고려되지 않음
	ll ans = cnt + (maxVal - arr[n - 1]);
	cout << ans;
}