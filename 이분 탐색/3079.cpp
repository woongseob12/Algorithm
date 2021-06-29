#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector <ll> arr(n);
	ll r = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r = max(r, arr[i] * m);
	}

	ll l = 0, ret;
	while(l < r){
		int mid = (l + r) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / arr[i];
		}
		if (cnt < m) {
			l = mid + 1;
		}
		else {
			ret = mid;
			r = mid - 1;
		}
	}
	cout << ret;
}