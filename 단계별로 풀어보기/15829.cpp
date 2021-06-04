#define HASH 31
#define MOD 1234567891
#define ll long long
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;

	ll ans = 0, mul = 1;
	// (a + b) mod n = {(a mod n) + (b mod n)} mod n
	// (a * b) mod n == {(a mod n) * (b mod n)} mod n
	for (int i = 0; i < N; i++) {
		//ans += (s.at(i) - 'a' + 1) * mul;
		ans = ((ans % MOD) + ((s.at(i) - 'a' + 1) * mul) % MOD) % MOD;
		mul = (mul * HASH) % MOD;
	}

	cout << ans << endl;
}