#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int diff = 2000000001, ans1, ans2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> sol(n);
	for (int i = 0; i < n; i++) {
		cin >> sol[i];
	}

	sort(sol.begin(), sol.end());
	
	int l = 0, r = n - 1;
	while (l < r) {
		int mix = sol[l] + sol[r];
		if (mix == 0) {
			ans1 = sol[l];
			ans2 = sol[r];
			break;
		}
		else {
			if (abs(mix) < diff) {
				diff = abs(mix);
				ans1 = sol[l];
				ans2 = sol[r];
			}
			if (mix < 0) {
				l++;
			}
			else {
				r--;
			}
		}
	}
	cout << ans1 << " " << ans2;
}
