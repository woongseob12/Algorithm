#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll sol(ll n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;

	cout << sol(n);
}

ll sol(ll n) {
	ll temp = sqrt(n);
	if (temp * temp == n) return temp;
	return temp + 1;
}