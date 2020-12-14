#define ll long long
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int TC = 3;
	while (TC--) {
		ll n;
		cin >> n;
		priority_queue<ll> pos;
		priority_queue<ll, vector<ll>, greater<ll>> neg;
		for (int i = 0; i < n; i++) {
			ll val;
			cin >> val;
			if (val < 0) {
				neg.push(val);
			}
			else if (val > 0) {
				pos.push(val);
			}
		}

		ll ans = 0;
		while (!pos.empty() || !neg.empty()) {
			
			if (ans > 0) {
				ans += neg.top();
				neg.pop();
			}
			else if (ans < 0){
				ans += pos.top();
				pos.pop();
			}
			else {
				if (pos.empty()) {
					ans += neg.top();
					neg.pop();
				}
				else {
					ans += pos.top();
					pos.pop();
				}
			}

			if ((pos.empty() && ans < 0) || (neg.empty() && ans > 0)) {
				break;
			}
		}

		if (ans == 0) {
			cout << "0\n";
		}
		else if (ans > 0) {
			cout << "+\n";
		}
		else {
			cout << "-\n";
		}
	}
}