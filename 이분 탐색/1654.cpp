#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int K, N;
ll calLen(vector<ll> lan, ll low, ll high);

int main()
{
	cin >> K >> N;
	
	vector<ll> lan(K);
	ll maxLen = 0;
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		maxLen = max((int)maxLen, (int)lan[i]);
	}

	maxLen = calLen(lan, 1, maxLen);
	
	cout << maxLen << endl;
}

ll calLen(vector<ll> lan, ll low, ll high)
{
	int ans = 0;
	while (low <= high) {
		ll mid = (low + high) / 2;
		ll total = 0;
		for (int i = 0; i < K; i++) {
			total += lan[i] / mid;
		}
		if (total < N) {
			high = mid  - 1;
		}
		else {
			ans = max(ans, (int)mid);
			low = mid + 1;
		}
	}
	return ans;
}