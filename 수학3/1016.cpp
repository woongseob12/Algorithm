#include <iostream>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

bool num[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll minVal, maxVal;
	cin >> minVal >> maxVal;
	int len = maxVal - minVal + 1;
	ll h = ceil(sqrt(maxVal));

	for (ll i = 2; i <= h; i++) {
		ll square = i * i;
		ll sVal = ceil((double)minVal / square);
		 
		for (ll idx = sVal * square; idx <= maxVal; idx += square) {
			num[idx - minVal] = true;
		}
	}


	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (!num[i]) ans++;
	}
	cout << ans << '\n';
}
